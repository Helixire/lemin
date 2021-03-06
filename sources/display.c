/*
** display.c for lemin in /home/bourge_k/Rendu/Modules/Prog_Elem/B2/CPE_2014_lemin/sources
**
** Made by arnaud bourget
** Login   <bourge_k@epitech.net>
**
** Started on  Sun May  3 14:34:38 2015 arnaud bourget
** Last update Sun May  3 16:48:56 2015 arnaud bourget
*/

#include "lemin.h"
#include "str.h"

static void	display_name(t_list *list)
{
  my_putstr(list->room->name);
  my_putstr(" ");
  my_putnbr(list->room->x);
  my_putstr(" ");
  my_putnbr(list->room->y);
  my_putstr("\n");
}

static void	display_link(t_list *list)
{
  t_list	*tmp;
  t_list	*link;

  tmp = list;
  while (tmp != NULL)
    {
      link = tmp->room->path;
      while (link != NULL)
	{
	  if (link->room->visited == 0)
	    {
	      my_putstr(tmp->room->name);
	      my_putstr("-");
	      my_putstr(link->room->name);
	      my_putstr("\n");
	    }
	  link = link->next;
	}
      tmp->room->visited = 1;
      tmp = tmp->next;
    }
}

void		final_display(t_list *list, int nb)
{
  t_list	*tmp;

  tmp = list;
  my_putnbr(nb);
  my_putstr("\n");
  while (tmp != NULL)
    {
      if (tmp->room->special != 0)
	{
	  (tmp->room->special == 1) ? my_putstr(START_ST) :
	    my_putstr(END_ST);
	  my_putstr("\n");
	}
      tmp->room->visited = 0;
      display_name(tmp);
      tmp = tmp->next;
    }
  display_link(list);
}
