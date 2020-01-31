/*
** next_analyze_ship.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Wed Feb  1 19:48:31 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:23:00 2017 Anselin Mackendy-pierre
*/

#include	"navy.h"

int	check_negative_size_ship(char **map, t_size_ship  *axe, int nbr, int i)
{
  int	count;

  count = 0;
  if (axe->from_y == axe->to_y)
    {
      i = axe->from_x;
      while (i >= axe->to_x)
	{
	  count++;
	  i -= 2;
	}
    }
  else if (axe->from_x == axe->to_x)
    {
      i = axe->from_y;
      while (i >= axe->to_y)
	{
	  count++;
	  i--;
	}
    }
  if (count == nbr)
    return (0);
  else
    return (-1);
}

int	check_size_ship(char **map, t_size_ship  *axe, int nbr, int i)
{
  int	count;

  count = 0;
  if (axe->from_y == axe->to_y)
    {
      i = axe->from_x;
      while (i <= axe->to_x)
	{
	  count++;
	  i += 2;
	}
    }
  else if (axe->from_x == axe->to_x)
    {
      i = axe->from_y;
      while (i <= axe->to_y)
	{
	  count++;
	  i++;
	}
    }
  if (count == nbr)
    return (0);
  else
    return (-1);
}

int	check_point_ship(char **map, int count, t_size_ship *axe, int nbr)
{
  int	i;

  axe->from_y = (axe->position[count][3] - 48) + 1;
  axe->to_y = (axe->position[count][6] - 48) + 1;
  axe->from_x = check_axe(map, axe->position, count, 2);
  axe->to_x = check_axe(map, axe->position, count, 5);
  if (axe->from_y != axe->to_y && axe->from_x != axe->to_x)
    return (-1);
  if (axe->from_x > axe->to_x && axe->from_y == axe->to_y)
    if (check_negative_size_ship(map, axe, nbr, i) == -1)
      return (-1);
  if (axe->from_x < axe->to_x && axe->from_y == axe->to_y)
    if (check_size_ship(map, axe, nbr, i) == -1)
      return (-1);
  if (axe->from_y > axe->to_y && axe->from_x == axe->to_x)
    if (check_negative_size_ship(map, axe, nbr, i) == -1)
      return (-1);
  if (axe->from_y < axe->to_y && axe->from_x == axe->to_x)
    if (check_size_ship(map, axe, nbr, i) == -1)
      return (-1);
  return (0);
}

int	check_heigth_ships(char **map, t_size_ship *axe)
{
  int	count;

  count = 0;
  while (axe->position[count] != NULL)
    {
      if (axe->position[count][0] == '2')
	if (check_point_ship(map, count, axe, 2) == -1)
	  return (-1);
      if (axe->position[count][0] == '3')
	if (check_point_ship(map, count, axe, 3) == -1)
	  return (-1);
      if (axe->position[count][0] == '4')
	if (check_point_ship(map, count, axe, 4) == -1)
	  return (-1);
      if (axe->position[count][0] == '5')
	if (check_point_ship(map, count, axe, 5) == -1)
	  return (-1);
      count++;
    }
  return (0);
}
