/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:33:48 by pgerbaud          #+#    #+#             */
/*   Updated: 2016/11/16 19:33:53 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lst;
	void		*cnt;

	cnt = NULL;
	lst = NULL;
	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(cnt = ft_memalloc(content_size + 1)))
		return (NULL);
	if (content)
		ft_memcpy(cnt, content, content_size);
	else
	{
		content_size = 0;
		cnt = NULL;
	}
	lst->content = cnt;
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
