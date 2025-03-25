/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:15:35 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/04 18:58:51 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstr(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_subslen(char const *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static void	ft_strfree(char **s, int j)
{
	while (j > 0)
	{
		free(s[j - 1]);
		j--;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	split = (char **)malloc((ft_countstr(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_countstr(s, c))
	{
		while (s[i] == c)
			i++;
		split[j] = ft_substr(s, i, ft_subslen(s, c, i));
		if (!split[j])
		{
			ft_strfree(split, j);
			return (0);
		}
		i = i + ft_subslen(s, c, i);
		j++;
	}
	split[j] = 0;
	return (split);
}

/* int	main(void)
{
	char const	*s = "ggggggggggggggg";
	char		c;
	char		**res;
	int			i;

	c = 'g';
	i = 0;
	res = ft_split(s, c);
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	ft_strfree(res);
	return (0);
}
 */