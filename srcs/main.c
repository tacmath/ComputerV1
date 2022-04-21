/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:46:43 by mtaquet           #+#    #+#             */
/*   Updated: 2022/03/18 13:14:55 by mtaquet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

int checkSpace(char *line) {
	int n;
	int ret;
	int space;
	int egale;

	n = -1;
	ret = 0;
	space = 0;
	egale = 0;
	while (line[++n]) {
		if (line[n] == ' ')
			space = 1;
		else if ((line[n] >= '0' && line[n] <= '9') || line[n] == '.') {
			if (ret && space) {
				ft_putendl_fd("Wrong format", 2);
				return 0;
			}
			space = 0;
			ret = 1;
		}
		else {
			space = 0;
			ret = 0;
			if (line[n] == '=' && ++egale > 1) {
				ft_putendl_fd("Wrong format", 2);
				return 0;
			}
		}
	}
	return 1;
}

char* ft_strTabJoin(char **tab, char *between, int tablen) {
	int len;
	int n;
	int i;
	int m;
	char *new;

	len = 0;
	n = -1;
	while (++n < tablen){
		m = -1;
		while (tab[n][++m])
			len++;
	}
	if (!(new = malloc(sizeof(char) * len + ft_strlen(between) * (tablen - 1) + 1)))
		return (0);
	len = 0;
	n = -1;
	while (++n < tablen){
		m = -1;
		while (tab[n][++m])
			new[len++] = tab[n][m];
		if (n < tablen - 1) {
			i = -1;
			while (between[++i])
				new[len++] = between[i];
		}

	}
	new[len] = '\0';
	return new;
}


int	main(int ac, char **av) {
	char *line;

	line = 0;
	if (ac == 1) {
		ft_putendl_fd("Not enought argument", 2);
		return -1;
	
	} else if (ac == 2) {
		if (!checkSpace(av[1]) || !ResolveEquation(av[1]))
			return -1;
	}
	else {
		line = ft_strTabJoin(av + 1, " ", ac - 1);
		if (!checkSpace(line) || !ResolveEquation(line)) {
			free(line);
			return -1;
		}
		free(line);
	}
	return 0;
}
