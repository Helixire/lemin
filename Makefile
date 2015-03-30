##
## Makefile for  in /home/baudin_r/rendu/Module/C/Lem_in/CPE_2014_lemin
##
## Made by Romain Baudin
## Login   <baudin_r@epitech.net>
##
## Started on  Mon Mar 30 13:55:23 2015 Romain Baudin
## Last update Mon Mar 30 14:02:17 2015 Romain Baudin
##

CC	= gcc

RM	= rm -rf

NAME	= lem_in

SRCS	=

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
