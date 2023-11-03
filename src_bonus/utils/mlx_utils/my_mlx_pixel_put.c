/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:28:38 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/23 22:26:51 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	my_mlx_pixel_put(
		t_mlx_data *mlx_data,
		int x,
		int y,
		int color)
{
	char	*dst;

	dst = mlx_data->addr +(y * mlx_data->line_length + x
			* (mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
