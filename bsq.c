/*
** bsq.c for  in /home/sepret_f/CPE_2015_BSQ
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Fri Dec 18 15:50:08 2015 fabrice sepret
** Last update Fri Dec 18 16:13:48 2015 fabrice sepret
*/

#include <stdlib.h>
#include "bsq.h"

int	find_square(t_size size, t_map map, t_incr incr)
{
  int	a;
  int	b;
  int	c;

  size.max = 0;
  a = map.array[incr.j - 1][incr.k];
  b = map.array[incr.j][incr.k - 1];
  c = map.array[incr.j - 1][incr.k - 1];
  if (a < b)
    b = a;
  if (b < c)
    c = b;
  return (c + 1);
}

int	check(t_map map, t_size size, t_incr incr)
{
  if (map.buffer[incr.i] == 'o')
    return (0);
  else if (incr.k == 0 || incr.j == 0)
    return (1);
  else if (map.buffer[incr.i] == '.')
    return (find_square(size, map, incr));
}

void	parc(t_map map, t_size size, t_incr incr)
{
  while (map.array[size.x][size.y] != size.bigger)
    {
      if (size.y < size.cols)
	size.y += 1;
      else
	{
	  size.y = 0;
	  size.x += 1;
	}
    }
  incr.tmp1 = size.y - size.bigger;
  incr.tmp2 = size.x - size.bigger;
  while (size.y != incr.tmp1)
    {
      size.x = incr.tmp2 + size.bigger;
      while (size.x != incr.tmp2)
	{
	  map.array[size.x][size.y] = -1;
	  size.x -= 1;
	}
      size.y -= 1;
    }
  disp(size, map);
}

int	disp(t_size size, t_map map)
{
  size.y = 0;
  while (size.y != size.lines)
    {
      size.x = 0;
      while (size.x != size.cols)
	{
	  if (map.array[size.y][size.x] == -1)
	    my_putchar('x');
	  else if (map.array[size.y][size.x] == 0)
	    my_putchar('o');
	  else
	    my_putchar('.');
	  size.x += 1;
	}
      my_putchar('\n');
      size.y += 1;
    }
}

int	fill_array(t_map map, t_size size, t_incr incr)
{
  incr.i = 0;
  while (map.buffer[incr.i - 1] != '\n')
    incr.i += 1;
  while (incr.j != size.lines)
    {
      incr.k = 0;
      while (incr.k != size.cols)
	{
	  map.array[incr.j][incr.k] = check(map, size, incr);
	  if (map.array[incr.j][incr.k] > size.bigger)
	    size.bigger = map.array[incr.j][incr.k];
	  incr.k += 1;
	  incr.i += 1;
	}
      incr.i += 1;
      incr.j += 1;
    }
  size.x = 0;
  size.y = 0;
  parc(map, size, incr);
  free(map.array);
}
