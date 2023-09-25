/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:41:51 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/25 19:19:46 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include <stdbool.h>
# include <stdlib.h>
# include "types.h"

size_t	hit_sphere(t_ray ray, t_vector3d center, double radius);

#endif