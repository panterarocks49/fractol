/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 01:45:35 by jbrown            #+#    #+#             */
/*   Updated: 2018/05/09 01:45:37 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static unsigned int	mandelbrot(unsigned int max_it, long double x0,
	long double y0)
{
	unsigned int	count;
	long double		x;
	long double		y;
	long double		x2;
	long double		y2;

	count = 0;
	x = x0;
	y = y0;
	x2 = x * x;
	y2 = y * y;
	while (x2 + y2 < 4.0)
	{
		if (++count == max_it)
			break ;
		y = 2 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
	}
	return (count);
}

void				render_mandel(t_env *e, unsigned int y_start,
	unsigned int y_end)
{
	unsigned int	x;
	unsigned int	y;
	long double		x0;
	long double		y0;
	long double		y0_start;

	x0 = 0 * e->zoom - WIN_X / 2.0 * e->zoom + e->x_shift;
	y0_start = y_start * e->zoom - WIN_Y / 2.0 * e->zoom + e->y_shift;
	x = 0;
	while (x < WIN_X)
	{
		y0 = y0_start;
		y = y_start;
		while (y < y_end)
		{
			image_pixel_put(e, x, y, e->colors[RANGE_CHANGE(
	mandelbrot(e->max_it, x0, y0), 0, MAX_COLORS - 1, 0, e->max_it)]);
			y++;
			y0 += e->zoom;
		}
		x++;
		x0 += e->zoom;
	}
}
