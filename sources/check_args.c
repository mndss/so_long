/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:08:25 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/08 22:01:29 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	valid_args(int argc, char *map)
{
	char	*extension;

	extension = ".ber";
	if (argc != 2)
		return (print_error(ERR_INVALID_ARGUMENTS));
	if (!ft_strnstr((const char *)map, extension, ft_strlen(map) + 1))
		return (print_error(ERR_INVALID_MAP));
	return (1);
}
