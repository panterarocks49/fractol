/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:09:29 by jbrown            #+#    #+#             */
/*   Updated: 2018/05/07 20:09:31 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	image_pixel_put(t_env *env, int x, int y, int color)
{
	t_image	*img;

	img = env->img;
	if (x >= 0 && y >= 0 && x < WIN_X && y < WIN_Y)
		*(int *)(img->img_ptr + (int)((y * WIN_X) + x) * img->bpp) = color;
}

void	image_init(t_env *env)
{
	t_image	*img;

	if (!(img = (t_image *)malloc(sizeof(t_image))))
		error_msg();
	img->mlx_img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	img->img_ptr = mlx_get_data_addr(img->mlx_img, &img->bpp,
		&img->size_line, &img->endian);
	img->bpp /= 8;
	env->img = img;
}
