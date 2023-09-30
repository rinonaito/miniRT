/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:09:34 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/29 19:52:00 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "types.h"
#include <mlx.h>

//TODO:printfと共に削除
#include <stdio.h>

int	handle_key_press(int keycode, void *value)
{
	t_mlx_data	*mlx_data;

	mlx_data = value;
	printf("key = %d\n", keycode);
	if (keycode == ESC || keycode == ESC_OS_TPYE_M1 || keycode == 65307)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		exit(0);
	}
	return (0);
}
