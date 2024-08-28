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
		print_utils.c \
		utils.c \
		table_funcs.c \
		philos_routine.c \
		waiter_routine.c \
		routine_utils.c \


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

#./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]


run: 
	@echo "$(GREEN)Launching philos normal$(RESET)"
	@./$(NAME) 2 800 200 200

run2:
	@echo "$(GREEN)Launching 3 philos $(RESET)"
	@./$(NAME) 5 800 200 200

run3:
		@echo "$(GREEN)Launching philos no meals$(RESET)"
	@./$(NAME) 4 600 200 100 3

run4:
	@echo "$(GREEN)Launching TONS of philos$(RESET)"
	@./$(NAME) 3 800 300 200

run5:
	@echo "$(GREEN)Launching philo with edge cases$(RESET)"
	@./$(NAME) 7 1000 200 300

run6:
	@echo "$(GREEN)Launching single philo$(RESET)"
	@./$(NAME) 10 1200 100 100 5

run7:
	@echo "$(GREEN)Launching philo with no way to eat$(RESET)"
	@./$(NAME) 100 800 200 200

run8:
	./$(NAME) 1 1000 200 200

run9:
	./$(NAME) 2 1000 200 1000 3

run10:
	./$(NAME) 5 700 200 200

run11:
	./$(NAME) 200 800 200 200

valgrind:
	@valgrind --tool=helgrind  ./$(NAME) 4 410 200 200

.PHONY: all clean fclean re run run2 run3 single no_way
