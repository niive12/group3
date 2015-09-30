#pragma once
#include <iostream>

struct pos_t{
    signed char x; //signed values so a position can be relative.
    signed char y;
    pos_t():x(0),y(0){x=0; y=0;}
    pos_t(signed char xx, signed char yy):x(0),y(0){x = xx; y = yy;}

    pos_t operator+(const pos_t& other){
        pos_t res;
        res.x = this->x + other.x;
        res.y = this->y + other.y;
        return res;
    }
    pos_t operator-(const pos_t& other){
        pos_t res;
        res.x = this->x - other.x;
        res.y = this->y - other.y;
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const pos_t& pos) {
        os << "(" << (int) pos.x << "," << (int) pos.y << ")";
        return os;
    }
    pos_t& operator=( const pos_t& other ) {
        x = other.x;
        y = other.y;
        return *this;
    }
    bool operator==( const pos_t& other){
        bool ans = false;
        if(x == other.x && y == other.y){
            ans = true;
        }
        return ans;
    }
};

const pos_t above(0,-1);
const pos_t below(0,1);
const pos_t right(1,0);
const pos_t left(-1,0);
enum answers{south=1,north=2,east=4,west=8};
