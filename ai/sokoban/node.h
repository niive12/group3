#pragma once
#include <vector>
#include "position_t.h"
class node {
private:
    //data:
    std::vector<node> paths;
public:
    node *parent;
    char direction;
    std::vector<pos_t> diamonds;
    pos_t man;
    void add_path(node next);
    node(const pos_t &man, const std::vector<pos_t> &diamonds_pos, node *par=nullptr);
    node& operator=( const node& other ) {
        paths = other.paths;
        parent = other.parent;
        direction = other.direction;
        diamonds = other.diamonds;
        man = other.man;
        return *this;
    }
};

void print_path(node* path);
