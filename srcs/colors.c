/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:03:08 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/09 15:40:24 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
/* convert colors from rgb to hexadecimal */
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/* endian == 0 means we are in Little Endian LSB */
/* endian != 0 means we are in Big Endian MSB */
void	img_pixel_put(t_fractal *image, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = image->bits_per_pixel - 8;
	pixel = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (image->endian != 0)
			*pixel = (color >> i) & 0xFF;
		else
			*pixel = (color >> (image->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
		pixel++;
	}
}

void	render_mandelbrot(t_fractal *image)
{
	/* y = 0; */
	mandelbrot_init(image);
	/* while (y < HEIGHT) */
	/* { */
	/* 	x = 0; */
	/* 	while (x < WIDTH) */
	/* 	{ */
			mandelbrot(image);
			/* x++; */
		/* } */
		/* y++; */
	/* } */
}

int	set_colors(int color)
{
	int			baby_blue;
	int			lavender;
	int			white;
	int			pastel_green;

	if (color == 1)
		return (baby_blue = create_trgb(0, 173, 193, 255));
	else if (color == 2)
		return (lavender = create_trgb(0, 218, 187, 255));
	else if (color == 3)
		return (white = create_trgb(0, 255, 255, 255));
	else
		return (pastel_green = create_trgb(0, 201, 237, 191));
}
