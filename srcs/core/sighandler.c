/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:00:04 by tduval            #+#    #+#             */
/*   Updated: 2019/03/20 20:44:55 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ft_select.h"
#include "libft.h"

extern t_args	*g_lst;

static void	sigwinch_case(int a)
{
	(void)a;
	print_list();
}

void		exit_properly(int a)
{
	char	*tc;
	t_args	*tmp;

	while (g_lst->prev->head == false)
		g_lst = g_lst->next;
	while (g_lst && g_lst->head == false)
	{
		tmp = g_lst;
		free(tmp->arg);
		free(tmp);
		g_lst = g_lst->next;
	}
	free(g_lst);
	free(g_lst->arg);
	tc = tgetstr("ve", 0);
	tputs(tc, 2, ft_putchar);
	tc = tgetstr("te", 0);
	tputs(tc, 2, ft_putchar);
	exit(1);
	(void)a;
}

static void	sigstop_case(int a)
{
	(void)a;
	ioctl(2, TIOCSTI, "\x1A");
}

void	sighandler(void)
{
	signal(SIGTSTP, sigstop_case);
	signal(SIGINT, exit_properly);
	signal(SIGWINCH, sigwinch_case);
}
