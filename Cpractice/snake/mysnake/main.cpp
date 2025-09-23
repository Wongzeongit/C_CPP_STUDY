#include <ctime>
#include <graphics.h>
#include "snake.h"


int main()
{
    srand(time(0));
    mouse_msg msg={0};
    for (;is_run();delay_fps(60)) {
        SETBASE();
        while (mousemsg()) {
            msg=getmouse();
        }
        if (msg.x>500&&msg.x<620&&msg.y>120&&msg.y<200&&msg.is_left()) {
            STARTGAME();
        }
        if (msg.x>525&&msg.x<600&&msg.y>220&&msg.y<260&&msg.is_left()) {
            flag_diff=0;
        }
        if (msg.x>525&&msg.x<600&&msg.y>270&&msg.y<310&&msg.is_left()) {
            flag_diff=1;
        }
    }

    getch();
    closegraph();
    return 0;
}
