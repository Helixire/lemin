##
## Makefile for  in /home/baudin_r/rendu/Module/C/Lem_in/CPE_2014_lemin
##
## Made by Romain Baudin
## Login   <baudin_r@epitech.net>
##
## Started on  Mon Mar 30 13:55:23 2015 Romain Baudin
## Last update Wed Apr 15 21:21:30 2015 arnaud bourget
##

CC	= gcc

RM	= rm -f

NAME	= lem_in

CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -Iinclude

SRCS	= sources/main.c

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
