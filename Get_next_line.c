/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:29:00 by mshazaib          #+#    #+#             */
/*   Updated: 2023/08/13 16:35:45 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char get_next_line(int fd)
{
	static t_list *root;
	t_list	*p;
	static char		*result;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	
}



int main()
{
	int fd;
	char buff[2048];
	char path[] = "/Users/mshazaib/Desktop/Get_Next_line/Hellotest.txt";

	fd = open(path, O_RDONLY);
	read(fd, buff, 2048);
	printf("\n\n-----\n%s-----\n\n\n", buff);
	
}
