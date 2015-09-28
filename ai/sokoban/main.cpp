#include <iostream>
#include "map.h"
#include "position_t.h"
#include "node.h"

using namespace std;

int main()
{
    Map map("map_one.txt");
    Map copy;
    node start(map.man,map.diamond_pos);
    map.add_all_possible_paths(start);
    map.print();
    std::cout << "\n\n";
    map.wave(copy,start.man,start.diamonds);
    copy.print();
    char ans;
    for(auto n : map.diamond_pos){
        ans = map.valid_move(n);
        if(ans){
            if(ans & east){
                //move;
            }
            if(ans & west){
                //move;
            }
            if(ans & north){
                //move;
            }
            if(ans & south){
                //move;
            }
            break;
        }
    }
    return 0;
}
