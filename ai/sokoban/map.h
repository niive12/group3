#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include "position_t.h"
#include "node.h"

#define DIAMOND  2
#define OBSTACLE 1
#define FREE     0

class Map {
private:
    //data:
    unsigned char **data;
    std::queue<pos_t> wave_color( pos_t pos, int previous_color, Map &wave_map); //stored in wavefront.cpp
    std::vector<pos_t> goals; //constant

    bool boundry_check(const pos_t &pos);
public:
    //data:
    int width, height;
    char n_diamonds;
    std::vector<pos_t> diamond_pos;
    pos_t man;
    //functions:
    void read_file(std::string file_name);
    void print();
    void set(const pos_t &pos, const unsigned char &value);
    unsigned char get(const pos_t &pos);

    unsigned char wave(Map &wave_map, pos_t man_pos, const std::vector<pos_t> &diamonds); //stored in wavefront.cpp
    bool game_complete(node test);
    char valid_move(pos_t diamond); //sees a diamond is movable
    bool locked_in(pos_t diamond); //sees if a diamond is locked into a corner.
    std::queue<node> add_all_possible_paths(node &N, Map &copy);
    node *bff_search(node start, Map &copy);

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

