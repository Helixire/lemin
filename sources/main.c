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

int		main(void)
{
  t_list	*list;

  list = NULL;
  if (init(&list) == 1)
    return (clean_list(list));
  if (algo(list) == 1)
    return (clean_list(list));
  clean_list(list);
  return (0);
}
