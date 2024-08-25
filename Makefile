NAME = philo

CC = gcc -g -O0 -o $(NAME)
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include

SRC = main.c \
		parse_args.c \
		parse_args_utils.c \
		prints.c \
		utils.c \
		table_funcs.c \
		philos_routine.c \
		waiter_routine.c \
		#philo.c \
		#threads.c \
		#monitor.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

#this doesnt work for the moment [seg_fault->core_dumped]
SANIT = -fsanitize=thread -g  
#PHONY
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) is ready$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c

	@if [ ! -d "$(OBJ_DIR)" ]; then \
		echo "$(GREEN)Creating directory$(RESET)"; \
		mkdir -p $(OBJ_DIR); \
	fi

	@$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)$(NAME) objects files are deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) is deleted$(RESET)"

re: fclean all

run: 
	@echo "$(GREEN)Launching philos normal$(RESET)"
	@./$(NAME) 5 800 200 200 5

run2:
	@echo "$(GREEN)Launching 3 philos $(RESET)"
	@./$(NAME) 3 600 150 150 3

tons:
	@echo "$(GREEN)Launching TONS of philos$(RESET)"
	@./$(NAME) 50 1000 200 200 10

edge:
	@echo "$(GREEN)Launching philo with edge cases$(RESET)"
	@./$(NAME) 5 5000 1000 1000 5

single:
	@echo "$(GREEN)Launching single philo$(RESET)"
	@./$(NAME) ./philo 1 500 100 100 1

no_way:
	@echo "$(GREEN)Launching philo with no way to eat$(RESET)"
	@./$(NAME) 5 1 1 1 1

valgrind:
	@valgrind --tool=helgrind  ./$(NAME) 4 410 200 200

.PHONY: all clean fclean re run run2 run3 single no_way
