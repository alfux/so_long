/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:57:42 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/21 02:01:42 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	get_err_map(int err, char ***map)
{
	size_t	i;

	i = 0;
	if (!err)
	{
		while (*(*map + i))
			ft_printf("%s%s%s", GREEN, *(*map + i++), WHITE);
		return (0);
	}
	else
	{
		if (err == 1)
			ft_printf("%sUnknown file type.%s\n", RED, WHITE);
		else if (err == 2)
			ft_printf("%sCouldn't open file.%s\n", RED, WHITE);
		else if (err == 3)
			ft_printf("%sFile is not a proper map.%s\n", RED, WHITE);
		else if (err == 4)
			ft_printf("%sCouldn't close file descriptor.%s\n", RED, WHITE);
		return (1);
	}
}

static void	show_imap(t_dat *win)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < win->map.h)
	{
		while (j < win->map.w)
			ft_printf("%2i ", *(*(win->map.imap + i) + j++));
		ft_printf("\n");
		i++;
		j = 0;
	}
}

int	main(int argc, char **argv)
{
	t_dat	*win;
	char	**map;

	if (argc != 2)
		return (1);
	if (get_err_map(get_map(*(argv + 1), &map), &map))
		return (2);
	win = open_win(map, "so_long");
	show_imap(win);
	draw_map(win);
	mpitw(win, win->hum.spr[0].iid, win->hum.pos.x, win->hum.pos.y);
	mlx_loop_hook(win->cid, &animate, win);
	mlx_hook(win->wid, KeyPress, KeyPressMask, &kd_event, win);
	mlx_hook(win->wid, KeyRelease, KeyReleaseMask, &ku_event, win);
	mlx_hook(win->wid, DestroyNotify, 0L, &close_and_exit, win);
	mlx_loop(win->cid);
	return (0);
}
