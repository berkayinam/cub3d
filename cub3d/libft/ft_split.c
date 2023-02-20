/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:17:32 by binam             #+#    #+#             */
/*   Updated: 2022/01/23 22:37:24 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cwords(const char *s, char c)
{
	int	rtn;

	rtn = 0;
	while (s && *s)
	{
		while (*s == c)
			s++;
		rtn += *s != 0;
		s = ft_strchr(s, c);
	}
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**rtn;
	int		i;
	size_t	len;

	if (!s)
		return (NULL);
	words = cwords(s, c);
	rtn = malloc((words + 1) * sizeof(char *));
	if (!rtn)
		return (0);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = ft_strchr(s, c) - s;
		rtn[i] = ft_substr(s, 0, len);
		s += len;
		if (!rtn[i++])
			return (0);
	}
	rtn[i] = 0;
	return (rtn);
}
