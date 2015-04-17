/*
** str2.c for lemin in /home/helixire/rendu/CPE_2014_lemin
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Fri Apr 17 13:29:04 2015 Blank Pierre
** Last update Fri Apr 17 13:29:04 2015 Blank Pierre
*/

#include "str.h"

char	*my_strdup(char *str)
{
  char	*dest;
  int	i;

  if ((dest = malloc(sizeof(dest) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = -1;
  while (str[++i])
    dest[i] = str[i];
  dest[i] = 0;
  return (dest);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}

int	clear_tab(char **tab)
{
  int	i;

  if (tab != NULL)
    {
      i = -1;
      while (tab[++i] != NULL)
	free(tab[i]);
      free(tab);
    }
  return (1);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      write(1, "-", 1);
      nb *= -1;
    }
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar('0' + nb % 10);
}
