NAME = push_swap
LIBFT = libft.a
PRINTF = libftprintf.a

SRC = main_ps.c general_check.c g_check_utiles.c free.c push.c rev_rotate.c rotate.c sort_stacks.c sort_three.c swap.c init_a_to_b.c init_b_to_a.c stack_init.c stack_utils.c 

OBJ = $(addprefix $(PS_OBJS_DIR)/, $(SRC:.c=.o)) 



CC = cc
CFLAGS = -Wextra -Wall -Werror -g 

PS_HEADER_DIR = includes
PS_SRC_DIR = srcs
PS_OBJS_DIR = objs

LIBFT_DIR = ./Libft
LIBFT_HEADER_DIR = $(LIBFT_DIR)/includes
LIBFT_SRC_DIR= ./srcs

PRINTF_DIR = ./ft_printf
PRINTF_HEADER_DIR = $(PRINTF_DIR)/includes
PRINTF_SRC_DIR= ./srcs


PS_INCLUDES = -I $(PS_HEADER_DIR) -I $(LIBFT_HEADER_DIR) -I $(PRINTF_HEADER_DIR)
PS_LIBRARIES = -L$(LIBFT_DIR) -lft  -L$(PRINTF_DIR) -lftprintf



all:  $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(PS_INCLUDES) $(OBJ) $(PS_LIBRARIES) -o $(NAME)

$(PS_OBJS_DIR)/%.o: $(PS_SRC_DIR)/%.c
	@mkdir -p $(PS_OBJS_DIR)
	${CC} ${CFLAGS} $(PS_INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

