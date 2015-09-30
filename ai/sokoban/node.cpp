#include "node.h"


node::node(const pos_t &man_pos, const std::vector<pos_t> &diamonds_pos, node *par){
    diamonds = diamonds_pos;
    man = man_pos;
    parent = par;
//    direction = 'Z';
}

void node::add_path(node *next){
    paths.push_back(next);
}

