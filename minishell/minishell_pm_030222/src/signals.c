#include "../inc/myshell.h"
#include <signal.h>

void	parent_hdl(int signum)
{
	if (signum == SIGINT)
	{

	}
	else if (signum == SIGQUIT)
	{

	}
}

void	child_hdl(int signum)
{
	if (signum == SIGINT)
	{
		printf("Sigint child\n");
	}
	else if (signum == SIGQUIT)
	{
		printf("Quit: 3");
	}
}

void	reg_parent_signals()
{
	printf("registering parent signals...\n");
	signal(SIGINT, parent_hdl);
	signal(SIGQUIT, parent_hdl);
}

void	reg_child_signals()
{
	printf("registering child signals...\n");
	signal(SIGINT, child_hdl);
	signal(SIGQUIT, child_hdl);
}
