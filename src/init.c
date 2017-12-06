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

#include "../includes/filler.h"

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

char which_player(char *this)
{
  if (ft_strstr(this, "filler"))
    return ((ft_strstr(this, "p1") ? 'O' : 'X'));
  return ('\0');
}

t_player *init(char *this)
{
  int i;
  int j;
  char *s = NULL;
  t_player *player;

  player = (t_player*)malloc(sizeof(t_player));
  if (!(player->p = which_player(this)))
    fucking_crash_and_burn("init\n");
  get_next_line(0, &this);
  s = ft_strchr(this, ' ');
  i = ft_atoi(s) + 1;
  player->y = i - 1;
  while (ft_isdigit(*s++));
  this = s;
  s = ft_strchr(this, ' ');
  j = ft_atoi(s);
  player->x = j;
  player->map = (char**)malloc(sizeof(char*)*player->y);
  while (--j >= 0)
    player->map[j] = (char*)malloc(sizeof(char)*player->x);
  return (player);
}

int init_piece(int fd, char *this, t_player *player)
{
  int lt;
  char *s;
  int i;
  int j;

  if ((lt = get_next_line(fd, &this)) < 0)
    return (-1);
  // ft_putstr("12 14\n");
  s = ft_strchr(this, ' ');
  i = ft_atoi(s) + 1;
  player->b = i - 1;
  while (ft_isdigit(*s++));
  this = s;
  s = ft_strchr(this, ' ');
  j = ft_atoi(s);
  player->a = j;
  player->piece = (struct s_piece*)malloc(sizeof(struct s_piece));
  return (0);
}
