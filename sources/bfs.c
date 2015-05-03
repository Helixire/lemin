/*
** bfs.c for lemin in /home/helixire/rendu/CPE_2014_lemin
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sat May  2 15:52:37 2015 Blank Pierre
** Last update Sat May  2 15:52:37 2015 Blank Pierre
*/

#include "my_error.h"
#include "lemin.h"

int		clean_paths(t_list **paths)
{
  int		i;
  t_list	*tmp;
  t_list	*c;

  i = -1;
  while (paths[++i] != NULL)
    {
      c = paths[i];
      while (c != NULL)
	{
	  tmp = c;
	  c = c->next;
	  free(tmp);
	}
    }
  free(paths);
  return (1);
}

static t_room	*find_next_path(t_list *list)
{
  t_list	*i;
  t_room	*ret;

  ret = NULL;
  i = list;
  while (i != NULL)
    {
      if (i->room->visited == 0 && (ret == NULL || i->room->poid < ret->poid))
	ret = i->room;
      i = i->next;
    }
  return (ret);
}

int		bfs(const t_room *end, int nb)
{
  t_list	**paths;
  t_list	*current;
  int		nbpath;

  (void)nb;
  nbpath = 0;
  current = end->path;
  while (current != NULL)
    {
      if (current->room->poid != -1)
	nbpath += 1;
      current = current->next;
    }
  if ((paths = malloc(sizeof(*paths) * (nbpath + 1))) == NULL)
    return (my_error(EM));
  paths[nbpath] = NULL;
  nbpath = -1;
  while (paths[++nbpath] != NULL)
    if ((paths[nbpath] = add_to_list(NULL, find_next_path(end->path))) == NULL)
      return (my_error(EM) + clean_paths(paths) - 1);
  return (0);
}
