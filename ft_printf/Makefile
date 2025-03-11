# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: desambou <desambou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:57:50 by desambou          #+#    #+#              #
#    Updated: 2025/02/21 11:25:24 by desambou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC
HEADER_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

INCLUDES = -I $(HEADER_DIR)
SRC =	ft_printf.c print_c.c print_hex.c print_nbr.c print_p.c print_str.c print_u.c

OBJ = $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o)) 
NAME = libftprintf.a
AR = ar -rcs
RM = rm -f
RM_DIR = rm -rf

all: ${NAME}

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	${CC} ${CFLAGS} $(INCLUDES) -c $< -o $@

clean:
	${RM} ${OBJ} 
	$(RM_DIR) $(OBJS_DIR)

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re