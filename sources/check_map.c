/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:08:44 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/10 14:15:14 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	read_line_map(char *map)
{
	int		fd;
	int		counter;
	int		gnl;
	char	*line;

	counter = 0;
	gnl = 1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (gnl < 0)
			return (print_error(ERR_COULDNT_READ_MAP));
		counter++;
		free(line);
	}
	close(fd);
	return (counter);
}

int	read_map(int line, char *map, t_map *board)
{
	int	fd;
	int	i;
	int	gnl;

	i = 0;
	gnl = 1;
	board->game = (char **)ft_calloc(sizeof(char *), line + 1);
	if (!board->game)
		return (0);
	fd = open(map, O_RDONLY);
	while (gnl)
	{
		gnl = get_next_line(fd, &board->game[i]);
		if (gnl < 0)
			return (0);
		i++;
	}
	board->game[line] = NULL;
	close(fd);
	board->line = line;
	board->column = ft_strlen(board->game[0]);
	return (1);
}

int	check_border(t_map *board)
{
	int	counter;

	counter = 0;
	while (counter < board->column)
	{
		if (board->game[0][counter] != '1' ||
			board->game[board->line - 1][counter] != '1')
			return (0);
		counter++;
	}
	counter = 0;
	while (counter < board->line - 1)
	{
		if (board->game[counter][0] != '1' ||
			board->game[counter][board->column - 1] != '1')
			return (0);
		counter++;
	}
	return (1);
}

int	check_elements(t_map *board)
{
	int	row;
	int	col;

	row = 1;
	while (row <= board->line - 2 )
	{
		col = 1;
		while (col <= board->column - 2)
		{
			if (board->game[row][col] != 'C' &&
				board->game[row][col] != 'P' &&
				board->game[row][col] != 'E' &&
				board->game[row][col] != '0' &&
				board->game[row][col] != '1')
				return (print_error(ERR_INVALID_MAP));
			col++;
		}
		row++;
	}
	return (1);
}
