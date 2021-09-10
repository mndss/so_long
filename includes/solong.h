/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:55:33 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/10 16:00:35 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <libft.h>
# include <mlx_int.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <get_next_line.h>
# define ESC		(0xff1b)
# define ERROR_SIZE 6

enum	e_position {
	MARIO_DOWN,
	MARIO_UP,
	MARIO_RIGHT,
	MARIO_LEFT,
};

enum	e_errors {
	ERR_INVALID_ARGUMENTS,
	ERR_COULDNT_READ_MAP,
	ERR_INVALID_MAP,
	ERR_NO_PLAYER,
	ERR_MULTIPLAYER,
	ERR_NO_EXIT,
	ERR_NO_COLLECT,
};

typedef struct s_vars
{
	void	*mlx;
	void	*window;
}	t_vars;

typedef struct s_elements
{
	int		colletables;
	int		player;
	int		exit;
	int		steps;
}	t_elements;

typedef struct s_mario
{
	char	*mario[4];
	void	*img;
	int		width;
	int		height;
	int		num;
}	t_mario;

typedef struct s_sprites
{
	char	*path;
	void	*img;
	int		width;
	int		height;
}	t_sprites;

typedef struct s_objects
{
	t_sprites	wall;
	t_sprites	exit;
	t_sprites	floor;
	t_sprites	collect;
}	t_objects;

typedef struct s_map
{
	char		**game;
	int			line;
	int			column;
	int			player_x;
	int			player_y;
	t_mario		mario;
	t_objects	obj;
	t_elements	config;
	t_vars		vars;
}	t_map;

int		main(int argc, char *argv[]);
int		print_error(int errornum);
int		valid_args(int argc, char *map);
int		valid_game(char *map, t_map	*board);
int		check_border(t_map *board);
int		read_line_map(char *map);
int		read_map(int line, char *map, t_map *board);
int		check_elements(t_map *board);
int		get_elements(t_map *board);
int		verify_game(t_map *board);
void	init_structs(t_map *board);
int		find_player(t_map *board);
int		start_game(t_map *board);
void	move_up(t_map *board);
void	move_down(t_map *board);
void	move_right(t_map *board);
void	move_left(t_map *board);
void	load_sprites(t_map *board);
void	create_image(t_map *board);
int		load_map(t_map *board);
void	print_steps(t_map *board);
void	free_all(t_map *board);
void	destroy_image(t_map *board);
int		quit_game(t_map *board);

#endif