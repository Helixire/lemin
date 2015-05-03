/*
** nb_get.c for lemin in /home/helixire/rendu/CPE_2014_lemin
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Fri May  1 15:48:50 2015 Blank Pierre
** Last update Fri May  1 15:48:50 2015 Blank Pierre
*/

#include "lemin.h"
#include "get_next_line.h"
#include "my_error.h"
#include "str.h"

int	nb_get(int *nb, int *stock, int *special)
{
  char	*str;

  if ((str = get_next_line(0)) == NULL)
    return (my_error(EM));
  if ((*nb = my_get_nbr(str)) <= 0)
    {
      free(str);
      return (my_error(EN));
    }
  free(str);
  *stock = 0;
  *special = 0;
  return (0);
}
