NAME = philo

CC = gcc -g -O0 -o $(NAME)
SANIT = -fsanitize=thread -g  
CFLAGS = -Wall -Wextra -Werror $(SANIT)

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include

PHILO_H = $(INC_DIR)/philosophers.h
TABLE_H = $(INC_DIR)/table.h

SRC = main.c \
		parse_args.c \
		parse_args_utils.c \
		prints.c \
		print_utils.c \
		utils.c \
		table_funcs.c \
		table_funcs_utils.c \
		philos_routine.c \
		philo_actions.c \
		waiter_routine.c \
		waiter_actions.c \
		critical_regions_setters.c \
		critical_regions_getters.c


OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

#this doesnt work for the moment [seg_fault->core_dumped]
#PHONY
all: $(NAME)

$(NAME): $(OBJ) $(PHILO_H) $(TABLE_H)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(SANIT)
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
	@./$(NAME) 2 800 200 200

run2:
	@./$(NAME) 5 800 200 200

run3:
	@./$(NAME) 4 600 200 100 3

run4:
	@./$(NAME) 3 800 300 200

run5:
	@./$(NAME) 7 1000 200 300

run6:
	@./$(NAME) 10 1200 100 100 5

run7:
	@./$(NAME) 100 800 200 200

run8:
	./$(NAME) 1 1000 200 200

run9:
	./$(NAME) 2 1000 200 1000 3

run10:
	./$(NAME) 5 700 200 200

run11:
	./$(NAME) 5 100 200 200

run12:
	./$(NAME) 5 300 200 300

run13:
	./$(NAME) 5 500 0 200

run14:
	./$(NAME) 200 800 200 200

run15:


valgrind:
	@valgrind --tool=helgrind  ./$(NAME) 4 410 200 200

.PHONY: all clean fclean re run run2 run3 valgrind
