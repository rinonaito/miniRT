/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vector3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:47:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/23 21:22:00 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	set_vector2d(
	t_vector2d *coordinate,
	double x,
	double y)
{
	coordinate->x = x;
	coordinate->y = y;
}
