#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include "position_t.h"

#define DIAMOND  2
#define OBSTACLE 1
#define FREE     0

class Map {
private:
    //data:
    std::vector<pos_t> goals; //constant
    unsigned char **data;
    std::queue<pos_t> wave_color( pos_t pos, int previous_color, Map &wave_map); //stored in wavefront.cpp

    bool boundry_check(const pos_t &pos);
public:
    //data:
    std::vector<pos_t> diamond_pos;
    pos_t man;
    int width, height, n_diamonds; //constant

    //functions:
    void read_file(std::string file_name);
    void print();
    void set(const pos_t &pos, const unsigned char &value);
    unsigned char get(const pos_t &pos);

    unsigned char wave(Map &wave_map, pos_t start); //stored in wavefront.cpp
    char diamonds_placed();
    char valid_move(pos_t diamond); //sees a diamond is movable
    bool locked_in(pos_t diamond); //sees if a diamond is locked into a corner.


    //operator overloads
    Map& operator=(const Map& other );

    //constructors
    Map();
    Map(std::string file_name );
    ~Map() {
        for(int i = 0; i < width; ++i){
            delete[] data[i];
        }
        delete[] data;
    }
};
