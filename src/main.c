/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:06:14 by jmilesi           #+#    #+#             */
/*   Updated: 2023/12/08 08:06:16 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_list	*ptr;

	ptr = NULL;
	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		perror("");
	ptr->img = (t_img *)malloc(sizeof(t_img));
	if (!ptr->img)
		perror("");
	ptr->window_width = 600;
	ptr->window_height = 600;
	ptr->display_shift = 0.1;
	if (argc < 2 || argc > 4 || ft_check_fractal_name(ptr, argv, argc) != 1)
		ft_usage_message();
	else
		ft_init_hooks_and_loop(ptr);
	return (0);
}

int	ft_check_fractal_name(t_list *ptr, char **argv, int argc)
{
	if (!ft_strncmp("mandelbrot", argv[1], 10))
		ptr->fractal_name = 1;
	else if (!ft_strncmp("julia", argv[1], 5))
	{
		ptr->fractal_name = 2;
		validating_julia_parameters(argc, argv, ptr);
	}
	else
		return (0);
	ft_init_each_fractal_settings(ptr);
	return (1);
}

void	ft_init_each_fractal_settings(t_list *ptr)
{
	if (ptr->fractal_name == 1)
		ft_mandelbrot_settings(ptr);
	else if (ptr->fractal_name == 2)
		ft_julia_settings(ptr);
}
