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
        std::cout << "argument: " << argv[1] << '\n';
        map.read_file(argv[1]);
    } else {
        map.read_file("map_one.txt");
    }
//    Map map("map_easy.txt");
    Map copy;
    node *goal;
    map.bff_search(copy);
    map.informed_bff_search(copy);
    return 0;
}

