void set_layout(WINDOW *con, WINDOW *timer, WINDOW *use, WINDOW *message, WINDOW *work){
    int ratio = x/4;
    con = newwin(const_y,ratio,0,0);
    timer = newwin(const_y,2*ratio,0,ratio);
    use = newwin(const_y,ratio,0,3*ratio);
    message = newwin(2,2*ratio,const_y,2*ratio);
    work = newwin((y-const_y-2),x,const_y+2,0);
    box(con,0,0);
    box(timer,0,0);
    box(use,0,0);
    box(message,0,0);
    box(work,0,0);
    refresh();
    wrefresh(con);
    wrefresh(timer);
    wrefresh(message);
    wrefresh(use);
    wrefresh(work);
}