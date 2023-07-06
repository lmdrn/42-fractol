# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedrano <lmedrano@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 15:10:04 by lmedrano          #+#    #+#              #
#    Updated: 2023/07/06 10:53:49 by lmedrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE 		= \033[38;5;69m
ORANGE 		= \033[38;5;215m
GREEN 		= \033[38;5;82m
RESET 		= \033[0m

SRCS 		= srcs/init.c \
		  	srcs/mandelbrot.c \
		  	srcs/julia.c \
			srcs/colors.c \
			srcs/misc.c \
			srcs/hooks.c 

OBJS 		= ${SRCS:.c=.o}

NAME		= fractol

CC 			= gcc

CFLAGS		= -Wall -Werror -Wextra -g -fsanitize=address -Imlx

MLXFLAGS 	= -L ${LIB} -lmlx -framework OpenGL -framework AppKit

RM			= rm -rf

LIB 		= ./mlx/

${NAME}:	${OBJS}
			@echo "$(RESET)$(ORANGE)ASSEMBLING $(NAME)$(RESET)"
			@$(MAKE) -C $(LIB)
			${CC} ${CFLAGS} ${OBJS} ${MLXFLAGS} -o ${NAME}
			$(CC) $(OBJS) $(CFLAGS) -I ${LIB} -o $(NAME) $(MLXFLAGS)
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

# test:		all
# 			$(CC) $(OBJS) $(CFLAGS) -I ${LIB} -o $(NAME) $(MLXFLAGS)
# 			./${NAME} mandelbrot
		

clean:		
			@echo "$(RESET)$(ORANGE)I'M CLEANING OUT MY CLOSET...$(RESET)"
			@$(MAKE) -C $(LIB) clean
			@echo "$(RESET)$(GREEN)CLEANED ✓$(RESET)"

fclean:		clean
			@echo "$(RESET)$(ORANGE)ONE MORE TIME...$(RESET)"
			${RM} ${OBJS} ${NAME}
			@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re:			fclean all

.PHONY:		all test clean fclean re
