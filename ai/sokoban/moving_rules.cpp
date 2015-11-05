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
    //TODO: find a way to keep track of if it is locked in by diamonds, right now they are not printed to map.
    //print to map every time?
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

std::queue<node*> Map::add_all_possible_paths(node *N, Map &copy,char direction){
    std::queue<node*> neighbohrs;
    std::vector<pos_t> J = N->diamonds;
    node *par = N;
    node *next;
    pos_t new_man = N->man;
    //Don't get children if there is a deadlock
    bool dead_end = false;
    for(size_t n=0; n < J.size(); ++n){
        if(locked_in(J.at(n))){
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
    char ans;
    for(size_t n=0; n < J.size(); ++n){
        if(direction == DIRECTION_PUSH){
            ans = copy.valid_push(J.at(n)); //gets all the directions a diamond can be PUSHED
        } else {
            ans = copy.valid_pull(J.at(n)); //gets all the directions a diamond can be PULLED
        }
        if(ans){
            new_man = J.at(n); //New position where the man is where the diamond was
            if(ans & east){
                J.at(n) = N->diamonds.at(n) + right; //move diamond
                next = new node(new_man,J,par);      //create node
                next->general_pos = copy.find_general_position();
                if(N->parent != nullptr)
                    next->path_length = N->path_length + copy.get(new_man-right) - 2;
                J.at(n) = N->diamonds.at(n);         //reset diamond
                neighbohrs.push(next);
            }
            if(ans & west){
                J.at(n) = N->diamonds.at(n) + left;
                next = new node(new_man,J,par);
                next->general_pos = copy.find_general_position();
                if(N->parent != nullptr)
                    next->path_length = N->path_length + copy.get(new_man-left) - 2;
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & north){
                J.at(n) = N->diamonds.at(n) + above;
                next = new node(new_man,J,par);
                next->general_pos = copy.find_general_position();
                if(N->parent != nullptr)
                    next->path_length = N->path_length + copy.get(new_man-above) - 2;
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & south){
                J.at(n) = N->diamonds.at(n) + below;
                next = new node(new_man,J,par);
                next->general_pos = copy.find_general_position();
                if(N->parent != nullptr)
                    next->path_length = N->path_length + copy.get(new_man-below) - 2;
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
        }
    }
    return neighbohrs;
}

node* Map::bff_search(Map &copy_map){
    std::queue<node*> search_list;                      //list of current search nodes.
    //    std::priority_queue<node*,queue<node*>,comparator_function> search_list;                      //list of current search nodes.
    std::queue<node*> neighbohrs;                       //result fra add_all_possible...
    std::queue<node*> neighbohrs_neighbohrs;            //2nd list of search nodes.
    node start(man,diamond_pos);
    wave(copy_map,man,diamond_pos);
    start.general_pos = copy_map.find_general_position();
    search_list.push(&start);                            //set first target
    closed_set.clear();
    std::unordered_map<std::string,node*>::const_iterator hash_ptr;
    closed_set.emplace(to_string(start.diamonds,start.general_pos),&start);
    char runs = 0;
    bool search_complete = false;
    node *current_node;
    while( !search_complete ) {
        search_complete = true;
        ++runs;
        while( !search_list.empty()) {
            search_complete = false; //prevent the loop to stop when there is more pixels to search for
            current_node = search_list.front();
            //            current_node = search_list.top();
            search_list.pop();
            neighbohrs = add_all_possible_paths(current_node,copy_map); //this gives the possible paths
            while( !neighbohrs.empty() ) {                       //append these nodes to the list.
                current_node = neighbohrs.front();
                neighbohrs.pop();
                hash_ptr = closed_set.find(to_string(current_node->diamonds,current_node->general_pos)); //check is visited;
                if( hash_ptr == closed_set.end() ) {//current_node does not exist in map
                    neighbohrs_neighbohrs.push( current_node );
                    //                    search_list.push( current_node ); //if the search list sorts, it will take the best node
                    closed_set.emplace(to_string(current_node->diamonds,current_node->general_pos),current_node);
                    if(game_complete(current_node)){
                        std::cout << (int) runs << " found the goal. Size: " << current_node->path_length << "\n";
                        print_path(copy_map,current_node);
                        return current_node; //goal node;
                    }
                } else {
                    delete current_node;
                }
            }
        }
        search_list = neighbohrs_neighbohrs; //append to search list
        std::cout << "runs: " << (int) runs << " frontier:\t" << search_list.size() << "\tclosed_set: " << closed_set.size() <<"\n";
        while(!neighbohrs_neighbohrs.empty()){ //clear the queue
            neighbohrs_neighbohrs.pop();
        }
    }
    return nullptr;
}
node* Map::informed_bff_search(Map &copy_map){
    std::priority_queue<node*,std::vector<node*>,comparator_functor> search_list;                      //list of current search nodes.
    std::queue<node*> neighbohrs;                       //result fra add_all_possible...
    node start(man,diamond_pos);
    wave(copy_map,man,diamond_pos);
    start.general_pos = copy_map.find_general_position();
    search_list.push(&start);                            //set first target
    closed_set.clear();
    std::unordered_map<std::string,node*>::const_iterator hash_ptr;
    closed_set.emplace(to_string(start.diamonds,start.general_pos),&start);
    char runs = 0;
    bool search_complete = false;
    node *current_node;
    while( !search_complete ) {
        search_complete = true;
        ++runs;
        while( !search_list.empty()) {
            search_complete = false; //prevent the loop to stop when there is more pixels to search for
            current_node = search_list.top();
            search_list.pop();
            neighbohrs = add_all_possible_paths(current_node,copy_map); //this gives the possible paths
            while( !neighbohrs.empty() ) {                       //append these nodes to the list.
                current_node = neighbohrs.front();
                neighbohrs.pop();
                hash_ptr = closed_set.find(to_string(current_node->diamonds,current_node->general_pos)); //check is visited;
                if( hash_ptr == closed_set.end() ) {//current_node does not exist in map
                    search_list.push( current_node ); //the search list sorts, it will take the best node
                    closed_set.emplace(to_string(current_node->diamonds,current_node->general_pos),current_node);
                    if(game_complete(current_node)){
                        std::cout << (int) runs << " found the goal. Size: " << current_node->path_length << "\n";
                        print_path(copy_map,current_node);
                        return current_node; //goal node;
                    }
                } else { //if the node is in the closed set
                    delete current_node;
                }
            }
        }
    }
    return nullptr;
}
node* Map::idf_search(node *start, Map &copy_map){
    /*
    idf:
    find neighbohrs (b = up to 20)
        stack.push neighbors
        while(!finished)
            current_node = stack.top
            if(current_node == goal)
                return current_node
            depth++
            closed_set.add current_node
            if depth < max_depth then
                stack.push neighbohrs...
            else
                depth--
    */
    std::stack<node*> search_list;                      //list of current search nodes.
    std::stack<node*> neighbohrs_neighbohrs;            //2nd list of search nodes.
    std::queue<node*> neighbohrs;                       //result fra add_all_possible...
    search_list.push(start);                            //set first target
    std::unordered_map<std::string,node*> closed_set;
    std::unordered_map<std::string,node*>::const_iterator hash_ptr;
    char depth = 0;
    bool search_complete = false;
    node *current_node;
    while( !search_complete ) {
        search_complete = true;
        while( !search_list.empty()) {
            ++depth;
            search_complete = false; //prevent the loop to stop when there is more pixels to search for
            current_node = search_list.top();
            search_list.pop();
            neighbohrs = add_all_possible_paths(current_node,copy_map); //this gives the possible paths
            while( !neighbohrs.empty() ) {                       //append these nodes to the list.
                current_node = neighbohrs.front();
                neighbohrs.pop();
                hash_ptr = closed_set.find(to_string(current_node->diamonds,current_node->general_pos)); //check is visited;
                if( hash_ptr == closed_set.end() ) {//current_node does not exist in map
                    neighbohrs_neighbohrs.push( current_node );
                    closed_set.emplace(to_string(current_node->diamonds,current_node->general_pos),current_node);
                    if(game_complete(current_node)){
                        std::cout << (int) depth << " found the goal. Size: " << neighbohrs_neighbohrs.size() << "\n";
                        return current_node; //goal node;
                    }
                } else {
                    delete current_node;
                }
            }
        }
        search_list = neighbohrs_neighbohrs; //append to search list
        std::cout << "runs: " << (int) depth << " size: " << search_list.size() << "\n";
        while(!neighbohrs_neighbohrs.empty()){ //clear the queue
            neighbohrs_neighbohrs.pop();
        }
    }
    return nullptr;
}

