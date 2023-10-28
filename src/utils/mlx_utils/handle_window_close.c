/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window_close.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:10:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 21:41:58 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <mlx.h>

int	handle_window_close(void *value)
{
	t_mlx_data	*mlx_data;

	mlx_data = value;
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
