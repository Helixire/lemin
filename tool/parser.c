/*
** parser.c for OSEF in /home/blank_p
** 
** Made by pierre blank
** Login   <blank_p@epitech.net>
** 
** Started on  Fri Jan 30 01:12:56 2015 pierre blank
** Last update Wed Mar 18 13:48:34 2015 pierre blank
*/

#include "parser.h"

int	index_of(const char *str, const char c)
{
  int	i;

  if (str != NULL)
    {
      i = -1;
      while (str[++i])
	if (str[i] == c)
	  return (i);
    }
  return (-1);
}

char	*my_strndup(char *str, int n)
{
  char	*result;
  int	i;

  if ((result = malloc(n + 1)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] && i < n)
    result[i] = str[i];
  result[i] = 0;
  return (result);
}

int	parse_count(char *str, char *delim)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      while (str[i] && index_of(delim, str[i]) != -1)
	++i;
      if (str[i] != 0)
	{
	  ++j;
	  while (str[i] && index_of(delim, str[i]) == -1)
	    ++i;
	}
    }
  return (j);
}

int	parse_init(char *str, char *delim, char ***result)
{
  if (str == NULL || str[0] == 0)
    {
      *result = NULL;
      return (1);
    }
  if ((*result = malloc(sizeof(**result) * (parse_count(str, delim) + 1)))
      == NULL)
    {
      *result = NULL;
      return (1);
    }
  return(0);
}

char	**parse(char *str, char *delim)
{
  int	i;
  int	j;
  int	k;
  char	**result;

  if (parse_init(str, delim, &result) == 1)
    return (result);
  i = 0;
  k = -1;
  while (str[i])
    {
      while (str[i] && index_of(delim, str[i]) != -1)
	++i;
      j = i;
      if (str[i] != 0)
	{
	  while (str[i] && index_of(delim, str[i]) == -1)
	    ++i;
	  result[++k] = my_strndup(str + j, i - j);
	}
    }
  result[++k] = NULL;
  return (result);
}
