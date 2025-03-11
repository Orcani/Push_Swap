/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:30:12 by desambou          #+#    #+#             */
/*   Updated: 2024/11/15 14:22:48 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*target;

	target = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (target == NULL)
		return (NULL);
	ft_strlcpy(target, s, ft_strlen(s) + 1);
	return (target);
}

// int	main(void)
// {
// 	char src[] = "s";

// 	printf("Code source: %s\nCode target: %s\n", src, ft_strdup(src));
// 	printf("Code source: %s\nCode target: %s\n", src, strdup(src));

// 	return (-42);
// }