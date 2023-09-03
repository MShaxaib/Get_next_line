/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaibi <zaibi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:36:45 by mshazaib          #+#    #+#             */
/*   Updated: 2023/09/03 19:53:37 by zaibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// takes cars of the chars that were not used in the prevous call
void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->str_buff[i] != '\0' && last_node->str_buff[i] != '\n')
		++i;
	while (last_node->str_buff[i] != '\0' && last_node->str_buff[++i])
		buf[k++] = last_node->str_buff[++i];
	buf[k] = '\0';
	clean_node->str_buff = buf;
	clean_node->next = NULL;
	cleanlists(list, clean_node, buf);
}
//copy the chars into the list
void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->str_buff[i])
		{
			if (list->str_buff[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->str_buff[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}
//counts the len of chars until it reaches new line
int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buff[i])
		{
			if (list->str_buff[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
//just checks if found new line 
int	found_newline(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buff[i] && i < BUFFER_SIZE)
		{
			if (list->str_buff[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}
//deallocate the lists for the next call
void	cleanlists(t_list **list, t_list *clean_node, char *buf)
{
	t_list *tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buff);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->str_buff[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}