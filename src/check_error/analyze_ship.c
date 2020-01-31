/*
** analyze_ship.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Wed Feb  1 12:03:40 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:21:23 2017 Anselin Mackendy-pierre
*/

#include	"navy.h"

int	check_the_point(char **post_ship)
{
  int	y;
  int	x;
  int	check;

  y = 0;
  check = 0;
  while (post_ship[y] != NULL)
    {
      x = 2;
      while (post_ship[y][x] != '\0')
	{
	  if  (post_ship[y][x] != ':')
	    check++;
	  else if (check != 2)
	    return (-1);
	  if (post_ship[y][x] == ':')
	    check= 0;
	  x++;
	}
      x = 0;
      check = 0;
      y++;
    }
  return (0);
}

int	check_arg(char **post_ship)
{
  int	y;
  int	x;
  int	check;

  y = 0;
  check = 0;
  while (post_ship[y] != NULL)
    {
      x = 0;
      while (post_ship[y][x] != '\0')
	{
	  if (post_ship[y][x] >= 48 && post_ship[y][x] <= 56
	      || post_ship[y][x] == 58 ||
	      post_ship[y][x] >= 65 && post_ship[y][x] <= 72)
	    check++;
	  x++;
	}
      y++;
    }
  if (check != 28)
    return (-1);
  else
    return (0);
}

int	check_nbr_ships(char **post_ship, int *nbr, int *y)
{

  if (post_ship[*y][1] != ':')
    return (-1);
  if (post_ship[*y][0] == 50)
    nbr[0]++;
  else if (post_ship[*y][0] == 51)
    nbr[1]++;
  else if (post_ship[*y][0] == 52)
    nbr[2]++;
  else if (post_ship[*y][0] == 53)
    nbr[3]++;
  return (0);
}

int	check_the_ships(char **post_ship)
{
  int	y;
  int	count;
  int	nbr[4];
  int	i;

  i = 0;
  y = 0;
  count = 0;
  init_my_counts(nbr, 4);
  while (y != 4)
    {
      if (post_ship[y][0] >= 50 && post_ship[y][0] <= 56)
	{
	  if ((check_nbr_ships(post_ship, nbr, &y)) == -1)
	    return (-1);
	  count++;
	}
      y++;
    }
  if (count == 4 && nbr[0] == 1 && nbr[1] == 1 && nbr[2] == 1 && nbr[3] == 1)
    return (0);
  else
    return (-1);
}

int	the_ships_errors(char **post_ship, char **map)
{
  t_size_ship   *axe;

  if ((axe = malloc(sizeof(char*) * 4)) == NULL)
    return (-1);
  axe->from_x = 0;
  axe->from_y = 0;
  axe->to_x = 0;
  axe->to_y = 0;
  axe->position = post_ship;
  if ((check_arg(post_ship)) == -1)
    return (-1);
  if (check_the_ships(post_ship) == -1)
    return (-1);
  post_ship = check_swap_pos(post_ship);
  if (check_the_point(post_ship) == -1)
    return (-1);
  if (check_heigth_ships(map, axe) == -1)
    return (-1);
}
