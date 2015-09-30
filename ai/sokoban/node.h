#pragma once
#include <vector>
#include "position_t.h"
class node {
private:
    //data: 229 bytes per node
    std::vector<node*> paths;    //24 + 8*n*4, n = number of diamonds (up to 184 in this example)
public:
    //this *could* be optimized so positions are reference points in a 1D array (saves n+1)
    //and the diamonds is stored as a string, saving 23 bytes.
    //in total going from 45 -> 16 bytes
    node *parent = nullptr;      //8 bytes
    char direction;              //1 byte
    pos_t man;                   //2 bytes
    std::vector<pos_t> diamonds; //24 + 2*n (34 in this example)
    void add_path(node *next);
    node(const pos_t &man, const std::vector<pos_t> &diamonds_pos, node *par=nullptr);
    node& operator=( const node& other ) {
        paths = other.paths;
        parent = other.parent;
//        direction = other.direction;
        diamonds = other.diamonds;
        man = other.man;
        return *this;
    }
};

