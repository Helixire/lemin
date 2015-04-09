/*
** str.c for str in /home/blank_p/Downloads
** 
** Made by pierre blank
** Login   <blank_p@epitech.net>
** 
** Started on  Wed Mar 18 13:58:55 2015 pierre blank
** Last update Wed Mar 18 23:10:51 2015 pierre blank
*/

#include "str.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

int	my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}

int	my_error(char *str)
{
  if (str != NULL)
    write(2, str, my_strlen(str));
  else
    write(2, "ERROR\n", 6);
  return (1);
}

int	my_strcmp(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] && str[i] == str2[i])
    ++i;
  return (str[i] - str2[i]);
}

int	my_get_nbr(char *str)
{
  int	nb;
  int	i;

  i = -1;
  nb = 0;
  while (str[++i] && str[i] >= '0' && str[i] <= '9')
    {
      nb *= 10;
      nb += str[i] - '0';
    }
  return (nb);
}

