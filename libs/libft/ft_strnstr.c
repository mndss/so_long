/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:44:38 by elima-me          #+#    #+#             */
/*   Updated: 2021/08/30 12:57:03 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	count;

	if (len > ft_strlen(big))
		len = (ft_strlen(big) + 1);
	i = 0;
	if (*little == '\0')
		return (0);
	while (big[i] != '\0')
	{
		count = 0;
		while ((i + count) < len && big[i + count] == little[count])
		{
			if (little[count + 1] == '\0')
				return (1);
			count++;
		}
		i++;
	}
	return (0);
}
