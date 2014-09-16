/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltournie <ltournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 07:42:53 by ltournie          #+#    #+#             */
/*   Updated: 2014/09/14 08:04:16 by ltournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"colle02.h"

void	ft_aff_nbr(int nb)
{
	if (nb >= 10)
	{
		ft_aff_nbr(nb / 10);
		ft_aff_nbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	ft_aff_nbr(nb);
}
