/*
** ship_info.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Wed Feb  1 11:50:51 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:20:25 2017 Anselin Mackendy-pierre
*/

#include	"navy.h"

char	**init_map()
{
  char	**map;
  int	op_map;
  char	*stock;
  int	y;

  y = 0;
  if ((map = malloc(sizeof(char*) * (10 + 1))) == NULL)
    return (NULL);
  if ((op_map = open("map", O_RDWR)) == -1)
    return (NULL);
  while ((stock = get_next_line(op_map)) != NULL)
    {
      map[y] = stock;
      y++;
    }
  map[y] = NULL;
  return (map);
}

char	**position_ship(char *str)
{
  char	**post;
  int	op_post;
  char	*stock;
  int	y;

  y = 0;
  if ((post = malloc(sizeof(char*) * (4 + 1))) == NULL)
    return (NULL);
  if ((op_post = open(str, O_RDWR)) == -1)
    return (NULL);
  while ((stock = get_next_line(op_post)) != NULL)
    {
      post[y] = stock;
      y++;
    }
  if (y > 5)
    return (NULL);
  post[y] = NULL;
  return (post);
}
