/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 04:29:19 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/03/12 21:06:35 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *str)
{
	char	*s;
	int		fd;
	char	**splited;
	char	*new;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	s = get_next_line(fd);
	new = ft_strdup("");
	while (s)
	{
		new = ft_strjoin(new, s);
		free (s);
		s = get_next_line(fd);
	}
	splited = ft_split(new, '\n');
	free (new);
	return (splited);
}

void	rassma(char **str)
{	
	t_img	t;

	t.str = str;
	t.moove = 1;
	t.i = 0;
	t.counter = 0;
	t.a = ft_strlen(str[0]);
	while (str[t.i])
		t.i++;
	t.b = t.i;
	t.pmlx = mlx_init();
	t.win_ptr = mlx_new_window(t.pmlx, t.a * 50, t.b * 50, "window");
	t.front = mlx_xpm_file_to_image(t.pmlx, "./xpm/front.xpm", &t.wdt, &t.higt);
	t.back = mlx_xpm_file_to_image(t.pmlx, "./xpm/back.xpm", &t.wdt, &t.higt);
	t.left = mlx_xpm_file_to_image(t.pmlx, "./xpm/left.xpm", &t.wdt, &t.higt);
	t.right = mlx_xpm_file_to_image(t.pmlx, "./xpm/right.xpm", &t.wdt, &t.higt);
	t.barre = mlx_xpm_file_to_image(t.pmlx, "./xpm/barre.xpm", &t.wdt, &t.higt);
	t.bkgrnd = mlx_xpm_file_to_image(t.pmlx, "./xpm/lard.xpm", &t.wdt, &t.higt);
	t.egg = mlx_xpm_file_to_image(t.pmlx, "./xpm/bonbon.xpm", &t.wdt, &t.higt);
	t.porte = mlx_xpm_file_to_image(t.pmlx, "./xpm/porte.xpm", &t.wdt, &t.higt);
	draw_map(&t);
	mlx_hook (t.win_ptr, 02, 1L << 0, key_press, &t);
	mlx_hook (t.win_ptr, 17, 0L, exit_mouse, NULL);
	mlx_loop(t.pmlx);
}

int	main(int ac, char **av)
{
	char	**s;

	if (ac == 2)
	{
		check_extention(av[1]);
		s = read_map(av[1]);
		check_forme(s);
		checker_wall(s);
		check_pce(s);
		rassma(s);
	}
}
