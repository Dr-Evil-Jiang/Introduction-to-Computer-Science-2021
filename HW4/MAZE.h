//
// Created by dell on 10/31/2021.
//
#include "stack"
#ifndef HW4_MAZE_H
#define HW4_MAZE_H
class position{
public:
    int x, y, direct;
};

class MAZE {
public:
    position curr_pos;
    position start_pos;
    position end_pos;
    int maze_size_m;
    int maze_size_n;
    int** maze;
    std::stack<position> record;

    MAZE(int* maze_def, int m, int n, position start, position end);
    ~MAZE(void);
    void prt_maze(void);
    void look_around(void);
    void move_to(int direction, int target_x, int target_y);
    void step_back();
    bool check(void);
    bool find_a_way(void);
};


#endif //HW4_MAZE_H
