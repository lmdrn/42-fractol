/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:07:21 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/06 11:03:04 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	fractal_typo(void)
{
	write(1, "------------------------------------------------\n", 50);
	write(1, "it looks ike you've got a typo bro... try again.\n", 50);
	write(1, "Launch the command <make ./fractol> followed by:\n", 50);
	write(1, "------------- [mandelbrot] [julia] -------------\n", 50);
	write(1, "------------------------------------------------\n", 50);
}

void	no_input(void)
{
	write(1, "------------------------------------------------\n", 50);
	write(1, "------------------ Wrong input -----------------\n", 50);
	write(1, "------- Usage: ./fractol [FractalNameHere] -----\n", 50);
	write(1, "------------- [mandelbrot] [julia] -------------\n", 50);
	write(1, "------------------------------------------------\n", 50);
}
