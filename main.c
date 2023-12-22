/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeltahi <haeltahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:26:10 by haeltahi          #+#    #+#             */
/*   Updated: 2023/12/20 16:18:10 by haeltahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0) || (ac == 4
			&& ft_strncmp(av[1], "julia", 5) == 0))
	{
		fractal.name = av[1];
		if ((ac == 4 && ft_strncmp(av[1], "julia", 5) == 0))
		{
			fractal.name = av[1];
			fractal.julia_x = atoidbl(av[2]);
			fractal.julia_y = atoidbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_hook(fractal.mlx_window, 2, 0, keysum, &fractal);
		mlx_hook(fractal.mlx_window, 4, 1L << 2, mouse_handler, &fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
