/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:16:45 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/29 21:34:19 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "types.h"
# include "stdlib.h"

void	free_scene(t_scene *scene);

void	malloc_2dimensional_array(
			void ***array,
			const size_t size1,
			const size_t size2,
			const size_t count_num);

#endif