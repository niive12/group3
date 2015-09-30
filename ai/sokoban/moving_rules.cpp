#include "map.h"

char Map::valid_move(pos_t diamond){
    const unsigned char col = 2;
    char ans = 0;
    pos_t A,B;
    A = diamond + above;
    B = diamond + below;
    //if i can move from A to B: and B does not lock the diamond, move;
    if( (get(A) > col) && (get(B) > col || get(B) == FREE) ){ if(!locked_in(diamond)){ ans += south; } }
    if( (get(B) > col) && (get(A) > col || get(A) == FREE) ){ if(!locked_in(diamond)){ ans += north; } }
    A = diamond + left;
    B = diamond + right;
    if( (get(A) > col) && (get(B) > col || get(B) == FREE) ){ if(!locked_in(diamond)){ ans += east; } }
    if( (get(B) > col) && (get(A) > col || get(A) == FREE) ){ if(!locked_in(diamond)){ ans += west; } }
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

bool Map::game_complete(node test){
    char ans = 0;
    for(auto J : test.diamonds){
        for(auto G : goals){
            if( J == G ){
                ++ans;
            }
        }
    }
    if(ans == n_diamonds){
        for(auto n : test.diamonds){
            std::cout << n;
        } std::cout << " WON\n";
        return true;
    } else {
        return false;
    }
}

//bool Map::game_complete(std::queue<node> )

std::queue<node*> Map::add_all_possible_paths(node *N, Map &copy){
    std::queue<node*> neighbohrs;
    std::vector<pos_t> J = N->diamonds;
    node *par = N;
    node *next;
    pos_t new_man = N->man;

    wave(copy,new_man,J);
    char ans;
    for(size_t n=0; n < J.size(); ++n){
        ans = copy.valid_move(J.at(n));
        if(ans){
            new_man = J.at(n); //manden skal stå hvor diamanten stod.
            if(ans & east){
                //move;
                J.at(n) = N->diamonds.at(n) + right;
                next = new node(new_man,J,par);
//                next->direction = 'R';
                N->add_path(next);
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & west){
                //move;
                J.at(n) = N->diamonds.at(n) + left;
                next = new node(new_man,J,par);
//                next->direction = 'L';
                N->add_path(next);
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & north){
                //move;
                J.at(n) = N->diamonds.at(n) + above;
                next = new node(new_man,J,par);
//                next->direction = 'U';
                N->add_path(next);
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & south){
                //move;
                J.at(n) = N->diamonds.at(n) + below;
                next = new node(new_man,J,par);
//                next->direction = 'D';
                N->add_path(next);
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
        }
    }
    return neighbohrs;
}

node* Map::bff_search(node *start, Map &copy_map){
    std::queue<node*> search_list;         //list of current search nodes.
    std::queue<node*> neighbohrs;          //result fra add_all_possible...
    std::queue<node*> neighbohrs_neighbohrs;        //2nd list of search nodes.
    search_list.push(start);           //set first target

    char runs = 0;
    bool search_complete = false;
    node *current_node;
    while( !search_complete ) {
        ++runs;
        search_complete = true;
        while( !search_list.empty()) {
            search_complete = false; //prevent the loop to stop when there is more pixels to search for
            current_node = search_list.front();
            search_list.pop();
            neighbohrs = add_all_possible_paths(current_node,copy_map); //this gives the possible paths
            while( !neighbohrs.empty() ) {                       //append these nodes to the list.
                current_node = neighbohrs.front();
                neighbohrs.pop();
                neighbohrs_neighbohrs.push( current_node );
                if(game_complete(*current_node)){
                    std::cout << (int) runs << " found the goal\n";
//                    for(auto n : current_node->diamonds){
//                        std::cout << n;
//                    } std::cout << "\n";
                    return current_node; //goal node;
                }
            }
        }
        search_list = neighbohrs_neighbohrs;
        std::cout << "runs: " << (int) runs << " size: " << search_list.size() << "\n";
        while(!neighbohrs_neighbohrs.empty()){ //clear the queue
            neighbohrs_neighbohrs.pop();
        }
    }
    return nullptr;
}

