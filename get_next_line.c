/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:16:27 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/03/11 21:27:17 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_before_line(char *s)
{
	int	i;

	if (!s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (ft_substr(s, 0, i + 1));
}

char	*ft_after_line(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			str = ft_substr(s, i + 1, ft_strlen(s));
			free (s);
			return (str);
		}
		i++;
	}
	free (s);
	return (NULL);
}

char	*ft_getline(int fd, char *a)
{
	char	*str;
	int		t;

	str = malloc (1);
	t = 1;
	while (!check_line(a) && t)
	{
		t = read(fd, str, 1);
		if (t == -1)
		{
			free(str);
			return (NULL);
		}
		str[t] = '\0';
		a = ft_strjoin(a, str);
	}
	free(str);
	return (a);
}

char	*get_next_line(int fd)
{
	static char	*red;
	char		*l;

	if (fd < 0)
		return (NULL);
	red = ft_getline(fd, red);
	if (!red)
		return (NULL);
	l = ft_before_line (red);
	red = ft_after_line(red);
	return (l);
}
