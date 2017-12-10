/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:24:30 by scollet           #+#    #+#             */
/*   Updated: 2017/12/09 16:46:23 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Initialize player;
*/

t_player	*make_player(void)
{
	t_player *new_player;

	new_player = (t_player*)malloc(sizeof(t_player));
	return (new_player);
}

/*
** Determine which player;
*/

char		which_player(char *this)
{
	if (ft_strstr(this, "filler"))
		return ((ft_strstr(this, "p1") ? 'O' : 'X'));
	return ('\0');
}

void		init_map_i(t_player *player)
{
	int i;

	i = -1;
	player->map_i = (int**)ft_memalloc(sizeof(int*) * player->y);
	while (++i < player->y)
		player->map_i[i] = (int*)ft_memalloc(sizeof(int) * player->x);
}

/*
** Initialize a board of variable size;
*/

t_player	*init(char *this)
{
	int			i;
	int			j;
	t_player	*player;

	player = (t_player*)malloc(sizeof(t_player));
	if (!(player->p = which_player(this)))
		expletive("init\n");
	player->q = player->p + 32;

	get_next_line(0, &this);
	this = ft_strchr(this, ' ');
	i = ft_atoi(this) + 1;
	player->y = i - 1;
	while (ft_isdigit(*this++))
		;
	this = ft_strchr(this, ' ');
	j = ft_atoi(this);
	player->x = j;
	player->zy = (player->p == 'X') ? -1 : 1;
	player->zx = player->zy;
	player->zz = player->zx;
	player->map = (char**)malloc(sizeof(char*) * player->y);
	while (--i >= 0)
		player->map[i] = (char*)malloc(sizeof(char) * player->x);
	return (player);
}

/*
** Initialize a piece of variable size;
*/

int			init_piece(int fd, char *this, t_player *player)
{
	int		lt;
	char	*s;
	int		i;
	int		j;

	if ((lt = get_next_line(fd, &this)) < 0)
		return (-1);
	s = ft_strchr(this, ' ');
	i = ft_atoi(s);
	player->b = i;
	while (ft_isdigit(*s++))
		;
	this = s;
	s = ft_strchr(this, ' ');
	j = ft_atoi(s);
	player->a = j;
	player->piece = (struct s_piece*)malloc(sizeof(struct s_piece));
	player->piece->next = NULL;
	player->piece->previous = NULL;
	return (0);
}
