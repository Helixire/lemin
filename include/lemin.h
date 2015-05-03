/*
** lemin.h for  in /home/baudin_r/rendu/Module/C/Lem_in/CPE_2014_lemin/include
**
** Made by Romain Baudin
** Login   <baudin_r@epitech.net>
**
** Started on  Mon Mar 30 14:03:39 2015 Romain Baudin
** Last update Sun May  3 22:53:40 2015 arnaud bourget
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

typedef struct	s_ant
{
  t_list	*path;
  int		nb;
  struct s_ant	*next;
}		t_ant;

t_room		*create_room(char **tab, int special);
t_list		*add_to_list(t_list *list, t_room *room);
t_room		*find_room(t_list *list, char *name);
int		link_room(t_list *list, char **tab);
int		nb_get(int *nb, int *stock, int *special);
int		clean_list(t_list *list);
int		clear_tab(char **tab);
int		init(t_list **list, int *nb);
int		algo(t_list *list, int nb, t_list ***paths);
int		bfs(const t_room *end, int nb, t_list ***paths);
void		final_display(t_list *list, int nb);
int		clean_paths(t_list **paths);
void		free_list(t_list *list);
void		tri_list(t_list **lists);
t_ant		*add_ant(t_ant *ants, t_list *list, int nb);
int		free_ant(t_ant *ants);
int		print_result(t_list **paths, int nb, char *end);

#endif /* !LEMIN_H_ */
