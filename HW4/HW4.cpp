#include <iostream>
#include "POLN.h"
#include "MAZE.h"
#include "STACK.h"
#include "OPERATION.h"

using namespace std;
//Implement 2.23
void test_2_23(){
    // 2-23 Test
    int expo_1[] = {4, 3, 1, 0};
    double coeff_1[] = {1, 2, 3, 3};
    POLN my_poly_1;
    my_poly_1.init_from_arr(coeff_1, sizeof(coeff_1)/ sizeof(coeff_1[0]), expo_1, sizeof(expo_1)/ sizeof(expo_1[0]));
    cout<<"Polynomial 1: "<<endl;
    my_poly_1.prt_poly();
    int expo_2[] = {4, 3, 1};
    double coeff_2[] = {1, -2, 3};
    POLN my_poly_2;
    my_poly_2.init_from_arr(coeff_2, sizeof(coeff_2)/ sizeof(coeff_2[0]), expo_2, sizeof(expo_2)/ sizeof(expo_2[0]));
    cout<<"Polynomial 2: "<<endl;
    my_poly_2.prt_poly();
    POLN add_res;
    cout<<"Results: "<<endl;
    add_res.add_poln(my_poly_1, my_poly_2);
    add_res.prt_poly();
    return;
}

// Implement maze
void test_maze(){
    // maze Test
    int maze_def[10][10] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
            {1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
            {1, 0 ,0 ,0, 0, 1, 1, 0, 0, 1},
            {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
            {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
            {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
            };
    position start, end;

    start.x = 1;
    start.y = 1;
    start.direct = -1;
    end.x = 8;
    end.y = 8;
    end.direct = -1;

    MAZE my_maze = MAZE((int*)maze_def, 10, 10, start, end);
    cout<<"The maze is: "<<endl;
    my_maze.prt_maze();
    bool status = my_maze.find_a_way();
    cout<<endl;
    if (status){
        cout<<"The solution is: "<<endl;
    }
    else{
        cout<<"The given maze has no solution!"<<endl;
    }
    my_maze.prt_maze();
}

// implement 3.4
void test_3_4(){
    OPERATION test;
    cout<<"Please input the expression: "<<endl;
    cout<<test.calculate_expression()<<endl;
}
int main() {
    cout<<"Test 2.23: "<<endl;
    test_2_23();
    cout<<endl;
    cout<<"Test maze: "<<endl;
    test_maze();
    cout<<endl;
    cout<<"Test 3.4: "<<endl;
    test_3_4();
    return 0;
}
