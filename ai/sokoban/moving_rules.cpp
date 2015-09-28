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

std::queue<node> Map::add_all_possible_paths(node &N, Map &copy){
    std::queue<node> neighbohrs;
    std::vector<pos_t> J = N.diamonds;
    pos_t new_man = N.man;

    wave(copy,new_man,J);
    char ans;
    for(int n=0; n < J.size(); ++n){
        ans = map.valid_move(J.at(n));
        if(ans){
            new_man = J.at(n); //manden skal stå hvor diamanten stod.
            if(ans & east){
                //move;
                J.at(n) = N.diamonds(n) + right;
                node next(new_man,J);
                N.add_path(next);
                J.at(n) = N.diamonds(n);
                neighbohrs.front(next);
            }
            if(ans & west){
                //move;
                J.at(n) = N.diamonds(n) + left;
                node next(new_man,J);
                N.add_path(next);
                J.at(n) = N.diamonds(n);
                neighbohrs.front(next);
            }
            if(ans & north){
                //move;
                J.at(n) = N.diamonds(n) + above;
                node next(new_man,J);
                N.add_path(next);
                J.at(n) = N.diamonds(n);
                neighbohrs.front(next);
            }
            if(ans & south){
                //move;
                J.at(n) = N.diamonds(n) + below;
                node next(new_man,J);
                N.add_path(next);
                J.at(n) = N.diamonds(n);
                neighbohrs.front(next);
            }
        }
    }
    return neighbohrs;
}

void Map::bff_search(node start, map &copy){
    std::queue<node> search_list;         //list of current search nodes.
    std::queue<node> neighbohrs;   //result fra add_all_possible...
    std::queue<node> neighbohrs_neighbohrs;        //2nd list of search nodes.
    search_list.push(start);           //set first target

    bool search_complete = false;
    node current_node;

    while ( !search_complete ) {
        search_complete = true;
        while ( search_list.size() > 0 ) {
            search_complete = false; //prevent the loop to stop when there is more pixels to search for
            current_node = search_list.front();
            search_list.pop();
            neighbohrs = add_all_possible_paths(current_node,copy); //this gives the possible paths
            while ( neighbohrs.size() > 0 ) {                       //append these nodes to the list.
                neighbohrs_neighbohrs.push( neighbohrs.front() );
                neighbohrs.pop();
            }
        }
        search_list = neighbohrs_neighbohrs;
        while(!neighbohrs_neighbohrs.empty()){
            neighbohrs_neighbohrs.pop();
        }
    }
}

