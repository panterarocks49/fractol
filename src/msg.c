/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 00:36:02 by jbrown            #+#    #+#             */
/*   Updated: 2018/05/07 00:36:04 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	usage_msg(void)
{
	ft_putendl_fd("usage: ./fractol [fractol options]", 2);
	ft_putendl_fd("Viewing Options:", 2);
	ft_putendl_fd("    1. Mandelbrot Set", 2);
	ft_putendl_fd("    2. Julia Set", 2);
	ft_putendl_fd("    3. Burning Ship", 2);
	ft_putendl_fd("Use the numbers!", 2);
	exit(0);
}

void	error_msg(void)
{
	perror("error");
	exit(1);
}

void	print_ctrls(void)
{
	ft_printf("Controls:\n");
	ft_printf("    wasd   -> move around\n");
	ft_printf("    arrows -> move around\n");
	ft_printf("    +      -> Zoom In\n");
	ft_printf("    -      -> Zoom Out\n");
	ft_printf("    q      -> Increase Definition (Iterations)\n");
	ft_printf("    e      -> Decrease Definition (Iterations)\n");
	ft_printf("    c      -> Change Theme\n");
	ft_printf("Viewing Options:\n");
	ft_printf("    1. Mandelbrot Set\n");
	ft_printf("    2. Julia Set\n");
	ft_printf("    3. Burning Ship\n");
}
