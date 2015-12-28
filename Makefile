##
## Makefile for  in /home/single_j//projets/malloc
## 
## Made by julien singler
## Login   <single_j@epitech.net>
## 
## Started on  Wed Feb  9 11:17:27 2011 julien singler
## Last update Sun Feb 13 10:04:03 2011 julien singler
##

NAME	=	libmalloc.so

SRC	=	fragment.c	\
		free.c		\
		fusion.c	\
		malloc.c	\
		show_alloc_mem.c	\
		power.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-O3 -W -Wall -Werror -ansi

all	:	$(OBJ)
		gcc -shared -fpic  -o libmalloc.so $(OBJ)

clean	:	
		rm -f $(OBJ) core *.core *~ \#*\#

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all