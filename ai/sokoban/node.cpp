#include "node.h"


node::node(const pos_t &man_pos, const std::vector<pos_t> &diamonds_pos, node *par){
    diamonds = diamonds_pos;
    man = man_pos;
    parent = par;
}

std::string to_string(const std::vector<pos_t> &J,pos_t general_position){
    std::string final_string;
    final_string += general_position.x;
    final_string += general_position.y;
    for(auto n : J){
        final_string += n.x;
        final_string += n.y;
    }
    return final_string;
}
std::string to_string(const std::vector<pos_t> &J){
    std::string final_string;
    for(auto n : J){
        final_string += n.x;
        final_string += n.y;
    }
    return final_string;
}

std::vector<pos_t> to_vector(std::string diamonds){
    std::vector<pos_t> vec;
    pos_t diamond;
    for(std::string::size_type i=0;i<diamonds.size();++i){
        if(i%2){//odd
            diamond.y = diamonds[i];
            vec.push_back(diamond);
        } else {
            diamond.x = diamonds[i];
        }
    }
    return vec;
}
