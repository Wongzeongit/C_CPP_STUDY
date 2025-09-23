//
// Created by JJ on 2025/9/23.
//

#ifndef MYSNAKE_SNAKE_H
#define MYSNAKE_SNAKE_H
#include <string>
#include <vector>

inline int flag_diff=0;//标记困难度
inline std::pmr::vector<std::pair<int, int>> wall;//障碍物标记


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