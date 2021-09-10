/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:23:14 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/10 14:15:45 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	find_player(t_map *board)
{
	while (board->player_y < board->line)
	{
		board->player_x = 0;
		while (board->player_x < board->column)
		{
			if (board->game[board->player_y][board->player_x] == 'P')
				return (1);
			board->player_x++;
		}
		board->player_y++;
	}
	return (0);
}
