# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 10:09:33 by tstrassb          #+#    #+#              #
#    Updated: 2023/03/04 13:37:10 by tstrassb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

SRCS		=	$(MAIN_SRC) $(SRC_MAP) $(SCR_GAME)

MINILIBX	=	minilibx/
LIBMLX_A	=	libmlx.a

MAIN_SRC	=	main.c error.c

LIBFT_A		=	libft.a
LIBFT_DIR	=	libft/
LIBFT		=	$(addprefix $(LIBFT_DIR), $(LIBFT_A))

MAP			=	map_reader.c map_checker.c map_checker_utils.c\
				tilemap_generator.c enemy_generator.c
SRC_MAP		=	$(addprefix map/, $(MAP))

GAME		=	draw_wall.c end_program.c enemy_ai.c follower_ai.c game_init.c\
				input.c open_images.c open_panel.c open_wall_images.c\
				player_kill.c player_movement.c render.c reset.c update.c

SRC_GAME	=	$(addprefix game/, $(GAME))

%.o:			%.c
				@$(CC) $(CFLAGS) -c $< -o $@

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
				@echo "$(BLUE)-compiling minilibx...$(DEF_COLOR)"
				@make -C $(MINILIBX)
				@echo "$(BLUE)-compiling GAME...$(DEF_COLOR)"
				@gcc $(CFLAGS) $(LIBFT) $(MINILIBX)libmlx.a $(INCLUDE) -o $(NAME)
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
				@echo "$(YELLOW)-Cleaning libmlx ...$(DEF_COLOR)"
				@make -C $(MINILIBX) clean
				@sleep 1.5
				@echo "$(GREEN)---CLEANED!---$(DEF_COLOR)"

fclean:			clean
				@echo "$(YELLOW)-Cleaning remaining files ...$(DEF_COLOR)"
				@$(RM) $(NAME)
				@make -C $(LIBFT_DIR) fclean
				@sleep 1.5
				@echo "$(GREEN)---CLEANED!---$(DEF_COLOR)"

re:				fclean all