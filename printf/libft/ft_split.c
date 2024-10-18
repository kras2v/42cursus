/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:07:50 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/18 16:37:35 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	words;

	words = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			words++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (words);
}

static int	ft_count_word_len(const char *s, char c)
{
	int	word_len;

	word_len = 0;
	while (*s != c && *s != '\0')
	{
		word_len++;
		s++;
	}
	return (word_len);
}

static int	ft_is_res_word_index(char **res, int words_index)
{
	int	j;

	j = 0;
	if (!res[words_index])
	{
		while (j < words_index)
		{
			free(res[j]);
			j++;
		}
		free(res);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words_index;
	int		word_len;

	res = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	words_index = 0;
	if (!res || !s)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		word_len = ft_count_word_len(s, c);
		if (word_len != 0)
		{
			res[words_index] = ft_substr(s, 0, word_len);
			if (!ft_is_res_word_index(res, words_index))
				return (NULL);
			words_index++;
		}
		while (*s != c && *s != '\0')
			s++;
	}
	res[words_index] = NULL;
	return (res);
}
