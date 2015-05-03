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

static t_list	*get_before(t_list *list, t_list *cible)
{
  t_list	*c;

  c = list;
  if (list == cible)
    return (NULL);
  while (c->next != cible)
    c = c->next;
  return (c);
}

static t_list	*invert_list(t_list *list)
{
  t_list	*c;
  t_list	*tmp;

  c = list;
  while (c->next != NULL)
    c = c->next;
  tmp = c;
  while (c != NULL)
    {
      c->next = get_before(list, c);
      c = c->next;
    }
  return (tmp);
}

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
  list = invert_list(list);
  final_display(list, nb);
  c = list;
  while (c->room->special != 2)
    c = c->next;
  print_result(paths, nb, c->room->name);
  clean_list(list);
  clean_paths(paths);
  return (0);
}
