# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aappleto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 01:18:31 by aappleto          #+#    #+#              #
#    Updated: 2022/06/17 01:18:33 by aappleto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= server.c client.c libft/ft_atoi.c libft/ft_putnbr_fd.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM 			= rm -f
AR			= ar rcs

all: server client

server: server.o
	$(CC) $(CFLAGS)  server.o libft/ft_atoi.c libft/ft_putnbr_fd.c -o server
	
client: client.o
	$(CC) $(CFLAGS) client.o libft/ft_atoi.c libft/ft_putnbr_fd.c -o client

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) server client

re:			fclean all

.PHONY:		all clean fclean re
