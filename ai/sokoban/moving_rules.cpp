#include "map.h"
#include <stack>
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
    //if i can move from A to B: move;
    const bool deadlock = locked_in(diamond);
    if (!deadlock){
        if( (get(A) > col) && (get(B) > col || get(B) == FREE) ){ ans += south; }
        if( (get(B) > col) && (get(A) > col || get(A) == FREE) ){ ans += north; }
        A = diamond + left;
        B = diamond + right;
        if( (get(A) > col) && (get(B) > col || get(B) == FREE) ){ ans += east; }
        if( (get(B) > col) && (get(A) > col || get(A) == FREE) ){ ans += west; }
    }
    return ans;
}

char Map::valid_pull(pos_t diamond){
    //a diamond is pullable if the diamond and the destination is reachable

    const unsigned char col = 2;
    char ans = 0;
    if( (get(diamond+below) > col) && (get(diamond+below+below) > col)) { ans += south; }
    if( (get(diamond+above) > col) && (get(diamond+above+above) > col)) { ans += north; }
    if( (get(diamond+right) > col) && (get(diamond+right+right) > col)) { ans += east; }
    if( (get(diamond+left ) > col) && (get(diamond+left +left ) > col)) { ans += west; }
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

bool Map::dead_lock(pos_t diamond){
    //A diamond can be in a dead lock if the diamond is in a corner of walls or a square of diamonds
    bool ans = false;
    unsigned char L = get(diamond + left);
    unsigned char R = get(diamond + right);
    unsigned char U = get(diamond + above);
    unsigned char D = get(diamond + below);

    unsigned char UL = get(diamond + above + left);
    unsigned char UR = get(diamond + above + right);
    unsigned char DL = get(diamond + below + left);
    unsigned char DR = get(diamond + below + right);

    if( (U == DIAMOND || U == OBSTACLE) && (R == DIAMOND || R == OBSTACLE) && (UR == DIAMOND || UR == OBSTACLE) ){ ans = true; }
    if( (U == DIAMOND || U == OBSTACLE) && (L == DIAMOND || L == OBSTACLE) && (UL == DIAMOND || UL == OBSTACLE) ){ ans = true; }
    if( (D == DIAMOND || D == OBSTACLE) && (R == DIAMOND || R == OBSTACLE) && (DR == DIAMOND || DR == OBSTACLE) ){ ans = true; }
    if( (D == DIAMOND || D == OBSTACLE) && (L == DIAMOND || L == OBSTACLE) && (DL == DIAMOND || DL == OBSTACLE) ){ ans = true; }

    for(auto wall : dead_locked_wall){
        if( wall == diamond){
            ans = true;
        }
    }
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
        return true;
    } else {
        return false;
    }
}

std::queue<node*> Map::add_all_possible_paths(node *N, Map &copy){
    std::queue<node*> neighbohrs;
    std::vector<pos_t> J = N->diamonds;
    node *par = N;
    pos_t new_man = N->man;
    //Don't get children if there is a deadlock
    bool dead_end = false;
    for(size_t n=0; n < J.size(); ++n){
        if(dead_lock(J.at(n))){
            dead_end = true;
            for(auto g : goals){
                if(g == J.at(n)){
                    dead_end = false;
                    //if a diamond is locked in a goal then it is not a deadlock.
                }
            }
            if(dead_end){
                return neighbohrs; //deadlock, no need to see what children might come of this.
            }
        }
    }
    wave(copy,new_man,J);
    Map wave_map; /******** If we want to optimize for robot moves ********/
    std::vector<std::vector<float>> cost_map;
    if(optimize_for_robot_moves){
        cost_map = find_robot_moves(wave_map, N);
    }
    char ans;
    for(size_t n=0; n < J.size(); ++n){
        ans = copy.valid_push(J.at(n)); //gets all the directions a diamond can be pushed
        if(ans){
            new_man = J.at(n); //New position where the man is where the diamond was
            if(ans & east){
                J.at(n) = N->diamonds.at(n) + right; //move diamond
                node *next = new node(new_man,J,par);      //create node
                if(optimize_for_robot_moves){
                    next->path_length = N->path_length + wave_map.get(new_man) -3;//based on robot moves in seconds
                } else {
                    next->path_length = N->path_length + copy.get(new_man-right) - 2; //wavefront approach
                }
                J.at(n) = N->diamonds.at(n);         //reset diamond
                neighbohrs.push(next);
            }
            if(ans & west){
                J.at(n) = N->diamonds.at(n) + left;
                node *next = new node(new_man,J,par);
                if(optimize_for_robot_moves){
                    next->path_length = N->path_length + wave_map.get(new_man) -3;
                } else {
                    next->path_length = N->path_length + copy.get(new_man-left) - 2; //wavefront approach
                }
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & north){
                J.at(n) = N->diamonds.at(n) + above;
                node *next = new node(new_man,J,par);
                if(optimize_for_robot_moves){
                    next->path_length = N->path_length + wave_map.get(new_man) -3;
                } else {
                    next->path_length = N->path_length + copy.get(new_man-above) - 2; //wavefront approach
                }
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & south){
                J.at(n) = N->diamonds.at(n) + below;
                node *next = new node(new_man,J,par);
                if(optimize_for_robot_moves){
                    next->path_length = N->path_length + wave_map.get(new_man) -3;
                } else {
                    next->path_length = N->path_length + copy.get(new_man-below) - 2; //wavefront approach
                }
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
        }
    }
    return neighbohrs;
}

void Map::informed_bff_search(Map &copy_map){
    std::priority_queue<node*,std::vector<node*>,comparator_functor> search_list; //list of current search nodes.
    std::queue<node*> neighbohrs;                       //results from add_all_possible
    node start(man,diamond_pos);
    wave(copy_map,man,diamond_pos);
    search_list.push(&start);                            //set first target
    closed_set.clear();
    std::string start_node_index = to_string(start.diamonds,start.man);
    std::string hash_index;
    node *current_node;
    std::unordered_map<std::string,node*>::iterator hash_ptr;
    while( !search_list.empty()) {
        current_node = search_list.top();
        if(game_complete(current_node)){
            std::cout << "//" << " found the goal. Number of nodes: " << closed_set.size() + search_list.size() << "\n";
            std::cout << "//" << " move length: " << current_node->path_length << "\n";
            //print the path as a string or as C code
            //print_path(copy_map,current_node);
            print_path_as_C_code(copy_map,current_node);
            clear_hashtable(closed_set,start_node_index);
            while(!search_list.empty()){
                current_node = search_list.top();
                delete current_node;
                search_list.pop();
            }
            return;
        }
        search_list.pop();

        hash_index = to_string(current_node->diamonds,current_node->man);
        if( closed_set.emplace(hash_index,current_node).second){         //if the configuration has not been visited
            neighbohrs = add_all_possible_paths(current_node,copy_map);  //this gives the possible paths
            while( !neighbohrs.empty() ) {                               //append these nodes to the list.
                current_node = neighbohrs.front();
                neighbohrs.pop();

                hash_index = to_string(current_node->diamonds,current_node->man);
                hash_ptr = closed_set.find(hash_index); ;

                if( hash_ptr != closed_set.end() ){ //if already visited
                    delete current_node;
                } else {
                    search_list.push(current_node);
                }
            }
        } else { //if already visited
            delete current_node;
        }
    }
    std::cout << "no solution\n";
    return;
}
