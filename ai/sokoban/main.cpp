#include <iostream>
#include "map.h"
#include "position_t.h"

using namespace std;

int main()
{
    Map map("map_one.txt");
    map.print();
    std::cout << "\n\n";

    Map copy;
    copy = map;
    map.wave(copy,map.man);
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
