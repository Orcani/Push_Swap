/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:36:40 by desambou          #+#    #+#             */
/*   Updated: 2024/11/15 14:13:07 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

// int main(void)
// {

// 	char	s1[] = "incroyable!";
// 	char	s2[] = "incredible!";
// 	char    s3[] = "Dedel";
// 	char    s4[] = "Dedel!";
// 	int	n = 5;
// 	printf("%d\n", ft_memcmp(s1, s2, n));
//     printf("%d\n", ft_memcmp(s3, s4, n));
//     printf("%d\n", memcmp(s1, s2, n));
//     printf("%d\n", memcmp(s3, s4, n));
// 	return (0);
// }
