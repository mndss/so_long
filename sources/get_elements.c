/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:21:26 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/10 14:16:24 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	get_elements(t_map *board)
{
	int	row;
	int	col;

	row = 1;
	while (row <= board->line - 2)
	{
		col = 0;
		while (col <= board->column - 2)
		{
			if (board->game[row][col] == 'C')
				board->config.colletables += 1;
			if (board->game[row][col] == 'P')
				board->config.player += 1;
			if (board->game[row][col] == 'E')
				board->config.exit += 1;
			col++;
		}
		row++;
	}
	return (1);
}

int	verify_game(t_map *board)
{
	get_elements(board);
	if (board->config.player == 0)
		return (print_error(ERR_NO_PLAYER));
	if (board->config.player > 1)
		return (print_error(ERR_MULTIPLAYER));
	if (board->config.colletables < 1)
		return (print_error(ERR_NO_COLLECT));
	if (board->config.exit < 1)
		return (print_error(ERR_NO_EXIT));
	return (1);
}
