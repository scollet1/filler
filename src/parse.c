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

#include "incldues/filler.h"

void get_piece(int fd, char* this, t_player player)
{
  int i;
  int j;
  int lt;
  char *s;
  char *tmp;

  i = -1;
  while (++i < player->a)
  {
    if ((lt = get_next_line(fd, &this)) < 0)
      return (-1);
    tmp = ft_strdup(this);
    s = ft_strchr(this, ' ');
    tmp = s;
    player->piece[i] = ft_strdup(tmp);
    ft_bzero(this, ft_strlen(this));
    ft_bzero(tmp, ft_strlen(tmp));
  }
  return ;
}

int parse(int fd, char *this, t_player *player)
{
  int lt;
  char *s;
  int i;
  char *tmp;

  tmp = (char*)malloc(sizeof(char) * ft_strlen(this));
  i = -1;
  lt = get_next_line(fd, &this);
  while (++i < player->y)
  {
    if ((lt = get_next_line(fd, &this)) < 0)
      return (-1);
    tmp = ft_strdup(this);
    s = ft_strchr(this, ' ');
    tmp = s;
    player->map[i] = ft_strdup(tmp);
    ft_bzero(this, ft_strlen(this));
    ft_bzero(tmp, ft_strlen(tmp));
  }
  init_piece(0, this, player);
  get_piece(0, this, player);
  return (0);
}
