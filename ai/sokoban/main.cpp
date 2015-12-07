#include <iostream>
#include "map.h"
#include "position_t.h"
#include "node.h"

#include <unistd.h>
using namespace std;

int main(int argc, char** argv){
//    Map map("map_one.txt");
    Map map;
    if(argc == 2){
//        std::cout << "argument: " << argv[1] << '\n';
        map.read_file(argv[1]);
    } else {
//        map.read_file("map_2014.txt");
//        map.read_file("solvertest03.txt");
//        map.read_file("map_5.txt");
        map.read_file("map_2015.txt");
    }
//    Map map("map_easy.txt");
    Map copy;

    map.man.x = 8;
    map.man.y = 2;
    node start(map.man,map.diamond_pos);
    std::vector<std::vector<float>> cost_map = map.find_robot_moves(copy, &start);
    map.print();
    for(size_t y = 0; y < cost_map.at(0).size(); ++y){
        for(size_t x = 0; x < cost_map.size(); ++x){
            std::cout << (int) cost_map[x][y] << "\t";
        }
        std::cout << "\n";
    }
//    node *goal;
//    map.bff_search(copy);
    map.informed_bff_search(copy);
//    map.idf_search(copy);
    return 0;
}
