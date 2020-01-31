/*
** next_other_fonction.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy/src
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Mon Feb  6 11:09:33 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:17:01 2017 Anselin Mackendy-pierre
*/

#include	"navy.h"

void	change_arg(char *str, t_positions *pos)
{
  char	c;
  char	n;

  c = 65;
  n = 49;
  while  (c <= str[0])
    {
      pos->x += 2;
      c++;
    }
  while (n <= str[1])
    {
      if (n == 49)
	pos->y += 1;
      pos->y += 1;
      n++;
    }
}

char	*check_sawp_att(char *str)
{
  char	c;

  if (str[0] >= 48 && str[0] <= 56)
    {
      c = str[0];
      str[1] = str[0];
      str[0] = c;
    }
  return (str);
}

char	**check_swap_pos(char **posit)
{
  int	y;
  int	x;
  char	c;

  y = 0;
  while (posit[y] != NULL)
    {
      x = 2;
      while (posit[y][x] != '\0')
	{
	  if (posit[y][x] >= 65 && posit[y][x] <= 72 && posit[y][x - 1] != 58)
	    {
	      c = posit[y][x - 1];
	      posit[y][x - 1] = posit[y][x];
	      posit[y][x] = c;
	    }
	  x++;
	}
      y++;
    }
  return (posit);
}

int	check_points(char **map, t_size_ship *axe, int i, int nbr)
{
  char	p;

  p = 50;
  while (p != 53)
    {
      if (nbr == 1 && map[axe->from_y][i] == p)
	return (-1);
      else if (nbr == 2 && map[i][axe->from_x] == p)
	return (-1);
      else if (nbr == -1 && map[axe->to_y][i] == p)
	return (-1);
      else if (nbr == -2 && map[i][axe->to_x] == p)
	return (-1);
      p++;
    }
  return (0);
}

void	init_axe(t_positions *pos)
{
  pos->x = 0;
  pos->y = 0;
}
