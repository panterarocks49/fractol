/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 01:08:10 by jbrown            #+#    #+#             */
/*   Updated: 2018/05/08 01:08:12 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	make_color(unsigned char r, unsigned char g, unsigned char b)
{
	int		color;

	color = 0;
	color |= r;
	color = color << 8;
	color |= g;
	color = color << 8;
	color |= b;
	return (color);
}

static void	set_theme_repeat(t_env *env, int *colors, int size)
{
	int	i;

	i = -1;
	while (++i < MAX_COLORS)
	{
		env->colors[i] = colors[i % (size - 1)];
	}
	env->colors[0] = colors[size - 1];
	env->colors[MAX_COLORS - 1] = 0;
}

static void	set_theme(t_env *env, int dec, int i)
{
	int	r;
	int	g;
	int	b;

	while (i < MAX_COLORS && (r = 255) == 255)
	{
		while (r >= 0 && (g = 255) == 255)
		{
			while (g >= 0 && (b = 255) == 255)
			{
				while (b >= 0)
				{
					env->colors[i] = make_color(r, g, b);
					if (++i == MAX_COLORS)
					{
						env->colors[MAX_COLORS - 1] = 0;
						return ;
					}
					b -= dec;
				}
				g -= dec;
			}
			r -= dec;
		}
	}
}

void		set_colors(t_env *env)
{
	static int	th_3_colors[5] =
	{0x7eff47, 0x47fff5, 0xff47e9, 0xfffb47, 0xffffff};
	static int	th_4_colors[5] = {0x7eff47, 0x47fff5, 0xff47e9, 0xfffb47, 0};
	int			i;

	i = 0;
	if (env->theme == THEME_1)
		set_theme(env, 75, i);
	else if (env->theme == THEME_2)
		set_theme(env, 150, i);
	else if (env->theme == THEME_3)
		set_theme_repeat(env, th_3_colors, 5);
	else if (env->theme == THEME_4)
		set_theme_repeat(env, th_4_colors, 5);
}
