/*
** get_next_line.h for OSEF in /home/blank_p/rendu/CPE_2014_get_next_line
** 
** Made by pierre blank
** Login   <blank_p@epitech.net>
** 
** Started on  Tue Nov 18 14:14:19 2014 pierre blank
** Last update Mon Jan 12 06:27:28 2015 pierre blank
*/

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

# define BUFFER_SIZE 666

# include <unistd.h>
# include <stdlib.h>

char	*add_char(char **str, const int l, const char c);
char	*get_next_line(const int fd);
void	gScrol(char *);

#endif /* _GET_NEXT_LINE_H_ */
