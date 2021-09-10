/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:35:17 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/10 15:31:53 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	load_sprites(t_map *board)
{
	board->mario.mario[MARIO_DOWN] = "./images/mario_down.xpm";
	board->mario.mario[MARIO_UP] = "./images/mario_up.xpm";
	board->mario.mario[MARIO_RIGHT] = "./images/mario_right.xpm";
	board->mario.mario[MARIO_LEFT] = "./images/mario_left.xpm";
	board->obj.collect.path = "./images/star.xpm";
	board->obj.wall.path = "./images/mario_wall.xpm";
	board->obj.floor.path = "./images/mario_floor.xpm";
	board->obj.exit.path = "./images/mario_exit1.xpm";
}

void	create_image(t_map *board)
{
	board->mario.img = mlx_xpm_file_to_image(board->vars.mlx,
			board->mario.mario[board->mario.num],
			&board->mario.width, &board->mario.height);
	board->obj.collect.img = mlx_xpm_file_to_image(board->vars.mlx,
			board->obj.collect.path, &board->obj.collect.width,
			&board->obj.collect.height);
	board->obj.wall.img = mlx_xpm_file_to_image(board->vars.mlx,
			board->obj.wall.path, &board->obj.wall.width,
			&board->obj.wall.height);
	board->obj.floor.img = mlx_xpm_file_to_image(board->vars.mlx,
			board->obj.floor.path, &board->obj.floor.width,
			&board->obj.floor.height);
	board->obj.exit.img = mlx_xpm_file_to_image(board->vars.mlx,
			board->obj.exit.path, &board->obj.exit.width,
			&board->obj.exit.height);
}
