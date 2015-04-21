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

t_room		*find_next(t_list *list)
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

int	is_in(char *str, char ***tab)
{
  int	i;
  int	j;

  i = -1;
  if (tab != NULL)
    while (tab[++i] != NULL)
      {
	j = -1;
	while (tab[i][++j] != NULL)
	  if (my_strcmp(str, tab[i][j]) == 0)
	    return (1);
      }
  return (0);
}

t_room		*get_min(t_room *room, char ***tab)
{
  t_list	*path;
  t_room	*res;

  path = room->path;
  res = NULL;
  while (path != NULL)
    {
      if (is_in(path->room->name, tab) == 0 &&
	  (res == NULL || res->poid > path->room->poid))
	res = path->room;
      path = path->next;
    }
  return (res);
}

int		algo(t_list *list)
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
  my_putnbr(end->poid);
  return (0);
}
