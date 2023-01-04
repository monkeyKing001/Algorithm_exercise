#!/bin/bash

########################################
#######    get pwd and shell    ########
########################################
cur_dir=`echo $PWD`
shell=`echo $SHELL | rev | cut -d '/' -f1 | rev`
rc=
# checking shell
printf "\033[1;37m"
printf "shell : "
printf "\e[1;32m"
printf "%s\n" ${shell}
printf "\033[0m"

# checking current directory
printf "\033[1;37m"
printf "cureendt directory : "
printf "\e[1;32m"
printf "%s\n" ${cur_dir}
printf "\033[1;37m"

########################################
#######    get shellrc name     ########
########################################
if [ "${shell}" = "zsh" ];
then
	rc=".zshrc"
else
	rc=".bashrc"
fi
printf "\033[1;37m"
printf "this script will edit %s\n" ${rc} 
printf "\033[0m"

########################################
######    vim c, cpp template   ########
########################################
# make templates dir
temp_dir="templates"
if [ ! -d ~/.vim/${temp_dir} ];
then
	mkdir ~/.vim/${temp_dir} 
fi

# download templates
printf "\033[1;34m"
printf "downloading skeleton files for LINUX\n"
printf ".\n.\n.\n"
printf "\033[0m"
curl https://raw.githubusercontent.com/monkeyKing001/Vim_Settings_LNX/main/templates/skeleton.cpp -o ~/.vim/${temp_dir}/skeleton.cpp
curl https://raw.githubusercontent.com/monkeyKing001/Vim_Settings_LNX/main/templates/skeleton.c -o ~/.vim/${temp_dir}/skeleton.c
curl https://raw.githubusercontent.com/monkeyKing001/Vim_Settings_LNX/main/templates/skeleton_makefile -o ~/.vim/${temp_dir}/skeleton_makefile
printf "\033[1;34m"
printf ".\n.\n.\n"
printf "completed downloading skeleton files.\n"
printf "\033[0m"

# update vimrc
# c_template
temp_list=(skeleton.c skeleton.cpp skeleton_makefile) 
for temp_file in "${temp_list[@]}"
do
	exist=`cat ~/.vimrc | grep "~/.vim/templates/${temp_file}"`
	if [ "${exist}" = "" ];
	then
		printf "\033[1;37m"
		printf "updated vimrc; :autocmd BufNewFile Makefile 0r ~/.vim/templates/${temp_file}\n"
		printf "\033[0m"
		echo ":autocmd BufNewFile Makefile 0r ~/.vim/templates/${temp_file}" >> ~/.vimrc
	fi
done
#temp_file="skeleton.c"
#exist_c_temp=`cat ~/.vimrc | grep "~/.vim/templates/${temp_file}"`
#if [ "${temp_file}" = "" ];
#then
#	printf "\033[1;37m"
#	printf "updated vimrc; :autocmd BufNewFile *.c 0r ~/.vim/templates/${temp_file}\n"
#	printf "\033[0m"
#	echo ":autocmd BufNewFile *.c 0r ~/.vim/templates/${temp_file}" >> ~/.vimrc
#fi
#
## cpp_template
#temp_file="skeleton.cpp"
#exist_cpp_temp=`cat ~/.vimrc | grep "~/.vim/templates/${cpp_temp}"`
#if [ "${exist_cpp_temp}" = "" ];
#then
#	printf "\033[1;37m"
#	printf "updated vimrc; :autocmd BufNewFile *.cpp 0r ~/.vim/templates/${cpp_temp}\n"
#	printf "\033[0m"
#	echo ":autocmd BufNewFile *.cpp 0r ~/.vim/templates/${cpp_temp}" >> ~/.vimrc
#fi
#
## make_template
#exist_makefile_temp=`cat ~/.vimrc | grep "~/.vim/templates/skeleton_makefile"`
#if [ "${exist_makefile_temp}" = "" ];
#then
#	printf "\033[1;37m"
#	printf "updated vimrc; :autocmd BufNewFile Makefile 0r ~/.vim/templates/skeleton_makefile\n"
#	printf "\033[0m"
#	echo ":autocmd BufNewFile Makefile 0r ~/.vim/templates/skeleton_makefile" >> ~/.vimrc
#fi

