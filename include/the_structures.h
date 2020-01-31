/*
** the_structurs.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy/include
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Wed Feb  1 20:49:47 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:14:42 2017 Anselin Mackendy-pierre
*/

#ifndef		_THE_STRUCTURES_H_
# define	_THE_STRUCTURES_H_

typedef struct  S_stock_map
{
  char	**map;
  char	**sec_map;
  char	**post_ship;
}       t_stock_map;

typedef struct S_size_ship
{
  char	**position;
  int	to_x;
  int	to_y;
  int	from_x;
  int	from_y;
}	t_size_ship;

extern int sec_player;

typedef struct S_my_pid
{
  struct sigaction *id;
  pid_t	first_pid;
  pid_t	sec_pid;
  int	player;
}		t_my_pid;

typedef struct	S_positions
{
  int	x;
  int	y;
}		t_positions;

#endif /* _THE_STRUCTURES_H_ */
