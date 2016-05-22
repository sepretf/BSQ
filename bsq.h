/*
** bsq.h for  in /home/sepret_f/CPE_2015_BSQ
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Fri Dec 18 15:54:39 2015 fabrice sepret
** Last update Fri Dec 18 15:56:01 2015 fabrice sepret
*/

#ifndef BSQ_H_
# define BSQ_H_

typedef struct	s_size
{
  int	lines;
  int	cols;
  int	max;
  int	x;
  int	y;
  int	bigger;
}		t_size;

typedef struct	s_map
{
  char	*buffer;
  int	**array;
}		t_map;

typedef struct	s_incr
{
  int	i;
  int	j;
  int	k;
  int	tmp1;
  int	tmp2;
}		t_incr;

#endif /* !BSQ_H_ */
