/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acieux <acieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 09:56:12 by acieux            #+#    #+#             */
/*   Updated: 2014/09/15 16:33:04 by acieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int		main(void)
{
	rectangle(30, 25);
	return (0);
}

/*
** exemple de main avec recuperation d'argument pour generer le rectangle et 
** appliquer les valeurs voulues
int	main(int argc, char **argv)
{
  int	i;
  char	**stock;
  int	tab[8];
  int	fd;

  i = 8;
  while (i > 0)
    tab[i--] = 0;
  fd = x_open(argv[1], O_RDONLY);
  SIZE = x_getnbr(next_line(fd, 0, 1));
  if (SIZE == 0)
    error();
  if (SIZE == 1)
    single_line(next_line(fd, 0, 1));
  stock = x_malloc(SIZE * sizeof(char *) + 1);
  stockage(stock, tab, fd, argc > 2 ? 1 : 0);
  return (0);
}
*/