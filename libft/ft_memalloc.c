/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:24:10 by scollet           #+#    #+#             */
/*   Updated: 2017/03/06 19:17:47 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;

	if (!(ret = (void*)malloc(sizeof(char) * (size + 1))) || size >= 2147483647)
		return (0);
	ft_bzero(ret, size);
	return (ret);
}
