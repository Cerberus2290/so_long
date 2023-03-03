/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:48:32 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/02 10:10:47 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "basic.h"
# include "minilibx/mlx.h"

/* size of every sprite in the game */
# define IMG_SIZE 64

/* ---- TILES ---- */

/* definition of map tiles */
typedef enum e_maptiles
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F',
}	t_maptiles;

/* struct for each maptile */
typedef struct s_tile
{
	t_maptiles		type;
	t_maptiles		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

/* ---- IMAGES ---- */

/* possible wall images */

typedef struct s_wallimage
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*down_left;
	void	*down;
	void	*down_right;
	void	*left;
	void	*right;
}	t_wallimage;

/* collectable animation */
typedef struct s_collect_img
{
	void	*current_img;
	int		anima_frames;
	void	*img_0;
	void	*img_1;
}	t_collect_img;

/* image for entire screen */
typedef struct s_img_entire
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}	t_img_entire;

/* colors */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

/* ---- ENEMIES ---- */

typedef enum e_enemytypes
{
	HORIZONTAL_ENEMY = 'H',
	VERTICAL_ENEMY = 'V',
	FOLLOW_ENEMY = 'F'
}	t_enemytypes;

/* struct for enemy animation */
typedef struct s_enemy_anim
{
	int		basic_anim;
	void	*basic_current;
	void	*basic_01;
	void	*basic_02;
	int		follow_anim;
	void	*follow_current;
	void	*follow_01;
	void	*follow_02;
}	t_enemy_anim;

/* struct for making multiple enemies */
typedef struct s_enemies
{
	t_enemytypes		type;
	int					dir;
	t_tile				*og_tile;
	t_tile				*tile;
	struct s_enemies	*next;
}	t_enemies;

/* ---- GAME ---- */

/* definition valid input keys */
enum e_keyinput
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	QUIT = 53
};

/* struct for player */
typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		frames_idle;
	void	*idle_img_0;
	void	*idle_img_1;
	int		frames_action;
	void	*action_img;
}	t_player;

/* struct for starting game */
typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		window_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_enemies		*enemy_list;
	t_vector		img_size;
	t_wallimage		wall_imgs;
	t_collect_img	collect_imgs;
	t_enemy_anim	enemy_imgs;
	t_collect_img	collect_imgs;
	void			*white_panel;
	void			*red_panel;
	void			*door_open_img;
	void			*door_close_img;
}	t_game;

/* ---- FUNCTIONS ---- */

t_bool	start(t_game *game, int argc, char **argv);
t_color	new_color(int r, int g, int b, int a);
void	*new_panel(t_game *game, t_color color);
int		input(int key, t_game *game);
int		update(t_game *game);
void	render(t_game game);
void	action_anim(t_player *player);
void	remove_player(t_game *game);
void	kill_player(t_game *game, t_vector pos);
int		reset(t_game *game);
int		end_program(t_game *game);

#endif