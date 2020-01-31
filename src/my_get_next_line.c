/*
** jenaimare.c for  in /home/M-P.anselin/delivery/CPE_2016/CPE_2016_getnextline
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Sun Jan 15 14:03:36 2017 Anselin Mackendy-pierre
** Last update Sun Feb 19 16:24:11 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>
#include	"get_next_line.h"

int	myread(int fd, char *buffer)
{
  int	check;

  check = read(fd, buffer, READ_SIZE);
  buffer[check] = '\0';
  return (check);
}

char	*my_standart(const int fd)
{
  char buffer[READ_SIZE + 1];
  char	*stock;
  int	nbr_read;
  int	my_int[2];

  my_int[0] = 0;
  my_int[1] = 0;
  if ((stock = malloc(sizeof(char*) * READ_SIZE)) == NULL)
    return (NULL);
  if (myread(fd, buffer) == 0)
    return (NULL);
  while (42)
    {
      while (buffer[my_int[1]] != '\0' && buffer[my_int[1]] != '\n')
	stock[my_int[0]++] = buffer[my_int[1]++];
      stock[my_int[0]] = '\0';
      if (buffer[my_int[1]] == '\0')
	{
	  if (myread(fd, buffer) == 0)
	    return (NULL);
	  my_int[1] = 0;
	}
      else if (buffer[my_int[1]] == '\n')
	return (stock);
    }
}

char	get_one_read(const int fd)
{
  static char buffer[READ_SIZE];
  static char* stock_buffer;
  static int check_count = 0;
  static int my_count = 0;
  char save_c;

  if (check_count == 0)
    {
      check_count = read(fd, buffer, READ_SIZE);
      if (check_count == 0)
	{
	  my_count = 0;
	  return (0);
	}
    }
  check_count--;
  while (my_count <= READ_SIZE)
    {
      if (my_count == READ_SIZE)
	my_count = 0;
      save_c = buffer[my_count];
      my_count++;
      return (save_c);
    }
}

char	*get_next_line(const int fd)
{
  int	count;
  char	save_c;
  char	*stock_line;

  count = 0;
  stock_line = malloc(sizeof(char*) * (READ_SIZE + 1));
  if (fd == 0)
    {
      stock_line = my_standart(fd);
      return (stock_line);
    }
  if (stock_line == NULL || fd == -1)
    return (NULL);
  save_c = get_one_read(fd);
  while (save_c != '\n' && save_c != '\0')
    {
      stock_line[count] = save_c;
      save_c = get_one_read(fd);
      count++;
    }
  stock_line[count] = '\0';
  count++;
  if (save_c == '\0' && stock_line[0] == '\0')
    return (0);
  return (stock_line);
}
