/*
** print_result.c for lemin in /home/helixire/rendu/CPE_2014_lemin
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sun May  3 19:53:33 2015 Blank Pierre
** Last update Sun May  3 19:53:33 2015 Blank Pierre
*/

#include "lemin.h"
#include "str.h"
#include "my_error.h"

static int	my_list_len(t_list *list)
{
  int		i;
  t_list	*c;

  c = list;
  i = 0;
  while (c != NULL)
    {
      c = c->next;
      i += 1;
    }
  return (i);
}

static int	*tables(t_list **paths, int nb)
{
  int	i;
  int	pas;
  int	*ret;

  i = 0;
  while (paths[i] != NULL)
    i += 1;
  if ((ret = malloc(sizeof(*ret) * (i + 1))) == NULL)
    return (NULL);
  ret[i] = -1;
  i = -1;
  while (ret[++i] != -1)
    ret[i] = 0;
  pas = my_list_len(paths[0]);
  while (nb != 0)
    {
      i = -1;
      while (nb != 0 && paths[++i] != NULL && my_list_len(paths[i]) <= pas)
	{
	  ret[i] += 1;
	  nb -= 1;
	}
      pas += 1;
    }
  return (ret);
}

static t_ant	*kill_ant(t_ant *list, t_ant *kill)
{
  t_ant	*c;

  if (list == kill)
    {
      c = list->next;
      free(list);
      return (c);
    }
  c = list;
  while (c->next != NULL && c->next != kill)
    c = c->next;
  if (c->next != NULL)
    {
      c->next = kill->next;
      free(kill);
    }
  return (list);
}

static void	advance_ant(t_ant **ants, char *end)
{
  t_ant	*c;
  t_ant	*tmp;

  c = *ants;
  while (c != NULL)
    {
      c->path = c->path->next;
      (void)write(1, "P", 1);
      my_putnbr(c->nb);
      (void)write(1, "-", 1);
      if (c->path == NULL)
	{
	  my_putstr(end);
	  tmp = c;
	  c = c->next;
	  *ants = kill_ant(*ants, tmp);
	}
      else
	{
	  my_putstr(c->path->room->name);
	  c = c->next;
	}
      if (c != NULL)
	(void)write(1, " ", 1);
    }
}

int	print_result(t_list **paths, int nb, char *end)
{
  t_ant	*ants;
  int	i;
  int	antnb;
  int	*tab;

  ants = NULL;
  if ((tab = tables(paths, nb)) == NULL)
    return (my_error(EM));
  antnb = 0;
  while (ants != NULL || tab[0] != 0)
    {
      i = -1;
      while (tab[++i] > 0)
	{
	  if ((ants = add_ant(ants, paths[i], ++antnb)) == NULL)
	    return (my_error(EM));
	  tab[i] -= 1;
	}
      advance_ant(&ants, end);
      (void)write(1, "\n", 1);
    }
  free(tab);
  return (0);
}
