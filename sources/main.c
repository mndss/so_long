/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:51:55 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/10 15:48:08 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	main(int argc, char *argv[])
{
	t_map	board;

	init_structs(&board);
	if (!valid_args(argc, argv[1]))
		return (0);
	if (!valid_game(argv[1], &board))
		return (0);
	if (!find_player(&board))
		return (0);
	if (!start_game(&board))
		return (0);
	return (1);
}
