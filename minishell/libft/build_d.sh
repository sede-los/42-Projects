#!/bin/bash

# COLORS
GREEN="\e[0;32m"
RED="\e[0;31m"
BLACK="\e[0;30m"
YELLOW="\e[1;33m"
BLUE="\e[0;34m"
PURPLE="\e[1;95m"
BG_PURPLE="\e[45m"
END="\e[0m"

MFILE=build_file
SRC_DIR="src"
INCLUDE_DIR="include"
PROJ_NAME=""
BONUS_FLAG=0
IDIR_FLAG=0
SDIR_FLAG=0

set_bonus (){
	bonus=$(find $SRC_DIR -name "*_bonus*" -type f 2>/dev/null)  
	if [ -n "$bonus" ]
	then
		BONUS_FLAG=1
	else
		echo "No bonus files found!"
		exit 1
	fi
}

usage (){
	echo "Usage: buildv2 <project_name> [OPTIONS]. Use buildv2 -h for more information."
}

print_help(){
	echo -e 'Usage: buildv2 <project_name> [OPTIONS]
The buildv2 script creates two folders "include" and "src" (unless specified otherwise) where all .h and .c files are moved 
respectively if they are found on the same directory where buildv2 is executed.
A generic Makefile is then created that  will compile all .c files and  asign to NAME the string given as parameter.
If a libft folder is found, the script will create default paths and compilation rules to include the library.
If the src folder is already created, buildv2 will create a default path for each file and folder in the Makefile.

Bonus:
 --bonus,	if files with the extension _bonus.c are found, buildv2 will NOT include them in the main executable, a separate
		rule will be created: _BONUS_NAME, that will ONLY build _bonus.c files and create a separate executable 
		_BONUS_NAME so a main_bonus.c is required.
		e.g. src/foo/bar_bonus.c yields _BONUS_SRC = src/foo/bar_bonus.c
		e.g. src/foo_bonus.c yields _BONUS_SRC = src/foo_bonus.c
Directories:
Only folders within the root directory of the project will be accepted, no subdirectories will be searched.
 -S, --source	specifies where to look for .c files (src by default).
 -I, --include	specifies where to look for .h files (include by default).
\nScript created by adavila- (adavila-@student.42madrid.com)'

exit 0
}

if [ $# -eq 0 ] ; then usage ; exit 1 ; fi
if [ $1 == "-h"  ] ; then print_help ; fi

TEMP=$(getopt -o I:S:b -l "source: include: bonus" -n $0 -- "$@" 2>&1)


if [ $? != 0 ] ; then echo $(sed 1q <<< "$TEMP"); exit ; fi

eval set -- "$TEMP"
while true; do
  case "$1" in
    -S | --source) SRC_DIR=$2; SDIR_FLAG=1; shift 2;;
    -I | --include) INCLUDE_DIR=$2; IDIR_FLAG=1; shift 2;;
    --bonus ) set_bonus; shift ;;
    -- ) shift ;;
    * ) if [ ! -n "$1" ]; then echo "buildv2: a project name must be provided." >&2; exit 1; else PROJ_NAME=$1; fi
        break ;;
  esac
done


if [[ ! -d include ]] && [ $IDIR_FLAG -eq 0 ] ; then mkdir include 2>/dev/null ; fi
if [[ ! -d src ]] && [ $SDIR_FLAG -eq 0 ] ; then mkdir src 2>/dev/null ; fi
if [ ! -n "$(find . -name $SRC_DIR -type d 2>/dev/null)" ] ; then echo "Please provide a valid source dir: $SRC_DIR"; exit 1; fi
if [ ! -n "$(find . -name $INCLUDE_DIR -type d 2>/dev/null)" ] ; then echo "Please provide a valid include dir: $INCLUDE_DIR"; exit 1; fi

