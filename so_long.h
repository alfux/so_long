/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:24:29 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/15 20:39:38 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# define AF_KEYDOWN 2
# define AF_KEYUP 3
# define AF_MOUSEDOWN 4
# define AF_MOUSEUP 5
# define AF_MOUSEMOVE 6
# define AF_EXPOSE 12
# define AF_DESTROY 17
# define MPITW mlx_put_image_to_window
# define MXFTI mlx_xpm_file_to_image
# define MGDA mlx_get_data_addr
# define MCW mlx_clear_window
# define MOVE_UP 0x7e
# define MOVE_DOWN 0x7d
# define MOVE_LEFT 0x7b
# define MOVE_RIGHT 0x7c
# define ESCAPE 0x35
# include "libft/libft.h"
# include <mlx.h>

typedef struct s_bool	t_bool;
struct					s_coo
{
	int	x;
	int	y;
};
typedef struct s_coo	t_coo;
struct					s_img
{
	void	*iid;
	char	*fpx;
	int		w;
	int		h;
	int		bpp;
	int		sil;
	int		end;
	t_coo	p;
};
typedef struct s_img	t_img;
struct					s_guy
{
	t_img	spr[16];
	t_coo	pos;
	int		k[4];
	int		i;
};
typedef struct s_guy	t_guy;
struct					s_dat
{
	void	*cid;
	void	*wid;
	int		w;
	int		h;
	char	*tit;
	t_guy	hum;
};
typedef struct s_dat	t_dat;

t_dat	*open_win(int x, int y, char *title);
void	close_and_exit(t_dat *win);
void	kd_event(int keycode, t_dat *win);
void	ku_event(int keycode, t_dat *win);
void	load_player(t_dat *win, int x, int y);
void	free_player(t_dat *win);
void	animate(t_dat *win);
t_coo	set_coo(int x, int y);
void	move_player(t_dat *win, int reset);
//int	mlx_hook(t_win_list *win, int x_event, int x_mask, int (*f)(), void *p);
#endif
