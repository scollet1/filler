/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:41:59 by scollet           #+#    #+#             */
/*   Updated: 2017/03/06 19:17:04 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*tmp;
	size_t		i;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
