/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:17:12 by scollet           #+#    #+#             */
/*   Updated: 2017/03/07 20:27:44 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_num(char *num, int n, int base)
{
	*--num = '0' + (n % base);
	n /= base;
	while (n != 0)
	{
		*--num = '0' + (n % base);
		n /= 10;
	}
	return (num);
}

char			*ft_itoa_base(int n, int base)
{
	char	*num;

	if (!(num = (char*)ft_memalloc(10)))
		return (0);
	if (n >= 0 && num)
		num = ft_num(num, n, base);
	else if (num)
	{
		*--num = '0' - (n % base);
		n /= 10;
		while (n != 0)
		{
			*--num = '0' - (n % base);
			n /= 10;
		}
		*--num = '-';
	}
	return (ft_strdup(num));
	free(num);
}
