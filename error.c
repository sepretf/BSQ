/*
** erroc.c for  in /home/sepret_f/CPE_2015_BSQ
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Fri Dec 18 15:57:27 2015 fabrice sepret
** Last update Fri Dec 18 17:51:14 2015 fabrice sepret
*/

#include <stdlib.h>
#include <unistd.h>

int	error(char *buf, int i)
{
  while (buf[i] != 0)
    {
      if (buf[i] == '\n' && buf[i + 1] == '\n')
	{
	  my_putstr("Invalid Map\n");
	  exit(-1);
	}
      if (buf[i] != '.' && buf[i] != 'o' && buf[i] != '\n')
	{
	  my_putstr("Invalid caracter on map\n");
	  my_putstr("Map can contain only '.' or 'o'\n");
	  exit(-1);
	}
      i += 1;
    }
  return (0);
}

int	check_error(char *buf)
{
  int	i;

  i = 0;
  while (buf[i] != '\n')
    {
      if (buf[i] < '0' || buf[i] > '9')
	{
	  my_putstr("Map need to contains ");
	  my_putstr("number on the first line\n");
	  exit(-1);
	}
      i += 1;
    }
  error(buf, i);
  check_map_empty(buf, i);
}

int	check_map_empty(char *buf, int i)
{
  if (buf[i] == '\n' && buf[i + 1] == 0)
    {
      my_putstr("Invalid Map\n");
      exit(-1);
    }
}

int	xread(const int fd, char *buffer, int size)
{
  int	nb_read;

  if ((nb_read = read(fd, buffer, size)) == -1)
    {
      my_putstr("Read Failed\n");
      my_putstr("Usage : ./bsq [map] -> [map] need ");
      my_putstr("to be store in a file\n");
      exit(-1);
    }
  return (nb_read);
}
