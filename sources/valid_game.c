/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:52:05 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/10 14:02:30 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	valid_game(char *map, t_map	*board)
{
	int	row;

	row = read_line_map(map);
	if (!row)
		return (print_error(ERR_COULDNT_READ_MAP));
	if (!read_map(row, map, board))
		return (print_error(ERR_COULDNT_READ_MAP));
	if (!check_border(board))
	{
		free_all(board);
		return (print_error(ERR_INVALID_MAP));
	}
	if (!check_elements(board))
	{
		free_all(board);
		return (print_error(ERR_INVALID_MAP));
	}
	if (!verify_game(board))
	{
		free_all(board);
		return (0);
	}
	return (1);
}
