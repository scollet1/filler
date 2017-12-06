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
  while (player->piece->next)
  {
    if (player->map[i + player->piece->y][j + player->piece->x] == '.' && x <= 1)
    {
      player->piece = player->piece->next;
    }
    else if (player->map[i + player->piece->y][j + player->piece->x] == player->p && x == 0)
    {
      x += 1;
      player->piece = player->piece->next;
    }
    else
    {
      player->piece = player->piece->root;
      return (0);
    }
  }
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
        info = ft_strjoin(ft_itoa(i), ft_strjoin(" ", ft_itoa(j)));
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
  FILE *fp;

  i = -1;
  fp = fopen("log.txt", "w+");
  while (++i < player->y)
  {
    j = -1;
    while (++j < player->x)
    {
      if (player->map_i[i][j] == 0)
      {
        if (fits(player, i, j, 0))
        {
          info = ft_strjoin(ft_itoa(i), ft_strjoin(" ",
          ft_strjoin(ft_itoa(j), "\n")));
          fprintf(fp, "info %s\n", info);
          return (info);
        }
        fprintf(fp, "loopin %d\n", i);
      }
    }
  }
  fclose(fp);
  return (find_option(player));
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
  FILE *fp;

  i = -1;
  fp = fopen("log.txt", "w+");
  player->map_i = (int**)malloc(sizeof(int*)*player->y);
  while (++i < player->y)
    player->map_i[i] = (int*)malloc(sizeof(int)*player->x);
  i = -1;
  fprintf(fp, "loopin %d\n", i);
  while (++i < player->y)
  {
    fprintf(fp, "loopin + 1 %d\n", i);
    j = -1;
    while (++j < player->x)
    {
      fprintf(fp, "loopin + 2 %d\n", j);
      if (player->map[i][j] == 'o' || player->map[i][j] == 'O')
      {
        fprintf(fp, "loopin + 2.1 %d\n", j);
        update_score(player, -1, i, j);
        fprintf(fp, "loopin + 2.2 %d\n", j);
      }
      else if (player->map[i][j] == 'x' || player->map[i][j] == 'X')
      {
        fprintf(fp, "loopin + 2.3 %d\n", j);
        update_score(player, 1, i, j);
        fprintf(fp, "loopin + 2.4 %d\n", j);
      }
      else
      {
        fprintf(fp, "loopin + 2.5 %d\n", j);
        update_score(player, 0, i, j);
        fprintf(fp, "loopin + 2.6 %d\n", j);
      }
      fprintf(fp, "loopin + 3 %d\n", j);
    }
    fprintf(fp, "loopin + 4 %d\n", i);
  }
  fclose(fp);
  return ;
}

int main(void)
{
  char *this = NULL;
  char *info = NULL;
  t_player *player = NULL;
  FILE *fp;

  get_next_line(0, &this);
  player = init(this);
  fp = fopen("log.txt", "w+");
  while (1)
  {
    fprintf(fp, "info %s\n", info);
    if (parse(0, this, player) < 0)
      fucking_crash_and_burn("main\n");
    fprintf(fp, "info + 1 %s\n", info);
    fclose(fp);
    calculate_map(player);
    fp = fopen("log.txt", "w+");
    fprintf(fp, "info + 2 %s\n", info);
    info = fill_that_shit(player);
    fprintf(fp, "info + 3 %s\n", info);
    ft_putstr(info);
    fprintf(fp, "info + 4 %s\n", info);
  }
  fclose(fp);
  if (this)
    free(this);
  if (info)
    free(info);
  if (player)
    free(player);
  return (0);
}
