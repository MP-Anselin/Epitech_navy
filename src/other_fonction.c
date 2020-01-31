/*
** other_fonction.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Tue Jan 31 14:54:16 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:17:22 2017 Anselin Mackendy-pierre
*/

#include	"navy.h"

int	my_getnbr(char *av)
{
  int	nbr;
  int	neg;
  int	i;

  neg = 1;
  i = 0;
  nbr = 0;
  while (av[i] != '\0')
    {
      while ((av[i] >= '0' && av[i] <= '9') || av[i] == '-')
	{
	  if (av[i] == '-')
	    neg = neg * (-1);
	  if (av[i] >= '0' && av[i] <= '9')
	    nbr = (av[i] - 48) + (10 * nbr);
	  i++;
	}
      if (av[i] < '0' || av[i] > '9')
	{
	  nbr = nbr * neg;
	  return (nbr);
	}
      i++;
    }
  return (nbr);
}

char	init_char(int nbr)
{
  if (nbr == 2)
    return ('2');
  else if (nbr == 3)
    return ('3');
  else if (nbr == 4)
    return ('4');
  else if (nbr == 5)
    return ('5');
}

void	init_my_counts(int *count, int nbr)
{
  int	i;

  i = 0;
  while (i != nbr)
    count[i++] = 0;
}

void	my_putstrstr(char **str)
{
  int	y;

  y = 0;
  while (str[y] != NULL)
    {
      my_putstr(str[y]);
      write (1, "\n", 1);
      y++;
    }
}
