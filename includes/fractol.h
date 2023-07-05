/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:38:06 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/05 18:38:08 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 500
# define HEIGHT 500
# define MANDELBROT 1
# define JULIA 2
# define MAX_ITER 100

typedef struct s_fractal
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	double	x;
	double	y;
	double	real;
	double	imgnr;
	double	tmp;
	double	zoom;
	double	c_real;
	double	c_imgnr;
	char	*addr;
	int		set;
	int		j;
	int		n;
	int		i;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
}	t_fractal;

/* PROTOTYPES DE FUNCTIONS */

/* init */
void	init_window(t_fractal *fractal);
void	init_image(t_fractal *fractal);
void	init_hooks(t_fractal *fractal);
void	set_fractal(int set, t_fractal *fractal);

/* colors */
void	color_fractal(t_fractal *fractal, int x, int y, int color);

/* hooks */
int		close_esc(int keycode, t_fractal *fractal);
int		close_btn(t_fractal *fractal);
int		mouse_hook(int keycode, int x, int y, t_fractal *fractal);

/* fractals */
void	fractal_mandelbrot(t_fractal *fractal);
int		mandelbrot_iter(t_fractal *fractal);
void	fractal_julia(t_fractal *fractal);
int		julia_iter(t_fractal *fractal);

/* misc */
int		ft_strcmp(char *s1, char *s2);
void	fractal_typo(void);
void	no_input(void);

#endif
