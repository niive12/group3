#include "map.h"
#include <unordered_map>

char Map::valid_push(pos_t diamond){
    //a diamond is pushable if the diamond if the origin is reachable,
    //the destination is not a wall or diamond
    //and if the diamond is not locked in.
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

char Map::valid_pull(pos_t diamond){
    //a diamond is pullable if the diamond if the destination is reachable
    const unsigned char col = 2;
    char ans = 0;
    if( get(diamond+below) > col) { ans += south; }
    if( get(diamond+above) > col) { ans += north; }
    if( get(diamond+right) > col) { ans += east; }
    if( get(diamond+left ) > col) { ans += west; }
    return ans;
}

bool Map::locked_in(pos_t diamond){
    //A diamond can be locked in if the diamond is in a corner of walls or diamonds

    bool ans = false;
    unsigned char L = get(diamond + left);
    unsigned char R = get(diamond + right);
    unsigned char U = get(diamond + above);
    unsigned char D = get(diamond + below);

    if( (U == OBSTACLE  || U == DIAMOND ) && (R == OBSTACLE  || R == DIAMOND ) ){ ans = true; }
    if( (U == OBSTACLE  || U == DIAMOND ) && (L == OBSTACLE  || L == DIAMOND ) ){ ans = true; }
    if( (D == OBSTACLE  || D == DIAMOND ) && (R == OBSTACLE  || R == DIAMOND ) ){ ans = true; }
    if( (D == OBSTACLE  || D == DIAMOND ) && (L == OBSTACLE  || L == DIAMOND ) ){ ans = true; }
    return ans;
}

bool Map::game_complete(node* N){
    char ans = 0;
    for(auto J : N->diamonds){
        for(auto G : goals){
            if( J == G ){
                ++ans;
            }
        }
    }
    if(ans == n_diamonds){
        for(auto n : N->diamonds){
            std::cout << n;
        } std::cout << " WON\n";
        return true;
    } else {
        return false;
    }
}


std::queue<node*> Map::add_all_possible_paths(node *N, Map &copy){
    std::queue<node*> neighbohrs;
    std::vector<pos_t> J = N->diamonds;
    node *par = N;
    node *next;
    pos_t new_man = N->man;

    wave(copy,new_man,J);
    char ans;
    for(size_t n=0; n < J.size(); ++n){
        ans = copy.valid_push(J.at(n)); //gets all the directions a diamond can be PUSHED
        if(ans){
            new_man = J.at(n); //New position for the man is where the diamond was
            if(ans & east){
                J.at(n) = N->diamonds.at(n) + right;
                next = new node(new_man,J,par);
//                N->add_path(next);
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & west){
                J.at(n) = N->diamonds.at(n) + left;
                next = new node(new_man,J,par);
//                N->add_path(next);
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & north){
                J.at(n) = N->diamonds.at(n) + above;
                next = new node(new_man,J,par);
//                N->add_path(next);
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & south){
                J.at(n) = N->diamonds.at(n) + below;
                next = new node(new_man,J,par);
//                N->add_path(next);
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
    std::unordered_map<std::string,node*> closed_set;
    std::unordered_map<std::string,node*>::const_iterator hash_ptr;
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
                hash_ptr = closed_set.find(to_string(current_node->diamonds));
                if( hash_ptr == closed_set.end() ) {//current_node does not exist in map
                    neighbohrs_neighbohrs.push( current_node );
                    closed_set.emplace(to_string(current_node->diamonds),current_node);
                    if(game_complete(current_node)){
                        std::cout << (int) runs << " found the goal\n";
    //                    for(auto n : current_node->diamonds){
    //                        std::cout << n;
    //                    } std::cout << "\n";
                        return current_node; //goal node;
                    }
                }
            }
        }
        search_list = neighbohrs_neighbohrs; //append to search list
        std::cout << "runs: " << (int) runs << " size: " << search_list.size() << "\n";
        while(!neighbohrs_neighbohrs.empty()){ //clear the queue
            neighbohrs_neighbohrs.pop();
        }
    }
    return nullptr;
}

