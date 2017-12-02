/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:36:38 by scollet           #+#    #+#             */
/*   Updated: 2017/03/07 20:14:20 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*ret;
	char	*hold;
	size_t	i;
	size_t	x;

	hold = (char*)src;
	ret = (char*)malloc(sizeof(char) * ft_strlen(dst) + ft_strlen(src) + 1);
	ret = dst;
	i = 0;
	x = 0;
	if (n)
	{
		while (ret[i] != 0)
			i++;
		while (x < n)
		{
			if ((ret[i] = hold[x]) == 0)
				return (ret);
			i++;
			ret[i] = 0;
			x++;
		}
	}
	return (ret);
}
