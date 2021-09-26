# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 21:51:25 by tshimoda          #+#    #+#              #
#    Updated: 2021/09/26 12:25:30 by tshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

AR= ar rc
CC= gcc
CFLAGS= -Wall -Werror -Wextra -c
RM= rm -rf

SDIR= sources
ODIR= objects

SRCS= ft_printf.c \
		ft_category_is.c \
		ft_category_is2.c \
		ft_putcollection.c \
		ft_putcollection2.c \

OBJS= $(SRCS:.c=.o)

SFIX= $(addprefix $(SDIR)/, $(SRCS))
OFIX= $(addprefix $(ODIR)/, $(OBJS)) 	

all: $(NAME)
		@echo "\033[1;32mmake done!"

$(NAME): $(ODIR) $(OFIX)
		$(AR) $(NAME) $(OFIX)

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

bonus: $(NAME)
		
clean:
		$(RM) $(OFIX) $(ODIR)

fclean: clean
				$(RM) $(NAME)
				@echo "\033[1;34mmake fclean done!"
	
re: fclean all

.PHONY: all bonus clean fclean re