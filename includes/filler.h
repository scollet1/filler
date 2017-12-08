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
  // struct s_piece *root;
} t_piece;

typedef struct s_player {
  int x, y;
  int a, b;
  char p;
  char q;
  int z;
  char **map;
  int **map_i;
  // t_piece *root;
  t_piece *piece;
} t_player;

void      expletive(char *loc);
int       get_piece(int fd, char* this, t_player *player);
t_player  *init(char *this);
int       init_piece(int fd, char* this, t_player *player);
t_player  *make_player();
int       parse(int fd, char *this, t_player *player);

#endif
