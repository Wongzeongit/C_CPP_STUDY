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
    img_head_up=newimage();getimage(img_head_up,"snakeHeadUp.png");
    img_head_down=newimage();getimage(img_head_down,"snakeHeadDown.png");
    img_head_left=newimage();getimage(img_head_left,"snakeHeadLeft.png");
    img_head_right=newimage();getimage(img_head_right,"snakeHeadRight.png");
    img_tail=newimage();getimage(img_tail,"snakeTail.png");
    img_apple=newimage();getimage(img_apple,"china.png");
    img_wall=newimage();getimage(img_wall,"wall.png");
    if (flag_diff==1) {
        SETWALL(wall);
    } else {
        cleardevice();
        SETBASE();
    }
    snake snk;
    snk.Printsnake();
    for (;is_run();delay_fps(60)) {
        if (!Myapple.is_exist) {
            Myapple.position.first=rand()%19;
            Myapple.position.second=rand()%19;
            if (flag_diff==1) {
                for (int i=0;i<10;i++) {
                    if (Myapple.position==wall.at(i)) {
                        Myapple.position.first=rand()%19;
                        Myapple.position.second=rand()%19;
                        i=0;
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
            Myapple.is_exist=true;
        }
        putimage(Myapple.position.first*24+2,Myapple.position.second*24+2,img_apple);
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
        setfillcolor(BLACK);
        bar(500,340,620,420);
        setfont(18,0,"consolas");
        setcolor(RED);
        outtextxy(510,350,("最高分数："+std::to_string(Max_score)).c_str());
        outtextxy(510,386,("当前分数："+std::to_string(score)).c_str());
        int sleep_time=300-snk.length*8;
        if (sleep_time<50) sleep_time=50;
        Sleep(sleep_time);
    }
}
void GAMEOVER() {
    if (score>Max_score) Max_score=score;
    std::string message="游戏结束！你的分数是："+std::to_string(score)+"\n最高分数是："+ std::to_string(Max_score);
    score=0;
    MessageBox(NULL, message.c_str(), "GAME OVER", MB_OK);
}
void SETWALL(std::pmr::vector<std::pair<int,int>> &wall) {
    cleardevice();
    SETBASE();
    wall.clear();
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
            if (Myapple.is_delicious) {length++;tailtoremove=0;score+=20;}
            else if (length>2) {length--;tailtoremove=2;score+=10;}
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
            if (Myapple.is_delicious) {length++;tailtoremove=0;score+=20;}
            else if (length>2) {length--;tailtoremove=2;score+10;}
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
            if (Myapple.is_delicious) {length++;tailtoremove=0;score+=20;}
            else if (length>2) {length--;tailtoremove=2;score+=10;}
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
            if (Myapple.is_delicious) {length++;tailtoremove=0;score+=20;}
            else if (length>2) {length--;tailtoremove=2;score+=10;}
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
        bar(tail->x*24+1,tail->y*24+1,tail->x*24+23,tail->y*24+23);
        delete tail;
        cur->next=nullptr;
    }
    return TRUE;
}
void snake::Printsnake() const {
    Node* cur=head;
    PIMAGE img_head=nullptr;
    if (direction=="left") {img_head=img_head_left;}
    else if (direction=="right") {img_head=img_head_right;}
    else if (direction=="up") {img_head=img_head_up;}
    else {img_head=img_head_down;}
    putimage(cur->x*24+2,cur->y*24+2,img_head);
    cur=cur->next;
    while (cur) {
        putimage(cur->x*24+2,cur->y*24+2,img_tail);
        cur=cur->next;
        }
}