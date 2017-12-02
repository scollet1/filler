/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:07:35 by scollet           #+#    #+#             */
/*   Updated: 2017/03/06 18:16:04 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*p;

	i = 0;
	d = (unsigned char)c;
	p = (unsigned char*)s;
	while (i < n)
	{
		if (p[i] == d)
			return (&p[i]);
		i++;
	}
	return (0);
}
