/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:12:27 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 18:09:07 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "object.h"
#include "types.h"

t_circle	*set_circle(
	const t_vector3d center,
	const double diameter,
	const t_vector3d direction_vec,
	const t_rgb rgb)
{
	t_circle	*circle;

	circle = malloc(sizeof(t_circle) * 1);
	circle->center = center;
	circle->diameter = diameter;
	circle->direction_vec = direction_vec;
	circle->color = rgb;
	return (circle);
}
