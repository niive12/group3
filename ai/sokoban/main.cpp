#include <iostream>
#include "map.h"
#include "position_t.h"
#include "node.h"

#include <unistd.h>
using namespace std;

int main()
{
    Map map("map_one.txt");
//    Map map("map_easy.txt");
    Map copy;
    node start(map.man,map.diamond_pos);
    node *goal;
    goal = map.bff_search(&start, copy);
//    for(auto n : goal->diamonds){
//        std::cout << n;
//    } std::cout << "\n";

    map.print_path(copy,goal);
    return 0;
}
