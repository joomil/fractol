/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:06:20 by jmilesi           #+#    #+#             */
/*   Updated: 2023/12/08 08:06:22 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_mandelbrot_settings(t_list *ptr)
{
	ptr->iteration = 0;
	ptr->x_min = -2.0;
	ptr->x_max = 2.0;
	ptr->y_min = -2.0;
	ptr->y_max = 2.0;
	ptr->zoom_x = 150;
	ptr->zoom_y = 150;
	ptr->c_real = ptr->x / ptr->zoom_x + ptr->x_min;
	ptr->c_im = ptr->y / ptr->zoom_y + ptr->y_max;
	ptr->z_real = 0;
	ptr->z_im = 0;
	ptr->max_iteration = 200;
	ptr->img_x = ptr->window_width;
	ptr->img_y = ptr->window_height;
	ptr->color = 0xFA0CF0C;
}

void	ft_init_mandelbrot(t_list *ptr)
{
	ptr->iteration = 0;
	ptr->c_real = ptr->x / ptr->zoom_x + ptr->x_min;
	ptr->c_im = ptr->y / ptr->zoom_y + ptr->y_min;
	ptr->z_real = 0;
	ptr->z_im = 0;
}

void	ft_calculate_and_launch_mandelbrot(t_list *ptr)
{
	ptr->x = -1;
	while (ptr->x < ptr->img_x)
	{
		ptr->y = 0;
		while (ptr->y < ptr->img_y)
		{
			ft_init_mandelbrot(ptr);
			while (ptr->z_real * ptr->z_real + ptr->z_im * ptr->z_im < 4
				&& ptr->iteration < ptr->max_iteration)
			{
				ptr->temp = ptr->z_real;
				ptr->z_real = ptr->z_real * ptr->z_real - ptr->z_im
					* ptr->z_im + ptr->c_real;
				ptr->z_im = 2 * ptr->z_im * ptr->temp + ptr->c_im;
				ptr->iteration++;
			}
			ft_draw_pixels(ptr->x, ptr->y,
				ptr->iteration * ptr->color / ptr->max_iteration, ptr);
			ptr->y++;
		}
		ptr->x++;
	}
}
