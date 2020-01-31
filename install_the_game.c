/*
** open_maps.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Tue Jan 31 14:31:12 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 16:30:07 2017 Anselin Mackendy-pierre
*/

#include	"navy.h"

void	display_battle_plan(t_stock_map *the_map)
{
  my_printf("\nmy positions:\n");
  my_putstrstr(the_map->map);
  my_printf("\nenemy's positions:\n");
  my_putstrstr(the_map->sec_map);
}

int	install_the_map(char *str, t_my_pid *sg, t_stock_map *the_map)
{
  if ((the_map->map = init_map()) == NULL ||
      (the_map->sec_map = init_map()) == NULL)
    return (84);
  if ((the_map->post_ship = position_ship(str)) == NULL)
    return (84);
  if (the_ships_errors(the_map->post_ship, the_map->map) ==  -1)
    return (84);
  if ((the_map->map = posit_the_ship(the_map->map, the_map->post_ship))
      == NULL)
    return (84);
  return (0);
}

void	help_player()
{
  my_printf("USAGE\n");
  my_printf("	   ./navy [first_player_pid] navy_positins\n");
  my_printf("DESCRIPTION\n");
  my_printf("	   first_player_pid	only for the 2nd player. pid of the");
  my_printf("first player.\n");
  my_printf("	   havy_positions	file representing the positions of");  
  my_printf("the ships.\n");
}

int	connect_player(int nbr, char *str, t_my_pid *sg, t_stock_map *the_map)
{
  if ((sg->id = malloc(sizeof(struct sigaction))) == NULL)
    return (-1);
  sigemptyset(&sg->id->sa_mask);
  sg->id->sa_sigaction = (&handler);
  sg->id->sa_flags = SA_SIGINFO | SA_RESTART;
  if (sigaction(SIGUSR1, sg->id, NULL) == -1)
    return (-1);
  if (sigaction(SIGUSR2, sg->id, NULL) == -1)
    return (-1);
  if (nbr == 0)
    {
      if (connect_first_player(sg) == -1)
	return (-1);
      display_battle_plan(the_map);
      battlefield(the_map, sg, nbr, 1);
    }
  if (nbr == 1)
    {
      if (connect_sec_player(sg, str) == -1)
	return (-1);
      display_battle_plan(the_map);
      battlefield(the_map, sg, nbr, 2);
    }
  return (0);
}

int	main(int ac, char **av)
{
  t_my_pid	*sg;
  t_stock_map	*the_map;

  if (((sg = malloc(sizeof(t_my_pid))) == NULL ||
       (the_map = malloc(sizeof(t_stock_map))) == NULL))
    return (-1);
  if (ac < 2 || ac > 3)
    return (0);
  if (av[1][0] == '-' && av[1][1] == 'h')
    help_player();
  else if (ac ==  2)
    {
      if (install_the_map(av[1], sg, the_map) == 84)
	return (84);
      if (connect_player(0, av[1], sg, the_map) == -1)
	return (-1);
    }
  else if (ac == 3)
    {
      if (install_the_map(av[2], sg, the_map) == 84)
	return (84);
      if (connect_player(1, av[1], sg, the_map) == -1)
	return (-1);
    }
  return (0);
}
