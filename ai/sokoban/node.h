#pragma once
#include <vector>
#include "position_t.h"
class node {
private:
    //data: 47 bytes per node
public:
    //this *could* be optimized so positions are reference points in a 1D array (saves n+1)
    //and the diamonds is stored as a string, saving 23 bytes.
    //in total going from 47 -> 24 bytes
    node *parent = nullptr;      //8 bytes
    char direction;              //1 byte
    pos_t man;                   //2 bytes
    pos_t general_pos;           //2 bytes
    std::vector<pos_t> diamonds; //24 + 2*n (34 in this example)
//    std::string diamonds;        //1+2*n //stored as index in the hash_table

    node(const pos_t &man, const std::vector<pos_t> &diamonds_pos, node *par=nullptr);
    node& operator=( const node& other ) {
        parent = other.parent;
//        direction = other.direction;
        diamonds = other.diamonds;
        man = other.man;
        return *this;
    }
};

//std::string to_string(const std::vector<pos_t> &J, pos_t general_position);
std::string to_string(const std::vector<pos_t> &J); //naiive
std::vector<pos_t> to_vector(std::string diamonds);
