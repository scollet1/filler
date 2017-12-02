/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:42:12 by scollet           #+#    #+#             */
/*   Updated: 2017/03/07 19:55:54 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	nb;
	size_t	i;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		if (nb >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (nb > 9223372036854775807 && sign == -1)
			return (0);
		nb = (nb * 10) + str[i++] - '0';
	}
	return (sign * nb);
}
