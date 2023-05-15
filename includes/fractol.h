/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:57:43 by lmedrano          #+#    #+#             */
/*   Updated: 2023/05/12 15:07:11 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH 500
# define HEIGHT 500

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "../mlx/mlx.h"
/* #include <stdint.h> */
/* #include <string.h> */
/* #include <inttypes.h> */

typedef struct s_complex
{
	double	real;
	double	imgnr;
}		t_complex;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_image;

typedef struct s_fractal
{
	void		*mlx;
	void		*mlx_win;
	t_image		image;
	unsigned int	max_iter;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	char		julia_block;
	unsigned char	color_shift;
	unsigned char	bright_shift;
	unsigned int	((*formula)(struct	s_fractal *fractal));
}		t_fractal;

#endif
