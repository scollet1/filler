/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:35:24 by scollet           #+#    #+#             */
/*   Updated: 2017/12/01 15:35:25 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_piece {
  int x, y;
  struct s_piece *next;
  struct s_piece *previous;
} t_piece;

typedef struct s_player {
  int x, y;
  int a, b;
  char p;
  char q;
  int zy;
  int zx;
  int co_y;
  int co_x;
  char **map;
  int **map_i;
  t_piece *piece;
} t_player;

int       update_p_z(t_player *player, int i, int j);
void      expletive(char *loc);
int      fatal_flying_guillotine(t_player *player);
char      *fill_that_shit(t_player *player);
char      *find_option(t_player *player);
int       fits(t_player *player, int i, int j, int x);
int       get_piece(int fd, char* this, t_player *player);
t_player  *init(char *this);
void    init_map_i(t_player *player);
int       init_piece(int fd, char* this, t_player *player);
t_player  *make_player();
int       parse(int fd, char *this, t_player *player);

#endif
