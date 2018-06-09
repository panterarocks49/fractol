/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 02:44:00 by jbrown            #+#    #+#             */
/*   Updated: 2018/05/08 02:44:15 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	mouse_reset(t_mouse *mouse)
{
	mouse->left_click = 1;
	mouse->x = 0;
	mouse->y = 0;
	mouse->cx = 0;
	mouse->cy = 0;
}

void	mouse_init(t_env *env)
{
	t_mouse	*mouse;

	if (!(mouse = (t_mouse *)malloc(sizeof(t_mouse))))
		error_msg();
	mouse_reset(mouse);
	env->mouse = mouse;
}

int		mouse_pressed_hook(int key, int x, int y, t_env *env)
{
	if (key == 1)
		env->mouse->left_click = !env->mouse->left_click;
	else if (key == 4)
		env->zoom *= 0.8;
	else if (key == 5)
		env->zoom /= 0.8;
	else
		return (0);
	render(env);
	(void)x;
	(void)y;
	return (0);
}

int		mouse_moved_hook(int x, int y, t_env *env)
{
	if (env->mouse->left_click)
	{
		env->mouse->x = x;
		env->mouse->y = y;
		env->mouse->cx = -1.0 + 2.0 / WIN_X * x;
		env->mouse->cy = -1.0 + 2.0 / WIN_Y * y;
		render(env);
	}
	return (0);
}
