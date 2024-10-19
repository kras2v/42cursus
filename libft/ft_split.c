/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:07:50 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/19 14:55:49 by kvalerii         ###   ########.fr       */
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

static void	ft_skip(char const **s, char c, int is_space)
{
	while ((**s == c) == is_space && **s != '\0')
		(*s)++;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words_index;
	int		word_len;

	if (!s)
		return (NULL);
	res = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	words_index = 0;
	if (!res)
		return (NULL);
	while (*s)
	{
		ft_skip(&s, c, 1);
		word_len = ft_count_word_len(s, c);
		if (word_len != 0)
		{
			res[words_index] = ft_substr(s, 0, word_len);
			if (!ft_is_res_word_index(res, words_index))
				return (NULL);
			words_index++;
		}
		ft_skip(&s, c, 0);
	}
	res[words_index] = NULL;
	return (res);
}

// #include <stdio.h>
// int main()
// {
//  	char *s = "olol                     ";  // input string
//     char **result = ft_split(s, 0);       // split based on space

//     if (!result)
//         return (1); // handle error if result is NULL
    
//     // Print the resulting split strings
//     for (int i = 0; result[i] != NULL; i++)
//     {
//         printf("result[%d]: %s\n", i, result[i]);
//     }

//     // Free the allocated memory for each string
//     int i = 0;
//     while (result[i] != NULL)
//     {
//         free(result[i]);  // free each string
//         i++;
//     }

//     // Free the array of pointers itself
//     free(result);

//     return 0;
// }