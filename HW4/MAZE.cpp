//
// Created by dell on 10/31/2021.
//

#include "MAZE.h"
#include "stack"
#include "iostream"
using namespace std;

MAZE::MAZE(int* maze_def, int m, int n, position start, position end) {

    maze_size_m = m;
    maze_size_n = n;
    start_pos = start;
    curr_pos = start;
    end_pos = end;
    maze = new int* [m];
    for (int i=0; i<m; i++){
        maze[i] = new int [n];
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            maze[i][j] = *(maze_def+ i * m + j);
        }
    }
}
MAZE::~MAZE() {
    ;
}

void MAZE::prt_maze() {
    for (int i = 0; i<maze_size_m; i++){
        for (int j=0; j<maze_size_n; j++){
            cout<<" "<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
}

void MAZE::look_around(void){
    int direct = curr_pos.direct;
    for (int i=0; i<4; i++){
        direct++;
        switch (direct) {
            case 0:{ // up
                int x = curr_pos.x - 1;
                int y = curr_pos.y;
                if (maze[x][y] == 0){
                    move_to(direct, x, y);
                    return;
                }
                else{break;}
            }
            case 1:{ // right
                int x = curr_pos.x;
                int y = curr_pos.y + 1;
                if (maze[x][y] == 0){
                    move_to(direct, x, y);
                    return;
                }
                else{break;}
            }
            case 2:{ //down
                int x = curr_pos.x + 1;
                int y = curr_pos.y;
                if (maze[x][y] == 0){
                    move_to(direct, x, y);
                    return;
                }
                else{break;}
            }
            case 3:{ //left
                int x = curr_pos.x;
                int y = curr_pos.y - 1;
                if (maze[x][y] == 0){
                    move_to(direct, x, y);
                    return;
                }
                else{break;}
            }
        }
    }
    step_back();
    return;
}
void MAZE::move_to(int direction, int target_x, int target_y) {
    curr_pos.direct = direction;
    record.push(curr_pos);
    maze[curr_pos.x][curr_pos.y] = 3;
    curr_pos.x = target_x;
    curr_pos.y = target_y;
    curr_pos.direct = -1;
    // cout<<"MOVE  To"<<"( "<<curr_pos.x<<", "<<curr_pos.y<<" )"<<endl;
    // prt_maze();
    return;
}

void MAZE::step_back() {
    maze[curr_pos.x][curr_pos.y] = 0;
    curr_pos = record.top();
    record.pop();
    // cout<<"BACK  To"<<"( "<<curr_pos.x<<", "<<curr_pos.y<<" )"<<endl;
    // prt_maze();

}

bool MAZE::check(){
    if(curr_pos.x == end_pos.x && curr_pos.y == end_pos.y){
        return true;
    }
    else{
        return false;
    }
}
bool MAZE::find_a_way() {
    if(start_pos.x == end_pos.x && start_pos.y == end_pos.y){
        return true;
    }
    curr_pos.x = start_pos.x;
    curr_pos.y = start_pos.y;
    curr_pos.direct = -1;
    record.push(curr_pos);
    do{
        look_around();
        if(check()){
            maze[end_pos.x][end_pos.y] = 3;
            return true;
        }
    }while(!record.empty());
    return false;
}