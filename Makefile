##
## Makefile for  in /home/M-P.anselin/delivery/PSU/PSU_2016_navy
## 
## Made by Anselin Mackendy-pierre
## Login   <M-P.anselin@epitech.net>
## 
## Started on  Tue Jan 31 14:22:22 2017 Anselin Mackendy-pierre
## Last update Sun Feb 19 09:53:54 2017 Anselin Mackendy-pierre
##

NAME	=	navy

SRCS	=	install_the_game.c			\
		src/check_error/analyze_ship.c		\
		src/check_error/next_analyze_ship.c	\
		src/check_error/check_ship.c		\
		src/my_get_next_line.c			\
		src/other_fonction.c			\
		src/ship_info.c				\
		src/posit_the_ships.c			\
		src/next_other_fonction.c		\
		src/battle/battle.c			\
		src/battle/connect.c			\
		src/battle/if_win.c			\
		src/battle/check_arg_the_attack.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I include

CC	=	gcc -g

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L. libmy.a -L.

clean:
	rm -f $(OBJS)

re:	clean all
