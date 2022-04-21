/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:21:09 by mtaquet           #+#    #+#             */
/*   Updated: 2022/03/21 11:21:11 by mtaquet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

int initNewPower(t_equa *nombre, double nb, int power) {
	if (!(nombre->other = malloc(sizeof(double) * 2)) || !(nombre->otherPower = malloc(sizeof(int) * 2))) {
		free(nombre->other);
		return 0;
	}
	nombre->other[0] = nb;
	nombre->other[1] = 0;
	nombre->otherPower[0] = power;
	nombre->otherPower[1] = 0;
	return 1;
}

int addNewPower(t_equa *nombre, double nb, int power) {
	int n;
	double *new;
	int *newPower;

	if (nb < 0.0001 && nb >= 0)
		return 1;
	if (!nombre->other) {
		if (!initNewPower(nombre, nb, power))
			return 0;
		return 1;
	}
	n = -1;
	while (nombre->otherPower[++n]) {
		if (nombre->otherPower[n] == power) {
			nombre->other[n] += nb; 
			return 1;
		}
	}
	newPower = 0;
	if (!(new = ft_realloc(nombre->other, sizeof(double) * n, sizeof(double) * (n + 2))) 
		|| !(newPower = ft_realloc(nombre->otherPower, sizeof(int) * n, sizeof(int) * (n + 2)))) {
		free(new);
		return 0;
	}
	new[n] = nb;
	new[n + 1] = 0;
	newPower[n] = power;
	newPower[n + 1] = 0;
	nombre->other = new;
	nombre->otherPower = newPower;
	return 1;
}

void swapPower(t_equa *equa, int a, int b){
	int tmp1;
	double tmp2;

	tmp1 = equa->otherPower[a];
	tmp2 = equa->other[a];
	equa->otherPower[a] = equa->otherPower[b];
	equa->other[a] = equa->other[b];
	equa->otherPower[b] = tmp1;
	equa->other[b] = tmp2;
}

void BadSort(t_equa *equa) {
	int n;
	int m;
	int max;
	int ret;

	n = -1;
	while (equa->otherPower[++n]) {
		m = n;
		ret = n;
		max = equa->otherPower[n];
		while (equa->otherPower[++m]) {
			if (max < equa->otherPower[m]) {
				max = equa->otherPower[m];
				ret = m;
			}
		}
		swapPower(equa, n, ret);
	}
}