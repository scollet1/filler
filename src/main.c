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

void display(t_player *player, int op)
{
  int i = -1;
  int j;

  if (!op)
  {
    while (++i < player->y)
    {
      j = -1;
      while (++j < player->x)
      {
        dprintf(2, " %d -- ", player->map_i[i][j]);
      }
      dprintf(2, "\n");
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
    // if (!root)
      // expletive("what the actual fuck\n");
    // dprintf(2, "%p\n", root);
    t = i + (root->y - player->piece->y);
    r = j + (root->x - player->piece->x);
    // dprintf(2, "%d, %d\n", t, r);
    // dprintf(2, "%c\n", player->map[t][r]);
    // if (t)
    // player->piece->y, root->y, root->x, player->piece->x);
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

  i = -1;
  while (++i < player->y)
  {
    j = -1;
    while (++j < player->x)
    {
      if (fits(player, i, j, 0))
      {
        // dprintf(2, "%d, %d\n", i, j);
        info = ft_strjoin(ft_itoa(i - player->piece->y),
        ft_strjoin(" ", ft_itoa(j - player->piece->x)));
        return (info);
      }
    }
  }
  return (NULL);
}

char *fill_that_shit(t_player *player)
{
  char *info = NULL;
  int i;
  int j;

  i = -1;
  while (++i < player->y)
  {
    j = -1;
    while (++j < player->x)
    {
      if (player->map_i[i][j] == 0)
      {
        if (fits(player, i, j, 0))
        {
          info = ft_strjoin(ft_itoa(i - player->piece->y),
          ft_strjoin(" ", ft_itoa(j - player->piece->x)));
          return (info);
        }
      }
    }
  }
  return (find_option(player));
}

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
  return ;
}

void calculate_map(t_player *player)
{
  int i;
  int j;

  i = -1;
  player->map_i = (int**)ft_memalloc(sizeof(int*)*player->y);
  while (++i < player->y)
    player->map_i[i] = (int*)ft_memalloc(sizeof(int)*player->x);
  i = -1;
  while (++i < player->y)
  {
    j = -1;
    while (++j < player->x)
    {
      if (player->map[i][j] == 'o' || player->map[i][j] == 'O')
      {
        update_score(player, -1, i, j);
      }
      else if (player->map[i][j] == 'x' || player->map[i][j] == 'X')
      {
        update_score(player, 1, i, j);
      }
      else
      {
        update_score(player, 0, i, j);
      }
    }
  }
  // display(player, 0);
  return ;
}

int main(void)
{
  char *this = NULL;
  char *info = NULL;
  t_player *player = NULL;
  int k;

  k = 1;
  if (get_next_line(0, &this) < 0)
    expletive("before you even started, jesus... \n");
  player = init(this);
  while (1)
  {
    if (!k)
      get_next_line(0, &this);
    dprintf(2, "parsing...\n");
    if (parse(0, this, player) < 0)
      expletive("main\n");
    dprintf(2, "calculating...\n");
    calculate_map(player);
    dprintf(2, "fillering...\n");
    info = ft_strjoin(fill_that_shit(player), "\n");
    dprintf(2, "got info -> %s", info);
    ft_putstr_fd(info, 1);
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
    dprintf(2, "successful frees\n");
    // int i = -1;
    // while (++i < player->y)
      // free(player->map[i]);
    // free(player->map);
    k = 0;
    // ft_bzero(&this, ft_strlen(this));
  }
  if (this)
    free(this);
  if (info)
    free(info);
  if (player)
    free(player);
  return (0);
}
