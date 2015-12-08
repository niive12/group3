#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include "position_t.h"
#include "node.h"
#include <unordered_map>

#define DIAMOND  2
#define OBSTACLE 1
#define FREE     0

void clear_hashtable(std::unordered_map<std::string,node*> &table, std::string start_node_index = "n");

struct robot_move{
    float cost;
    pos_t pos;
    char  direction;
    robot_move(){
        cost = 0;
        pos = pos_t(0,0);
        direction = 'U';
    }
    robot_move(float c, pos_t p, char d){
        cost = c;
        pos = p;
        direction = d;
    }
};

class Map {
private:
    unsigned char **data;    //map container

    //Wavefront to move in the map
    std::queue<pos_t> wave_color( pos_t pos, int previous_color, Map &wave_map);          //stored in wavefront.cpp
    unsigned char wave(Map &wave_map, pos_t man_pos, const std::vector<pos_t> &diamonds); //stored in wavefront.cpp

    //print the solution
    std::string calculate_path(Map &wave_map, node *N);                          //stored in wavefront.cpp
    void print_path(Map &wave_map, node* path, bool first = true);               //stored in wavefront.cpp
    void print_path_as_C_code(Map &wave_map, node* path, bool first = true);     //stored in wavefront.cpp

    //Get neighboring solutions
    std::queue<robot_move> add_connected_moves(robot_move m, std::vector<std::vector<float>> &cost_map); //stored in robot_moving.cpp

    //analysis of the map
    bool boundry_check(const pos_t &pos);
    bool locked_in(pos_t diamond);  //sees if a diamond is locked into a corner.
    bool dead_lock(pos_t diamond);  //sees if a diamond is in a dead lock.
    char valid_push(pos_t diamond); //sees a diamond is movable
    char valid_pull(pos_t diamond); //sees a diamond is movable
    bool game_complete(node* N);

    //closed set
    std::unordered_map<std::string,node*> closed_set;
    std::string to_string(const std::vector<pos_t> &J, const pos_t &man_pos);

    //Solve the game
    std::queue<node*> add_all_possible_paths(node *N, Map &copy);

    //model of the map:
    int width, height;
    char n_diamonds;
    std::vector<pos_t> diamond_pos;
    std::vector<pos_t> goals; //constant
    std::vector<pos_t> dead_locked_wall;
public:
    std::vector<std::vector<float>> find_robot_moves(Map &copy_map, node* N);                   //stored in robot_moving.cpp

    void find_dead_lock_pos(Map &wave_map);

    pos_t man;
    bool optimize_for_robot_moves = false;

    //functions:
    void read_file(std::string file_name);
    void print();
    void set(const pos_t &pos, const unsigned char &value);
    unsigned char get(const pos_t &pos);

    //solve the game
    void informed_bff_search(Map &copy_map);

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

