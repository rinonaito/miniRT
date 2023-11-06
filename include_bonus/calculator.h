/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:52:45 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/05 20:57:01 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATOR_H
# define CALCULATOR_H

# include <stdlib.h>

size_t	get_num_of_positive_solutions(double a, double b, double c);
size_t	get_num_of_solutions(double a, double b, double c);
double	get_closer_hit_distance(double a, double b, double c);
double	get_farer_hit_distance(double a, double b, double c);
double	scale_to_minus_one_to_one(double value);
double	scale_to_zero_to_one(double value);

#endif