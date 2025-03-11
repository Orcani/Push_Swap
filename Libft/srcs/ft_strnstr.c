/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:24:48 by desambou          #+#    #+#             */
/*   Updated: 2024/11/16 15:02:30 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strnstr(const char *big, const char *little, size_t len)
// {
// 	size_t	i;
// 	size_t	little_len;

// 	i = 0;
// 	if (!little)
// 		return ((char *)big);
// 	little_len = ft_strlen(little);
// 	if (little_len > len)
// 		return (NULL);
// 	while (i < len - little_len)
// 	{
// 		if (ft_strncmp(big + i, little, little_len) == 0)
// 			return ((char *)(big + i));
// 		i++;
// 	}
// 	return (NULL);
// }

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		tmp = 0;
		if (big[i] == little[tmp])
		{
			
			while (big[i + tmp] == little[tmp] && (i + tmp) < len)
			{
				tmp++;
				if (little[tmp] == '\0')
					return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}

/*
si little vide -> rendre big
si little nowhere -> null
si little plus grand que big -> rendre je ne sais pas
si little dans big -> rendre pointeur de la premiere occurence
*/
// #include <stdio.h>

// int main(void)
// {
//     char	s1[] = "";
// 	char	s2[] = "une";
// 	char    s3[] = "Ni une ni deux, le loup mangea le chaperon-rouge";
// 	char    s4[] = "";
// 	int	n = 25;
// 	printf("%s\n", ft_strnstr(s1, s2, n));
//     printf("%s\n", ft_strnstr(s3, s4, n));
// 	return (0);
// }