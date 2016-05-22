/*
** buffer.c for  in /home/sepret_f/CPE_2015_BSQ
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Fri Dec 18 15:56:17 2015 fabrice sepret
** Last update Mon Dec 21 12:00:00 2015 fabrice sepret
*/

#include <stdlib.h>
#include "bsq.h"

void	fill_buffer(t_map map, int fd, int size)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 1;
  while (k > 0 && i < size)
    {
      k = xread(fd, map.buffer, size);
      if (k > 0)
	j += k;
      i += 1;
    }
  map.buffer[j] = 0;
}

int	nbr_lines(char *buffer)
{
  int	i;
  int	nbr;
  char	*str;

  i = 0;
  nbr = 0;
  if ((str = malloc(sizeof(*buffer))) == NULL)
    exit(-1);
  while (buffer[i] != '\n')
    {
      str[i] = buffer[i];
      i += 1;
    }
  while (buffer[i] != 0)
    {
      if (buffer[i] == '\n')
	nbr += 1;
      i += 1;
    }
  if (nbr - 1 != my_atoi(str))
    exit (-1);
  free(str);
  return (nbr - 1);
}

int	nbr_cols(char *buffer)
{
  int	i;
  int	nbr;

  i = 0;
  nbr = 0;
  while (buffer[i] != '\n')
    i += 1;
  i += 1;
  while (buffer[i] != '\n')
    {
      nbr += 1;
      i += 1;
    }
  return (nbr);
}
