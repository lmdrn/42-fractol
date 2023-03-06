# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedrano <lmedrano@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 16:12:34 by lmdrn             #+#    #+#              #
#    Updated: 2023/03/06 16:58:13 by lmedrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE 		= \033[38;5;69m
ORANGE 		= \033[38;5;215m
GREEN 		= \033[38;5;82m
RESET 		= \033[0m

SRCS 		= srcs/init.c

OBJS 		= ${SRCS:.c=.o}

NAME		= fractol

CC 			= gcc

CFLAGS		= -Wall -Werror -Wextra -g -fsanitize=address

MLXFLAGS	= -L./lib/mlx -lmlx -framework OpenGL -framework AppKit

RM			= rm -rf

LIB 		= ./lib/mlx

${NAME}:	${OBJS}
			@echo "$(RESET)$(ORANGE)ASSEMBLING $(NAME)$(RESET)"
			make -C lib/mlx
			${CC} ${CFLAGS} ${OBJS} ${MLXFLAGS} -o ${NAME}
			@echo "$(RESET)$(GREEN)$(NAME) HAS ASSEMBLED ✓$(RESET)"

all:		header $(NAME)

header:	
			@echo "$(BLUE)                           $(RESET)"
			@echo "$(BLUE)       Welcome mon p'tit ! $(RESET)"
			@echo "$(BLUE)        ___  _____ ___  ___      _        $(RESET)"
			@echo "$(BLUE)       /   |/ __  \|  \/  |     | |        $(RESET)"
			@echo "$(BLUE)      / /| |\`' / /'| .  . | __ _| | _____  $(RESET)"
			@echo "$(BLUE)     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\ $(RESET)"
			@echo "$(BLUE)     \___  |./ /___| |  | | (_| |   <  __/ $(RESET)"
			@echo "$(BLUE)         |_/\_____/\_|  |_/\__,_|_|\_\___|......I'm so badass wesh $(RESET)"
			@echo "$(BLUE)                           $(RESET)"

clean:		
			@echo "$(RESET)$(ORANGE)I'M CLEANING OUT MY CLOSET...$(RESET)"
			make clean -C ${LIB}
			@echo "$(RESET)$(GREEN)CLEANED ✓$(RESET)"

fclean:		clean
			@echo "$(RESET)$(ORANGE)ONE MORE TIME...$(RESET)"
			rm -f ./lib/mlx/mlx.a
			${RM} ${OBJS} ${NAME}
			@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re:			fclean all

.PHONY:		all test clean fclean re