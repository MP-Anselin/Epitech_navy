/*
** post_the_ships.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Thu Feb  2 15:34:48 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:19:36 2017 Anselin Mackendy-pierre
*/

#include	"navy.h"

char	**draw_negative_ship(char **map, t_size_ship  *axe, int nbr, int i)
{
  char	o;

  o = init_char(nbr);
  if (axe->from_y == axe->to_y)
    while (i >= axe->to_x)
      {
	if (check_points(map, axe, i, -1) == -1)
	  return (NULL);
	map[axe->from_y][i] = o;
	i -= 2;
      }
  else if (axe->from_x == axe->to_x)
    while (i >= axe->to_y)
      {
	if (check_points(map, axe, i, -2) == -1)
	  return (NULL);
	map[i][axe->from_x] = o;
	i--;
      }
  return (map);
}

char	**draw_ship(char **map, t_size_ship  *axe, int nbr, int i)
{
  char	o;

  o = init_char(nbr);
  if (axe->from_y == axe->to_y)
    while (i <= axe->to_x)
      {
	if (check_points(map, axe, i, 1) == -1)
	  return (NULL);
	map[axe->from_y][i] = o;
	i += 2;
      }
  else if (axe->from_x == axe->to_x)
    while (i <= axe->to_y)
      {
	if (check_points(map, axe, i, 2) == -1)
	  return (NULL);
	map[i][axe->from_x] = o;
	i++;
      }
  return (map);
}

int	check_axe(char **map, char **posit, int count, int nbr)
{
  int	l;
  int	i;

  l = 65;
  i = 2;
  while  (l < 73)
    {
      if (posit[count][nbr] != l)
	i += 2;
      else if (posit[count][nbr] == l)
	return (i);
      l++;
    }
  return (0);
}

char	**point_ship(char **map, int count, t_size_ship *axe, int nbr)
{
  int	i;

  axe->from_y = (axe->position[count][3] - 48) + 1;
  axe->to_y = (axe->position[count][6] - 48) + 1;
  axe->from_x = check_axe(map, axe->position, count, 2);
  axe->to_x = check_axe(map, axe->position, count, 5);
  if (axe->from_y == axe->to_y)
    i = axe->from_x;
  else if (axe->from_x == axe->to_x)
    i = axe->from_y;
  if (axe->from_y == axe->to_y && axe->from_x < axe->to_x)
    map = draw_ship(map, axe, nbr, i);
  else if (axe->from_y == axe->to_y && axe->from_x > axe->to_x)
    map = draw_negative_ship(map, axe, nbr, i);
  if (axe->from_x == axe->to_x && axe->from_y < axe->to_y)
    map = draw_ship(map, axe, nbr, i);
  else if (axe->from_x == axe->to_x && axe->from_y > axe->to_y)
    map = draw_negative_ship(map, axe, nbr, i);
  return (map);
}

char	**posit_the_ship(char **map, char **str)
{
  t_size_ship	*axe;
  int	count;

  count = 0;
  if ((axe = malloc(sizeof(char*) * 4)) == NULL)
    return (NULL);
  axe->from_x = 0;
  axe->from_y = 0;
  axe->to_x = 0;
  axe->to_y = 0;
  axe->position = str;
  while (axe->position[count] != NULL)
    {
      if (axe->position[count][0] == '2')
	map = point_ship(map, count, axe, 2);
      else if (axe->position[count][0] == '3')
	map = point_ship(map, count, axe, 3);
      else if (axe->position[count][0] == '4')
	map = point_ship(map, count, axe, 4);
      else if (axe->position[count][0] == '5')
	map = point_ship(map, count, axe, 5);
      count++;
    }
  return (map);
}
