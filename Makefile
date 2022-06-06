# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 20:42:26 by rteles            #+#    #+#              #
#    Updated: 2022/06/06 15:19:56 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	./libft/ft_lstnew.c \
			./libft/ft_lstfirst.c \
			./libft/ft_lstlast.c \
			./libft/ft_atoi.c \
			./libft/ft_itoa.c \
			./libft/ft_split.c \
			./libft/ft_lstsize.c \
			./libft/ft_str_s_str.c \
			./ft_printf/ft_printf.c \
			./ft_printf/ft_printf_utils.c \
			./ft_printf/ft_print_unsigned_decimal.c \
			./ft_printf/ft_strlen.c \
			push_swap.c \
			ft_organize_index.c \
			ft_comands.c \
			ft_comands_1.c \
			ft_comands_2.c \
			ft_comands_3.c \
			ft_logic.c \
			ft_logic_utils.c \
			ft_logic_3.c \
			ft_logic_5.c \
			ft_logic_E.c \
			ft_logic_500_1.c \
			ft_logic_500_2.c \
			ft_logic_500_3.c \
			ft_checker.c
			

OBJECTS	=	$(SOURCES:.c=.o)

NAME	= 	push_swap

CC		=	gcc #-fsanitize=address

CFLAGS	=	-Wall -Wextra -Werror 

RM		=	rm -f

AR		= ar -rcs

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) -g $(OBJECTS) -o $(NAME)

%.o: %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	
fclean: clean

re:		fclean $(NAME)

.PHONY: $(NAME) all clean fclean re
