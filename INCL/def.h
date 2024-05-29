#define INIT \
	initscr();\
	raw();\
	noecho();\
	keypad(stdscr,TRUE);\
	curs_set(0);\
	if(has_colors()){\
		start_color();\
		init_pair(1, COLOR_WHITE, COLOR_BLACK);\
		init_pair(2, COLOR_RED, COLOR_BLACK);\
		bkgd(COLOR_PAIR(1));\
	}\
	attron(A_BOLD);
	

#define END \
	curs_set(1);\
	endwin();


#define space(n)\
	for(int i=0;i<n;i++){\
		printw(" ");\
	}
