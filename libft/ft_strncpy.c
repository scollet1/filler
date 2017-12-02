/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:12:59 by scollet           #+#    #+#             */
/*   Updated: 2017/03/06 19:24:35 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (ft_strlen(src) < len)
	{
		while (i < len)
		{
			dst[i] = 0;
			i++;
		}
	}
	return (dst);
}
