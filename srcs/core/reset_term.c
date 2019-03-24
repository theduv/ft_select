/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:31:06 by tduval            #+#    #+#             */
/*   Updated: 2019/03/24 20:26:40 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <termios.h>
#include "libft.h"

extern struct termios	g_rep;

void	reset_term(void)
{
	tputs(tgetstr("ve", 0), 2, ft_putchar);
	tcsetattr(2, TCSANOW, &g_rep);
}
