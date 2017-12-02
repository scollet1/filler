/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:16:49 by scollet           #+#    #+#             */
/*   Updated: 2017/03/07 19:58:18 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char*)big);
	if (!*big || len == 0)
		return (0);
	if (*big == *little)
		if (ft_strnstr(big + 1, little + 1, len - 1) - 1 == big)
			return ((char*)big);
	return (ft_strnstr(big + 1, little, len - 1));
}
