/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 21:43:32 by cbouvet           #+#    #+#             */
/*   Updated: 2014/09/07 23:02:31 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		solve(int pos, int *tab, int *solved);
int		verifcase(int pos, int *tab, int *solved);
int		position(int pos, int *tab, int value);
int		verifcarre(int pos, int *tab, int value);
void	tabcopy(int *tab, int *solved);

int		solve(int pos, int *tab, int *solved)
{
	if (pos == 81)
	{
		if (*solved == 0)
		{
			tabcopy(tab, solved);
			if (solve(pos, tab, solved))
				return (0);
		}
		return (1);
	}
	if (verifcase(pos, tab, solved))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		verifcase(int pos, int *tab, int *solved)
{
	int		value;

	value = 1;
	if (tab[pos] == 0)
	{
		while (value++ <= 9)
		{
			if (position(pos, tab, value - 1))
			{
				tab[pos] = value - 1;
				if (solve(pos + 1, tab, solved))
					return (1);
			}
		}
		tab[pos] = 0;
	}
	else
	{
		if (position(pos, tab, tab[pos]))
		{
			if (solve(pos + 1, tab, solved))
				return (1);
		}
	}
	return (0);
}

int		position(int pos, int *tab, int value)
{
	int		a;
	int		b;
	int		b2;
	int		a2;

	a2 = pos % 9;
	b2 = pos / 9;
	b = 0;
	a = 0;
	while (b < 9)
	{
		if (tab[b2 * 9 + b] == value && b != a2)
			return (0);
		b++;
	}
	while (a < 9)
	{
		if (tab[a * 9 + a2] == value && a != b2)
			return (0);
		a++;
	}
	return (verifcarre(pos, tab, value));
}

int		verifcarre(int pos, int *tab, int value)
{
	int		i;
	int		b2;
	int		a2;
	int		cur_a;
	int		cur_b;

	b2 = pos % 9 / 3;
	a2 = pos / 9 / 3;
	i = 0;
	while (i < 81)
	{
		if (tab[i] == value && i != pos)
		{
			cur_a = i % 9 / 3;
			cur_b = i / 9 / 3;
			if (b2 == cur_a && a2 == cur_b)
				return (0);
		}
		i++;
	}
	return (1);
}

void	tabcopy(int *tab, int *solved)
{
	int		i;

	i = 80;
	while (i >= 0)
	{
		solved[i] = tab[i];
		i--;
	}
}
