/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:48:21 by desambou          #+#    #+#             */
/*   Updated: 2024/11/13 13:44:38 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// int main(void)
// {
//     char test [] = "Oh non de Zeus";
//     int test2 = 110;
//     printf("%s\n", test);
//     printf("%d dans le tableau Ascii\n", test2);
//     printf("%p\n", strchr(test, test2));
//     printf("%p\n", ft_strchr(test, test2));
//     return (0);
// }