#pragma once
#include <vector>
#include "map.h"
class node {
private:
    //data:
    std::vector<node> paths;
public:
    std::vector<pos_t> diamonds;
    pos_t man;
    void add_path(node next);
    node(const pos_t &man, const std::vector<pos_t> &diamonds_pos);
};
