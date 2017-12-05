/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:24:30 by scollet           #+#    #+#             */
/*   Updated: 2017/12/04 14:24:32 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

t_player  *make_player()
{
  t_player *new_player;

  new_player = (t_player*)malloc(sizeof(t_player));
  new_player->piece = (t_piece*)malloc(sizeof(t_piece));
  new_player->piece->next = NULL;
  new_player->piece->previous = NULL;
  new_player->piece->root = new_player->piece;
  return (new_player);
}

t_player *init(char *this)
{
  int i;
  int j;
  char *s = NULL;
  t_player *player;

  player = (t_player*)malloc(sizeof(t_player));
  get_next_line(0, &this);
  s = ft_strchr(this, ' ');
  i = ft_atoi(s) + 1;
  player->x = i - 1;
  while (ft_isdigit(*s++));
  this = s;
  s = ft_strchr(this, ' ');
  j = ft_atoi(s);
  player->y = j;
  player->map = (char**)malloc(sizeof(char*)*player->y);
  while (--i >= 0)
    player->map[i] = (char*)malloc(sizeof(char)*player->x);
  return (player);
}

void init_piece(int fd, char* this, t_player player)
{
  int lt;
  char *s;
  int i;
  int j;

  if ((lt = get_next_line(fd, &this)) < 0)
    return (NULL);
  s = ft_strchr(this, ' ');
  i = ft_atoi(s) + 1;
  player->a = i - 1;
  while (ft_isdigit(*s++));
  this = s;
  s = ft_strchr(this, ' ');
  j = ft_atoi(s);
  player->b = j;
  player->piece = (char**)malloc(sizeof(char*)*player->b);
  while (--i >= 0)
    player->piece[i] = (char*)malloc(sizeof(char)*player->a);
  return ;
}
