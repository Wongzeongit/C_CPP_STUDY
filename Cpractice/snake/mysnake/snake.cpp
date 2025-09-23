//
// Created by JJ on 2025/9/23.
//

#include "snake.h"

#include <ctime>
#include <ege.h>
#include <utility>
#include <vector>
#include <graphics.h>


void STARTGAME() {
    if (flag_diff==1) {
        SETWALL(wall);
    } else {
        cleardevice();
        SETBASE();
    }
    snake snk;
    snk.Printsnake();
    PIMAGE apple=newimage();
    getimage(apple,"china.png");
    for (;is_run();delay_fps(60)) {
        if (!Myapple.is_exist) {
            Myapple.position.first=rand()%19;
            Myapple.position.second=rand()%19;
            if (flag_diff==1) {
                for (auto it:wall) {
                    if (Myapple.position==it) {
                        Myapple.position.first=rand()%19;
                        Myapple.position.second=rand()%19;
                        it=wall.at(0);
                    }
                }
            } else {
                Myapple.position.first=rand()%19;
                Myapple.position.second=rand()%19;
            }
            switch (rand()%2) {
                case 0:
                Myapple.is_delicious=false;
                break;
                case 1:
                Myapple.is_delicious=true;
                break;
            }
            putimage(Myapple.position.first*24+2,Myapple.position.second*24+2,apple);
            Myapple.is_exist=true;
        }
        int k=0;
        if (kbhit()) k=getch();
        switch (k) {
            case 293:
                snk.direction="left";
                break;
            case 294:
                snk.direction="up";
                break;
            case 295:
                snk.direction="right";
                break;
            case 296:
                snk.direction="down";
                break;
        }
        if (!snk.move(wall)) break;
        snk.Printsnake();
        Sleep(300);
    }
}
void GAMEOVER() {
    MessageBox(NULL, "GAME OVER", "GAME OVER", MB_OK);
}
void SETWALL(std::pmr::vector<std::pair<int,int>> &wall) {
    cleardevice();
    SETBASE();
    wall.clear();
    PIMAGE img_wall;
    img_wall=newimage();
    getimage(img_wall,"wall.png");
    for (int n=0;n<10;n++) {
        int rdx=rand()%19;
        int rdy=rand()%19;
        while (rdx>=10&&rdx<=12&&rdy>=10&&rdy<=12) {
            rdx=rand()%19;
            rdy=rand()%19;
        }
        putimage(rdx*24+2,rdy*24+2,img_wall);
        wall.push_back(std::make_pair(rdx,rdy));
    }
}

void SETBASE() {
    initgraph(640,480,0);
    setcolor(WHITE);
    line(480,0,480,480);
    setfillcolor(LIGHTGRAY);
    floodfill(639,479,WHITE);
    for (int i=0;i<=480;i+=24) {
        setcolor(BLUE);
        line(0,i,480,i);
        if (i!=480) line(i,0,i,480);
    }
    setfillcolor(WHITE);
    bar(500,120,620,200);
    setfont(30,0,"consolas");
    setbkmode(TRANSPARENT);
    outtextxy(530,145,"开 始");
    setfillcolor(DARKGRAY);
    bar(525,220,600,260);
    setcolor(BLACK);
    outtextxy(535,225,"简单");
    bar(525,270,600,310);
    outtextxy(535,275,"困难");
    setrendermode(RENDER_MANUAL);

    //前置工作完成
}

Node::Node(int a,int b) {
    x=a;
    y=b;
    next = nullptr;
}

