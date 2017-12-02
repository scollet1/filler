/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 09:44:06 by scollet           #+#    #+#             */
/*   Updated: 2017/03/06 18:15:29 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ret;
	unsigned char	*hold;

	ret = (unsigned char*)dst;
	hold = (unsigned char*)src;
	if (hold < ret)
	{
		ret = ret + len - 1;
		hold = hold + len - 1;
		while (len-- > 0)
			*ret-- = *hold--;
	}
	else if (ret < hold)
	{
		while (len > 0)
		{
			*ret++ = *hold++;
			len--;
		}
	}
	else
		return (hold);
	return (dst);
}
