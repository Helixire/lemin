/*
** lemin.h for  in /home/baudin_r/rendu/Module/C/Lem_in/CPE_2014_lemin/include
**
** Made by Romain Baudin
** Login   <baudin_r@epitech.net>
**
** Started on  Mon Mar 30 14:03:39 2015 Romain Baudin
** Last update Sun May  3 16:26:01 2015 arnaud bourget
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
int		nb_get(int *nb, int *stock, int *special);
int		clean_list(t_list *list);
int		clear_tab(char **tab);
int		init(t_list **list, int *nb);
int		algo(t_list *list, int nb);
int		bfs(const t_room *end, int nb);
int		final_display(t_list *list, int nb);

#endif /* !LEMIN_H_ */
