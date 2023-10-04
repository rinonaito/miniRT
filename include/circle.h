/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:01:29 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/04 22:01:55 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_H
# define CIRCLE_H

# include "types.h"

double	hit_circle(const t_ray ray, const void *object);

#endif