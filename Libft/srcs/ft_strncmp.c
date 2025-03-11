/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:13:07 by desambou          #+#    #+#             */
/*   Updated: 2024/11/14 16:09:29 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n--)
	{
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
// int main(void)
// {

// 	char	s1[] = "incroyable!";
// 	char	s2[] = "incredible!";
// 	char    s3[] = "Dedel";
// 	char    s4[] = "Dedel!";
// 	int	n = 5;
// 	printf("%d\n", ft_strncmp(s1, s2, n));
//     printf("%d\n", ft_strncmp(s3, s4, n));
//     printf("%d\n", strncmp(s1, s2, n));
//     printf("%d\n", strncmp(s3, s4, n));
// 	return (0);
// }
