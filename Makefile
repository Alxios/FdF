NAME = fdf

CC = gcc
CFLAGS = -Werror -Wall -Wextra

INC_MINILIBX = -Iminilibx/
INC_LIBFT = -Ilibft/includes
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/

LIBFT = -Llibft/ -lft
MINILIBX = -Lminilibx/ -lmlx -framework Opengl -framework Appkit

SRC_NAME = main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(INC_MINILIBX) $(INC_LIBFT)

LDFLAGS = $(LIBFT) $(MINILIBX)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "\033[38;5;47m"$(CC) $(CFLAGS) $(INC) -o $@ -c $<"\033[0m"

$(NAME): $(OBJ)
	@make -C libft/
	@make -C minilibx/
	@$(CC) $(LDFLAGS) $(OBJ) -o $@
	@echo "\033[38;5;47m"$(CC) $(LDFLAGS) $(OBJ) -o $@"\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[38;5;9m"rm -rf $(OBJ)"\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[38;5;9m"rm -rf $(NAME)"\033[0m"

re: fclean all

norme:
	@norminette $(SRC) $(INC_PATH) | sed "s/Norme/[0;1;47m\
	[0;38;5;47mNorme/g; s/Warning/[38;5;9m Warning/g; s/Error/\
	[38;5;9m Error/g"
