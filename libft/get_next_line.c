/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:01:26 by scollet           #+#    #+#             */
/*   Updated: 2017/04/21 11:56:37 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*learn_to_read(const int fd, char **block, int *s)
{
	char	tmp[BUFF_SIZE + 1];
	char	*hold;

	*s = read(fd, tmp, BUFF_SIZE);
	tmp[*s] = '\0';
	hold = block[fd];
	block[fd] = ft_strjoin(hold, tmp);
	ft_memdel((void**)&hold);
	return (block[fd]);
}

int		get_next_line(const int fd, char **line)
{
	static char *block[FT_MAX_FD];
	int			ret;
	char		*str;

	if (!(line) || fd < 0 || fd > FT_MAX_FD)
		return (-1);
	if ((ret = 1) && !(block[fd]))
		block[fd] = ft_strnew(0);
	while (ret > 0)
	{
		if ((block[fd] = learn_to_read(fd, block, &ret)) && ret < 0)
			return (-1);
		if ((str = ft_memchr(block[fd], '\n', ft_strlen(block[fd]))))
		{
			*str = '\0';
			*line = ft_strdup(block[fd]);
			ft_memmove(block[fd], str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
	}
	if ((*block[fd]) && (*line = ft_strdup(block[fd])))
		if ((str = ft_memchr(block[fd], '\0', ft_strlen(block[fd]) + 1)) &&
			(ft_memmove(block[fd], str + 1, ft_strlen(str + 1) + 1)))
			return (1);
	return (0);
}
