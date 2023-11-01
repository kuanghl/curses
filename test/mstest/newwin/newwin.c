/*
Compile: gcc main.c -lncurses
*/
#include <curses.h>

WINDOW* create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW* local_win);

int main(int argc, char* argv[])
{
    WINDOW* my_win;
    int startx, starty, width, height;
    int ch;
    initscr(); /* 初始化并进入curses 模式*/
    cbreak(); /* 行缓冲禁止，传递所有控制信息*/
    keypad(stdscr, TRUE); /* 程序需要使用F1 功能键*/
    height = 3;
    width = 10;
    starty = (LINES - height) / 2; /*计算窗口中心位置的行数*/
    startx = (COLS - width) / 2; /*计算窗口中心位置的列数*/
    printw("Press ESC/Q to exit");
    refresh();
    my_win = create_newwin(height, width, starty, startx);
    while (1)
    {
        ch = getch();
        printw("Press key 0x%x", ch);
        if ((ch == 0x01b) || (ch == 0x071)) {
            break;
        }

        switch (ch)
        {
        case KEY_LEFT:
            destroy_win(my_win);
            my_win = create_newwin(height, width, starty, --startx);
            break;
        case KEY_RIGHT:
            destroy_win(my_win);
            my_win = create_newwin(height, width, starty, ++startx);
            break;
        case KEY_UP:
            destroy_win(my_win);
            my_win = create_newwin(height, width, --starty, startx);
            break;
        case KEY_DOWN:
            destroy_win(my_win);
            my_win = create_newwin(height, width, ++starty, startx);
            break;
        }
    }
    endwin(); /*结束curses 模式*/
    return 0;
}

WINDOW* create_newwin(int height, int width, int starty, int startx)
{
    WINDOW* local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0);      /* 0, 0 是字符默认的行列起始位置*/
    wrefresh(local_win);        /*刷新窗口缓冲，显示box */
    return local_win;
}

void destroy_win(WINDOW* local_win)
{
    /* box(local_win, ' ', ' ');不会按照预期的那样清除窗口边框。
    而是在窗口的四个角落留下残余字符*/
    wborder(local_win, '1', '2', '3', '4', '5', '6', '7', '8');
    //wborder(local_win, '|', '|', '-', '-', '-', '-', '-', '+');
    /*参数注解9.3：
    * 1. win:当前操作的窗口
    * 2. ls:用于显示窗口左边界的字符
    * 3. rs:用于显示窗口右边界的字符
    * 4. ts:用于显示窗口上边界的字符
    * 5. bs:用于显示窗口下边界的字符
    * 6. tl:用于显示窗口左上角的字符
    * 7. tr:用于显示窗口右上角的字符
    * 8. bl:用于显示窗口左下角的字符
    * 9. br:用于显示窗口右下角的字符
    */
    wrefresh(local_win);
    delwin(local_win);
}
/**
结果：
                 ┌────────┐66666666666666666666666666666
                 │        │22222222222222222222222222222
                 └────────┘88888888888888888888888888888
                                              7444444448
                 53333333366666666666666      7444444448
                 53333333362222222222222      7444444448
                 53333333368888888888888      7444444448
                 5333333336   7444444448      7444444448
                 5333333336   7444444448      7444444448
                 5333333336   7444444448      7444444448
                 5333333336   7444444448      7444444448
                 5333333336   7444444448      7444444448
                 5333333336   7444444448      7444444448
                 5333333336   7444444448      7444444448
                 5333333336                   7444444448
                 5333333336                   7444444448
                 5333333336                   7444444448
                 555555555555555555555555555557444444448
                 111111111111111111111111111117444444448
                 777777777777777777777777777777444444448
*/

/*
wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
+--------------+
|              |
|              |
|              |
|              |
|              |
|              |
+--------------+
*/