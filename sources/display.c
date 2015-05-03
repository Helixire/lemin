/*
** display.c for lemin in /home/bourge_k/Rendu/Modules/Prog_Elem/B2/CPE_2014_lemin/sources
**
** Made by arnaud bourget
** Login   <bourge_k@epitech.net>
**
** Started on  Sun May  3 14:34:38 2015 arnaud bourget
** Last update Sun May  3 15:07:20 2015 arnaud bourget
*/

#include "lemin.h"

int		final_display(t_list *list, int nb)
{
  t_list	*tmp;

  tmp = list;
  my_putnbr(nb);
  my_putchar('\n');
  while (tmp != NULL)
    {
      if (tmp->room->visited = 0)
	{
	  if (tmp->room->special != 0)
	    {
	      (tmp->room->special == 1) ? my_putstr(START_ST) : my_putstr(END_ST);
	      my_putchar('\n');
	    }
	  my_putstr(tmp->room->name);
	  my_putchar('\n');
	  tmp->room->visited = 1;
	}
      tmp = tmp->next;
    }
}