vim -c "source %" -c "PluginInstall" -c "q" -c "q"


########################################
#######     setting alias       ########
########################################
exist_gogo_alias=`cat ~/${rc} | grep "alias gogo="`
if [ "${exist_gogo_alias}" = "" ];
then
	printf "\033[1;37m"
	printf "updated gogo alias!\n"
	printf "\033[0m"
	echo "alias gogo=\"cd ${cur_dir} && source ${cur_dir}/start_problem.sh\"" >> ${HOME}/${rc}
fi
source ~/${rc}
printf "\033[1;37m"
echo '                 __                             __                                                                       '
echo '  _      _____  / /________  ____ ___  ___     / /_____                                                                  '
echo ' | | /| / / _ \/ / ___/ __ \/ __ `__ \/ _ \   / __/ __ \                                                                 '
echo ' | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /                                                                 '
echo ' |__/|__/\___/_/\___/\____/_/ /_/ /_/\___/   \__/\____/                                                                  '
echo '                                                                                                                         '
echo '     ____                                 ____   _____       _      _ __                     __   _______                '
echo '    / __ \____  ____  ____ ___     ____  / __/  / ___/____  (_)____(_) /_   ____ _____  ____/ /  /_  __(_)___ ___  ___   '
echo '   / /_/ / __ \/ __ \/ __ `__ \   / __ \/ /_    \__ \/ __ \/ / ___/ / __/  / __ `/ __ \/ __  /    / / / / __ `__ \/ _ \  '
echo '  / _, _/ /_/ / /_/ / / / / / /  / /_/ / __/   ___/ / /_/ / / /  / / /_   / /_/ / / / / /_/ /    / / / / / / / / /  __/  '
echo ' /_/ |_|\____/\____/_/ /_/ /_/   \____/_/     /____/ .___/_/_/  /_/\__/   \__,_/_/ /_/\__,_/    /_/ /_/_/ /_/ /_/\___/   '
echo '                                                  /_/                                                                    '
printf "\033[0m\n\n"
echo "                                                                                                                                                                                                        "
echo "                                                                                                                                                                                                        "
echo "                                                                       .                                                                                                                                "
echo "                                                                       /,                                                                                                                               "
echo "                                                                   ,,,**//((.                                                                                       .                                   "
echo "                                                                 .,.,,,,,,*/((                               ,                                                      *                                   "
echo "                                                                 ,*,,,,,,,*///*                             .(.                                                .,/.,*/(,                                "
echo "                                                                 ...,,*,,**/*.                             .*/#.                                             ..,.,,,**((((*                             "
echo "                                                                 .,..*//////(/                   ...,,*,....,(/(/////*,,...                                .,,,,,,,,,,,/////                            "
echo "                                                                  /,,/((###(#/              .,,,..,,,,,/,..,....,///(((((//****.                          .*,,,,.,,,,,,,///(*                           "
echo "                                                                  /,./((##(((.           ..........,,,..,,..,,,,,,,,,*////((((/*,**                        *....,****/*//*/*                            "
echo "                                                          ,,*(/    ,**/((##.            ............,,,,,,**,,,,,,,,,,,,*////(((//*,,                      **/ *////(##%(/#                             "
echo "                                                            ..,,       (,.           .........  ..,*/  ,**//,*,,,,,,,,,,,,*/*//((((//*,                     .  /(///#%##,.                              "
echo "                                                          ..*/.      .....          ..,...,,,  . .   ,* ./(/*,,,,,,,,,,,,,,,*/*//(((/**.                     ./    .    .                               "
echo "                                                            #      ..    ...        ...,,.,..  *     ,/  ((,,..,,,,,,,,,*,,,,,*////////                      .       .  .                               "
echo "                                                            *             ..   .........,..*,    ,*,*,   /*...,,*,,,,,,,,,***/,.*////(.                       .      . .                                "
echo "                                                            ,             ...,,,,,,,...,.. ...           /,,,,,,,*****,   ,,.. ./(/*,........                  .    . .        .***/.                   "
echo "                                                            ,.. .         ..,,,,,,,,,.,,,,,.,,.     .....,,..,,,..     ...,*(/*,,,....................,*,        .  .              **,                  "
echo "                                                     ....   ..... .*//((//*. ........ ,,,..,************,***,#/.*///////*.  ...,,,,,,,,,,,,,,,,,,,,,***,,*       .,.             ...,.                  "
echo "                                                 ...........*#. .#.*/((/////   ....., ,**,/*,*******////*/%@&*/.*////////* ....,,,,,,,,,,,,,,,,,,,,**,./(*    ...(#, .          . ,                     "
echo "                                                ...................*(#(((#/(    ....* .*,,,,*,*******,(/,*..(*,,//////*//* ....,,,,,,,,,,,,,,,,,,*,,%&(((.  ./..(((((#*          (                      "
echo "                                               ................,,..,,,,,,****........,. .*,,,,*(#(/@*&(*,,////*,*//******* ................ ....,&&&%&(((..( .////((((*%,.       /                      "
echo "                                                .,,,,...............,,..........,,,,**,*.,*,,,,,,,#/,((*****//*,*//(,//,  ..........**. .....  .*%%%##(((,*..//*/((((((##.       /                      "
echo "                                                        ..,,*,,,.....,,.........,,..,*,,.*(*,,,,*%&&&,**,,*//*./ . ....*,,,............,*//#(. ./##//,//,.( ,///((//(((,%....    ,                      "
echo "                                                                    ...,,***,.,......,*,,*/*,////#%%%*******//.,,,,,,,,,,,,.............       ,/**((,..../ *////(//*(#,%...............                "
echo "                                                                           ..........,.,**.,,///////*//*,*////.*,,,,,,*,,..,***,......*...     ,/(......... *///(((((#%,%.......,...........            "
echo "                                                                        ...........,,,,,,,,,*/*,.............,.......,**//,.......**.........,...........,. .,,,......,.*,**....,............*          "
echo "                                                                     ......... .##/.,,,,,,,,,,,,,,...,,*****,,,,...*/*........**,.........,,............................//,/.../*(,..........*          "
echo "                                                                  ..............*%%&,,,,,,,,,,,,,,....,,,,,...,*/,.......,//,..... ........................,,,,,,,*****/(*.................,/.          "
echo "                                                               ..........,*, .  &%%#,,,,,,,,,,,,,,.,,,,,,,///,,......,/*,.......#.    ...**//*,.....................,....................,#,            "
echo "                                                            ...,,..............,**,....,,,,,,,,,,,,,.*//*,,,,,...,/*,.......#/.                   ....,*///,..........................,#/.              "
echo "                                                          ..,...,*,................,,,,***********/**,,,,,,,.,**,,....,./(..                                   ....,*//*,,   .../(((*.                  "
echo "                                                        .....,......,***..........,,,,,,,,,,,,,,,,..,,,,,*/*,......,*#.                                                       .                         "
echo "                                                        .*,....,.........,.*//*...,,,,,,,,,,,,,,,,..,*/*,.......,#*.                                                                                    "
echo "                                                         ,/,...................,,.,***/***,**********,.......(/..                                                                                       "
echo "                                                           ./****............,..........,,,,...,..,.,,.../#..                                                                                           "
echo "                                                                 .*****,.......,,....,,,..........,,./#*.                                                                                               "
echo "                                                                        .,,****..................*(/,.                                                                                                  "
echo ".                                                                            .****/((////*/////,,,                                                                                                      "
echo "                                                                                     .,.,...                                                                                                            "
