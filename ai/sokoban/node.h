#pragma once
#include <vector>
#include "map.h"
class node {
private:
    //data:
    Map map;
    int cost;
    node *parent;
    std::vector<node*> paths;
public:
    void add_path();
    void prune();
};
