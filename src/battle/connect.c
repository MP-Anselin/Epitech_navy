/*
** connect.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy/src/battle
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Wed Feb  8 17:49:09 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:28:50 2017 Anselin Mackendy-pierre
*/

#include	"navy.h"

int	sec_player;

void	kill_result(t_my_pid *sg, int nbr)
{
  int	count;

  count = 0;
  while (count <= nbr)
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
  usleep(20000);
}

void	handler(int x, siginfo_t *id, void *str)
{
  sec_player = id->si_pid;
  if (x == SIGUSR1)
    sec_player *= 1;
  if (x == SIGUSR2)
    sec_player *= -1;
}

int	connect_sec_player(t_my_pid *sg, char *str)
{
  sg->sec_pid  = getpid();
  sg->first_pid = my_getnbr(str);
  if (kill(sg->first_pid, SIGUSR1) == -1)
    return (-1);
  else
    my_printf("my_pid: %i\nsuccessfully connected\n", sg->sec_pid);
  return (0);
}

int	connect_first_player(t_my_pid *sg)
{
  sg->first_pid = getpid();
  my_printf("my_pid: %i \nwaiting for enemy connection...\n", sg->first_pid);
  pause();
  sg->sec_pid = sec_player;
  return (0);
}
