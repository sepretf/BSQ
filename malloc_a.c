/*
** malloc_a.c for  in /home/sepret_f/CPE_2015_BSQ
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Fri Dec 18 16:01:03 2015 fabrice sepret
** Last update Sun Dec 20 19:26:24 2015 fabrice sepret
*/

#include <stdlib.h>
#include "bsq.h"

int	array_alloc(t_map map, t_size size, t_incr incr)
{
  incr.i = 0;
  if ((map.array = malloc(sizeof(int *) * size.lines)) == NULL)
    {
      my_putstr("Malloc Fail\n");
      exit(-1);
    }
  while (incr.i < size.lines)
    {
      if ((map.array[incr.i++] = malloc(sizeof(int *) * size.cols)) == NULL)
	{
	  my_putstr("Malloc Fail\n");
	  exit(-1);
	}
    }
  fill_array(map, size, incr);
}
