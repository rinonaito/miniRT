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
#include "parser.h"

void	set_vector3d(
	t_vector3d *coordinate,
	double x,
	double y,
	double z)
{
	coordinate->x = x;
	coordinate->y = y;
	coordinate->z = z;
}
