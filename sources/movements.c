/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:20:01 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/10 14:18:24 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	move_up(t_map *board)
{
	if (board->game[board->player_y - 1][board->player_x] != '1')
	{
		if (board->game[board->player_y - 1][board->player_x] == 'E' &&
			board->config.colletables != 0)
			return ;
		if (board->game[board->player_y - 1][board->player_x] == 'E' &&
			board->config.colletables == 0)
			board->config.exit -= 1;
		if (board->game[board->player_y - 1][board->player_x] == 'C')
			board->config.colletables -= 1;
		board->game[board->player_y][board->player_x] = '0';
		board->player_y -= 1;
		board->game[board->player_y][board->player_x] = 'P';
		board->config.steps++;
	}
	board->mario.num = MARIO_UP;
}

void	move_down(t_map *board)
{
	if (board->game[board->player_y + 1][board->player_x] != '1')
	{
		if (board->game[board->player_y + 1][board->player_x] == 'E' &&
			board->config.colletables != 0)
			return ;
		if (board->game[board->player_y + 1][board->player_x] == 'E' &&
			board->config.colletables == 0)
			board->config.exit -= 1;
		if (board->game[board->player_y + 1][board->player_x] == 'C')
			board->config.colletables -= 1;
		board->game[board->player_y][board->player_x] = '0';
		board->player_y += 1;
		board->game[board->player_y][board->player_x] = 'P';
		board->config.steps++;
	}
	board->mario.num = MARIO_DOWN;
}

void	move_right(t_map *board)
{
	if (board->game[board->player_y][board->player_x + 1] != '1')
	{
		if (board->game[board->player_y][board->player_x + 1] == 'E' &&
			board->config.colletables != 0)
			return ;
		if (board->game[board->player_y][board->player_x + 1] == 'E' &&
			board->config.colletables == 0)
			board->config.exit -= 1;
		if (board->game[board->player_y][board->player_x + 1] == 'C')
			board->config.colletables -= 1;
		board->game[board->player_y][board->player_x] = '0';
		board->player_x += 1;
		board->game[board->player_y][board->player_x] = 'P';
		board->config.steps++;
	}
	board->mario.num = MARIO_RIGHT;
}

void	move_left(t_map *board)
{
	if (board->game[board->player_y][board->player_x - 1] != '1')
	{
		if (board->game[board->player_y][board->player_x - 1] == 'E' &&
			board->config.colletables != 0)
			return ;
		if (board->game[board->player_y][board->player_x - 1] == 'E' &&
			board->config.colletables == 0)
			board->config.exit -= 1;
		if (board->game[board->player_y][board->player_x - 1] == 'C')
			board->config.colletables -= 1;
		board->game[board->player_y][board->player_x] = '0';
		board->player_x -= 1;
		board->game[board->player_y][board->player_x] = 'P';
		board->config.steps++;
	}
	board->mario.num = MARIO_LEFT;
}
