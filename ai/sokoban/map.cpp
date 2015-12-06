#include "map.h"
#include <stdlib.h> //atoi
#include <iomanip> //hex
#include <algorithm>

Map::Map() : data(0), width(0), height(0){
    //Empty constructor
    //Values are initialized to 0
}

Map::Map(std::string file_name) : data(0), width(0), height(0){
    read_file(file_name);
}

void Map::read_file(std::string file_name){
    //delete before loading a new map
    for(int i = 0; i < width; ++i){
        delete[] data[i];
    }
    delete[] data;
    clear_hashtable(closed_set);
    diamond_pos.clear();
    goals.clear();


    std::ifstream data_file;
    data_file.open(file_name.c_str(),std::ios::in);
    if(data_file.is_open()){
        char c = 'U';
        std::string str_value;
        //get dimensions
        std::getline(data_file, str_value, ' ');
        width = atoi(str_value.c_str());
//        std::cout <<"width: " << width << "\n";
        std::getline(data_file, str_value, ' ');
        height = atoi(str_value.c_str());
//        std::cout <<"height: "<< height << "\n";

        std::getline(data_file,str_value);
        n_diamonds = atoi(str_value.c_str());
//        std::cout <<"diamonds: "<< (int) n_diamonds << "\n";
        //create array
        data = new unsigned char*[width];
        for(int w=0;w<width;++w){
            data[w] = new unsigned char[height];
        }
        //fill array
        unsigned char x = 0;
        unsigned char y = 0;
        while(data_file.get(c) ){
                switch(c){
                    case ' ': //treat spaces as obstacles
                        data[x][y] = OBSTACLE;
                        break;
                    case 'X':
                        data[x][y] = OBSTACLE;
                        break;
                    case 'J':
                        data[x][y] = FREE;
                        diamond_pos.push_back(pos_t(x,y));
                        break;
                    case '.':
                        data[x][y] = FREE;
                        break;
                    case 'G':
                        data[x][y] = FREE;
                        goals.push_back(pos_t(x,y));
                        break;
                    case 'M':
                        data[x][y] = FREE;
                        man = pos_t(x,y);
                        break;
                    case '+': //man + goal
                        data[x][y] = FREE;
                        man = pos_t(x,y);
                        goals.push_back(pos_t(x,y));
                        break;
                    case '*': //diamand + goal
                        data[x][y] = FREE;
                        goals.push_back(pos_t(x,y));
                        diamond_pos.push_back(pos_t(x,y));
                        break;
                    default:
                        if(x > 0){
                            x = -1;
                            ++y;
                        } else { //in case of windows break lines
                            --x;
                        }
                        break;
            }
                ++x;
        }
        data_file.close();
//        std::cout << "file loaded\n";
    } else {
//        std::cout << file_name << " does not exist\n";
    }
    Map wave_map;
    find_dead_lock_pos(wave_map);
}

