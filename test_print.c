/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:27:57 by pniva             #+#    #+#             */
/*   Updated: 2021/11/23 13:47:34 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	char	*nl = "\n";
	int		fd;
	ft_putchar('1');
	ft_putchar('\n');
	ft_putstr("2");
	ft_putstr(nl);
	ft_putendl("3");
	ft_putchar_fd('4', 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("5\n", 1);
	ft_putendl_fd("6", 1);
	ft_putnbr_fd(7, 1);
	ft_putchar('\n');
	fd = open("./printtest",O_WRONLY | O_CREAT , 0777);
	ft_putstr_fd("first line", fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("2nd line", fd);
	ft_putnbr_fd(3, fd);
	ft_putstr_fd("rd line", fd);
	ft_putchar_fd('\n', fd);
	close(fd);
}
