/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_fov_ratio.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:20:57 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 19:43:10 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "config.h"
#include <stdbool.h>

bool	is_invalid_fov_ratio(const int fov)
{
	return (is_invalid_int_ratio(fov, MAX_FOV, MIN_FOV));
}
