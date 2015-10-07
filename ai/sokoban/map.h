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

//directions for add_all_possible_paths()
#define DIRECTION_PUSH 0
#define DIRECTION_PULL 1

class Map {
private:
    //data:
    unsigned char **data;
    std::queue<pos_t> wave_color( pos_t pos, int previous_color, Map &wave_map); //stored in wavefront.cpp

    bool boundry_check(const pos_t &pos);
public:
    //data:
    int width, height;
    char n_diamonds;
    std::vector<pos_t> diamond_pos;
    std::vector<pos_t> goals; //constant
    pos_t man;
    //functions:
    void read_file(std::string file_name);
    void print();
    void set(const pos_t &pos, const unsigned char &value);
    unsigned char get(const pos_t &pos);

    unsigned char wave(Map &wave_map, pos_t man_pos, const std::vector<pos_t> &diamonds); //stored in wavefront.cpp
    std::string calculate_path(Map &wave_map, node *N);                              //stored in wavefront.cpp
    void print_path(Map &wave_map, node* path, bool first = true);
    bool game_complete(node* N);
    char valid_push(pos_t diamond); //sees a diamond is movable
    char valid_pull(pos_t diamond); //sees a diamond is movable
    bool locked_in(pos_t diamond); //sees if a diamond is locked into a corner.
    std::queue<node*> add_all_possible_paths(node *N, Map &copy, char direction = DIRECTION_PUSH);
    node *bff_search(Map &copy);
    node *idf_search(node *start, Map &copy);

    std::vector<pos_t> find_all_general_positions(Map copy, node* N);
    pos_t find_general_position();
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
    std::string to_string(const std::vector<pos_t> &J, pos_t &general_position);
};

