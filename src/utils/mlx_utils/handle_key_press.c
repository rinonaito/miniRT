/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:09:34 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/27 21:46:13 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "types.h"
#include <mlx.h>

#include <stdio.h>
int	handle_key_press(int keycode, void *value)
{
	t_mlx_data	*mlx_data;

	mlx_data = value;
	if (keycode == ESC || keycode == ESC_OS_TPYE_M1)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		exit(0);
	}
	return (0);
}
