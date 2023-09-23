/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:16:04 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/23 18:23:33 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"

void    make_image(t_mlx_data *mlx_data, t_sphere *sphere)
{
    double  x;
    double  y;

    x = 0;
    y = 0;
    while (y < HEIGHT)
    {
        while (x < WIDTH)
        {
			(void)mlx_data;
			(void)sphere;
            x++;
        }
        x = 0;
        y++;
    }
}
