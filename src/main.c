/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 00:13:28 by jbrown            #+#    #+#             */
/*   Updated: 2018/05/07 00:13:34 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		reset_env(t_env *env)
{
	env->zoom = 0.004;
	env->x_shift = 0;
	env->y_shift = 0;
	mouse_reset(env->mouse);
	set_colors(env);
}

static void	set_env(t_env *env, char *set_type)
{
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, WIN_X, WIN_Y, "fractol");
	image_init(env);
	mouse_init(env);
	env->max_it = MAX_IT;
	env->theme = THEME_1;
	if (!ft_strcmp(set_type, "1"))
		env->type = M_SET;
	else if (!ft_strcmp(set_type, "2"))
		env->type = J_SET;
	else if (!ft_strcmp(set_type, "3"))
		env->type = B_SET;
	else
		env->type = M_SET;
	reset_env(env);
}

static void	window_init(char *set_type)
{
	t_env	env;

	set_env(&env, set_type);
	render(&env);
	mlx_key_hook(env.window, on_key_up, &env);
	mlx_hook(env.window, 2, 0, on_key_press, &env);
	mlx_hook(env.window, 4, 0, mouse_pressed_hook, &env);
	mlx_hook(env.window, 6, 0, mouse_moved_hook, &env);
	mlx_loop(env.mlx);
}

int			main(int ac, char *av[])
{
	int		i;
	int		opt;
	int		windows;
	int		process;

	if (ac < 2)
		usage_msg();
	print_ctrls();
	windows = ac - 1;
	i = -1;
	opt = 1;
	while (++i < windows)
	{
		if (windows - i > 1)
		{
			if ((process = fork()) < 0)
				error_msg();
			if (process == 0)
			{
				opt = i + 2;
				break ;
			}
		}
	}
	window_init(av[opt]);
	return (0);
}
