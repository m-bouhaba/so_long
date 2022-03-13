/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:23:51 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/03/12 21:09:34 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_img{
	int		wdt;
	int		x;
	int		y;
	int		higt;
	void	*front;
	void	*back;
	void	*left;
	void	*right;
	void	*barre;
	void	*bkgrnd;
	void	*egg;
	void	*porte;
	void	*pmlx;
	void	*win_ptr;
	char	**str;
	int		counter;
	int		i;
	int		j;
	int		a;
	int		b;
	int		moove;
}	t_img;

typedef struct s_check
{
	int		i;
	int		j;
	int		p;
	int		e;
	int		c;
	char	**str;
}	t_check;

void	check_extention(char *str);
char	**read_map(char *str);
void	check_forme(char **str);
void	checker_wall(char **s);
void	check_pce(char **str);
int		key_press(int key, t_img *t);
void	rassma(char **str);
int		ft_strlen(char *str);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *src);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strrchr(const char *s, int c);
char	*get_next_line(int fd);
void	right(t_img *t);
void	left(t_img *t);
void	back(t_img *t);
void	front(t_img *t);
void	draw_map(t_img *t);
void	darwing(t_img *t);
int		exit_mouse(void);
void	ft_putnbr(int nbr);
void	error_wall(void);

#endif