##
## Makefile for  in /home/sepret_f/CPE_2015_BSQ
## 
## Made by fabrice sepret
## Login   <sepret_f@epitech.net>
## 
## Started on  Fri Dec 18 16:00:02 2015 fabrice sepret
## Last update Sun May 22 16:40:57 2016 fabrice sepret
##

SRC =	bsq.c \
	buffer.c \
	my_put.c \
	main.c \
	error.c \
	malloc_a.c \
	my_atoi.c \

NAME =	bsq

OBJ =	$(SRC:.c=.o)

RM =	rm -rf

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
