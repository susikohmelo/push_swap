.PHONY: all clean fclean re

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_BLUE=\033[0;34m
C_CYAN=\033[0;36m
C_END=\033[0m

NAME = push_swap

LIBFTPATH = source/libft/

SOURCE = source/

CC = cc
FLAG = -Wall -Wextra -Werror -I $(SOURCE)
AR = ar rcs
RM = -rm -f

C_FILES = \
main.c \
get_node_info.c \
assign_stack_values.c \
freeing_functions.c \
operations_push.c \
operations_rotate.c \
operations_reverserotate.c \
operations_swap.c \
push_to_target.c \
sorting_algorithms.c \
update_node_data_a.c \
update_node_data_b.c \

C_FILES := $(addprefix $(SOURCE), $(C_FILES))

all: $(NAME)

$(NAME): $(C_FILES)
	make -C $(LIBFTPATH)
	$(CC) $(FLAG) $(C_FILES) -L $(LIBFTPATH) -l ft -o $(NAME)
	@echo "$(C_GREEN)⌘ $(NAME) compiled! ⌘$(C_END)"

clean:
	make -C $(LIBFTPATH) clean
	@echo "$(C_CYAN)⌘ $(NAME) cleaned up! ⌘$(C_END)"

fclean: clean
	make -C $(LIBFTPATH) fclean
	$(RM) $(NAME)
	@echo "$(C_GREEN)⌘ $(NAME) removed! ⌘$(C_END)"

re: fclean all