void Map::find_dead_lock_pos(Map &wave_map){
    enum colors{reachable=3, cleared = 4, dead_wall = 6, corner = 7, diamond = 9};
    std::unordered_map<int,pos_t> walls;
    wave_map = *this;
    std::queue<pos_t> search_list;
    std::queue<pos_t> surrounding_points;

    wave_map.set(man, reachable);             //set first value
    search_list.push(man);           //set first target
    pos_t current_pos, testing_pos;
    //find walls
    while ( !search_list.empty() ) {
        current_pos = search_list.front();
        search_list.pop();
        for(int x = -1; x <= 1; ++x){
            for(int y = -1; y <= 1; ++y){
                if((x == 0) || (y == 0)){
                    testing_pos.x = current_pos.x + x;
                    testing_pos.y = current_pos.y + y;
                    if(wave_map.get( testing_pos ) == FREE) {
                        wave_map.set(testing_pos, reachable);
                        surrounding_points.push( testing_pos );
                    } else if(wave_map.get(testing_pos) == OBSTACLE){
                        walls.emplace(current_pos.x + width * current_pos.y, current_pos);
                    }
                }
            }
        }
        while ( !surrounding_points.empty() ) {                       //append these coordinates to the list.
            search_list.push( surrounding_points.front() );
            surrounding_points.pop();
        }
    }

    for(auto n : goals){
        wave_map.set(n, diamond);
    }

    char v = 0;
//    bool goal_encountered;
    pos_t direction;
    //remove corners

    for(std::unordered_map<int,pos_t>::iterator i =walls.begin(); i != walls.end() ; ++i){
        if( wave_map.get(i->second) == reachable){
            if(locked_in(i->second)){
                wave_map.set(i->second,corner);
            }
        }
    }
    bool wall_has_goal = false;
    bool wall_has_clearance = false;
    char pull;
    for(std::unordered_map<int,pos_t>::iterator i =walls.begin(); i != walls.end() ; ++i){
        if(wave_map.get(i->second) == corner){
            for(int x = -1; x <= 1; ++x){
                for(int y = -1; y <= 1; ++y){
                    if((x == 0) ^ (y == 0)){
                        testing_pos = i->second;
                        direction = pos_t(x,y);
                        wall_has_goal = false;
                        wall_has_clearance = false;
                        do{
                            search_list.push(testing_pos); //add all locked in values
                            testing_pos = testing_pos + direction; //check in all directions until a wall occour
                            v = wave_map.get(testing_pos);
                            pull = wave_map.valid_push(testing_pos);
                            if(v == diamond || v == OBSTACLE){
                                wall_has_goal = true;
                                break;
                            }
                            if (v == cleared || pull == (north | south | east | west) ){
                                wall_has_clearance = true;
                                break;
                            }
                        }while( v != corner);

                        if(wall_has_goal){ // ignore them
                            while(!search_list.empty()){
                                search_list.pop();
                            }
                        } else if(wall_has_clearance) {
                            search_list.pop();
                            while(!search_list.empty()){
                                testing_pos = search_list.front();
                                wave_map.set(testing_pos,cleared);
                                search_list.pop();
                            }
                        } else {
                            while(!search_list.empty()){
                                testing_pos = search_list.front();
                                wave_map.set(testing_pos,dead_wall);
                                search_list.pop();
                            }
                        }
                    }
                }
            }
        }
    }
    for(std::unordered_map<int,pos_t>::iterator i =walls.begin(); i != walls.end() ; ++i){
        if(wave_map.get(i->second) == dead_wall || wave_map.get(i->second) == corner){
            dead_locked_wall.push_back(i->second);
        }
    }
}

void Map::print(){
//    data[man.x][man.y] = 'M';
    for(int h=0; h<height; ++h){
        for(int w=0; w<width; ++w){
            switch(data[w][h]){
            case OBSTACLE:
                std::cout << 'X';
                break;
            case FREE:
                std::cout << '.';
                break;
            case DIAMOND:
                std::cout << 'J';
                break;
            case 'M':
                std::cout << 'M';
                break;
            default:
                std::cout << std::hex << (int) data[w][h] - 3;
                std::cout.unsetf(std::ios::hex);
                break;
            }
        }
        std::cout << "\n";
    }
    data[man.x][man.y] = FREE;
}

Map& Map::operator=(const Map& other ) {
//    if(height != other.height || width != other.width){
        for(int i = 0; i < width; ++i){
            delete[] data[i];
        }
        delete[] data;
//    }
    height = other.height;
    width  = other.width;
    n_diamonds = other.n_diamonds;
    man = other.man;
    data = new unsigned char*[width];
    for(int w=0;w<width;++w){
        data[w] = new unsigned char[height];
    }
    for(int w=0; w<width;++w){
        for(int h=0; h<height; ++h){
            data[w][h] = other.data[w][h];
        }
    }
    return *this;
}

bool Map::boundry_check(const pos_t &pos){
    if(pos.x > 0 && pos.x < width &&
       pos.y > 0 && pos.y < height){
        return true;
    } else {
        return false;
    }
}

void Map::set(const pos_t &pos, const unsigned char &value){
    if(boundry_check(pos))
        data[pos.x][pos.y] = value;
    else
//        throw("ERROR: trying to set a value outside map\n");
        std::cerr << "ERROR: trying to set a value outside map\n";
}

unsigned char Map::get(const pos_t &pos){
    if(boundry_check(pos))
        return data[pos.x][pos.y];
//    std::cout << "THIS IS AN ERROR\n";
    return OBSTACLE;
}

std::string Map::to_string(const std::vector<pos_t> &J, const pos_t &man_pos){
    std::string final_string;
    for(auto n : J){
        final_string += n.x + n.y * width;
    }
    std::sort(final_string.begin(), final_string.end()); //The order of the diamonds does not matter
    final_string += man_pos.x + man_pos.y * width;
    return std::move(final_string);
}

std::string Map::to_string(node *N){
    std::string final_string;
    for(auto n : N->diamonds){
        final_string += n.x;
        final_string += n.y;
    }
    return std::move(final_string);
}

void clear_hashtable(std::unordered_map<std::string,node*> &table, const std::string start_node_index){
    for(std::unordered_map<std::string,node*>::iterator i =table.begin(); i != table.end() ; ++i){
        if( i->first != start_node_index ){ //Don't delete start node
            delete i->second;
        }
    }
    if(!table.empty()){
        table.clear();
    }
}

