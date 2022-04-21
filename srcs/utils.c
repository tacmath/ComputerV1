/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:18:44 by mtaquet           #+#    #+#             */
/*   Updated: 2022/03/17 17:00:00 by mtaquet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

double    ft_strtod(const char *str) {
    double resultat;
    int precision;
    int n;

    resultat = 0;
    n = -1;
    while (str[++n] >= '0' && str[n] <= '9')
        resultat = resultat * 10 + (str[n] - 48);
    if (str[n] == '.') {
        precision = 10;
        while (str[++n] >= '0' && str[n] <= '9') {
            resultat += (1.0 / precision) * (str[n] - 48);
            precision *= 10;
        }
    }
    return (resultat);
}

void        ft_putfloat(double nb) {
    int decimal; 

	if (nb < 0) {
		ft_putchar('-');
		nb = -nb;
	}
	nb += 0.00000001;
    ft_putnbr((int)nb);
    nb = nb - (int)nb;
    if (nb > 0.000001) {
        ft_putchar('.');
		decimal = nb * 1000000;
		while (!(decimal % 10))
			decimal /= 10;
        ft_putnbr(decimal);
    }
}

char* RemoveSpace(char *string) {
    int        n;
    char    *new;
    int        len;
    int     m;
    
    n = -1;
    len = 1;
    m = 0;
    while (string[++n])
        if (string[n] != ' ')
            len++;
    if (!(new = malloc(sizeof(char) * len)))
        return 0;
    n = -1;
    while (string[++n])
        if (string[n] != ' ')
            new[m++] = string[n];
    new[m] = 0;
    return new;
}

int checkTimes(char *line) {
	int n;

	n = 1;
	if (*line == '*')
		return (0);
	while (line[++n])
		if (line[n] == '*' && ((line[n - 1] < '0' || line[n - 1] > '9') || ((line[n - 1] >= '0' && line[n - 1] <= '9') && line[n + 1] != 'x' && line[n + 1] != 'X')))
			return (0);
	return (1);
}
