/*
** my_put.c for  in /home/sepret_f/CPE_2015_BSQ
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Fri Dec 18 16:01:47 2015 fabrice sepret
** Last update Fri Dec 18 16:02:08 2015 fabrice sepret
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i += 1;
    }
}
