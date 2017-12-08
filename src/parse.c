/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:23:47 by scollet           #+#    #+#             */
/*   Updated: 2017/12/04 14:23:51 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int get_piece(int fd, char* this, t_player *player)
{
  int i;
  int j;
  int lt;
  char *tmp;
  int fuck;
  t_piece *root;

  i = -1;
  fuck = 0;
  root = player->piece;
  while (++i < player->b)
  {
    if ((lt = get_next_line(fd, &this)) < 0)
      return (-1);
    else if (lt == 0)
      break ;
    tmp = ft_strdup(this);
    j = -1;
    while (++j < player->a)
    {
      // dprintf(2, "temporary -> %s\n", tmp);
      if (*tmp++ == '*')
      {
        fuck += 1;
        player->piece->x = j;
        player->piece->y = i;

        // dprintf(2, "x, y -> %d, %d\nj, i, -> %d, %d\n",
        // player->piece->x,
        // player->piece->y,
        // j, i);

        player->piece->next = (struct s_piece*)malloc(sizeof(struct s_piece));
        player->piece->next->previous = player->piece;
        // player->piece->next->root = (struct s_piece*)malloc(sizeof(struct s_piece));
        // player->piece->next->root = player->piece->root;
        player->piece = player->piece->next;
        player->piece->next = NULL;
      }
    }
  }
  // dprintf(2, "what the fuquke -> %d\n", fuck);
  player->piece->previous = NULL;
  // dprintf(2, "playa k -> %d\n", player->piece->y);
  // while (player->piece->previous)
    // player->piece = player->piece->previous;
  // player->piece->next = NULL;
  player->piece = root;
  // dprintf(2, "fugging OMG y, x -> %d, %d\n", player->piece->y, player->piece->x);
  return (0);
}

/*
Parse the map;
*/

int parse(int fd, char *this, t_player *player)
{
  int lt;
  char *s;
  int i;
  int j;
  char *tmp;

  i = -1;
  if (get_next_line(fd, &this) < 0)
    return (-1);
  dprintf(2, "parsed\n");
  tmp = (char*)malloc(sizeof(char) * ft_strlen(this));
  dprintf(2, "malloced\n");
  while (++i < player->y)
  {
    j = -1;
    if ((lt = get_next_line(fd, &this)) < 0)
      return (-1);
    tmp = ft_strdup(this);
    s = ft_strchr(this, ' ');
    tmp = s;
    while (++j < player->x)
      player->map[i][j] = *++tmp;
  }
  if (init_piece(0, this, player) < 0)
    expletive("parse\n");
  if (get_piece(0, this, player) < 0)
    expletive("parse\n");
  return (lt);
}
