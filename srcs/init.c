/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:10:29 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/17 18:22:44 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_window(int fractal)
{
	t_fractal	image;

	image.mlx = mlx_init();
	image.mlx_win = mlx_new_window(image.mlx, WIDTH, HEIGHT, "FRACT'OL");
	image.img = mlx_new_image(image.mlx, WIDTH, HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	if (fractal == 1)
		render_mandelbrot(&image);
	else if (fractal == 2)
		render_julia(&image);
	mlx_put_image_to_window(image.mlx, image.mlx_win, image.img, 0, 0);
	mlx_string_put(image.mlx, image.mlx_win, 0,
		0, set_colors(2, 0), "To exit press  : [ESC]");
	mlx_key_hook(image.mlx_win, close_esc, &image);
	mlx_mouse_hook(image.mlx_win, mouse_hook, &image);
	mlx_hook(image.mlx_win, 17, 0, close_btn, &image);
	mlx_loop(image.mlx);
}	

int	ft_strncmp(const char *s1, const char *s2, size_t nbytes)
{
	size_t	i;

	i = 0;
	while ((i < nbytes) && ((s1[i] != '\0') || (s2[i] != '\0')))
	{
		if (s1[i] > s2[i])
			return ((((unsigned char *)s1)[i]) - ((unsigned char *)s2)[i]);
		if (s1[i] < s2[i])
			return ((((unsigned char *)s1)[i]) - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

void	fractal_typo(void)
{
	write(1, "------------------------------------------------\n", 50);
	write(1, "it looks ike you've got a typo bro... try again.\n", 50);
	write(1, "------------------------------------------------\n", 50);
	write(1, "Launch the command  <make ./fractol> followed by\n", 50);
	write(1, "-----  mandelbrot || julia || burning ship -----\n", 50);
	write(1, "------------------------------------------------\n", 50);
}

void	no_input(void)
{
	write(1, "------------------------------------------------\n", 50);
	write(1, "Hmmm... I think you forgot to add a fractal name\n", 50);
	write(1, "------------------------------------------------\n", 50);
	write(1, "Usage: ./fractol FractalNameHere. ex: ./fractol mandelbrot\n", 59);
	write(1, "------------------------------------------------\n", 50);
	write(1, "----- [mandelbrot] [julia] [burning ship] ------\n", 50);
}

/* mlx_new_image is fct used x mem allocation x img; */
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
			init_window(1);
		else if (ft_strncmp(av[1], "julia", 5) == 0)
			init_window(2);
		else if (ft_strncmp(av[1], "burning ship", 12) == 0)
			init_window(0);
		else
		{
			fractal_typo();
		}
	}
	else if (ac == 3)
	{
		if ((ft_strncmp(av[1], "burning", 7) == 0)
			&& (ft_strncmp(av[2], "ship", 4) == 0))
			init_window(0);
	}
	else
	{
		no_input();
		exit(0);
	}
	return (0);
}
