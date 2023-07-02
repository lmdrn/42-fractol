/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:57:43 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/02 15:01:26 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH 500
# define HEIGHT 500
# define MANDELBROT 1
# define JULIA 2

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"

/* typedef struct s_complex */
/* { */
/* 	double	real; */
/* 	double	imgnr; */
/* }		t_complex; */

/* typedef struct s_color */
/* { */
/* 	unsigned int	r; */
/* 	unsigned int	g; */
/* 	unsigned int	b; */
/* 	unsigned int	t; */
/* }		t_color; */

typedef struct s_fractal
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				x;
	int				y;
	unsigned int	max_iter;
	double			min_real;
	double			max_real;
	double			min_imgnr;
	double			max_imgnr;
	double			c_real;
	double			c_imgnr;
	double			k_real;
	double			k_imgnr;
	double			factor_real;
	double			factor_imgnr;
	int				set;
	int				color_r;
	int				color_g;
	int				color_b;
	double			zoom;
}		t_fractal;

/* PROTOTYPES DE FUNCTIONS */

/* init */
void	init_window(int fractal, t_fractal *image);

/* colors */
int		create_trgb(int t, int r, int g, int b);
void	img_pixel_put(t_fractal *image, int x, int y, int color);
void	render(t_fractal *image);
int		set_colors(int color);
int		rgb_to_int(unsigned int count, t_fractal *fractal);

/* hooks */
int		close_esc(int keycode, t_fractal *fractal);
int		close_btn(t_fractal *fractal);
int		mouse_hook(int keycode, int x, int y, t_fractal *fractal);

/* fractals */
void	fractal(t_fractal *fractal, int set);
void	mandelbrot_init(t_fractal *fractal);
void	mandelbrot_iter(t_fractal *fractal,
			double z_real, double z_imgnr);
void	julia_init(t_fractal *fractal);
void	julia_iter(t_fractal *fractal, double z_real, double z_imgnr);

#endif