snake::snake() {
    head = new Node(11,11);
    head->next = new Node(12,11);
    length=2;
    direction="left";
}
snake::~snake() {
    while (head) {
        Node *p=head->next;
        delete head;
        head = p;
    }
}
bool snake::move(const std::pmr::vector<std::pair<int,int>> wall) {
    int tailtoremove=1;
    if (direction=="left") {
        if (this->head->x-1==-1) {GAMEOVER();Myapple.is_exist=false;return FALSE;}
        for (auto it:wall) {
            if (it.first==this->head->x-1 && it.second==this->head->y) {
                GAMEOVER();
                Myapple.is_exist=false;
                return FALSE;
            }
        }
        Node* cur=head;
        while (cur) {
            if (cur->x==this->head->x-1 && cur->y==this->head->y) {
                GAMEOVER();
                Myapple.is_exist=false;
                return FALSE;
            }
            cur=cur->next;
        }
        if (this->head->x-1==Myapple.position.first && this->head->y==Myapple.position.second) {
            if (Myapple.is_delicious) {length++;tailtoremove=0;}
            else if (length>2) {length--;tailtoremove=2;}
            Myapple.is_exist=false;
        }
        Node* newNode=new Node(this->head->x-1,this->head->y);
        newNode->next=head;
        head=newNode;
    } else if (direction=="right") {
        if (this->head->x+1==20) {GAMEOVER();Myapple.is_exist=false;return FALSE;}
        for (auto it:wall) {
            if (it.first==this->head->x+1 && it.second==this->head->y) {
                GAMEOVER();
                Myapple.is_exist=false;
                return FALSE;
            }
        }
        Node* cur=head;
        while (cur) {
            if (cur->x==this->head->x+1 && cur->y==this->head->y) {
                GAMEOVER();
                Myapple.is_exist=false;
                return FALSE;
            }
            cur=cur->next;
        }
        if (this->head->x+1==Myapple.position.first && this->head->y==Myapple.position.second) {
            if (Myapple.is_delicious) {length++;tailtoremove=0;}
            else if (length>2) {length--;tailtoremove=2;}
            Myapple.is_exist=false;
        }
        Node* newNode=new Node(this->head->x+1,this->head->y);
        newNode->next=head;
        head=newNode;
    } else if (direction=="up") {
        if (this->head->y-1==-1) {GAMEOVER();Myapple.is_exist=false;return FALSE;}
        for (auto it:wall) {
            if (it.first==this->head->x && it.second==this->head->y-1) {
                GAMEOVER();
                Myapple.is_exist=false;
                return FALSE;
            }
        }
        Node* cur=head;
        while (cur) {
            if (cur->x==this->head->x && cur->y==this->head->y-1) {
                GAMEOVER();
                Myapple.is_exist=false;
                return FALSE;
            }
            cur=cur->next;
        }
        if (this->head->x==Myapple.position.first && this->head->y-1==Myapple.position.second) {
            if (Myapple.is_delicious) {length++;tailtoremove=0;}
            else if (length>2) {length--;tailtoremove=2;}
            Myapple.is_exist=false;
        }
        Node* newNode=new Node(this->head->x,this->head->y-1);
        newNode->next=head;
        head=newNode;
    } else if (direction=="down") {
        if (this->head->y+1==20) {GAMEOVER();Myapple.is_exist=false;return FALSE;}
        for (auto it:wall) {
            if (it.first==this->head->x && it.second==this->head->y+1) {
                GAMEOVER();
                Myapple.is_exist=false;
                return FALSE;
            }
        }
        Node* cur=head;
        while (cur) {
            if (cur->x==this->head->x && cur->y==this->head->y+1) {
                GAMEOVER();
                Myapple.is_exist=false;
                return FALSE;
            }
            cur=cur->next;
        }
        if (this->head->x==Myapple.position.first && this->head->y+1==Myapple.position.second) {
            if (Myapple.is_delicious) {length++;tailtoremove=0;}
            else if (length>2) {length--;tailtoremove=2;}
            Myapple.is_exist=false;
        }
        Node* newNode=new Node(this->head->x,this->head->y+1);
        newNode->next=head;
        head=newNode;
    }
    for (int i=0;i<tailtoremove;i++) {
        if (head==nullptr||head->next==nullptr||head->next->next==nullptr) {
            break;
        }
        Node* cur = head;
        while (cur->next && cur->next->next != nullptr) {
            cur = cur->next;
        }
        Node* tail = cur->next;
        setfillcolor(BLACK);
        floodfill(tail->x*24+1,tail->y*24+1,BLUE);
        delete tail;
        cur->next=nullptr;
    }
    return TRUE;
}
void snake::Printsnake() const {
    Node* cur=head;
    PIMAGE img_head;
    img_head=newimage();
    if (direction=="left") {getimage(img_head,"snakeHeadLeft.png");}
    else if (direction=="right") {getimage(img_head,"snakeHeadRight.png");}
    else if (direction=="up") {getimage(img_head,"snakeHeadUp.png");}
    else {getimage(img_head,"snakeHeadDown.png");}
    putimage(cur->x*24+2,cur->y*24+2,img_head);
    delimage(img_head);
    cur=cur->next;
    PIMAGE img_tail;
    img_tail=newimage();
    getimage(img_tail,"snakeTail.png");
    while (cur) {
        putimage(cur->x*24+2,cur->y*24+2,img_tail);
        cur=cur->next;
        }
    delimage(img_tail);
}
