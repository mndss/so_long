/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 23:28:09 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/10 15:40:02 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	print_image(t_map *board, int l, int c)
{
	if (board->game[l][c] == '1')
		mlx_put_image_to_window(board->vars.mlx, board->vars.window,
			board->obj.wall.img, c * 32, l * 32);
	if (board->game[l][c] == 'E')
		mlx_put_image_to_window(board->vars.mlx, board->vars.window,
			board->obj.exit.img, c * 32, l * 32);
	if (board->game[l][c] == '0')
		mlx_put_image_to_window(board->vars.mlx, board->vars.window,
			board->obj.floor.img, c * 32, l * 32);
	if (board->game[l][c] == 'P')
		mlx_put_image_to_window(board->vars.mlx, board->vars.window,
			board->mario.img, c * 32, l * 32);
	if (board->game[l][c] == 'C')
		mlx_put_image_to_window(board->vars.mlx, board->vars.window,
			board->obj.collect.img, c * 32, l * 32);
}

int	load_map(t_map *board)
{
	int	l;
	int	c;

	create_image(board);
	l = -1;
	while (board->game[++l])
	{
		c = -1;
		while (board->game[l][++c])
			print_image(board, l, c);
	}
	destroy_image(board);
	return (0);
}

void	print_steps(t_map *board)
{
	char	*count;
	char	*steps;

	steps = ft_calloc(sizeof(char), 100);
	count = ft_itoa(board->config.steps);
	ft_strcopy(steps, "Steps:", 7);
	ft_strcopy(&steps[ft_strlen(steps)], count, ft_strlen(count) + 1);
	mlx_string_put(board->vars.mlx, board->vars.window,
		(board->column * 32) / 2 - 30, 16, 0xFFFFFF, steps);
	free(steps);
	free(count);
	return ;
}
