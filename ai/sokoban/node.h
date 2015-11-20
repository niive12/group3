#pragma once
#include <vector>
#include "position_t.h"
class node {
private:
    //data: 54 bytes per node.
    //In order to store the thing in a heap an index string 8 (n+1) bytes is required + a pointer (8 bytes)
    //70 bytes in total.
    //I am currently using about 3 times as much memory.
public:
    //this *could* be optimized so positions are reference points in a 1D array (saves n+1)
    //and the diamonds is stored as a string, saving 23 bytes.
    //in total going from 54 -> 26 bytes
    node *parent = nullptr;      //8 bytes
    float path_length;           //4 byte
    pos_t man;                   //2 bytes
    pos_t general_pos;           //2 bytes
    std::vector<pos_t> diamonds; //24 + 2*n (38 in this example)

    node(const pos_t &man, const std::vector<pos_t> &diamonds_pos, node *par=nullptr);
    node& operator=( const node& other ) {
        parent = other.parent;
        path_length = other.path_length;
        diamonds = other.diamonds;
        man = other.man;
        return *this;
    }
    bool operator<(const node& rhs) const {
        return path_length > rhs.path_length;
    }
};

struct comparator_functor {
  bool operator() (const node* a, const node* b) const {
    return a->path_length > b->path_length; //calls your operator
  }
};
