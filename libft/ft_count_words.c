/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:25:51 by scollet           #+#    #+#             */
/*   Updated: 2017/03/07 20:06:06 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *s, char c)
{
	int split;
	int split_t;

	split_t = 0;
	split = 0;
	while (*s)
	{
		if (split_t == 1 && *s == c)
			split_t = 0;
		if (split_t == 0 && *s != c)
		{
			split_t = 1;
			split++;
		}
		s++;
	}
	return (split);
}
