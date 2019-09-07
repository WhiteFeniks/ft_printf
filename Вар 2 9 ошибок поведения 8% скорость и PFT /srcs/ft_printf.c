/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 11:19:18 by shunt             #+#    #+#             */
/*   Updated: 2019/06/02 11:19:44 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbuf(char *s, int b)
{
	int		i;

	i = -1;
	while (++i < b)
		write(1, &s[i], 1);
}

t_rd	*ft_newlist(t_rd **t)
{
	t_rd	*l;

	if (!(l = (t_rd *)malloc(sizeof(t_rd))))
		return (NULL);
	l->mod = NULL;
	l->mod2 = NULL;
	l->mod_smb = 0;
	l->zero = 0;
	l->kostil = 0;
	l->width = 0;
	l->flag = 0;
	l->prs = 6;
	l->size = 0;
	l->next = NULL;
	l->prev = *t;
	l->smb_cnt = 0;
	l->sign = 0;
	l->strlen = 0;
	return (l);
}

void	ft_next_list(t_printf *p, const char *format)
{
	p->read = p->read->next;
	p->read->smb_cnt = p->read->prev->smb_cnt;
	p->read->strlen = p->read->prev->strlen;
	format[p->read->smb_cnt] ? ++p->read->smb_cnt : 0;
}

int		ft_prepare(t_printf *p, const char *format)
{
	p->output.cnt = 0;
	p->output.buf = NULL;
	if (!(p->read = (t_rd *)malloc(sizeof(t_rd))))
		return (0);
	p->read->strlen = ft_strlen(format);
	p->read->smb_cnt = 0;
	p->read->prev = NULL;
	p->read->mod = NULL;
	p->read->mod2 = NULL;
	p->read->mod_smb = 0;
	p->read->zero = 0;
	p->read->kostil = 0;
	p->read->width = 0;
	p->read->flag = 0;
	p->read->prs = 6;
	p->read->size = 0;
	p->read->next = NULL;
	p->read->sign = 0;
	return (SUCCESS);
}

int		ft_printf(const char *format, ...)
{
	t_printf	p;

	if (!(*format))
		return (0);
	if (!(ft_prepare(&p, format)))
		return (0);
	va_start(p.ap, format);
	while (format[p.read->smb_cnt])
	{
		if (!(p.read->next = ft_newlist(&p.read)))
			return (0);
		if (!(ft_pt_frst(format, &p.output, &p.read)))
			return (0);
		ft_reader(&p.read, &p.ap, format, &p.output);
		if (!(ft_solver(&p.read, &p.output)))
			return (0);
		ft_next_list(&p, format);
	}
	va_end(p.ap);
	ft_putbuf(p.output.buf, p.output.cnt);
	p.output.buf ? free(p.output.buf) : 0;
	ft_free_lists(&p.read);
	return (p.output.cnt);
}
