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
  t_piece *next;
  t_piece *previous;
  t_piece *root;
} t_piece;

typedef struct s_player {
  int x, y;
  int a, b;
  char **map;
  int **map_i;
  t_piece *piece;
} t_player;

void      fucking_crash_and_burn(char *loc);
void      get_piece(int fd, char* this, t_player player);
t_player  *init(char *this);
void      init_piece(int fd, char* this, t_player player);
t_player  *make_player();
int       parse(int fd, char *this, t_player *player);

#endif
