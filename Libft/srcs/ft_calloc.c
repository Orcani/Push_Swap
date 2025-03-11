/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:21:55 by desambou          #+#    #+#             */
/*   Updated: 2024/11/15 14:12:48 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb != 0 && size > ((size_t)-1) / nmemb)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}

// int	main(void)
// {
// 	int test1 = 4;
//     int test2 = 3;

// 	printf("Code source: %d\nCode target: %p\n", test1, ft_calloc(test1,
//			test2));
// 	printf("Code source: %d\nCode target: %p\n", test1, calloc(test1, test2));

// 	return (-42);
// }
