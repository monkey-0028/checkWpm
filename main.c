#include <ncurses.h>

#define const_y 5

enum permission{
    enable,disable
};

int x=0;
int y=0;

//functions
enum permission check_window_size();
void set_layout(WINDOW *con, WINDOW *timer, WINDOW *use, WINDOW *message, WINDOW *work);
//

int main(){
    WINDOW *control,*timer,*user_info,*message,*work_space;
    
    initscr();
    noecho();
    raw();
    curs_set(0);
    keypad(stdscr,TRUE);
    
    //color
    if(has_colors()){
        start_color();
        init_pair(1,COLOR_RED,COLOR_BLACK);
        init_pair(2,COLOR_WHITE,COLOR_BLACK);
        init_pair(3,COLOR_YELLOW,COLOR_BLACK);
        init_pair(4,COLOR_GREEN,COLOR_BLACK);
        bkgd(COLOR_PAIR(2));
    }
    else{
        printw("This terminal doesn't support color : ");
        getchar();
        return 0;
    }
    refresh();

    getmaxyx(stdscr,y,x);

    //initial layout
    if(check_window_size() == enable){
        set_layout(control,timer,user_info,message,work_space);
    }
    
    int main_input=0;
    while(1){
        if(check_window_size() == disable){
            attron(COLOR_PAIR(1));
            printw("Current window size is not supported..");
            attroff(COLOR_PAIR(1));
            printw("\nPlease resize your window then press \"F2\"");
            refresh();
        }

        main_input = getch();

        //handling key inputs
        if(main_input == KEY_RESIZE){
            clear();
            getmaxyx(stdscr,y,x);
            if(check_window_size() == enable){
                set_layout(control,timer,user_info,message,work_space);
            }
        }
        
        refresh();

    }


    getch();

    curs_set(1);
    endwin();
    return 0;
}

#include "./INCL/check_window_size.h"
#include "./INCL/set_layout.h"