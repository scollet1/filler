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

/*
Initialize player;
*/

t_player  *make_player()
{
  t_player *new_player;

  new_player = (t_player*)malloc(sizeof(t_player));
  return (new_player);
}

/*
Determine which player;
*/

char which_player(char *this)
{
  if (ft_strstr(this, "filler"))
    return ((ft_strstr(this, "p1") ? 'O' : 'X'));
  return ('\0');
}

/*
Initialize a board of variable size;
*/

t_player *init(char *this)
{
  int i;
  int j;
  char *s = NULL;
  t_player *player;

  player = (t_player*)malloc(sizeof(t_player));
  if (!(player->p = which_player(this)))
    expletive("init\n");
  else
    player->q = player->p + 32;
  player->z = (player->p == 'X') ? 1 : -1;
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
  while (--i >= 0)
    player->map[i] = (char*)malloc(sizeof(char)*player->x);
  return (player);
}

/*
Initialize a piece of variable size;
*/

int init_piece(int fd, char *this, t_player *player)
{
  int lt;
  char *s;
  int i;
  int j;

  if ((lt = get_next_line(fd, &this)) < 0)
    return (-1);
  dprintf(2, "piece before strch -> %s\n", this);
  s = ft_strchr(this, ' ');
  dprintf(2, "piece after strch -> %s\n", s);
  i = ft_atoi(s);
  dprintf(2, "y dim -> %d\n", i);
  player->b = i;
  while (ft_isdigit(*s++));
  this = s;
  s = ft_strchr(this, ' ');
  j = ft_atoi(s);
  player->a = j;
  player->piece = (struct s_piece*)malloc(sizeof(struct s_piece));
  player->piece->next = NULL;
  player->piece->previous = NULL;
  // player->piece->root = (struct s_piece*)malloc(sizeof(struct s_piece));
  // player->piece->root = player->piece;
  // player->root = (struct s_piece*)malloc(sizeof(struct s_piece));
  // player->root = player->piece;
  return (0);
}
