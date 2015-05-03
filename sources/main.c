/*
** main.c for  in /home/baudin_r/rendu/Module/C/Lem_in/CPE_2014_lemin/sources
**
** Made by Romain Baudin
** Login   <baudin_r@epitech.net>
**
** Started on  Mon Mar 30 14:02:43 2015 Romain Baudin
** Last update Mon Mar 30 14:02:44 2015 Romain Baudin
*/

#include "lemin.h"
#include "str.h"

int		main(void)
{
  t_list	*list;
  int		nb;
  t_list	**paths;
  t_list	*c;

  list = NULL;
  if (init(&list, &nb) == 1)
    return (clean_list(list));
  if (algo(list, nb, &paths) == 1)
    return (clean_list(list));
  final_display(list, nb);
  c = list;
  while (c->room->special != 2)
    c = c->next;
  print_result(paths, nb, c->room->name);
  clean_list(list);
  clean_paths(paths);
  return (0);
}
