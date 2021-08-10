# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 21:51:25 by tshimoda          #+#    #+#              #
#    Updated: 2021/08/01 16:32:04 by tshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

AR= ar rc
CC= gcc
CFLAGS= -Wall -Werror -Wextra -c
OBJS= $(SRCS:.c=.o)

SFIX= $(addprefix $(SDIR), $(SRCS))
SDIR= sources/
SRCS= ft_printf.c \
		ft_category_is.c \
		ft_category_is2.c \
		ft_putcollection.c \
		ft_putcollection2.c \

all: $(NAME)
		@echo "\033[1;32mmake done!"

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

$(OBJS):
		$(CC) $(CFLAGS) $(SFIX)
		
clean:
		$(RM) $(OBJS)

fclean: clean
				$(RM) $(NAME)
				clear
				@echo "\033[1;34mmake fclean done!"
	
re: fclean all

.PHONY: all clean fclean re