/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:03:34 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/03/12 21:06:24 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_mouse(void)
{
	printf("EXIT\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int key, t_img *t)
{
	if ((key == 124 || key == 2) && (t->str[t->y][t->x + 1] != '1'))
		right(t);
	else if ((key == 123 || key == 0) && (t->str[t->y][t->x - 1] != '1'))
		left(t);
	else if ((key == 125 || key == 1) && (t->str[t->y + 1][t->x] != '1'))
		front(t);
	else if ((key == 126 || key == 13) && (t->str[t->y - 1][t->x] != '1'))
		back(t);
	if (t->str[t->y][t->x] == 'C')
	{
		t->str[t->y][t->x] = '0';
		t->counter--;
	}
	if (t->counter == 0 && (t->str[t->y][t->x] == 'E'))
		exit(0);
	if (key == 53)
		exit(0);
	return (0);
}

void	darwing(t_img *t)
{
	mlx_put_image_to_window(t->pmlx, t->win_ptr, t->bkgrnd, \
	t->j * 50, t->i * 50);
	if (t->str[t->i][t->j] == '1')
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->barre, \
		t->j * 50, t->i * 50);
	else if (t->str[t->i][t->j] == 'C')
	{
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->egg, \
		t->j * 50, t->i * 50);
		t->counter++;
	}
	else if (t->str[t->i][t->j] == 'E')
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->porte, \
		t->j * 50, t->i * 50);
	else if (t->str[t->i][t->j] == 'P')
	{
		mlx_put_image_to_window(t->pmlx, t->win_ptr, \
		t->front, t->j * 50, t->i * 50);
		t->x = t->j;
		t->y = t->i;
	}
}

void	draw_map(t_img *t)
{
	t->i = 0;
	while (t->str[t->i])
	{
		t->j = 0;
		while (t->str[t->i][t->j])
		{
			darwing(t);
			t->j++;
		}
		t->i++;
	}
}
