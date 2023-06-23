# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 13:15:37 by mvavasso          #+#    #+#              #
#    Updated: 2023/05/11 13:15:37 by mvavasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= philo

CFLAGS			= -Wall -Werror -Wextra
PHILOFLAGS		= -g -pthreads

RM				= rm -rf
			
PATH_INCLUDES	= ./includes/
PATH_OBJS		= ./objects/
PATH_SRCS		= ./srcs/

SRCS			= $(addprefix $(PATH_SRCS), \
					philosophers.c \
					check_error.c \
					philo_utils.c \
					start_philo.c \
					print_functions.c \
					monitor.c)
OBJS 			= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))
INCLUDES		= -I $(PATH_INCLUDES)

all:	$(NAME)

$(NAME): $(OBJS)
	@ clang $(CFLAGS) $(PHILOFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) -fsanitize=address 
	@ echo -e '\033[0;32m[SUCCESS]\033[0m Compilation done!'

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@ mkdir -p $(PATH_OBJS)
	@ clang $(CFLAGS) $(INCLUDES) -c $< -o $@ -fsanitize=address
	
clean:
	@ $(RM) $(PATH_OBJS)
	@ $(RM) valgrind-out.txt
	@ echo -e '\033[0;33mObjects removed\033[0m'

fclean:	clean
	@ $(RM) $(NAME)
	@ echo -e '\033[0;33mEverything is clean\033[0m'

valgrind:
			@echo "$(WHT)Removing old log.$(EOC)"
			@rm -f valgrind-out.txt
			@echo "$(WHT)Old log removed.$(EOC)"
			@echo "$(WHT)Executing Valgrind.$(EOC)"
			@valgrind --leak-check=full --show-leak-kinds=reachable --track-origins=yes \
			--log-file=valgrind-out.txt \
			./philo 1 100 100 100 100
			@echo "$(GREEN)Valgrind-log created.$(EOC)"

re:		fclean all

.PHONY: all clean fclean re valgrind