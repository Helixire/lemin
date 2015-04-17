/*
** list.c for lemin in /home/helixire/rendu/CPE_2014_corewar/include
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Wed Apr 15 22:34:55 2015 Blank Pierre
** Last update Wed Apr 15 22:34:55 2015 Blank Pierre
*/

#include "lemin.h"
#include "str.h"
#include "my_error.h"

#include <stdio.h>

t_room		*create_room(char **tab, int special)
{
  t_room	*result;

  if ((result = malloc(sizeof(*result))) == NULL)
    return (NULL);
  if ((result->name = my_strdup(tab[0])) == NULL)
    {
      free(result);
      return (NULL);
    }
  result->special = special;
  result->x = my_get_nbr(tab[1]);
  result->y = my_get_nbr(tab[2]);
  result->poid = (special == 1) ? 0 : -1;
  result->visited = 0;
  result->path = NULL;
  return (result);
}

t_list		*add_to_list(t_list *list, t_room *room)
{
  t_list	*result;

  if ((result = malloc(sizeof(*result))) == NULL)
    return (NULL);
  result->room = room;
  result->next = list;
  return (result);
}

t_room		*find_room(t_list *list, char *name)
{
  t_list	*current;

  current = list;
  while (current != NULL)
    {
      if (my_strcmp(current->room->name, name) == 0)
	return (current->room);
      current = current->next;
    }
  return (NULL);
}

int		link_room(t_list *list, char **tab)
{
  t_room	*r1;
  t_room	*r2;

  if ((r1 = find_room(list, tab[0])) == NULL ||
      (r2 = find_room(list, tab[1])) == NULL)
    {
      my_error(tab[0]);
      my_error(" or ");
      my_error(tab[1]);
      return (my_error(ER));
    }
  if (find_room(r1->path, tab[1]) != NULL)
    return (my_error(LE));
  if ((r1->path = add_to_list(r1->path, r2)) == NULL ||
      (r2->path = add_to_list(r2->path, r1)) == NULL)
    return (my_error(EM));
  return (0);
}

int		clean_list(t_list *list)
{
  t_list	*i;
  t_list	*j;
  t_list	*tmp;

  i = list;
  while (i != NULL)
    {
      j = i->room->path;
      while (j != NULL)
	{
	  tmp = j;
	  j = j->next;
	  free(tmp);
	}
      tmp = i;
      i = i->next;
      free(tmp->room->name);
      free(tmp->room);
      free(tmp);
    }
  return (1);
}
