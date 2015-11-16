#include "map.h"
#include <stdlib.h> //atoi
#include <iomanip> //hex

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

    std::ifstream data_file;
    data_file.open(file_name.c_str(),std::ios::in);
    if(data_file.is_open()){
        char c = 'U';
        std::string str_value;
        //get dimensions
        std::getline(data_file, str_value, ' ');
        width = atoi(str_value.c_str());
        std::cout <<"width: " << width << "\n";
        std::getline(data_file, str_value, ' ');
        height = atoi(str_value.c_str());
        std::cout <<"height: "<< height << "\n";

        std::getline(data_file,str_value);
        n_diamonds = atoi(str_value.c_str());
        std::cout <<"diamonds: "<< (int) n_diamonds << "\n";
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
                            std::cout << "error\n";
                        }
                        break;
            }
                ++x;
        }
        data_file.close();
        std::cout << "file loaded\n";
    } else {
        std::cout << file_name << " does not exist\n";
    }
}

void Map::print(){
    data[man.x][man.y] = 'M';
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
                std::cout << std::hex << (int) data[w][h];
                break;
            }
        }
        std::cout << "\n";
    }
    data[man.x][man.y] = FREE;
}


std::vector<pos_t> Map::find_all_general_positions(Map copy, node* N){
    pos_t res(-1,-1);
    pos_t old_res(-1,-1);
    pos_t L;
    pos_t R;
    pos_t U;
    pos_t D;
    std::vector<pos_t> solve_states;
    std::vector<pos_t> general_positions;
    for(auto J : N->diamonds){
        L = J+left;
        R = J+right;
        U = J+above;
        D = J+below;
        if( (get(L) == FREE) && (get(L+left) == FREE)){
            solve_states.push_back(L);
        }
        if( (get(R) == FREE) && (get(R+right) == FREE)){
            solve_states.push_back(R);
        }
        if( (get(U) == FREE) && (get(U+above) == FREE)){
            solve_states.push_back(U);
        }
        if( (get(D) == FREE) && (get(D+below) == FREE)){
            solve_states.push_back(D);
        }
    }
    for(auto pos : solve_states){
        wave(copy,pos,N->diamonds);
        res = copy.find_general_position();
        if( !((res == pos_t(-1,-1)) || (res == old_res)) ){
            general_positions.push_back(res);
            old_res = res;
        }
    }
    return general_positions;
}

pos_t Map::find_general_position(){ //should be done on a already waved map
    for(unsigned char x=1; x<width;++x){
        for(unsigned char y=1;y<height;++y){
            if(get(pos_t(x,y))>2){
                return pos_t(x,y);
            }
        }
    }
    return pos_t(-1,-1); //failure
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
    data[pos.x][pos.y] = value;
}

unsigned char Map::get(const pos_t &pos){
    if(boundry_check(pos))
        return data[pos.x][pos.y];
//    std::cout << "THIS IS AN ERROR\n";
    return OBSTACLE;
}

std::string Map::to_string(const std::vector<pos_t> &J,const pos_t &general_position){
    std::string final_string;
    final_string += general_position.x;
    final_string += general_position.y;
    for(auto n : J){
        final_string += n.x;
        final_string += n.y;
    }
    return std::move(final_string);
}

void clear_hashtable(std::unordered_map<std::string,node*> &table, const std::string start_node_index){
    for(std::unordered_map<std::string,node*>::iterator i =table.begin(); i != table.end() ; ++i){
        if( i->first != start_node_index ){ //Don't delete start node
            delete i->second;
            table.erase(i);
        }
    }
}
