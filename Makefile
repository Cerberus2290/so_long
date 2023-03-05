# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 10:09:33 by tstrassb          #+#    #+#              #
#    Updated: 2023/03/05 09:58:18 by tstrassb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

SRCS		=	$(MAIN_SRC) $(SRC_MAP) $(SRC_GAME)

MAIN_SRC	=	main.c error.c

LIBFT_A		=	libft.a
LIBFT_DIR	=	libft/
LIBFT		=	$(addprefix $(LIBFT_DIR), $(LIBFT_A))

MAP			=	map_reader.c map_checker.c map_checker_utils.c\
				tilemap_generator.c enemy_generator.c
SRC_MAP		=	$(addprefix map/, $(MAP))

GAME		=	game_init.c open_images.c open_wall_images.c open_panel.c\
					input.c player_movement.c player_kill.c update.c enemy_ai.c follower_ai.c\
					render.c draw_wall.c\
					reset.c end_program.c

SRC_GAME	=	$(addprefix game/, $(GAME))

OBJ			=	*.o

INCLUDE		=	-lmlx -framework OpenGL -framework AppKit

#colors

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

all:			$(NAME)

$(NAME):		$(OBJ)
				@echo "$(BLUE)-compiling libft...$(DEF_COLOR)"
				@make -C $(LIBFT_DIR)
				@echo "$(BLUE)-compiling GAME...$(DEF_COLOR)"
				@cc $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)
				@echo "$(GREEN)-GAME ready-$(DEF_COLOR)"

$(OBJ):			$(SRCS)
				@echo "$(BLUE)-creating object files...$(DEF_COLOR)"
				@gcc $(CFLAGS) -c $(SRCS)

norm:
				@echo "$(CYAN)Checking the Norm..."
				@sleep 1.5
				@norminette *.c *.h game/ map/
				@echo "$(DEF_COLOR)"

clean:
				@echo "$(YELLOW)-Cleaning object files ...$(DEF_COLOR)"
				@$(RM) *.o
				@make -C $(LIBFT_DIR) clean
				@sleep 1.5
				@echo "$(GREEN)---CLEANED!---$(DEF_COLOR)"

fclean:			clean
				@echo "$(YELLOW)-Cleaning remaining files ...$(DEF_COLOR)"
				@$(RM) $(NAME)
				@make -C $(LIBFT_DIR) fclean
				@sleep 1.5
				@echo "$(GREEN)---CLEANED!---$(DEF_COLOR)"

re:				fclean all