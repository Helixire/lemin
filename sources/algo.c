/*
** algo.c for lemin in /home/helixire/rendu/CPE_2014_lemin
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Fri Apr 17 14:21:49 2015 Blank Pierre
** Last update Fri Apr 17 14:21:49 2015 Blank Pierre
*/

#include "lemin.h"
#include "str.h"
#include "my_error.h"

static void	reset_visited(t_list *list)
{
  t_list	*current;

  current = list;
  while (current != NULL)
    {
      current->room->visited = 0;
      current = current->next;
    }
}

static t_room	*find_next(t_list *list)
{
  t_list	*i;
  t_room	*result;

  result = NULL;
  i = list;
  while (i != NULL)
    {
      if (i->room->visited == 0 && i->room->poid != -1 &&
	  (result == NULL || result->poid > i->room->poid))
	result = i->room;
      i = i->next;
    }
  return (result);
}

int		algo(t_list *list, int nb, t_list ***paths)
{
  t_room	*current;
  t_room	*end;
  t_list	*i;

  i = list;
  while (i->room->special != 2)
    i = i->next;
  end = i->room;
  while ((current = find_next(list)) != NULL)
    {
      current->visited = 1;
      i = current->path;
      while (i != NULL)
	{
	  if (i->room->poid > current->poid + 1 || i->room->poid == -1)
	    i->room->poid = current->poid + 1;
	  i = i->next;
	}
    }
  if (end->poid == -1)
    return (my_error(NP));
  reset_visited(list);
  return (bfs(end, nb, paths));
}
