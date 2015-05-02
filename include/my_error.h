/*
** my_error.h for lemin in /home/helixire/rendu/CPE_2014_corewar/include
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Wed Apr 15 22:33:24 2015 Blank Pierre
** Last update Wed Apr 15 22:33:28 2015 Blank Pierre
*/

#ifndef         MY_ERROR_H_
# define        MY_ERROR_H_

# define EM	"ERROR : malloc failure.\n"
# define EF	"ERROR : incorrect format\n"
# define ER	"\nDoes not exist, please create it before link\n"
# define SS	"ERROR : start is already set\n"
# define ES	"ERROR : end is already set\n"
# define SA	"ERROR : a room can't be the end and the beginning\n"
# define NS	"ERROR : start or end not set\n"
# define CE	"ERROR : a room with those coordinate already exist\n"
# define NE	"ERROR : a room with that name already exist\n"
# define LE	"ERROR : this link already exist\n"
# define NP	"ERROR : there is no path to go from start to end\n"
# define EN	"ERROR : the number of ants must be greater than 0\n"

int	my_error(char *str);

#endif /* !MY_ERROR_H_ */
