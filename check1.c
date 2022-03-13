/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:27:55 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/03/11 22:28:41 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extention(char *str)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strrchr(str, '.');
	if (!s)
	{
		printf("No extention");
		exit(1);
	}
	if (ft_strncmp(s, ".ber", 4) != 0 || ft_strlen(s) != 4)
	{
		printf("Wrong extention");
		exit(1);
	}
}

void	check_forme(char **str)
{
	int	i;
	int	k;
	int	j;

	i = ft_strlen(str[0]);
	j = 1;
	while (str[j])
	{
		k = ft_strlen(str[j]);
		if (k != i)
		{
			write(2, "Not a rectangle\n", 17);
			exit (1);
		}
		j++;
	}
}

void	error_wall(void)
{
	write (2, "ERROR : Wall\n", 13);
	exit (1);
}
