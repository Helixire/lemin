/*
** bfs.c for lemin in /home/helixire/rendu/CPE_2014_lemin
**
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
**
** Started on  Sat May  2 15:52:37 2015 Blank Pierre
** Last update Sun May  3 23:00:05 2015 arnaud bourget
*/

#include "my_error.h"
#include "lemin.h"
#include "str.h"

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

static void	end_of_path(t_list **paths, const int i)
{
  int		j;

  j = i;
  free_list(paths[j + 1]);
  while (paths[++j] != NULL)
    paths[j] = paths[j + 1];
}

static int	bfs_end(t_list **paths)
{
  int		i;
  t_room	*tmp;
  int		start;

  start = 0;
  while (paths[start] != NULL)
    {
      if (paths[start]->room->poid == 0)
	start += 1;
      i = start - 1;
      while (paths[++i] != NULL)
	{
	  if ((tmp = find_next_path(paths[i]->room->path)) == NULL)
	    end_of_path(paths, i -= 1);
	  else
	    {
	      if ((paths[i] = add_to_list(paths[i], tmp)) == NULL)
		return (my_error(EM) + clean_paths(paths) - 1);
	      if (tmp->poid == 0)
		start += 1;
	      else
		tmp->visited = 1;
	    }
	}
    }
  return (0);
}

static t_room	*get_next_in_list(t_list *list)
{
  static t_list	*c;
  t_room	*ret;

  if (c == NULL)
    c = list;
  while (c != NULL)
    {
      if (c->room->poid != -1)
	{
	  if (c->room->poid != 0)
	    c->room->visited = 1;
	  ret = c->room;
	  c = c->next;
	  return (ret);
	}
      c = c->next;
    }
  return (NULL);
}

int		bfs(const t_room *end, int nb, t_list ***paths)
{
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
  if ((*paths = malloc(sizeof(**paths) * (nbpath + 1))) == NULL)
    return (my_error(EM));
  (*paths)[nbpath] = NULL;
  while (--nbpath > -1)
    if (((*paths)[nbpath] =
	 add_to_list(NULL, get_next_in_list(end->path))) == NULL)
      return (my_error(EM) + clean_paths(*paths) - 1);
  tri_list(*paths);
  return (bfs_end(*paths));
}
