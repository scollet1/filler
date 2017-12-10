/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:56:10 by scollet           #+#    #+#             */
/*   Updated: 2017/12/09 16:58:46 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		scan(t_player *player, int i, int j, int t)
{
	if (i + 1 < player->y)
		if (player->map[i + 1][j] == (player->p == 'X') ? 'O' : 'X')
			t++;
	if (i + 1 < player->y && j + 1 < player->x)
		if (player->map[i + 1][j + 1] == (player->p == 'X') ? 'O' : 'X')
			t++;
	if (i - 1 > -1)
		if (player->map[i - 1][j] == (player->p == 'X') ? 'O' : 'X')
			t++;
	if (i - 1 > -1 && j - 1 > -1)
		if (player->map[i - 1][j - 1] == (player->p == 'X') ? 'O' : 'X')
			t++;
	if (j + 1 < player->x)
		if (player->map[i][j + 1] == (player->p == 'X') ? 'O' : 'X')
			t++;
	if (j + 1 < player->x && i - 1 > -1)
		if (player->map[i - 1][j + 1] == (player->p == 'X') ? 'O' : 'X')
			t++;
	if (j - 1 > -1)
		if (player->map[i][j - 1] == (player->p == 'X') ? 'O' : 'X')
			t++;
	if (i + 1 < player->y && j - 1 > -1)
		if (player->map[i + 1][j - 1] == (player->p == 'X') ? 'O' : 'X')
			t++;
	return ((t >= 8) ? 0 : t);
}

int		fatal_flying_guillotine(t_player *player)
{
	int	i;
	int	j;

	i = player->co_y;
	j = player->co_x;
	while (j < player->x && j > -1)
	{
		player->map_i[i][j] = -player->zz;
		j += player->zx;
	}
	j = player->co_x;
	while (i < player->y && i > -1)
	{
		player->map_i[i][j] = -player->zz;
		i += player->zy;
	}
	return (1);
}

int		fits(t_player *player, int i, int j, int x)
{
	int		t;
	int		r;
	t_piece	*root;

	root = player->piece;
	while (root->next)
	{
		t = i + (root->y - player->piece->y);
		r = j + (root->x - player->piece->x);
		if (t > -1 && t < player->y && r > -1 && r < player->x)
			if (player->map[t][r] == '.' && x <= 1)
				root = root->next;
			else if (player->map[t][r] == player->p ||
				player->map[t][r] == player->q)
			{
				x += 1;
				root = root->next;
			}
			else
				return (0);
		else
			return (0);
	}
	return ((x == 1) ? x : 0);
}

char	*find_option(t_player *player)
{
	char	*info;
	int		i;
	int		j;

	i = (player->zy > 0) ? 0 : player->y - 1;
	while (i < player->y && i > -1)
	{
		j = (player->zx > 0) ? 0 : player->x - 1;
		while (j < player->x && j > -1)
		{
			if (fits(player, i, j, 0))
			{
				info = ft_strjoin(ft_itoa(i - player->piece->y),
				ft_strjoin(" ", ft_itoa(j - player->piece->x)));
				return (info);
			}
			j += player->zx;
		}
		i += player->zy;
	}
	return (NULL);
}

char	*fill_that_shit(t_player *player)
{
	char	*info;
	int		t;
	int		i;
	int		j;

	i = (player->zy < 0) ? 0 : player->y;
	while (i < player->y && i > -1 && (t = 3) == 3)
	{
		j = (player->zx < 0) ? 0 : player->x;
		while (j < player->x && j > -1)
		{
			if ((player->zz < 0) ? player->map_i[i][j] < 0
			: player->map_i[i][j] > 0)
				if (t <= scan(player, i, j, 0))
				{
					if (fits(player, i, j, 0))
					{
						info = ft_strjoin(ft_itoa(i - player->piece->y),
						ft_strjoin(" ", ft_itoa(j - player->piece->x)));
						return (info);
					}
					update_p_z(player, i, j);
				}
			j += player->zx;
		}
		i += player->zy;
		// update_p_z(player, i, j);
	}
	return (find_option(player));
}
