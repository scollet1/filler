/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 08:39:48 by scollet           #+#    #+#             */
/*   Updated: 2017/03/06 17:58:27 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	a;
	char			*pb;

	a = (unsigned char)c;
	i = 0;
	pb = (char*)b;
	while (i < len)
		pb[i++] = a;
	b = (void*)pb;
	return (b);
}
