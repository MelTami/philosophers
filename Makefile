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

RM				= rm -rf
			
PATH_INCLUDES	= ./includes/
PATH_OBJS		= ./objects/
PATH_SRCS		= ./srcs/
PATH_LIBFT		= ./libft

SRCS			= philosophers.c \
					$(addprefix $(PATH_SRCS), \
					check_error.c)
LFLAGS			= -L $(PATH_LIBFT) -lft
OBJS 			= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))
INCLUDES		= -I $(PATH_INCLUDES)

all:	$(NAME)

$(NAME): $(OBJS)
	@ make -C $(PATH_LIBFT)
	@ clang $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@ echo -e '\033[0;32m[SUCCESS]\033[0m Compilation done!'

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@ mkdir -p $(PATH_OBJS)
	@ clang $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	@ $(RM) $(PATH_OBJS)
	@ make clean -C $(PATH_LIBFT)
	@ echo -e '\033[0;33mObjects removed\033[0m'

fclean:	clean
	@ $(RM) $(NAME)
	@ make fclean -C $(PATH_LIBFT)
	@ echo -e '\033[0;33mEverything is clean\033[0m'

re:		fclean all

.PHONY: all clean fclean re