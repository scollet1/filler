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
  int f;
  int lt;
  char *s;
  int offx;
  int offy;
  char *tmp;
  // FILE *fp;

  i = -1;
  f = 0;
  // fp = fopen("log.txt", "w+");
  // fprintf(fp, "this %s\n", this);
  while (++i < player->b)
  {
    if ((lt = get_next_line(fd, &this)) < 0)
      return (-1);
    // fprintf(fp, "this + 1 %s\n", this);
    tmp = ft_strdup(this);
    // fprintf(fp, "this + 2 %s\n", this);
    s = ft_strchr(this, ' ');
    // tmp = s;
    j = -1;
    // fprintf(fp, "tmp %s\n", tmp);
    // fprintf(fp, "s %s\n", s);
    // ft_putstr("12 14\n");
    while (++j < player->a)
    {
      // fprintf(fp, "stuff %c, %s\n", *tmp, tmp);
      if (*tmp++ == '*')
      {
        // fprintf(fp, "this + 3.1 %s\n", this);
        if (!f)
        {
          // fprintf(fp, "this + 3.2 %s\n", this);
          offx = j;
          offy = i;
          f = 1;
        }
        // fprintf(fp, "this + 4 %s\n", this);
        player->piece->x = j - offx;
        player->piece->y = i - offy;
        player->piece->next = (struct s_piece*)malloc(sizeof(struct s_piece));
        player->piece->next->previous = player->piece;
        player->piece->next->root = player->piece->root;
        player->piece = player->piece->next;
        player->piece->next = NULL;
        // ft_putstr("12 14\n");
      }
      // fprintf(fp, "this + 5 %s\n", this);
    }
    // ft_putstr("12 14\n");
    // ft_bzero(this, ft_strlen(this));
    // ft_bzero(tmp, ft_strlen(tmp));
  }
  // fprintf(fp, "this + 6 %s\n", this);
  // fclose(fp);
  return (0);
}

int parse(int fd, char *this, t_player *player)
{
  int lt;
  char *s;
  int i;
  char *tmp;
  // FILE *fp;

  // fp = fopen("log.txt", "w+");
  i = -1;
  // fprintf(fp, "this %s\n", this);
  lt = get_next_line(fd, &this);
  tmp = (char*)malloc(sizeof(char) * ft_strlen(this));
  while (++i < player->y)
  {
    if ((lt = get_next_line(fd, &this)) < 0)
    {
      // fprintf(fp, "lt %d\n", lt);
      return (lt);
    }
    // fprintf(fp, "this + 1 %s\n", this);
    tmp = ft_strdup(this);
    s = ft_strchr(this, ' ');
    tmp = s;
    // ft_putstr("12 14\n");
    player->map[i] = ft_strdup(tmp);
    // fprintf(fp, "this + 3 %s\n", this);
    // ft_bzero(this, ft_strlen(this));
    // ft_bzero(tmp, ft_strlen(tmp));
    // ft_putstr("12 14\n");
    // if (tmp)
      // free(tmp);
  }
  // ft_putstr("12 14\n");
  // fprintf(fp, "this + 4 %s\n", this);
  init_piece(0, this, player);
  // fprintf(fp, "this + 5 %s\n", this);
  // fclose(fp);
  // ft_putstr("12 14\n");
  get_piece(0, this, player);
  // fprintf(fp, "this + 6 %s\n", this);
  // ft_putstr("12 14\n");
  // fclose(fp);
  return (0);
}
