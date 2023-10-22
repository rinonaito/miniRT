/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_file_extension.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:20:31 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 21:25:30 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_utils.h"
#include "config.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

bool	is_invalid_file_extension(const char *const file_name)
{
	size_t	str_len;

	str_len = ft_strlen(file_name);
	if (file_name == NULL
		|| str_len < 3
		|| file_name[str_len - 3] != '.'
		|| file_name[str_len - 2] != 'r'
		|| file_name[str_len - 1] != 't')
	{
		print_error_msg(INVALID_FILE);
		return (true);
	}
	return (false);
}
