#include "node.h"

node::node(const pos_t &man_pos, const std::vector<pos_t> &diamonds_pos, node *par){
    diamonds = diamonds_pos;
    man = man_pos;
    parent = par;
    path_length = 0;
}

