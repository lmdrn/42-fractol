/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:57:43 by lmedrano          #+#    #+#             */
/*   Updated: 2023/05/19 18:06:51 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH 500
# define HEIGHT 500

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"

typedef struct s_complex
{
	double	real;
	double	imgnr;
}		t_complex;

typedef struct s_fractal
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	max_iter;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
}		t_fractal;

/* PROTOTYPES DE FUNCTIONS */

/* colors */
int		create_trgb(int t, int r, int g, int b);
void	img_pixel_put(t_fractal *image, int x, int y, int color);
void	render_bg(t_fractal *image, int color);
int		set_colors(int color);

/* hooks */
int		close_esc(int keycode, t_fractal *fractal);
int		close_btn(t_fractal *fractal);

#endif
