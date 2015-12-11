#include <iostream>
#include "map.h"
#include "position_t.h"
#include "node.h"

#include <unistd.h>

//to meassure timing
#include <ratio>
#include <chrono>


int main(int argc, char** argv){
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;

    Map map;
    if(argc == 2){
        map.read_file(argv[1]);
    } else {
        map.read_file("map_2015.txt");
    }
    Map copy;

    t1 = std::chrono::high_resolution_clock::now();
    map.informed_bff_search(copy);
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() << "\n";
//    map.optimize_for_robot_moves = true;
//    t1 = std::chrono::high_resolution_clock::now();
//    map.informed_bff_search(copy);
//    t2 = std::chrono::high_resolution_clock::now();
//    std::cout << std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() << "\n";
    return 0;
}
