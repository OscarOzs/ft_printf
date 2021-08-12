# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 14:20:31 by oozsertt          #+#    #+#              #
#    Updated: 2021/08/12 14:26:13 by oozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

FILES.C =  ft_printf.c \
parsing/parse_conversion.c parsing/set_data.c \
utils/ft_itoa.c utils/ft_putchar.c \
utils/ft_putstr.c utils/ft_strdup.c \
utils/ft_strjoin.c utils/ft_strlen.c utils/ft_utoa_base_uppercase.c \
utils/ft_utoa_base.c utils/ft_utoa.c \
display/ft_print_conversion.c display/%_conversion/ft_convert_percent.c \
display/c_conversion/ft_convert_c.c display/d_i_conversion/ft_convert_d_i.c \
display/p_conversion/ft_convert_p.c display/s_conversion/ft_convert_s.c \
display/u_conversion/ft_convert_u.c display/x_conversion/ft_convert_x.c \

FILES.O = ft_printf.o \
parse_conversion.o set_data.o \
ft_itoa.o ft_putchar.o \
ft_putstr.o ft_strdup.o \
ft_strjoin.o ft_strlen.o ft_utoa_base_uppercase.o \
ft_utoa_base.o ft_utoa.o \
ft_print_conversion.o ft_convert_p.o ft_convert_c.o ft_convert_d_i.o \
ft_convert_percent.o ft_convert_s.o ft_convert_u.o ft_convert_x.o \

all : $(NAME)

$(NAME) :
	@gcc -c $(FLAGS) $(FILES.C)
	@ar -rcs $(NAME) $(FILES.O)

clean :
	@rm -rf $(FILES.O)

fclean : clean
	@rm -rf $(NAME) ./a.out

re : fclean all
