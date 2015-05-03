/*
** list2.c for lemin in /home/helixire/rendu/CPE_2014_lemin
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sun May  3 18:22:20 2015 Blank Pierre
** Last update Sun May  3 18:22:20 2015 Blank Pierre
*/

#include "lemin.h"
#include "str.h"
#include "my_error.h"

void	free_list(t_list *list)
{
  t_list	*tmp;
  t_list	*c;

  c = list;
  while (c != NULL)
    {
      tmp = c;
      c = c->next;
      free(tmp);
    }
}

int		clean_paths(t_list **paths)
{
  int		i;

  i = -1;
  while (paths[++i] != NULL)
    free_list(paths[i]);
  free(paths);
  return (1);
}

int		clean_list(t_list *list)
{
  t_list	*i;
  t_list	*tmp;

  i = list;
  while (i != NULL)
    {
      free_list(i->room->path);
      tmp = i;
      i = i->next;
      free(tmp->room->name);
      free(tmp->room);
      free(tmp);
    }
  return (1);
}

void		tri_list(t_list **lists)
{
  t_list	*tmp;
  int		i;
  int		j;

  i = -1;
  while (lists[++i]!= NULL)
    {
      j = i - 1;
      while (lists[++j] != NULL)
	if (lists[j]->room->poid < lists[i]->room->poid)
	  {
	    tmp = lists[i];
	    lists[i] = lists[j];
	    lists[j] = tmp;
	  }
    }
}

t_ant	*add_ant(t_ant *ant, t_list *list, int nb)
{
  t_ant	*ret;
  t_ant	*c;

  if ((ret = malloc(sizeof(*ret))) == NULL)
    {
      free_ant(ant);
      return (NULL);
    }
  ret->path = list;
  ret->nb = nb;
  ret->next = NULL;
  if (ant == NULL)
    return (ret);
  c = ant;
  while (c->next != NULL)
    c = c->next;
  c->next = ret;
  return (ant);
}
