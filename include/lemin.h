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

# define START_ST	"##start"
# define END_ST		"##end"

# include <stdlib.h>

typedef struct	s_room t_room;

typedef struct	s_list
{
  t_room	*room;
  struct s_list	*next;
}		t_list;

struct		s_room
{
  char		*name;
  int		special;
  int		x;
  int		y;
  int		poid;
  int		visited;
  t_list	*path;
};

t_room		*create_room(char **tab, int special);
t_list		*add_to_list(t_list *list, t_room *room);
t_room		*find_room(t_list *list, char *name);
int		link_room(t_list *list, char **tab);
int		clean_list(t_list *list);
int		clear_tab(char **tab);
int		init(t_list **list);
int		algo(t_list *list);

#endif	/* !LEMIN_H_ */
