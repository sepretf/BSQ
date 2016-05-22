/*
** main.c for  in /home/sepret_f/CPE_2015_BSQ
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Fri Dec 18 15:58:44 2015 fabrice sepret
** Last update Mon Dec 21 23:30:09 2015 fabrice sepret
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsq.h"

int		main(int ac, char **av)
{
  struct stat	*buf;
  t_size	size;
  t_map		map;
  int		fd;
  t_incr	incr;

  incr.i = 0;
  incr.j = 0;
  size.bigger = 0;
  if (ac != 2
      || ((buf = malloc(sizeof(*buf))) == NULL)
      || (stat(av[1], buf) == -1)
      || ((map.buffer = malloc(sizeof(char *)*buf->st_size)) == NULL)
      || (fd = open(av[1], O_RDONLY)) == -1)
    return (-1);
  fill_buffer(map, fd, buf->st_size);
  check_error(map.buffer);
  size.lines = nbr_lines(map.buffer);
  size.cols = nbr_cols(map.buffer);
  array_alloc(map, size, incr);
  free(map.buffer);
  free(buf);
}
