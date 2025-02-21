/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by your_username     #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by your_username    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

static char	*get_next_word(char *str, int *i)
{
	char	*word;
	int		len;
	int		j;

	len = 0;
	while (str[*i + len] && str[*i + len] != ' ')
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = str[*i + j];
		j++;
	}
	word[j] = '\0';
	*i += len;
	return (word);
}

char	**ft_split(char *str)
{
	char	**words;
	int		word_count;
	int		i;
	int		j;

	word_count = count_words(str);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
		{
			words[j] = get_next_word(str, &i);
			if (!words[j++])
				return (NULL);
		}
	}
	words[j] = NULL;
	return (words);
} 