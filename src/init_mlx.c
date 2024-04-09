/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:06:03 by jmilesi           #+#    #+#             */
/*   Updated: 2023/12/08 08:06:04 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_init_hooks_and_loop(t_list *ptr)
{
	ft_init_mlx(ptr);
	mlx_hook(ptr->mlx_win, 2, 1L << 0, key_hook, ptr);
	mlx_mouse_hook(ptr->mlx_win, zoom_hook, ptr);
	mlx_hook(ptr->mlx_win, 17, 0, destroy_fractol, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}

int	ft_init_mlx(t_list *ptr)
{
	ptr->mlx_ptr = mlx_init();
	if (!(ptr->mlx_ptr))
		perror("");
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr,
			ptr->window_width, ptr->window_height, "fract-ol ;p");
	if (!(ptr->mlx_win))
		perror("");
	put_image_to_window(ptr);
	return (0);
}
