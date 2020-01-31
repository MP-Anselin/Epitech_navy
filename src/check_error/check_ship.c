/*
** check_ship.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Tue Jan 31 17:45:28 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 10:21:44 2017 Anselin Mackendy-pierre
*/

int	check_post_ship(char *stock, int nbr)
{
  int	i;
  int	check;

  i = 0;
  check = 0;
  while (stock[i] != '\0')
    {
      if (nbr == 1)
	if (stock[i] >= 65 && stock[i] <= 90  ||
	    stock[i] >= 48 && stock[i] <= 57)
	  check++;
      if (nbr == 0)
	if (stock[i] >= 48 && stock[i] <= 57)
	  check++;
      i++;
    }
  if (check != i)
    return (-1);
  return (0);
}
