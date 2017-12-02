/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:23:01 by scollet           #+#    #+#             */
/*   Updated: 2017/03/07 20:12:20 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	if (!*little)
		return ((char*)big);
	if (!*big)
		return (0);
	if (*big == *little)
		if (ft_strstr(big + 1, little + 1) - 1 == big)
			return ((char*)big);
	return (ft_strstr(big + 1, little));
}
