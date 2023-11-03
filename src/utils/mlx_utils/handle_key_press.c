/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:09:34 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 17:50:12 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "types.h"
#include <mlx.h>

int	handle_key_press(int keycode, void *value)
{
	t_mlx_data	*mlx_data;

	mlx_data = value;
	if (keycode == ESC || keycode == ESC_OS_TPYE_M1 || keycode == 65307)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
