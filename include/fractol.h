/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 00:16:10 by jbrown            #+#    #+#             */
/*   Updated: 2018/05/07 00:16:14 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>

# define RANGE_CHANGE(x,a,b,min,max) (((b)-(a))*((x)-(min))/((max)-(min)))+(a)

# define WIN_X 1000
# define WIN_Y 800
# define MAX_IT 200
# define MAX_COLORS 50
# define THREADS 4
# define THEME_COUNT 4
# define THEME_1 0
# define THEME_2 1
# define THEME_3 2
# define THEME_4 3
# define M_SET 0
# define J_SET 1
# define B_SET 2

typedef struct	s_mouse
{
	int			x;
	int			y;
	int			old_x;
	int			old_y;
	long double	cx;
	long double	cy;
	int			left_click;
}				t_mouse;

typedef struct	s_image
{
	void	*mlx_img;
	char	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_env
{
	void			*mlx;
	void			*window;
	t_image			*img;
	t_mouse			*mouse;
	unsigned int	max_it;
	int				type;
	long double		zoom;
	long double		x_shift;
	long double		y_shift;
	int				theme;
	int				colors[MAX_COLORS];
}				t_env;

typedef struct	s_arg
{
	t_env			*env;
	int				i;
}				t_arg;

void			render(t_env *env);

void			render_julia(t_env *e, unsigned int y_start,
	unsigned int y_end);

void			render_mandel(t_env *e, unsigned int y_start,
	unsigned int y_end);

void			render_bs(t_env *e, unsigned int y_start, unsigned int y_end);

void			reset_env(t_env *env);

void			set_colors(t_env *env);

void			image_pixel_put(t_env *env, int x, int y, int color);
void			image_init(t_env *env);

void			mouse_reset(t_mouse *mouse);
void			mouse_init(t_env *env);
int				mouse_pressed_hook(int key, int x, int y, t_env *env);
int				mouse_released_hook(int key, int x, int y, t_env *env);
int				mouse_moved_hook(int x, int y, t_env *env);

int				on_key_press(int key, t_env *env);
int				on_key_up(int key, t_env *env);

void			usage_msg(void);
void			error_msg(void);
void			print_ctrls(void);

#endif
