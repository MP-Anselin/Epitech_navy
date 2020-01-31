/*
** if_win.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy/src/battle
** 
** Made by root
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Sun Feb 12 10:04:04 2017 root
** Last update Sun Feb 19 10:36:39 2017 Anselin Mackendy-pierre
*/
#include	"navy.h"

void	interpret(int y, int x)
{
  int	nbr;
  char	c;

  nbr = 2;
  c = 65;
  while (nbr < x)
    {
      nbr += 2;
      c++;
    }
  if (nbr == x)
    my_printf("%c", c);
  if (y == 2)
    my_printf("1:  ");
  else
    my_printf("%d:  ", y - 1);
}

void	recpt_result_of_attack(t_positions *pos, t_my_pid *sg,
			       t_stock_map *the_map)
{
  int	count;

  count = -2;
  if (sec_player > 0)
    sec_player *= -1;
  while (sec_player < 0)
    {
      pause();
      count++;
    }
  if (count == 9)
    {
      interpret(pos->y, pos->x);
      the_map->sec_map[pos->y][pos->x] = 'o';
      my_printf("missed\n");
    }
  else if (count == 10)
    {
      interpret(pos->y, pos->x);
      the_map->sec_map[pos->y][pos->x] = 'x';
      my_printf("hit\n");
    }
}

int	enemy_won(int nbr_x, t_my_pid *sg)
{
  if (nbr_x == 14)
    {
      kill_result(sg, 14);
      my_printf("\nEnemy won\n");
      return (1);
    }
  return (0);
}

int	check_lose(t_stock_map *the_map, t_my_pid *sg)
{
  int	nbr_x;
  int	y;
  int	x;

  nbr_x = 0;
  y = 2;
  while (the_map->map[y] != NULL)
    {
      x = 2;
      while (the_map->map[y][x] != '\0')
	{
	  if (the_map->map[y][x] == 'x')
	    {
	      nbr_x++;
	      if (enemy_won(nbr_x, sg) == 1)
		return (1);
	    }
	  x += 2;
	}
      y++;
    }
  if (nbr_x != 14)
    kill_result(sg, 11);
  return (0);
}

int	check_win()
{
  int	count;

  count = -2;
  if (sec_player > 0)
    sec_player *= -1;
  while (sec_player < 0)
    {
      pause();
      count++;
      if (count == 14)
	{
	  my_printf("\nI win\n");
	  return (1);
	}
    }
  return (0);
}
