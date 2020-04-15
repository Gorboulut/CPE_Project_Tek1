#!/bin/bash

BLACK=$'\e[30m'
RED=$'\e[31m'
GREEN=$'\e[32m'
YELLOW=$'\e[33m'
BLUE=$'\e[34m'
ROSE=$'\e[35m'
CYAN=$'\e[36m'
GRAY=$'\e[37m'
RESET=$'\e[0m'
GRAS=$'\e[1m'
UDLINE=$'\e[4m'
OVLINE=$'\e[7m'

read -p "${YELLOW}${UDLINE}${GRAS}CHECK${RESET} ${CYAN}${GRAS}${UDLINE}[warning/norm/valgrind/criterion/push/ALL]${RESET} : " -r funcall

function warning(){
    echo -e "${GREEN}${UDLINE}\nCHECK WARNING...${RESET}"
    make re &>/dev/null
    if [ 2 == $? ];then
        sleep 1
        echo -e "${RED}${GRAS}${OVLINE}\nYOU HAVE AT LEAST ONE WARNING, NOT GOOD${RESET}"
        read -p "${YELLOW}${GRAS}Do you still want to continue ? [y/n] : " -r follow
        if [ $follow == "y" ];then
            sleep 0.3
        fi
        if [ $follow == "n" ];then
            exit
        fi
    else
        echo -e "${GREEN}${UDLINE}${OVLINE}\nNo warning, good boy !\n${RESET}"
    fi
}

function norm(){
    echo -e "${GREEN}${UDLINE}CHECK NORM...${RESET}"
    sleep 1
    norminette -T4 -i4 -A -v
}

function valgrind_func(){

    echo -e "${GREEN}${UDLINE}\nCHECK VALGRIND...${RESET}"
    read -p "Do command : " -r var1
    if [ -x $var1 ]; then
        valgrind $var1
    else
        echo -e "${RED}${OVLINE}${GRAS}\nTHE FILE IS NOT EXECUTABLE !${RESET}"
        valgrind_func
    fi
}

function criterion(){
    echo -e "${GREEN}${UDLINE}CHECK CRITERION...${RESET}"
    sleep 1
    cd tests &>/dev/null
    if [ $? == 0 ];then
        echo "${GREEN}${GRAS}EXECUTING TESTS...${RESET}"
        read -p "[Launch your tests]" var2
        var2
    else
        echo -e "${RED}${GRAS}NO BONUS FILES !${RESET}"
    fi
}

function push(){
    read -p "[Do you want to push something ?] [y/n] : " -r sure

    if [ $sure = "y" ];then
        make fclean &>/dev/null
        git status
        read -p "[What do you want to push] : " pushing
        git add $pushing
        echo -e "\e[32mAdding \e[37m $pushing\e[32m...\e[37m"
        read -p "[Commit message] : " commit
        git commit -m "$commit"
        echo -e "\e[35mSuccessfully committed\e[37m"
        git push origin master
        echo -e "\e[35mSuccessfully pushed\e[35m"

    elif [ $sure = "n" ];then
        echo -e "\e[31m\e[1m[You don't want to push]\e[37m\e[0m"
    fi
}

function ALL(){
    warning
    norm
    valgrind_func
    criterion
    push
}

$funcall