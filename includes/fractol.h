/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:57:43 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/16 17:24:12 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH 500
# define HEIGHT 500

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"

typedef struct s_complex
{
	double	real;
	double	imgnr;
}		t_complex;

typedef struct s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}		t_color;

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
	int				is_in;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	t_color			color;
}		t_fractal;

/* PROTOTYPES DE FUNCTIONS */

/* colors */
int		create_trgb(int t, int r, int g, int b);
void	img_pixel_put(t_fractal *image, int x, int y, int color);
void	render_mandelbrot(t_fractal *image);
void	render_julia(t_fractal *image);
int		set_colors(int color);

/* hooks */
int		close_esc(int keycode, t_fractal *fractal);
int		close_btn(t_fractal *fractal);
int		mouse_hook(int mouse_code);

/* fractals */
void	mandelbrot_init(t_fractal *fractal);
void	mandelbrot(t_fractal *fractal);
void	mandelbrot_iter(t_fractal *fractal, double z_real, double z_imgnr);
void	julia_init(t_fractal *fractal);
void	julia(t_fractal *fractal);
void	julia_iter(t_fractal *fractal, double z_real, double z_imgnr);

#endif
