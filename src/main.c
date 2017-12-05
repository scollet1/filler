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

int fits(t_player *player, int i, int j, int x)
{
  if (i >= player->y)
    i = 0;
  if (j >= player->x)
    j = 0;
  if (player->map[i + player->piece->y][j + player->piece->x] == '.')
  {
    // if (player->map[i + player->piece->y][j + player->piece->x] == '')
    // {

    // }
    if (x > 1)
    {
      fits();
    }
  }
  else if (player->map[i + player->piece->y][j + player->piece->x] == 'X' ||
            player->map[i + player->piece->y][j + player->piece->x] == 'x')
  {
    return (fits(player, i + 1, j + 1, 1))
  }
  return (1);
}

char *fill_that_shit(t_player *player)
{
  char *info = NULL;
  int direction;
  int offx;
  int offy;
  int i;
  int j;

  i = -1;
  while (++i < player->a)
  {
    j = -1;
    while (++j < player->b)
    {
      if (player->map_i[i][j] <= 1)
      {
        if (fits(player, i, j, 0))
        {

        }
        else
        {

        }
      }
    }
  }
  return (info);
}

void update_score(t_player *player, int score, int i, int j)
{
  if (player->map_i[i + 1][j])
    player->map_i[i + 1][j] += score;
  if (player->map_i[i - 1][j])
    player->map_i[i - 1][j] += score;
  if (player->map_i[i + 1][j + 1])
    player->map_i[i + 1][j + 1] += score;
  if (player->map_i[i + 1][j - 1])
    player->map_i[i + 1][j - 1] += score;
  if (player->map_i[i][j + 1])
    player->map_i[i][j + 1] += score;
  if (player->map_i[i][j - 1])
    player->map_i[i][j - 1] += score;
  if (player->map_i[i - 1][j - 1])
    player->map_i[i - 1][j - 1] += score;
  if (player->map_i[i - 1][j + 1])
    player->map_i[i - 1][j + 1] += score;
}

void calculate_map(t_player *player)
{
  int i;
  int j;

  i = -1;
  player->map_i = (int**)malloc(sizeof(int*)*player->y);
  while (++i < player->y)
    player->map_i[i] = (int*)malloc(sizeof(int)*player->x);
  i = -1;
  while (++i < player->y)
  {
    j = -1;
    while (++j < player->x)
    {
      if (player->map[i][j] == 'o' || player->map[i][j] == 'O')
        update_score(player, -1, i, j);
      else if (player->map[i][j] == 'x' || player->map[i][j] == 'X')
        update_score(player, 1, i, j);
      else
        update_score(player, 0, i, j);
    }
  }
  return ;
}

int main(void)
{
  char *this = NULL;
  char *info;
  t_player *player = NULL;
  int i;

  get_next_line(0, &this);
  player = init(this);
  while (1)
  {
    i = -1;
    if (parse(0, this, player) < 0)
      fucking_crash_and_burn("main");
    calculate_map(player);
    info = fill_that_shit(player);
    ft_putstr(info);
  }
  if (this)
    free(this);
  if (info)
    free(info);
  if (player)
    free(player);
  return (0);
}
