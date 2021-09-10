/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:28:35 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/10 16:00:51 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	free_all(t_map *board)
{
	int	i;

	i = 0;
	while (board->game[i])
	{
		free(board->game[i]);
		i++;
	}
	free(board->game);
}

int	quit_game(t_map *board)
{
	free_all(board);
	mlx_destroy_window(board->vars.mlx, board->vars.window);
	mlx_destroy_display(board->vars.mlx);
	free(board->vars.mlx);
	exit(0);
	return (0);
}

void	destroy_image(t_map *board)
{
	mlx_destroy_image(board->vars.mlx, board->obj.collect.img);
	mlx_destroy_image(board->vars.mlx, board->obj.exit.img);
	mlx_destroy_image(board->vars.mlx, board->obj.wall.img);
	mlx_destroy_image(board->vars.mlx, board->obj.floor.img);
	mlx_destroy_image(board->vars.mlx, board->mario.img);
}

int	key_hook(int keycode, t_map *board)
{
	int	counter;

	counter = 0;
	if (keycode == 'w')
		move_up(board);
	if (keycode == 's')
		move_down(board);
	if (keycode == 'a')
		move_left(board);
	if (keycode == 'd')
		move_right(board);
	if (keycode == ESC || board->config.exit == 0)
		quit_game(board);
	load_map(board);
	print_steps(board);
	return (0);
}

int	start_game(t_map *board)
{
	board->vars.mlx = mlx_init();
	board->vars.window = mlx_new_window(board->vars.mlx, board->column * 32,
			board->line * 32, "game");
	load_sprites(board);
	mlx_key_hook(board->vars.window, key_hook, board);
	mlx_hook(board->vars.window, 33, 1L << 2, quit_game, board);
	mlx_expose_hook(board->vars.window, &load_map, board);
	mlx_loop(board->vars.mlx);
	return (0);
}
