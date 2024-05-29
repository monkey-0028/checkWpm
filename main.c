#include <ncurses.h>
#include <string.h>
#include "./INCL/def.h"


int x=0;
short int option(char *non_select[],char *select[],int len, int max_char);


int main(){
	INIT
	x = getmaxx(stdscr);

	char *strings[] = {"hi","this"};
	char *s_strings[]={"h i","t h i s"};
	option(strings,s_strings,2,strlen("t h i s"));
	
	

	END
	return 0;
}
short int option(char *non_select[],char *select[],int len,int max_char){
	short int pointer=0;
	short int input_value=0;
	while(input_value != 10){
		printw("\n\n");
		for(int i=0;i<len;i++){
			//align in the center
			space((x-max_char)/2)
		
			if(pointer==i){
				attron(COLOR_PAIR(2));
				printw("%s\n",select[i]);
				attroff(COLOR_PAIR(2));
			}
			else{
				printw("%s\n",non_select[i]);
			}

		}
		refresh();
		input_value  = getch();
		if(input_value == KEY_UP){
			pointer-=1;
			if(pointer == -1){pointer = len-1;}
		}
		if(input_value == KEY_DOWN){
			pointer+=1;
			if(pointer == len){pointer=0;}
		}
		printw("%d",pointer);
		clear();
	}
	return pointer;
}

