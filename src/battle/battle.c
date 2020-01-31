/*
** first_player.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy/src
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Sat Feb  4 20:34:35 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:52:11 2017 Anselin Mackendy-pierre
*/

#include	"navy.h"

int	check_attack(t_stock_map *the_map, t_my_pid *sg, int y, int x)
{
  if (the_map->map[y][x] == '.' || the_map->map[y][x] == 'o')
    {
      the_map->map[y][x] = 'o';
      kill_result(sg, 9);
      interpret(y, x);
      my_printf("missed\n");
      return (1);
    }
  else if (the_map->map[y][x] == '2' ||
	   the_map->map[y][x] == '3' ||
	   the_map->map[y][x] == '4' ||
	   the_map->map[y][x] == '5' ||
	   the_map->map[y][x] == 'x')
    {
      the_map->map[y][x] = 'x';
      kill_result(sg, 10);
      interpret(y, x);
      my_printf("hit\n");
    }
  return (0);
}

void	receipt_arg(t_stock_map *the_map, t_my_pid *sg)
{
  int	axe_x;
  int	axe_y;

  axe_x = 0;
  axe_y =-1;
  if (sg->player == 2)
    sec_player = sg->first_pid;
  while (sec_player > 0)
    {
      pause();
      axe_y++;
    }
  while (sec_player < 0)
    {
      pause();
      axe_x++;
    }
  check_attack(the_map, sg, axe_y, axe_x);
}

void	send_sig(t_positions *pos, t_my_pid *sg)
{
  int	count;

  count = 0;
  while (count != pos->y)
    {
      if (sg->player == 1)
	kill(sg->sec_pid, SIGUSR1);
      else
	kill(sg->first_pid, SIGUSR1);
      usleep(20000);
      count++;
    }
  count = 0;
  while (count != pos->x)
    {
      if (sg->player == 1)
	kill(sg->sec_pid, SIGUSR2);
      else
	kill(sg->first_pid, SIGUSR2);
      usleep(20000);
      count++;
    }
  if (sg->player == 1)
    kill(sg->sec_pid, SIGUSR1);
  else
    kill(sg->first_pid, SIGUSR1);
}

int	result_of_attack(char *shot, t_stock_map *the_map,
			 t_my_pid *sg, int count)
{
  t_positions	*pos;

  if ((pos = malloc(sizeof(t_positions))) == NULL)
    return (-1);
  if (count == 0)
    {
      init_axe(pos);
      shot = check_sawp_att(shot);
      change_arg(shot, pos);
      send_sig(pos, sg);
      recpt_result_of_attack(pos, sg, the_map);
      if (check_win() == 1)
	return (1);
    }
  else
    {
      receipt_arg(the_map, sg);
      if (check_lose(the_map, sg) == 1)
	return (1);
    }
  return (0);
}

int	battlefield(t_stock_map *the_map, t_my_pid *sg, int count, int nbr)
{
  char	*shot;
  int	i;

  sg->player = nbr;
  while (42)
    {
      i = 0;
      while (i++ != 2)
	{
	  if (count == 0)
	    {
	      my_printf("\nattack:");
	      shot = arg_the_attack();
	    }
	  else if (count == 1)
	    my_printf("\nwaiting for enemy's attack...\n");
	  if (result_of_attack(shot, the_map, sg, count) == 1)
	    return (0);
	  if (count == 0)
	    count = 1;
	  else if (count == 1)
	    count = 0;
	}
      display_battle_plan(the_map);
    }
}
