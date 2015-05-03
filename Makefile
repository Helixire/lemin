##
## Makefile for  in /home/baudin_r/rendu/Module/C/Lem_in/CPE_2014_lemin
##
## Made by Romain Baudin
## Login   <baudin_r@epitech.net>
##
## Started on  Mon Mar 30 13:55:23 2015 Romain Baudin
## Last update Sun May  3 23:04:07 2015 arnaud bourget
##

CC	= gcc

RM	= rm -f

NAME	= lem_in

CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -Iinclude

SRCS	= sources/main.c \
	  sources/init.c \
	  sources/algo.c \
	  sources/nb_get.c \
	  sources/bfs.c \
	  sources/display.c \
	  sources/print_result.c \
	  tool/get_next_line.c \
	  tool/str.c \
	  tool/str2.c \
	  tool/parser.c \
	  tool/list.c \
	  tool/list2.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
