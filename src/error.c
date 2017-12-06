/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:09:02 by scollet           #+#    #+#             */
/*   Updated: 2017/12/04 14:09:03 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void fucking_crash_and_burn(char *loc)
{
  perror("Something happened...\n\
          It was bad.");
  perror(loc);
  exit(-1);
}
