/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:09:41 by jbrown            #+#    #+#             */
/*   Updated: 2018/05/07 20:09:43 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	cycle_theme(t_env *env)
{
	env->theme++;
	if (env->theme == THEME_COUNT)
		env->theme = 0;
	set_colors(env);
}

static void	change_type(int key, t_env *env)
{
	if (key == 18)
		env->type = M_SET;
	else if (key == 19)
		env->type = J_SET;
	else if (key == 20)
		env->type = B_SET;
	reset_env(env);
}

int			on_key_press(int key, t_env *env)
{
	if (key == 69 || key == 24)
		env->zoom *= 0.8;
	else if (key == 78 || key == 27)
		env->zoom /= 0.8;
	else if (key >= 18 && key <= 20)
		change_type(key, env);
	else if (key == 8)
		cycle_theme(env);
	else if (key == 12)
		env->max_it = env->max_it / 0.9 + 1;
	else if (key == 14)
		env->max_it =
	((unsigned int)(env->max_it * 0.9) == 0) ? 1 : env->max_it * 0.9;
	else if (key == 123 || key == 0)
		env->x_shift -= 40 * env->zoom;
	else if (key == 124 || key == 2)
		env->x_shift += 40 * env->zoom;
	else if (key == 125 || key == 1)
		env->y_shift += 40 * env->zoom;
	else if (key == 126 || key == 13)
		env->y_shift -= 40 * env->zoom;
	else
		return (0);
	render(env);
	return (0);
}

int			on_key_up(int key, t_env *env)
{
	(void)env;
	if (key == 53)
		exit(0);
	return (0);
}
