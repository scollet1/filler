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

#include "filler.h"

t_player make_player()
{
  t_player new_player;

  new_player = (t_player*)malloc(sizeof(t_player));
  return (new_player);
}

char **parse(int **board, const int fd)
{
  int i;
  int j;
  int size;

  get_next_line(const int fd, char **board);
  return (board);
}

int main(int ac, char **av)
{
  char **board;
  t_player player;

  if (ac == 1)
  {
    player = make_player();
    while (1)
    {
      parse(1, board);
      make_player(player);
      fill_that_shit(board, player);
    }
  }
  if (board)
    free(baord);
  if (player)
    free(player);
  return (0);
}
