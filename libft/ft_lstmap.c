/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 22:59:13 by scollet           #+#    #+#             */
/*   Updated: 2017/03/07 08:10:34 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;

	tmp = f(lst);
	ret = tmp;
	if (!(ret) || !(lst))
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		if (!(tmp->next))
			return (0);
		tmp = tmp->next;
	}
	return (ret);
}
