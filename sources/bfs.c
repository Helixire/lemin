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
  paths[nbpath] == NULL;
  nbpath = -1;
  while (paths[++nbpath] != NULL)
    paths[nbpath] = find_next_path(end->path);
  return (0);
}
