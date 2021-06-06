GRREN = "\\033[32m"
RESET_FORMAT = "\\033[0m"
ERASE_LINE = "\\033[A\\033[K\\033[A"

CC	= gcc

CFLAGS = -Wall -Wextra -Werror
CHECKER_NAME = checker
PUSH_SWAP_NAME = push_swap

LIB_DIR = ./libft/
LIB_INCLUDES = $(LIB_DIR)includes
LIB_NAME = libft.a
LIB_FLAGS = -L $(LIB_DIR) -lft
LIB = $(addprefix $(LIB_DIR), $(LIB_NAME))

SRC_DIR = ./src/
OBJ_DIR = ./obj/
SRC_FILES = apply_instr.c deal_args.c deal_args_aux.c \
			check_instr.c check_order.c chunk_sort.c chunk_sort_aux.c \
			push.c swap.c rotate.c rotate_rev.c checker.c \
			main_p_s.c replace_value_by_rank.c selection_sort.c \
			sort_last_3.c utils.c utils_aux.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

CHECKER_OBJ_FILES = apply_instr.o check_instr.o check_order.o \
					deal_args.o deal_args_aux.o push.o swap.o \
					rotate.o rotate_rev.o checker.o utils.o utils_aux.o\

CHECKER_OBJ = $(addprefix $(OBJ_DIR), $(CHECKER_OBJ_FILES))
PUSH_SWAP_OBJ_FILES = apply_instr.o check_instr.o check_order.o \
					  deal_args.o deal_args_aux.o push.o swap.o \
					  rotate.o rotate_rev.o utils.o utils_aux.o\
					  replace_value_by_rank.o selection_sort.o \
					  sort_last_3.o main_p_s.o chunk_sort.o chunk_sort_aux.o \

PUSH_SWAP_OBJ = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_OBJ_FILES))

HDR_DIR	= ./includes/
HDR_FILES = push_swap.h
HDR = $(addprefix $(HDR_DIR), $(HDR_FILES))

all: $(OBJ_DIR) $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJ) $(LIB)
	@echo "Object files related to checker created"
	@$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIB_FLAGS) -o $(CHECKER_NAME)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ) $(LIB)
	@echo "Object files related to push_swap created"
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LIB_FLAGS) -o $(PUSH_SWAP_NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HDR)
	@$(CC) $(CFLAGS) -I $(HDR_DIR) -I $(LIB_INCLUDES) -c -o $@ $<
	@echo "Compiled: $*.o [$(GREEN)OK$(RESET_FORAT)]"
	@echo "$(ERASE_LINE)"

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "Object files related to push_swap and checker deleted"

fclean:
	@make -C $(LIB_DIR) fclean
	@rm -rf $(CHECKER_NAME)
	@rm -rf $(PUSH_SWAP_NAME)
	@echo "$(PUSH_SWAP_NAME) deleted"
	@echo "$(CHECKER_NAME) deleted"

re:
	@$(MAKE) fclean
	@echo ""
	@$(MAKE) all
