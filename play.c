/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:56:10 by scollet           #+#    #+#             */
/*   Updated: 2017/12/08 11:56:11 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void fatal_flying_guillotine(t_player *player)
{
  int i;
  int j;

  i = -1;
  while (++i < player->y)
  {
    j = -1;
    while (++j < player->x)
    {
      (player->z > 0) ? {
        player->
      } : {

      }
    }
  }
}

int fits(t_player *player, int i, int j, int x)
{
  int t;
  int r;
  t_piece *root;

  root = player->piece;
  while (root->next)
  {
    t = i + (root->y - player->piece->y);
    r = j + (root->x - player->piece->x);
    // dprintf(2, "%d, %d\n", t, r);
    if (t > -1 && t < player->y && r > -1 && r < player->x)
    {
      if (player->map[t][r] == '.' && x <= 1)
      {
        root = root->next;
      }
      else if (player->map[t][r] == player->p ||
              player->map[t][r] == player->q)
      {
        x += 1;
        // dprintf(2, "we have overlap on %d, %d -> %d\n", t, r, x);
        root = root->next;
      }
      else
      {
        return (0);
      }
    }
    else
    {
      return (0);
    }
  }
  if (x != 1)
    return (0);
  return (1);
}

char *find_option(t_player *player)
{
  char *info = NULL;
  int i;
  int j;

  i = (player->z > 0) ? 0 : player->y - 1;
  while (i < player->y &&  i > -1)
  {
    j = (player->z > 0) ? 0 : player->x - 1;
    while (j < player->x && j > -1)
    {
      if (fits(player, i, j, 0))
      {
        // dprintf(2, "%d, %d\n", i, j);
        info = ft_strjoin(ft_itoa(i - player->piece->y),
        ft_strjoin(" ", ft_itoa(j - player->piece->x)));
        return (info);
      }
      j += player->z;
    }
    i += player->z;
  }
  return (NULL);
}

char *fill_that_shit(t_player *player)
{
  char *info = NULL;
  int i;
  int j;

  i = (player->z > 0) ? 0 : player->y - 1;
  while (i < player->y &&  i > -1)
  {
    // dprintf(2, "iiii %d\n", i);
    j = (player->z > 0) ? 0 : player->x - 1;
    while (j < player->x && j > -1)
    {
      // dprintf(2, "jjjj %d\n", j);
      if (player->map_i[i][j] == 0)
      {
        // dprintf(2, "doing the thing\n");
        if (fits(player, i, j, 0))
        {
          info = ft_strjoin(ft_itoa(i - player->piece->y),
          ft_strjoin(" ", ft_itoa(j - player->piece->x)));
          return (info);
        }
      }
      j += player->z;
    }
    i += player->z;
  }
  return (find_option(player));
}
