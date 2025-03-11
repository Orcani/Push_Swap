# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: desambou <desambou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:57:50 by desambou          #+#    #+#              #
#    Updated: 2025/02/24 13:12:18 by desambou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC

HEADER_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

INCLUDES = -I $(HEADER_DIR)
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
 ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
 ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
 ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c \
 ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c \
	ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstsize.c \
get_next_line.c get_next_line_bonus.c ft_atol.c


OBJ = $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o)) 
NAME = libft.a
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