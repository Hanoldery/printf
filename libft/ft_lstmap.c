/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:46:57 by Pierre            #+#    #+#             */
/*   Updated: 2016/11/16 19:35:29 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	result = NULL;
	temp = NULL;
	if (!(result = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	result = f(lst);
	temp = result;
	lst = lst->next;
	while (lst)
	{
		temp->next = f(lst);
		if (!temp)
			return (NULL);
		temp = (temp)->next;
		lst = lst->next;
	}
	return (result);
}
