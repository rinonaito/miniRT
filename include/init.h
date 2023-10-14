/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:48:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/14 19:28:23 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "types.h"

void	set_vector3d(
			t_vector3d *coordinate,
			double x,
			double y,
			double z);

void	set_vector2d(
			t_vector2d *coordinate,
			double x,
			double y);

void	set_ray(
			t_ray *ray,
			const t_vector3d origin,
			const t_vector3d xyz,
			const t_ambient_lighting ambient);

#endif
