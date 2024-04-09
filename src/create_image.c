/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:05:45 by jmilesi           #+#    #+#             */
/*   Updated: 2023/12/08 08:05:46 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_draw_pixels(int x, int y, int color, t_list *ptr)
{
	int	i;
	int	*ptr2;

	if (x >= 0 && x < ptr->window_width && y >= 0 && y < ptr->window_height)
	{
		i = y * ptr->img->line_length + x * ptr->img->bits_per_pixel / 8;
		ptr2 = (int *)&ptr->img->data[i];
		*ptr2 = color;
	}
}

int	put_image_to_window(t_list *ptr)
{
	if (ptr->img->mlx_img)
		mlx_destroy_image(ptr->mlx_ptr, ptr->img->mlx_img);
	ptr->img->mlx_img = mlx_new_image(ptr->mlx_ptr,
			ptr->window_width, ptr->window_height);
	if (!(ptr->img->mlx_img))
		perror("");
	ptr->img->data = mlx_get_data_addr(ptr->img->mlx_img,
			&ptr->img->bits_per_pixel, &ptr->img->line_length,
			&ptr->img->endian);
	if (!(ptr->img->data))
		perror("");
	ft_launch_each_fractal(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr,
		ptr->mlx_win, ptr->img->mlx_img, 0, 0);
	return (0);
}

void	ft_launch_each_fractal(t_list *ptr)
{
	if (ptr->fractal_name == 1)
		ft_calculate_and_launch_mandelbrot(ptr);
	else if (ptr->fractal_name == 2)
		ft_calculate_and_launch_julia(ptr);
}
