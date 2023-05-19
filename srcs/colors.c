/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:03:08 by lmedrano          #+#    #+#             */
/*   Updated: 2023/05/19 18:06:24 by lmedrano         ###   ########.fr       */
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

void	render_bg(t_fractal *image, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pixel_put(image, j, i, color);
			j++;
		}
		i++;
	}
}

int	set_colors(int color)
{
	int			baby_blue;
	int			lavender;
	int			pastel_green;

	if (color == 1)
		return (baby_blue = create_trgb(0, 173, 193, 255));
	else if (color == 2)
		return (lavender = create_trgb(0, 218, 187, 255));
	else
		return (pastel_green = create_trgb(0, 201, 237, 191));
}
