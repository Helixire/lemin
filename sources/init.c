/*
** init.c for lemin in /home/helixire/rendu/CPE_2014_lemin
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Fri Apr 17 13:49:56 2015 Blank Pierre
** Last update Fri Apr 17 13:49:56 2015 Blank Pierre
*/

#include "get_next_line.h"
#include "lemin.h"
#include "str.h"
#include "parser.h"
#include "my_error.h"

static int	check_room(t_list *list, char **tab)
{
  t_list	*current;
  int		x;
  int		y;

  x = my_get_nbr(tab[1]);
  y = my_get_nbr(tab[2]);
  current = list;
  while (current != NULL)
    {
      if (x == current->room->x && y == current->room->y)
	return (my_error(CE));
      if (my_strcmp(tab[0], current->room->name) == 0)
	return (my_error(NE));
      current = current->next;
    }
  return (0);
}

static int	in_loop(t_list **list, char **tab, char *str, int *special)
{
  int		i;
  t_room	*tmp;
  char		**tab2;

  i = my_tablen(tab);
  if (i == 1)
    {
      if ((tab2 = parse(str, "-")) == NULL)
	return (my_error(EM));
      if (tab2[1] == NULL && tab2[2] != NULL)
	return(my_error(EF) + clear_tab(tab2) - 1);
      return (link_room(*list, tab2) + clear_tab(tab2) - 1);
    }
  else if (i == 3)
    {
      if (check_room(*list, tab) == 1)
	return (1);
      if (!((tmp = create_room(tab, *special)) != NULL &&
	    (*list = add_to_list(*list, tmp)) != NULL))
	return (my_error(EM));
      *special = 0;
    }
  else
    return (my_error(EF));
  return (0);
}

static int	loop(char *str, t_list **list, int *special)
{
  char		**tab;

  if ((tab = parse(str, " \t")) == NULL)
    return (my_error(EM));
  return (in_loop(list, tab, str, special) + clear_tab(tab) - 1);
}

static int	check_special(int *stock, char *str, int *special)
{
  if (my_strcmp(str, START_ST) == 0)
    {
      if (*special != 0)
	return (my_error(SA));
      *special = 1;
      if ((*stock & 1) == 0)
	*stock |= 1;
      else
	return (my_error(SS));
      return (0);
    }
  else if (my_strcmp(str, END_ST) == 0)
    {
      if (*special != 0)
	return (my_error(SA));
      *special = 2;
      if ((*stock & 2) == 0)
	*stock |= 2;
      else
	return (my_error(ES));
      return (0);
    }
  return (-1);
}

int	init(t_list **list, int *nb)
{
  char	*str;
  int	special;
  int	stock;
  int	tmp;

  if (nb_get(nb, &stock, &special) == 1)
    return (1);
  while ((str = get_next_line(0)) != NULL)
    {
      if ((tmp = check_special(&stock, str, &special)) == 1)
	{
	  free(str);
	  return (1);
	}
      else if (tmp == -1 && str[0] != '#' && str[0] != 0
	       && loop(str, list, &special) == 1)
	{
	  free(str);
	  return (1);
	}
      free(str);
    }
  if ((stock & 1) == 0 || (stock & 2) == 0 || special != 0)
    return (my_error(NS));
  return (0);
}
