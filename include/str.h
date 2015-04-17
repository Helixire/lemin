/*
** str.h for str in /home/blank_p/Downloads
** 
** Made by pierre blank
** Login   <blank_p@epitech.net>
** 
** Started on  Wed Mar 18 14:02:07 2015 pierre blank
** Last update Wed Mar 18 23:10:29 2015 pierre blank
*/

#ifndef _STR_H_
# define _STR_H_

# include <unistd.h>
# include <stdlib.h>

int	my_strlen(char *str);
int	my_putstr(char *str);
int	my_error(char *str);
int	my_strcmp(char *str, char *str2);
int	my_get_nbr(char *str);
int	my_tablen(char **tab);
int	clear_tab(char **tab);
char	*my_strdup(char *str);
void	my_putnbr(int nb);

#endif /* _STR_H_ */
