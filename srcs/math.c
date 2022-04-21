/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:32:07 by mtaquet           #+#    #+#             */
/*   Updated: 2022/03/16 11:32:09 by mtaquet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

double ft_sqrtd(double number) {                                            //changer la fonction pour la norme
    int start;
    int end;
    int mid;
    double res;
    double precision;

    start = 0;
    end = number;
    while(start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number)
            res = mid;
            break;
        if (mid * mid < number) {
            res = start;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    precision = 0.1;
    for (int i = 0; i < 10; i++) {
        while (res * res <= number) {
            res += precision;
        }
        res = res - precision;
        precision = precision / 10;
    }
    return res;
}

double ft_abs(double nb) {
    if (nb < 0)
        nb = -nb;
    return nb;
}
