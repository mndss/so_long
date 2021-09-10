/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:52:39 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/01 23:36:10 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	print_error(int errornum)
{
	char	*message[ERROR_SIZE];

	message[ERR_INVALID_ARGUMENTS] = "Invalid arguments";
	message[ERR_COULDNT_READ_MAP] = "Could not read the map";
	message[ERR_INVALID_MAP] = "Invalid map";
	message[ERR_NO_PLAYER] = "The game must have at least 1 player";
	message[ERR_MULTIPLAYER] = "The game must have only 1 player";
	message[ERR_NO_EXIT] = "The game must have an exit";
	message[ERR_NO_COLLECT] = "The game must have at least 1 collectable";
	printf("Error %s\n", message[errornum]);
	return (0);
}
