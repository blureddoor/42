#include "../inc/myshell.h"
#include <signal.h>

void	parent_hdl(int signum)
{
	(void)signum;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	ft_putstr("\n($) ");
	//set status a 130?
}

void	child_hdl(int signum)
{

	if (signum == SIGQUIT)
		printf("Quit: 3");
		//set status a 131?
}

void	reg_parent_signals()
{
	signal(SIGINT, parent_hdl);
	signal(SIGQUIT, SIG_IGN);
}

void	reg_child_signals()
{
	signal(SIGINT, child_hdl);
	signal(SIGQUIT, child_hdl);
}
