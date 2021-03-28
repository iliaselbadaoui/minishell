#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <termcap.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#define KEY_UP 183
#define KEY_DOWN 184
#define KEY_LEFT 186
#define KEY_RIGHT 185
#define ENTER 10
#define KEY_REMOVE 127
#define KEY_TAB 9
#define CTRL_D 4
int get_char()
{
	char c;
	int total;
	struct termios term, init;
	tcgetattr(0, &term);
	tcgetattr(0, &init);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
	total = 0;
	while (read(0, &c, 1) <= 0)
		;
	total += c;
	while (read(0, &c, 1) > 0)
		total += c;
	tcsetattr(0, TCSANOW, &init);
	return (total);
}
int ft_puts(int d)
{
	return (write(1, &d, sizeof(int)));
}
void ft_putchar(void *dt)
{
	write(1, dt, sizeof(int));
}
/*** FUNCTION STACK***/
void from_first_to_second(t_stack **first, t_stack **second)
{
	void *data;
	data = pop_st(second);
	while (data)
	{
		push(first, data);
		data = pop_st(second);
	}
}
void transfer_one_char(t_stack **first, t_stack **second)
{
	void *data;
	data = pop_st(second);
	if (data)
		push(first, data);
}
void delete_one_char(t_stack **st)
{
	void *data;
	data = pop_st(st);
	free(data);
}
void iprint(void *data)
{
	write(0, data, sizeof(int));
}
void input(t_stack **left, t_stack **right)
{
	print_stack(*right, iprint);
	write(0, "\n", 1);
	clear_stack(left, free);
	clear_stack(right, free);
}
/*** ***/
int main(void)
{
	int d;
	int *c;
	char *s;
	int len;
	int iter;
	t_stack *left, *right;
	len = 0;
	iter = 0;
	left = NULL;
	right = NULL;
	tgetent(NULL, getenv("TERM"));
	while (1)
	{
		d = get_char();
		if (d >= 32 && d < 127)
		{
			c = malloc(sizeof(int));
			*c = d;
			push(&left, c);
			write(1, &d, sizeof(int));
			s = tgetstr("sc", NULL);
			tputs(s, 1, ft_puts);
			print_stack(right, ft_putchar);
			//from_first_to_second(&left, &right);
			len++;
			iter++;
			s = tgetstr("rc", NULL);
			tputs(s, 1, ft_puts);
		}
		else if (d == KEY_UP)
			write(1, "\nKEY_UP\n", 8);
		else if (d == KEY_DOWN)
			write(1, "\nKEY_DOWN\n", 10);
		else if (d == KEY_LEFT)
		{
			if (iter > 0)
			{
				transfer_one_char(&right, &left);
				s = tgetstr("le", NULL);
				tputs(s, 1, ft_puts);
				iter--;
			}
		}
		else if (d == KEY_RIGHT)
		{
			if (iter < len)
			{
				transfer_one_char(&left, &right);
				s = tgetstr("nd", NULL);
				tputs(s, 1, ft_puts);
				iter++;
			}
		}
		else if (d == KEY_REMOVE)
		{
			if (iter > 0)
			{
				delete_one_char(&left);
				s = tgetstr("le", NULL);
				tputs(s, 1, ft_puts);
				s = tgetstr("sc", NULL);
				tputs(s, 1, ft_puts);
				s = tgetstr("ce", NULL);
				tputs(s, 1, ft_puts);
				print_stack(right, ft_putchar);
				s = tgetstr("rc", NULL);
				tputs(s, 1, ft_puts);
				iter--;
				len--;
			}
		}
		else if (d == ENTER)
		{
			while (iter > 0)
			{
				s = tgetstr("le", NULL);
				tputs(s, 1, ft_puts);
				iter--;
			}
			s = tgetstr("ce", NULL);
			tputs(s, 1, ft_puts);
			from_first_to_second(&left, &right);
			from_first_to_second(&right, &left);
			input(&left, &right);
			break;
		}
	}
	return (0);
}