c_files=$(ls ./*.c  2>/dev/null| wc -l)
h_files=$(ls ./*.h  2>/dev/null| wc -l)
if [ $c_files != 0 ] ; then printf "$YELLOW> All .c files in '$(pwd)' have been moved to '$SRC_DIR'$END\n"  ; mv *.c $SRC_DIR ; fi
if [ $h_files != 0 ] ; then printf "$YELLOW> All .h files in '$(pwd)' have been moved to '$INCLUDE_DIR'$END\n" ; mv *.h $INCLUDE_DIR ; fi
if [ -f $MFILE ] ; then rm $MFILE ; fi

# COLORS TABLE

echo -e 'GREEN\t\t=\t\t\\033[0;32m' >> $MFILE
echo -e 'RED\t\t\t=\t\t\\033[0;31m' >> $MFILE
echo -e 'BLACK\t\t=\t\t\\033[0;30m' >> $MFILE
echo -e 'YELLOW\t\t=\t\t\\033[1;33m' >> $MFILE
echo -e 'BLUE\t\t=\t\t\\033[0;34m' >> $MFILE
echo -e 'PURPLE\t\t=\t\t\\033[1;95m' >> $MFILE
echo -e 'END\t\t\t=\t\t\\033[0m' >> $MFILE
echo -e "\n" >> $MFILE


# CREATE COMPILATION / BUILD FLAGS
echo -e "CC\t\t\t=\t\tgcc" >> $MFILE
echo -e "CFLAGS\t\t=\t\t-Wall -Wextra -Werror" >> $MFILE
echo -e "RM\t\t\t=\t\trm -rf" >> $MFILE

libft_path=$(find . -name libft -type d)
if [ -n "$libft_path" ]
then
	echo -e "LIBS\t\t=\t\t-L $libft_path -l:libft.a" >> $MFILE
	echo -e "LIBFT\t\t=\t\t$libft_path/libft.a" >> $MFILE
fi
printf "\n\n" >> $MFILE
echo -e "NAME\t\t=\t\t$PROJ_NAME" >> $MFILE

if [ $BONUS_FLAG -gt 0 ]
then
	echo -e "_BONUS_NAME\t\t=\t\t${PROJ_NAME}_bonus" >> $MFILE
fi

# CREATE PATH_SRC = FILES.c
all_path=$(find $SRC_DIR -type d 2>/dev/null)
if [ -n "$all_path" ]
then
	for folder in $all_path
	do
		strip_folder=$(basename $folder)
		c_files=$(ls $folder/*.c 2>/dev/null | sort -V)
		echo -e "${strip_folder^^}_SRC\t\t=\t\\" >> $MFILE
		for file in $c_files
		do
			if [[ $file == *"_bonus"* ]]
			then
				if [ $BONUS_FLAG -eq 0 ]
				then
					echo -e "\t\t\t\t\t$(basename $file) \\" >> $MFILE
				fi
			else
				echo -e "\t\t\t\t\t$(basename $file) \\" >> $MFILE
			fi
		done
			echo " " >> $MFILE
	done
	if [ $BONUS_FLAG -gt 0 ]
	then
		echo -e "_BONUS_SRC\t\t=\t\\" >> $MFILE
		for bonus_file in $bonus
		do
			echo -e "\t\t\t\t\t$bonus_file \\" >> $MFILE
		done
		echo " " >> $MFILE
	fi


# MERGE ALL PATH_SRC INTO SRC_FILES & CREATE OBJ VARIABLE
	echo -e "SRC_FILES\t\t=\t\\" >> $MFILE
	for folder in $all_path
	do
		strip_folder=$(basename $folder)
		echo -e '\t\t\t\t\t$(addprefix $('${strip_folder^^}'_DIR)/, $('${strip_folder^^}_SRC')) \' >> $MFILE
	done
	echo " " >> $MFILE
	echo -e 'OBJ\t\t\t\t=\t$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))' >> $MFILE
	if [ $BONUS_FLAG -gt 0 ]
	then
		echo -e '_BONUS_OBJ\t\t=\t$(addprefix $(OBJ_DIR)/, $(_BONUS_SRC:.c=.o))' >> $MFILE
	fi
	echo -e '\n' >> $MFILE

# CREATE ALL DIRECTORIES VARIABLES FOR EACH FOLDER: PATH_SRC BECOMES PATH_DIR
	for folder in $all_path
	do
		dirname=$(basename $folder)
		if [ $folder = "$SRC_DIR" ]
		then
			echo -e ''${dirname^^}_DIR'\t\t=\t'$dirname'' >> $MFILE
		else
			echo -e ''${dirname^^}_DIR'\t\t=\t'$folder'' >> $MFILE
		fi
	done
else
	echo "$SRC_DIR dir was not found"
fi

# MISC DIRS
echo -e 'INC_DIR\t\t=\t\t'${INCLUDE_DIR}'' >> $MFILE
echo -e 'OBJ_DIR\t\t=\t\tobj' >> $MFILE
printf "\n\n" >> $MFILE

# all
echo -e 'all: $(NAME)\n' >> $MFILE

if [ $BONUS_FLAG -gt 0 ]
then
	echo -e 'bonus: $(_BONUS_NAME)\n' >> $MFILE
	echo -ne '$(_BONUS_NAME): ' >> $MFILE
	if [ -n "$libft_path" ]
	then
		echo ' $(LIBFT) $(_BONUS_OBJ)' >> $MFILE
		echo -e '\t@$(CC) $(CFLAGS) $(_BONUS_OBJ) $(LIBS) -o $(_BONUS_NAME)' >> $MFILE

	else
		echo ' $(_BONUS_OBJ)' >> $MFILE
		echo -e '\t@$(CC) $(CFLAGS) $(_BONUS_OBJ) -o $(_BONUS_NAME)' >> $MFILE
	fi
	echo -e '\t@printf "                                   \\r"' >> $MFILE
	echo -e '\t@printf "$(GREEN)> BUILDING $(_BONUS_NAME)\t\t\t[✓]$(END)\\n"\n' >> $MFILE
	echo " " >> $MFILE 
fi

if [ -n "$libft_path" ]
then
	echo '$(LIBFT):' >> $MFILE
	echo -e "\t@make -s -C $libft_path\n" >> $MFILE
fi
# NAME RULE
echo -ne '$(NAME):' >> $MFILE
if [ -n "$libft_path" ]
then
	echo ' $(LIBFT) $(OBJ)' >> $MFILE
	echo -e '\t@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)' >> $MFILE

else
	echo ' $(OBJ)' >> $MFILE
	echo -e '\t@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)' >> $MFILE
fi
echo -e '\t@printf "                                   \\r"' >> $MFILE
echo -e '\t@printf "$(GREEN)> BUILDING '${PROJ_NAME^^}'\t\t\t[✓]$(END)\\n"\n' >> $MFILE

# OBJ CREATION RULE & OBJ DIR RULE
echo -e '$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)' >> $MFILE
echo -ne "\t" >> $MFILE
echo '@printf "$(YELLOW)> BUILDING $<               \r$(END)"' >> $MFILE
echo -e '\t@$(CC) $(CFLAGS) -I $(INC_DIR) -c -o $@ $<\n' >> $MFILE

echo '$(OBJ_DIR):' >> $MFILE
for	folders in $all_path
do
	echo -e '\t@mkdir -p obj/'$folders'' >> $MFILE
done
echo "" >> $MFILE

# CLEANERS
echo "clean:" >> $MFILE
if [ -n "$libft_path" ]
then
	echo -e "\t@make clean -s -C $libft_path" >> $MFILE
fi
echo -e '\t@$(RM) $(OBJ_DIR)\n' >>$MFILE

echo "fclean: clean" >> $MFILE
if [ -n "$libft_path" ]
then
	echo -e "\t@make fclean -s -C $libft_path" >> $MFILE
fi
echo -e '\t@$(RM) $(NAME)\n' >>$MFILE

echo -e "re: fclean all\n" >> $MFILE

#.PHONY
echo -ne ".PHONY: all clean fclean re" >> $MFILE
if [ $BONUS_FLAG -gt 0 ]
then 
	echo -ne " bonus" >> $MFILE
fi
