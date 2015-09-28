#include "node.h"

node::node(const pos_t &man_pos, const std::vector<pos_t> &diamonds_pos){
    diamonds = diamonds_pos;
    man = man_pos;
}

node::add_path(node next){
    paths.push_back(next);
}
