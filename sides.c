/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sides.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:02:12 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/03/12 22:35:48 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_img *t)
{
	if (t->str[t->y][t->x + 1] != 'E' || \
	(t->str[t->y][t->x + 1] == 'E' && t->counter == 0))
	{
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->bkgrnd, \
		t->x * 50, t->y * 50);
		t->x++;
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->bkgrnd, \
		t->x * 50, t->y * 50);
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->right, \
		t->x * 50, t->y * 50);
		ft_putnbr(t->moove++);
		write(1, "\n", 1);
	}
}

void	left(t_img *t)
{
	if (t->str[t->y][t->x - 1] != 'E' || \
	(t->str[t->y][t->x - 1] == 'E' && t->counter == 0))
	{
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->bkgrnd, \
		t->x * 50, t->y * 50);
		t->x--;
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->bkgrnd, \
		t->x * 50, t->y * 50);
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->left, \
		t->x * 50, t->y * 50);
		ft_putnbr(t->moove++);
		write(1, "\n", 1);
	}
}

void	front(t_img *t)
{
	if (t->str[t->y + 1][t->x] != 'E' || \
	(t->str[t->y + 1][t->x] == 'E' && t->counter == 0))
	{
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->bkgrnd, \
		t->x * 50, t->y * 50);
		t->y++;
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->bkgrnd, \
		t->x * 50, t->y * 50);
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->front, \
		t->x * 50, t->y * 50);
		ft_putnbr(t->moove++);
		write(1, "\n", 1);
	}
}

void	back(t_img *t)
{
	if (t->str[t->y - 1][t->x] != 'E' || \
	(t->str[t->y - 1][t->x] == 'E' && t->counter == 0))
	{
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->bkgrnd, \
		t->x * 50, t->y * 50);
		t->y--;
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->bkgrnd, \
		t->x * 50, t->y * 50);
		mlx_put_image_to_window(t->pmlx, t->win_ptr, t->back, \
		t->x * 50, t->y * 50);
		ft_putnbr(t->moove++);
		write(1, "\n", 1);
	}
}
