#include <iostream>
#include "map.h"
#include "position_t.h"
#include "node.h"

using namespace std;

int main()
{
//    Map map("map_one.txt");
    Map map("map_easy.txt");
    Map copy;
    node start(map.man,map.diamond_pos);
    node *goal;
    goal = map.bff_search(start, copy);
    print_path(goal);
    return 0;
}
