#include "map.h"

char Map::valid_move(pos_t diamond){
    const unsigned char col = 2;
    char ans = 0;
    pos_t A,B;
    A = diamond + above;
    B = diamond + below;
    //if i can move from A to B: and B does not lock the diamond, move;
    if( (get(A) > col) && (get(B) > col || get(B) == FREE) ){ if(!locked_in(B)){ ans += south; } }
    if( (get(B) > col) && (get(A) > col || get(A) == FREE) ){ if(!locked_in(A)){ ans += north; } }
    A = diamond + left;
    B = diamond + right;
    if( (get(A) > col) && (get(B) > col || get(B) == FREE) ){ if(!locked_in(B)){ ans += east; } }
    if( (get(B) > col) && (get(A) > col || get(A) == FREE) ){ if(!locked_in(A)){ ans += west; } }
    return ans;
}

bool Map::locked_in(pos_t diamond){
    bool ans = false;
    if( get(diamond + above) == OBSTACLE && get(diamond + right) == OBSTACLE){ ans = true; }
    if( get(diamond + above) == OBSTACLE && get(diamond + left)  == OBSTACLE){ ans = true; }
    if( get(diamond + below) == OBSTACLE && get(diamond + right) == OBSTACLE){ ans = true; }
    if( get(diamond + below) == OBSTACLE && get(diamond + left)  == OBSTACLE){ ans = true; }
    //overwride if diamond is in a goal
    for(auto G : goals){
        if( diamond == G ){
            ans = false;
        }
    }
    return ans;
}

char Map::diamonds_placed(){
    char ans = 0;
    for(auto J : diamond_pos){
        for(auto G : goals){
            if( J == G ){
                ++ans;
            }
        }
    }
    return ans;
}
