/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_file_extension.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:20:31 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/09 17:45:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_utils.h"
#include "config.h"
#include <stdbool.h>
#include <stdlib.h>

bool	is_invalid_file_extension(const char *const file_name)
{
	if (file_name == NULL
		|| ft_strlen(file_name) < 3
		|| file_name[ft_strlen(file_name) - 3] != '.'
		|| file_name[ft_strlen(file_name) - 2] != 'r'
		|| file_name[ft_strlen(file_name) - 1] != 't')
	{
		print_error_msg(INVALID_FILE);
		return (true);
	}
	return (false);
}
