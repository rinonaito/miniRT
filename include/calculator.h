/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:52:45 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/08 19:07:11 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATOR_H
# define CALCULATOR_H

# include <stdlib.h>
# include <stdbool.h>

size_t	get_num_of_positive_solutions(double a, double b, double c);
size_t	get_num_of_solutions(double a, double b, double c);
double	get_closer_hit_distance(double a, double b, double c);
double	scale_to_minus_one_to_one(double value, bool invert);
double	scale_to_zero_to_one(double value);

#endif