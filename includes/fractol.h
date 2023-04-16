/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:01:07 by lmedrano          #+#    #+#             */
/*   Updated: 2023/04/16 14:08:43 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "keycode.h"
# include <stdlib.h>

/* mlx basics */

# define WIDTH 500
# define HEIGHT 500
# define WINDOW_TITLE "Fractol-42"

/* struct for minilibX img initialization */

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		*img;
	char	*buffer;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_mlx;

#endif
