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
        std::cout <<"diamonds: "<< n_diamonds << "\n";
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
        std::cout << "File does not exist\n";
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

Map& Map::operator=(const Map& other ) {
    if(height != other.height || width != other.width){
        for(int i = 0; i < width; ++i){
            delete[] data[i];
        }
        delete[] data;
    }
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
    return data[pos.x][pos.y];
}
