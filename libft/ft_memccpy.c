/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 09:40:25 by scollet           #+#    #+#             */
/*   Updated: 2017/03/06 19:28:38 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*tdst;
	const char	*fsrc;

	tdst = (char*)dst;
	fsrc = (char*)src;
	if (n)
	{
		while (n > 0)
		{
			if ((*tdst++ = *fsrc++) == c)
				return ((char*)tdst);
			n--;
		}
	}
	return (0);
}