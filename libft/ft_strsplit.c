/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:26:05 by jsankari          #+#    #+#             */
/*   Updated: 2020/09/13 14:48:42 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_freetwodee(char **twodee, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		free(twodee[i]);
		i++;
	}
	free(twodee);
}

static size_t	ft_wordlen(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char		**ft_tdfllr(char **rslt, char const *s, size_t wrdcnt, char c)
{
	size_t x;
	size_t i;

	x = 0;
	i = 0;
	while (x < wrdcnt)
	{
		while (s[i] == c)
			i++;
		if (i == 0 || (s[i] != c && s[i] != '\0'))
		{
			if (!(rslt[x] = ft_strsub(s, i, (ft_wordlen(s + i, c)))))
			{
				ft_freetwodee(rslt, x);
				return (NULL);
			}
			i += ft_wordlen(s + i, c);
			x++;
		}
	}
	rslt[x] = NULL;
	return (rslt);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**rslt;
	size_t		wrdcnt;

	if (!(s))
		return (NULL);
	wrdcnt = ft_countstring(s, c);
	if (!(rslt = (char**)malloc(sizeof(char*) * (wrdcnt + 1))))
		return (NULL);
	rslt = ft_tdfllr(rslt, s, wrdcnt, c);
	return (rslt);
}
