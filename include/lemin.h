/*
** lemin.h for  in /home/baudin_r/rendu/Module/C/Lem_in/CPE_2014_lemin/include
**
** Made by Romain Baudin
** Login   <baudin_r@epitech.net>
**
** Started on  Mon Mar 30 14:03:39 2015 Romain Baudin
** Last update Mon Mar 30 14:05:05 2015 Romain Baudin
*/

#ifndef LEMIN_H_
# define LEMIN_H_

typedef t_room s_room;

typedef struct	s_list
{
  t_room	*room;
  struct s_path	*next;
}		t_list;

struct	s_room
{
  char		*name;
  t_list	*path;
}		t_room;

#endif	/* !LEMIN_H_ */
