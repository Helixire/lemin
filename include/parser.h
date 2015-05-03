/*
** parser.h for parser in /home/blank_p/Downloads
** 
** Made by pierre blank
** Login   <blank_p@epitech.net>
** 
** Started on  Wed Mar 18 13:45:19 2015 pierre blank
** Last update Wed Mar 18 13:49:04 2015 pierre blank
*/

#ifndef _PARSER_H_
# define _PARSER_H_

# include <stdlib.h>

int	index_of(const char *str, const char c);
char	*my_strndup(char *str, int n);
char	**parse(char *str, char *delim);

#endif /* _PARSER_H_ */
