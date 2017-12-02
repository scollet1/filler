/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:48:24 by scollet           #+#    #+#             */
/*   Updated: 2017/03/06 19:30:37 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (!tmp)
		return (0);
	if (content == 0)
	{
		tmp->content = 0;
		tmp->content_size = 0;
	}
	else
	{
		tmp->content = malloc(content_size);
		if (tmp->content == 0)
			return (0);
		ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = 0;
	return (tmp);
}
