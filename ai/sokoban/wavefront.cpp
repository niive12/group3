#include "map.h"

std::queue<pos_t> Map::wave_color(pos_t pos, int previous_color, Map &wave_map){
    std::queue<pos_t> colored_positions;
    //color 4 surrounding pixels
    int color = previous_color + 1;
    pos_t testing_pos;
    for(int x = -1; x <= 1; ++x){
        for(int y = -1; y <= 1; ++y){
            if((x == 0) || (y == 0)){
                testing_pos.x = pos.x + x;
                testing_pos.y = pos.y + y;
                if ( boundry_check(testing_pos) ) {
                    if(wave_map.get( testing_pos ) == FREE) {
                        wave_map.set(testing_pos, color);
                        colored_positions.push( testing_pos );
                    }
                }
            }
        }
    }
    return colored_positions;
}

unsigned char Map::wave(Map &wave_map, pos_t man_pos, const std::vector<pos_t> &diamonds){
    //place all diamonds
    wave_map = *this;
    for(auto n : diamonds){
        wave_map.set(n, DIAMOND);
    }

    unsigned char color = 3;                // this means distance is (color - 3)

    std::queue<pos_t> search_list;         //list of pixels to search for.
    std::queue<pos_t> surrounding_points;
    std::queue<pos_t> colored_list;        //list of pixels colored by a single color.
    wave_map.set(man_pos, color);             //set first value
    search_list.push(man_pos);           //set first target

    bool wave_complete = false;
    pos_t current_pos;

    while ( !wave_complete ) {
        wave_complete = true;
        while ( !search_list.empty() ) {
            wave_complete = false; //prevent the loop to stop when there is more pixels to search for
            current_pos = search_list.front();
            search_list.pop();
            surrounding_points = wave_color( current_pos, color, wave_map); //this gives the surrounding coordinates
            while ( !surrounding_points.empty() ) {                       //append these coordinates to the list.
                colored_list.push( surrounding_points.front() );
                surrounding_points.pop();
            }
        }
        search_list = colored_list;
        while(!colored_list.empty()){
            colored_list.pop();
        }
        color++;
    }
    return color;
}

std::string Map::calculate_path(Map &wave_map, node *N){
    pos_t target_position = N->man;
    char diamond_n = 0;
    std::vector<pos_t> old_diamond_pos;
    pos_t current_pos;
    if( N->parent != nullptr){
        current_pos = N->parent->man;
        old_diamond_pos = N->parent->diamonds;
    } else {
        current_pos = man;
        old_diamond_pos = diamond_pos;
    }

    //find which diamond has been moved
    for(size_t n=0; n < goals.size(); ++n){
        if(!(old_diamond_pos.at(n) == N->diamonds.at(n))){
            target_position = old_diamond_pos.at(n) + old_diamond_pos.at(n) - N->diamonds.at(n);
            diamond_n = n;
            break;
        }
    }
    std::string ans;

    //create a wavefront
    wave(wave_map,target_position,old_diamond_pos);
    //follow that to destination
    unsigned char max_distance = wave_map.get(current_pos);
    unsigned char current_distance = max_distance + 1;
    pos_t test_pos;
    pos_t next_move;
    while( !(current_pos == target_position) ){
        for(int x = -1; x <= 1; ++x){
            for(int y = -1; y <= 1; ++y){
                if((x == 0) || (y == 0)){
                    test_pos = current_pos + pos_t(x,y);
                    current_distance = wave_map.get(test_pos);
                    if(current_distance < max_distance && current_distance > 2 ){
                        max_distance = current_distance;
                        next_move = pos_t(x,y);
                    }
                }
            }
        }
        if(next_move == above){
            ans += "u";
        }else if(next_move == below){
            ans += "d";
        }else if(next_move == right){
            ans += "r";
        }else if(next_move == left){
            ans += "l";
        }
        current_pos = current_pos + next_move;
    }
    //final move
    next_move = old_diamond_pos.at(diamond_n) - target_position;
    if(next_move == above){
        ans += "U";
    }else if(next_move == below){
        ans += "D";
    }else if(next_move == right){
        ans += "R";
    }else if(next_move == left){
        ans += "L";
    }
    return ans;
}

void Map::print_path_as_C_code(Map &wave_map, node* path, bool first){
    static std::string final_path;
    static std::string c_variable;
    if(first){
        final_path = "";
    }
    if(path->parent != nullptr){
        print_path_as_C_code(wave_map, path->parent,false);
        final_path += calculate_path(wave_map,path);
//        std::cout << path->path_length << " moves\n";
        if(first){
            for(unsigned int i = 0; i < final_path.size();++i){
                if( i == 0 ){
                    c_variable = "const char path[";
                    c_variable += final_path.size() / 100     + '0';
                    c_variable += final_path.size() / 10 % 10 + '0';
                    c_variable += final_path.size()      % 10 + '0';
                    c_variable += "] = {\'";
                    c_variable += final_path[i];
                } else {
                    c_variable += "\' , \'";
                    c_variable += final_path[i];
                }
            }
            c_variable += "\'};\n";
            std::cout << c_variable;
        }
    }
}

void Map::print_path(Map &wave_map, node* path, bool first){
    if ( path->parent != nullptr ){
        print_path(wave_map, path->parent,false);
        std::cout << calculate_path(wave_map,path) << std::flush;
        if(first)
            std::cout << "\n";
    }
}
