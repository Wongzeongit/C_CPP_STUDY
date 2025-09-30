//
// Created by JJ on 2025/9/23.
//

#ifndef MYSNAKE_SNAKE_H
#define MYSNAKE_SNAKE_H
#include <ege.h>
#include <string>
#include <vector>

inline int flag_diff=0;//标记困难度
inline std::pmr::vector<std::pair<int, int>> wall;//障碍物标记
inline int score=0,Max_score=0;
inline ege::PIMAGE img_head_up,img_head_down,img_head_left,img_head_right,img_tail,img_wall,img_apple;


void SETWALL(std::pmr::vector<std::pair<int,int>>&);
void SETBASE();
void STARTGAME();


struct Node {
    int x;
    int y;
    Node* next;
    Node(int a=0, int b=0);
};

class snake {
    public:
    Node* head;
    int length;
    std::string direction;
    snake();
    ~snake();
    bool move(const std::pmr::vector<std::pair<int,int>> wall);
    void Printsnake() const;
};

class apple {
    public:
    bool is_exist=false;
    bool is_delicious=false;
    std::pair<int,int> position;
};
inline apple Myapple;

#endif //MYSNAKE_SNAKE_H