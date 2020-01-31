/*
** check_arg_the_attack.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy
** 
** Made by root
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Sun Feb 12 16:50:16 2017 root
** Last update Sun Feb 19 15:53:38 2017 Anselin Mackendy-pierre
*/

#include	"navy.h"

int	check_arg_attack(char *str)
{
  if (str[0] >= 65 && str[0] <= 72 &&
      str[1] >= 49 && str[1] <= 56)
    return (0);
  else
    return (1);
}

char	*arg_the_attack()
{
  char	*str;

  str = get_next_line(0);
  while (check_arg_attack(str) == 1)
    {
      my_printf("wrong position\n");
      my_printf("attack:");
      str = get_next_line(0);
    }
  return (str);
}
