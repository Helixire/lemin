/*
** get_next_line.c for OSEF in /home/blank_p/rendu/CPE_2014_get_next_line
** 
** Made by pierre blank
** Login   <blank_p@epitech.net>
** 
** Started on  Tue Nov 18 14:14:06 2014 pierre blank
** Last update Mon Jan 12 06:26:36 2015 pierre blank
*/

#include "get_next_line.h"

/*
** add_char: doc
**
** description: add a char to a string
** param: str: the string to add a char to
**        l: the current lenght of the string
**        c: the character to add
** detail: if malloc returned NULL the function with also return NULL
*/

static char	*add_char(char **str, const int l, const char c)
{
  char	*result;
  int	i;

  if ((result = malloc(l + 2)) != NULL)
    {
      i = -1;
      while (++i < l)
	result[i] = (*str)[i];
      result[i] = c;
      result[i + 1] = 0;
      free(*str);
      *str = result;
    }
  else
    return (NULL);
  return (result);
}

/*
** gScrol: doc
**
** description : delete the first char and push all the others
** put a 0 at the end of buffer
**
** param: buffer: the buffer to scrol
*/

static void	gScrol(char *buffer)
{
  int	i;

  i = -1;
  while (++i < BUFFER_SIZE - 1)
    buffer[i] = buffer[i + 1];
  buffer[i] = 0;
}

/*
** get_next_line: doc
** 
** description: read one line from the file descriptor and retrun it
** param: fd = file descriptor
** return: char * of to the line read
** detail: if there are no more line to read get_next_line will return NULL
**         get_next_line will not return the \n
*/

char		*get_next_line(const int fd)
{
  static char	buffer[BUFFER_SIZE];
  char		*tmp;
  int		l;

  l = 0;
  tmp = NULL;
  while (buffer[0] != '\n')
    {
      if (buffer[0] == 0)
	{
	  if (read(fd, buffer, BUFFER_SIZE) <= 0 || buffer[0] == 0)
	    return (tmp);
	}
      else
	{
	  if (add_char(&tmp, l++, buffer[0]) == NULL)
	    return (NULL);
	  gScrol(buffer);
	}
    }
  gScrol(buffer);
  return ((tmp == NULL) ? add_char(&tmp, 0, 0) : tmp);
}
