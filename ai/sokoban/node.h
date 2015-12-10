#pragma once
#include <vector>
#include "position_t.h"

//The game exploring a graph, where each node represents a diamond move.
class node {
    //data: 46 bytes per node.
    //In order to store the thing in a heap an index string 5 (n+1) bytes is required + a pointer (8 bytes)
    //59 bytes in total.
public:
    node *parent = nullptr;      //8 bytes
    float path_length;           //4 byte
    pos_t man;                   //2 bytes
    std::vector<pos_t> diamonds; //24 + 2*n (32 in this example)

    node(const pos_t &man, const std::vector<pos_t> &diamonds_pos, node *par=nullptr);
    node& operator=( const node& other ) {
        parent = other.parent;
        path_length = other.path_length;
        diamonds = other.diamonds;
        man = other.man;
        return *this;
    }
};

//used to sort the nodes by the path length
struct comparator_functor {
  bool operator() (const node* a, const node* b) const {
    return a->path_length > b->path_length;
  }
};
