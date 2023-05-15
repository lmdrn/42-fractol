/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:10:29 by lmedrano          #+#    #+#             */
/*   Updated: 2023/05/12 15:22:12 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t nbytes)
{
	size_t i;
	
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

void	fractal_type(char *name)
{
	if(!ft_strncmp(name, "Mandelbrot", 10)
			mandelbrot();
}

int main(int ac, char **av)
{
	t_fractal	fractal;
	if (ac == 2 && fractal_type(av[1]))
	{
	
	} else
		write(1, "NOPE!<\n", 6);
	return (0);

