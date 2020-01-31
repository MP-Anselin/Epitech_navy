/*
** navy.h for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Sun Feb 19 10:12:40 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:13:47 2017 Anselin Mackendy-pierre
*/

#include	<string.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<signal.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	"get_next_line.h"
#include	"the_structures.h"

#ifndef		_NAVY_H_
# define	_NAVY_H_

char	*arg_the_attack();
int	battlefield(t_stock_map *the_map, t_my_pid *sg, int count, int nbr);
int	connect_player(int nbr, char *str, t_my_pid *sg, t_stock_map *the_map);
int	connect_sec_player(t_my_pid *sg, char *str);
int	connect_first_player(t_my_pid *sg);
int	check_size_ship(char **map, t_size_ship  *axe, int nbr, int i);
int	check_point_ship(char **map, int count, t_size_ship *axe, int nbr);
int	check_heigth_ships(char **map, t_size_ship *axe);
int	check_nbr_ships(char **post_ship, int *nbr, int *y);
int	check_the_ships(char **post_ship);
char	**check_swap_pos(char **posit);
char	*check_sawp_att(char *str);
int	check_post_ship(char *stock, int nbr);
int	check_axe(char **map, char **posit, int count, int nbr);
void	change_arg(char *str, t_positions *pos);
int	check_negative_size_ship(char **map, t_size_ship  *axe, int nbr, int i);
int	check_arg_attack(char *str);
int	check_points(char **map, t_size_ship *axe, int i, int nbr);
int	check_win();
int	check_lose(t_stock_map *the_map, t_my_pid *sg);
char	**draw_negative_ship(char **map, t_size_ship  *axe, int nbr, int i);
void	display_battle_plan(t_stock_map *the_map);
void	display_play(t_stock_map *the_map);
void	display_first_player(t_stock_map *the_map);
void	display_second_player(t_stock_map *the_map);
char	**draw_ship(char **map, t_size_ship  *axe, int nbr, int i);
void	handler(int x, siginfo_t *id, void *str);
char	init_char(int nbr);
void	interpret(int y, int x);
int	install_the_map(char *str, t_my_pid *sg, t_stock_map *the_map);
void	init_axe(t_positions *pos);
char	**init_map();
void	init_my_counts(int *count, int nbr);
void	kill_result(t_my_pid *sg, int nbr);
int	my_printf(const char *format, ...);
void	my_putstrstr(char **str);
void	my_putstr(char *str);
int	my_getnbr(char *av);
char	**posit_the_ship(char **map, char **str);
char	**point_ship(char **map, int count, t_size_ship *axe, int nbr);
char	**position_ship(char *str);
void	receipt_arg(t_stock_map *the_map, t_my_pid *sg);

void	recpt_result_of_attack(t_positions *pos, t_my_pid *sg,
			       t_stock_map *the_map);
int	the_ships_errors(char **post_ship, char **map);

#endif	/* !NAVY_H_ */
