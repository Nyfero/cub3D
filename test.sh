#!/bin/bash

# Black        0;30     Dark Gray     1;30
# Red          0;31     Light Red     1;31
# Green        0;32     Light Green   1;32
# Brown/Orange 0;33     Yellow        1;33
# Blue         0;34     Light Blue    1;34
# Purple       0;35     Light Purple  1;35
# Cyan         0;36     Light Cyan    1;36
# Light Gray   0;37     White         1;37

BLUE='\033[0;34m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# WITHOUT VALGRIND
echo -e "\n${RED}BAD COLOUR ${NC}"
./cub3D ./wrong_file/bad_colour.cub
echo -e "\n${BLUE}BAD COLOUR 2 ${NC}"
./cub3D ./wrong_file/bad_colour2.cub
echo -e "\n${GREEN}BAD COLOUR 3 ${NC}"
./cub3D ./wrong_file/bad_colour3.cub

echo -e "\n${RED}BAD ELEMENT ${NC}"
./cub3D ./wrong_file/bad_element.cub
echo -e "\n${BLUE}BAD EXTENSION ${NC}"
./cub3D ./wrong_file/bad_extension.poil
echo -e "\n${GREEN}BAD TEXTURES ${NC}"
./cub3D ./wrong_file/bad_textures.cub

echo -e "\n${RED}DOUBLON ${NC}"
./cub3D ./wrong_file/doublon.cub
echo -e "\n${BLUE}MAP WRONG CARACTER ${NC}"
./cub3D ./wrong_file/map_bad_caracter.cub
echo -e "\n${GREEN}MAP FIRST ${NC}"
./cub3D ./wrong_file/map_first.cub

echo -e "\n${RED}MAP EMPTY LINE ${NC}"
./cub3D ./wrong_file/map_line_empty.cub
echo -e "\n${BLUE}MAP NOT CLOSE ${NC}"
./cub3D ./wrong_file/map_not_close.cub
echo -e "\n${GREEN}MAP NOT CLOSE 2 ${NC}"
./cub3D ./wrong_file/map_not_close2.cub

echo -e "\n${RED}NO PLAYER ${NC}"
./cub3D ./wrong_file/map_no_player.cub
echo -e "\n${BLUE}TWO PLAYER ${NC}"
./cub3D ./wrong_file/map_two_players.cub
echo -e "\n${GREEN}NO MAP ${NC}"
./cub3D ./wrong_file/no_map.cub
echo -e "\n${RED}FILE IS A DIRECTORY ${NC}"
./cub3D libft
echo -e "\n${YELLOW}WHAT HAPPENED WITH ENV ? ${NC}"
env -i ./cub3D file.cub
