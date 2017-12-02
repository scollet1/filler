/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:31:49 by scollet           #+#    #+#             */
/*   Updated: 2017/03/09 18:41:50 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		split;
	char	**ret;
	int		i;
	int		j;
	int		start;

	if (s == 0 || c == 0)
		return (0);
	split = ft_count_words(s, c);
	if (!(ret = (char**)malloc((sizeof(char*) * (split + 1)))))
		return (0);
	i = 0;
	j = -1;
	while (++j < split)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		ret[j] = ft_strsub(s, start, i - start);
		i++;
	}
	ret[j] = 0;
	return (ret);
}