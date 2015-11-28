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
    //print to map every time?
    if( (U == OBSTACLE) && (R == OBSTACLE) ){ ans = true; }
    if( (U == OBSTACLE) && (L == OBSTACLE) ){ ans = true; }
    if( (D == OBSTACLE) && (R == OBSTACLE) ){ ans = true; }
    if( (D == OBSTACLE) && (L == OBSTACLE) ){ ans = true; }

    if( (U == DIAMOND) && (R == DIAMOND) && (UR == DIAMOND) ){ ans = true; }
    if( (U == DIAMOND) && (L == DIAMOND) && (UL == DIAMOND) ){ ans = true; }
    if( (D == DIAMOND) && (R == DIAMOND) && (DR == DIAMOND) ){ ans = true; }
    if( (D == DIAMOND) && (L == DIAMOND) && (DL == DIAMOND) ){ ans = true; }

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
//        for(auto n : N->diamonds){
//            std::cout << n;
//        } std::cout << " WON\n";
        return true;
    } else {
        return false;
    }
}

std::queue<node*> Map::add_all_possible_paths(node *N, Map &copy,char direction){
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
                node *next = new node(new_man,J,par);      //create node
                next->general_pos = copy.find_general_position();
//                next->path_length = N->path_length + copy.get(new_man-right) - 2; //wavefront approach
                next->path_length = N->path_length + robot_move_time(next); //based on robot moves in seconds
                J.at(n) = N->diamonds.at(n);         //reset diamond
                neighbohrs.push(next);
            }
            if(ans & west){
                J.at(n) = N->diamonds.at(n) + left;
                node *next = new node(new_man,J,par);
                next->general_pos = copy.find_general_position();
//                next->path_length = N->path_length + copy.get(new_man-left) - 2;
                next->path_length = N->path_length + robot_move_time(next);
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & north){
                J.at(n) = N->diamonds.at(n) + above;
                node *next = new node(new_man,J,par);
                next->general_pos = copy.find_general_position();
//                next->path_length = N->path_length + copy.get(new_man-above) - 2;
                next->path_length = N->path_length + robot_move_time(next);
                J.at(n) = N->diamonds.at(n);
                neighbohrs.push(next);
            }
            if(ans & south){
                J.at(n) = N->diamonds.at(n) + below;
                node *next = new node(new_man,J,par);
                next->general_pos = copy.find_general_position();
//                next->path_length = N->path_length + copy.get(new_man-below) - 2;
                next->path_length = N->path_length + robot_move_time(next);
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
    std::string start_node_index = to_string(start.diamonds,start.man);
//    std::string start_node_index = to_string(start.diamonds,start.general_pos);
    size_t last_cost    = 0;
    size_t current_cost = 0;
    std::string hash_index;
    node *current_node;
    std::unordered_map<std::string,node*>::iterator hash_ptr;
    while( !search_list.empty()) {
        last_cost = current_cost;
        current_node = search_list.top();
        current_cost = current_node->path_length;
        if(game_complete(current_node)){
            std::cout << "//" <<  (int) current_cost << " found the goal. Size: " << current_node->path_length << "\n";
//            print_path(copy_map,current_node);
//            std::cout << "\n\n\n";
            print_path_as_C_code(copy_map,current_node);
            clear_hashtable(closed_set,start_node_index);
//            std::cout << "We didn't die\n";
            while(!search_list.empty()){
                current_node = search_list.top();
                delete current_node;
                search_list.pop();
            }
//            std::cout << "Press <RETURN> twice to close this window..."; std::cin.get();
            return nullptr; //goal node;
        }
        search_list.pop();

        hash_index = to_string(current_node->diamonds,current_node->man);
        //            hash_index = to_string(current_node->diamonds,current_node->general_pos);
        if( closed_set.emplace(hash_index,current_node).second){//if successfully inserted
//            if(current_cost > last_cost) { std::cout << "moves: " << current_cost << " frontier:\t" << search_list.size() << "\tclosed_set: " << closed_set.size() << " max buckets: " << closed_set.bucket_count() <<'\n'; }

            neighbohrs = add_all_possible_paths(current_node,copy_map); //this gives the possible paths
            while( !neighbohrs.empty() ) {                       //append these nodes to the list.
                current_node = neighbohrs.front();
                neighbohrs.pop();

                hash_index = to_string(current_node->diamonds,current_node->man);
                //                    hash_index = to_string(current_node->diamonds,current_node->general_pos);
                hash_ptr = closed_set.find(hash_index); //check is visited;

                if( hash_ptr != closed_set.end() ){ //if it exists
                    delete current_node;
                } else {
                    search_list.push(current_node);
                }
            }
        } else {
            delete current_node;
        }
    }
    std::cout << "no solution\n";
    return nullptr;
}
//node* Map::idf_search(Map &copy_map){
//    /*
//    idf:
//    find neighbohrs (b = up to 20)
//        stack.push neighbors
//        while(!finished)
//            current_node = stack.top
//            if(current_node == goal)
//                return current_node
//            depth++
//            closed_set.add current_node
//            if depth < max_depth then
//                stack.push neighbohrs...
//            else
//                depth--
//    */
//    std::stack<node*> search_list;                      //list of current search nodes.
//    std::queue<node*> neighbohrs;                       //result fra add_all_possible...
//    node start(man,diamond_pos);
//    wave(copy_map,man,diamond_pos);
//    start.general_pos = copy_map.find_general_position();
//    search_list.push(&start);                            //set first target
//    closed_set.clear();
//    std::unordered_map<std::string,node*>::const_iterator hash_ptr;
//    closed_set.emplace(to_string(start.diamonds,start.general_pos),&start);
//    node *current_node;
//    size_t depth = 0;
//    size_t max_depth = 300;
//    while( !search_list.empty()) {
//        current_node = search_list.top();
//        search_list.pop();
//        if(depth < max_depth){
//            ++depth;
//            neighbohrs = add_all_possible_paths(current_node,copy_map); //this gives the possible paths
//        } else {
//            --depth;
//        }
//        while( !neighbohrs.empty() ) {                       //append these nodes to the list.
//            current_node = neighbohrs.front();
//            neighbohrs.pop();
//            hash_ptr = closed_set.find(to_string(current_node->diamonds,current_node->general_pos)); //check is visited;
//            if( hash_ptr == closed_set.end() ) {//current_node does not exist in map
//                search_list.push( current_node ); //the search list stacks, it will take the newest node
//                closed_set.emplace(to_string(current_node->diamonds,current_node->general_pos),current_node);
//                if(game_complete(current_node)){
//                    std::cout << " found the goal. Size: " << current_node->path_length << "\n";
//                    print_path(copy_map,current_node);
//                    return current_node; //goal node;
//                }
//            } else { //if the node is in the closed set
//                delete current_node;
//            }
//        }
//    }
//    return nullptr;
//}
node* Map::idf_search(Map &copy_map){
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
    std::queue<node*> neighbohrs;                       //result fra add_all_possible...
    node start(man,diamond_pos);
    search_list.push(&start);                            //set first target
    std::unordered_map<std::string,node*>::const_iterator hash_ptr;
    std::string start_node_index = to_string(start.diamonds,start.man);
    node *current_node;
    size_t depth = 0;
    size_t n_children = 0;
    size_t max_depth = 3;
    bool finished = false;
    std::string hash_index;
    while( !finished ){
        finished = true;
        while( !search_list.empty()) {
            current_node = search_list.top();
            search_list.pop();
            std::cout << depth << " ";//<< " closed set: " << closed_set.size()  << " open: " << search_list.size() << " \t";
//            for(size_t i = 0; i <current_node->diamonds.size(); ++i)
//                std::cout << start.diamonds.at(i)-current_node->diamonds.at(i) << "\t";
//            std::cout << " \n";
            print_path(copy_map,current_node);
            if(game_complete(current_node)){
                std::cout << " found the goal. Size: " << current_node->path_length << "\n";
                print_path(copy_map,current_node);
                return current_node; //goal node;
            }
            hash_index = to_string(current_node->diamonds,current_node->man);
            hash_ptr = closed_set.find(hash_index);
            if( hash_ptr == closed_set.end() ) {//current_node does not exist in map
                closed_set.emplace(to_string(current_node->diamonds,current_node->man),current_node);
                if(depth < max_depth ){
                    ++depth;
                    neighbohrs = add_all_possible_paths(current_node,copy_map); //this gives the possible paths
                    n_children = neighbohrs.size();
                    while( !neighbohrs.empty() ) {                       //append these nodes to the list.
                        current_node = neighbohrs.front();
                        neighbohrs.pop();
                        //                    if( closed_set.emplace(to_string(current_node->diamonds,current_node->man),current_node).second ) {//current_node does not exist in map
                        search_list.push( current_node ); //the search list stacks, it will take the newest node
                    }
                } else if(n_children > 0) {
                    hash_index = to_string(current_node->diamonds,current_node->man);
                    hash_ptr = closed_set.find(hash_index);
                    if( hash_index != start_node_index){
                        delete hash_ptr->second;
                    }
                    closed_set.erase(hash_ptr);
                    --n_children;
                    if(n_children == 0){
                        --depth;
                    }
                }
            } else { //if the node is in the closed set
                delete current_node;
            }
        }
        if(max_depth < 31){
            clear_hashtable(closed_set,start_node_index);
            search_list.push(&start);
            depth = 0;
            std::cout << "I got here: " << max_depth << "\n";
            finished = false;
            ++max_depth;
        }
    }
    clear_hashtable(closed_set,start_node_index);
    std::cout << "no solution\n";
    return nullptr;
}
