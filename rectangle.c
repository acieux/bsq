/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acieux <acieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 09:52:45 by acieux            #+#    #+#             */
/*   Updated: 2014/09/15 16:31:17 by acieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	which(int x, int xx, int y, int yy)
{
	if (x == 0 || y == 0 || x == (xx - 1) || y == (yy - 1))
		ft_putchar('.');
	else
		ft_putchar('.');
}

void	rectangle(int xx, int yy)
{
	int		x;
	int		y;

	if (xx <= 0 || yy <= 0)
		return ;
	y = 0;
	while (y < yy)
	{
		x = 0;
		while (x < xx)
		{
			which(x, xx, y, yy);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
