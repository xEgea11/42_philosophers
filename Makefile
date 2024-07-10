NAME = philo

CC = gcc -g -O0 -o $(NAME)
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include

SRC = main.c \
		check_args.c \
		prints.c \
		utils.c \
		table_funcs.c \
		routines.c \
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
	@./$(NAME) 10 600 400 200

run2:
	@echo "$(GREEN)Launching philos with times_to_eat$(RESET)"
	@./$(NAME) 10 600 400 200 20 

run3:
	@echo "$(GREEN)Launching TONS of philos$(RESET)"
	@./$(NAME) 1000 800 200 200 

valgrind:
	@valgrind --tool=helgrind  ./$(NAME) 4 410 200 200
.PHONY: all clean fclean re run run2 run3
