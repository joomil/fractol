/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:05:57 by jmilesi           #+#    #+#             */
/*   Updated: 2023/12/08 08:05:59 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	zoom_hook(int keysym, int x, int y, t_list *ptr)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = x / ptr->zoom_x + ptr->x_min;
	tmp_y = y / ptr->zoom_y + ptr->y_min;
	if (keysym == Button4)
	{
		ptr->zoom_x *= 1.1;
		ptr->zoom_y *= 1.1;
		ptr->display_shift /= 1.1;
	}
	if (keysym == Button5)
	{
		ptr->zoom_x /= 1.1;
		ptr->zoom_y /= 1.1;
		ptr->display_shift *= 1.1;
	}
	ptr->x_min = tmp_x - (x / ptr->zoom_x);
	ptr->y_min = tmp_y - (y / ptr->zoom_y);
	put_image_to_window(ptr);
	return (0);
}

int	key_hook(int keysym, t_list *ptr)
{
	if (keysym == XK_Escape)
		destroy_fractol(ptr);
	if (keysym == XK_c)
		ptr->color = ptr->color + 0xF0A0F0;
	if (keysym == XK_Up || keysym == XK_w)
		ptr->y_min = ptr->y_min - ptr->display_shift;
	if (keysym == XK_Down || keysym == XK_s)
		ptr->y_min = ptr->y_min + ptr->display_shift;
	if (keysym == XK_Left || keysym == XK_a)
		ptr->x_min = ptr->x_min - ptr->display_shift;
	if (keysym == XK_Right || keysym == XK_d)
		ptr->x_min = ptr->x_min + ptr->display_shift;
	put_image_to_window(ptr);
	return (0);
}
