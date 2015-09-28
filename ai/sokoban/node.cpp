#include "node.h"


node::node(const pos_t &man_pos, const std::vector<pos_t> &diamonds_pos, node *par){
    diamonds = diamonds_pos;
    man = man_pos;
    parent = par;
    direction = 'Z';
}

void node::add_path(node next){
    paths.push_back(next);
}

void print_path(node* path){
    if ( path != nullptr ){
        std::cout << "hello\n";
        print_path(path->parent);
        std::cout << (int) path->direction << " ";
    } else {
        std::cout << "oops\n";
    }
}
