/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 21:42:29 by cbouvet           #+#    #+#             */
/*   Updated: 2014/09/07 22:30:59 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		solution1(int *solution);
void	table(int argc, char **argv);
void	translate_strings();
int		solve(int pos, int *tab, int *solved);
int		error(int argc, char **argv);

void	table(int argc, char **argv)
{
	int		arcount;
	int		compteur;
	int		cnt_line;
	int		tab_nbr[81];
	int		solved[81];

	arcount = 1;
	compteur = 0;
	cnt_line = 0;
	while (arcount < argc)
	{
		while (argv[arcount][compteur] != '\0')
		{
			if (argv[arcount][compteur++] == '.')
				tab_nbr[cnt_line++] = 0;
			else
				tab_nbr[cnt_line++] = argv[arcount][compteur - 1] - '0';
		}
		arcount++;
		compteur = 0;
	}
	if (!solve(0, tab_nbr, solved) && *solved)
		solution1(solved);
	else
		write(1, "Erreur\n", 7);
}

int		solution1(int *solution)
{
	int		compteur;
	int		ascii;

	compteur = 0;
	while (compteur < 81)
	{
		if (compteur % 9)
		{
			write(1, " ", 1);
		}
		else if (compteur > 1)
			write(1, "\n", 1);
		ascii = solution[compteur] + 48;
		write(1, &ascii, 1);
		compteur++;
	}
	write(1, "\n", 1);
	return (0);
}

int		error(int argc, char **argv)
{
	int		arcount;
	int		compteur;

	arcount = 1;
	compteur = 0;
	while (arcount < argc)
	{
		while (argv[arcount][compteur] != '\0')
		{
			if ((argv[arcount][compteur] >= '1'
				&& argv[arcount][compteur] <= '9')
				|| (argv[arcount][compteur] == '.'))
				compteur++;
			else
				return (0);
		}
		if (compteur != 9)
			return (0);
		compteur = 0;
		arcount++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if ((argc == 10) && error(argc, argv))
		table(argc, argv);
	else
		write(1, "Erreur\n", 7);
	return (0);
}
