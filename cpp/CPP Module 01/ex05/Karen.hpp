#ifndef KAREN_H
# define KAREN_H

# include <iostream>
# include <map>
# include <string>


class Karen{
	typedef struct s_status
	{
		std::string name;
		void(Karen::*ptr)(void);
	}	t_status;
	public:
		void complain(std::string level);
		Karen(void);

	private:
		t_status stat[4];
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

		void init(void);
};

#endif