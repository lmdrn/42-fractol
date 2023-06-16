/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:03:08 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/16 17:15:41 by lmedrano         ###   ########.fr       */
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
	mandelbrot_init(image);
	mandelbrot(image);
}

void	render_julia(t_fractal *image)
{
	julia_init(image);
	julia(image);
}

int	set_colors(int color)
{
	int			white;
	int			lavender;
	int			lavender2;
	int			lavender3;
	int			black;

	if (color == 1)
		return (lavender = create_trgb(200, 218, 187, 255));
	else if (color == 2)
		return (lavender2 = create_trgb(100, 218, 187, 255));
	else if (color == 3)
		return (lavender3 = create_trgb(0, 218, 187, 255));
	else if (color == 4)
		return (white = create_trgb(0, 255, 255, 255));
	else if (color == 5)
		return (black = create_trgb(0, 0, 0, 0));
	else
		return (0);
}
