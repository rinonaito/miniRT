/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:41:51 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/27 22:18:14 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include <stdbool.h>
# include <stdlib.h>
# include "types.h"

double		hit_sphere(t_ray ray, t_vector3d center, double radius);

t_vector3d	get_normal_vector_for_sphere(
				t_ray ray,
				double hit_distance,
				t_vector3d center);

#endif