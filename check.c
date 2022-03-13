/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:40:34 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/03/12 21:10:22 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall_up(char **s)
{
	int	j;

	j = 0;
	while (s[0][j])
	{
		if (s[0][j] != '1')
			error_wall();
		j++;
	}
}

void	checker_wall(char **s)
{
	t_img	t;

	t.i = 0;
	check_wall_up(s);
	while (s[++t.i])
	{
		t.j = 0;
		if (s[t.i][t.j] != '1')
			error_wall();
		while (s[t.i][t.j])
		{
			if (s[t.i + 1] == NULL && s[t.i][t.j] != '1')
				error_wall();
			else if (s[t.i][t.j + 1] == '\0' && s[t.i][t.j] != '1')
				error_wall();
			t.j++;
		}
	}
}

void	ft_error(t_check *check)
{
	if (check->p != 1 || check->c < 1 || check->e < 1)
	{
		write(2, "no chaaar\n", 10);
		exit(1);
	}
}

void	check_char(t_check *check)
{
	while (check->str[check->i][check->j])
	{
		if (check->str[check->i][check->j] != '0' \
		&& check->str[check->i][check->j] != '1' \
		&& check->str[check->i][check->j] != 'P' \
		&& check->str[check->i][check->j] != 'E' \
		&& check->str[check->i][check->j] != 'C')
		{
			write(2, "no char\n", 8);
			exit(1);
		}
		if (check->str[check->i][check->j] == 'P')
			check->p++;
		if (check->str[check->i][check->j] == 'C')
			check->c++;
		if (check->str[check->i][check->j] == 'E')
			check->e++;
		check->j++;
	}
}

void	check_pce(char **str)
{
	t_check	check;

	check.str = str;
	check.i = 0;
	check.c = 0;
	check.e = 0;
	check.p = 0;
	while (check.str[check.i])
	{
		check.j = 0;
		check_char(&check);
		check.i++;
	}
	ft_error(&check);
}
