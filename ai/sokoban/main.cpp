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
//    node start(map.man,map.diamond_pos);
//    node end(map.man,map.goals);
    node *goal;
//    std::vector<pos_t> kaj;
    goal = map.bff_search(copy);
    map.print_path(copy,goal);
    return 0;
}
