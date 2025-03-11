/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:18:04 by desambou          #+#    #+#             */
/*   Updated: 2024/11/16 16:04:59 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len != 0)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		len--;
	}
	if (s[len] == (char)c)
		return ((char *)s + len);
	return (NULL);
}

// int main(void)
// {
//     char test [] = "Oh non de Zeus";
//     int test2 = 110;
//     printf("%s\n", test);
//     printf("%d dans le tableau Ascii\n", test2);
//     printf("%p\n", strrchr(test, test2));
//     printf("%p\n", ft_strrchr(test, test2));
//     return (0);
// }