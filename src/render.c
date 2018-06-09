/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:49:40 by jbrown            #+#    #+#             */
/*   Updated: 2018/05/07 19:49:42 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <pthread.h>

static void	render_set(t_env *e, unsigned int y_start, unsigned int y_end)
{
	if (e->type == J_SET)
		render_julia(e, y_start, y_end);
	else if (e->type == B_SET)
		render_bs(e, y_start, y_end);
	else
		render_mandel(e, y_start, y_end);
}

void		*start_thread(void *a)
{
	t_env	*e;
	t_arg	*args;

	args = a;
	e = args->env;
	render_set(e, WIN_Y / THREADS * args->i, WIN_Y / THREADS * (args->i + 1));
	return (NULL);
}

void		render(t_env *e)
{
	int			i;
	t_arg		args[THREADS];
	pthread_t	threads[THREADS];

	ft_bzero(e->img->img_ptr, (WIN_X * WIN_Y * e->img->bpp));
	i = -1;
	while (++i < THREADS)
	{
		args[i].i = i;
		args[i].env = e;
		if (pthread_create(&threads[i], NULL, start_thread, &args[i]))
			error_msg();
	}
	i = -1;
	while (++i < THREADS)
		if (pthread_join(threads[i], NULL))
			error_msg();
	mlx_put_image_to_window(e->mlx, e->window, e->img->mlx_img, 0, 0);
}
