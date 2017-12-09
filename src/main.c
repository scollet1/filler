/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:30:21 by scollet           #+#    #+#             */
/*   Updated: 2017/12/01 15:30:22 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void update_score(t_player *player, int score, int i, int j)
{
  if (i < player->y && j < player->x && i > -1 && j > -1)
    player->map_i[i][j] += score;
  if (i + 1 < player->y && j < player->x)
    player->map_i[i + 1][j] += score;
  if (i - 1 < player->y && j < player->x && i - 1 > -1)
    player->map_i[i - 1][j] += score;
  if (i + 1 < player->y && j + 1 < player->x)
    player->map_i[i + 1][j + 1] += score;
  if (i + 1 < player->y && j - 1 < player->x && j - 1 > -1)
    player->map_i[i + 1][j - 1] += score;
  if (i < player->y && j + 1 < player->x)
    player->map_i[i][j + 1] += score;
  if (i < player->y && j - 1 < player->x && j - 1 > -1)
    player->map_i[i][j - 1] += score;
  if (i - 1 < player->y && j - 1 < player->x &&
      i - 1 > -1 && j - 1 > -1)
    player->map_i[i - 1][j - 1] += score;
  if (i - 1 < player->y && j + 1 < player->x && i - 1 > -1)
    player->map_i[i - 1][j + 1] += score;
}

int update_p_z(t_player *player, int i, int j)
{
  if (player->zy < 0)
    player->zy = (i >= player->co_y) ? -1 : 1;
  else if (player->zy > 0)
    player->zy = (i <= player->co_y) ? 1 : -1;
  if (player->zx < 0)
    player->zx = (j >= player->co_x) ? -1 : 1;
  else if (player->zx > 0)
    player->zx = (j <= player->co_x) ? 1 : -1;
  return (fatal_flying_guillotine(player));
  // return (1);
}

void calculate_map(t_player *player)
{
  int i;
  int j;

  i = -1;
  init_map_i(player);
  while (++i < player->y && (j = -1) == -1) /* Savin' lines like a champ */
  {
    while (++j < player->x)
    {
      if (player->map[i][j] == 'o' || player->map[i][j] == 'O')
        update_score(player, -1, i, j);
      else if (player->map[i][j] == 'x' || player->map[i][j] == 'X')
        update_score(player, 1, i, j);
      else
        update_score(player, player->zx + player->zy, i, j);
      if (player->map[i][j] == player->p || player->map[i][j] == player->q)
      {
        if (((player->zy > 0) ? i >= player->co_y : i <= player->co_y))
          player->co_y = i;
        if (((player->zx > 0) ? j >= player->co_x : j <= player->co_x))
          player->co_x = j;
      }
      // update_p_z(player, i, j);
    }
  }
}

/*
Hey look, there's free stuff in here!
*/

void free_stuff(int op, t_player *player, char *this, char *info)
{
  if (op == 1)
  {
    while (player->piece->next)
      player->piece = player->piece->next;
    while (player->piece->previous)
    {
      player->piece = player->piece->previous;
      if (player->piece->next)
        free(player->piece->next);
    }
    if (player->piece)
      free(player->piece);
  }
  if (op == 2)
  {
    if (this)
      free(this);
    if (info)
      free(info);
    if (player)
      free(player);
  }
}

int main(void)
{
  char *this = NULL;
  char *info = NULL;
  t_player *player = NULL;
  int k;

  k = 1;
  if (get_next_line(0, &this) < 0)
    expletive("before you even started, time to rethink life... \n");
  player = init(this);
  while (1)
  {
    if (!k)
      get_next_line(0, &this);
    if (parse(0, this, player) < 0)
      expletive("main\n");
    calculate_map(player);
    info = ft_strjoin(fill_that_shit(player), "\n");
    ft_putstr_fd(info, 1);
    free_stuff(1, player, this, info);
    k = 0;
  }
  free_stuff(2, player, this, info);
  return (0);
}
