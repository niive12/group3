#include "map.h"
#include <queue>

std::queue<pos_t> Map::wave_color(pos_t pos, int previous_color, Map &wave_map){
    std::queue<pos_t> colored_positions;
    //color 4 surrounding pixels
    int color = previous_color + 1;
    pos_t testing_pos;
    for(int x = -1; x <= 1; ++x){
        for(int y = -1; y <= 1; ++y){
            if((x == 0) || (y == 0)){
                testing_pos.x = pos.x + x;
                testing_pos.y = pos.y + y;
                if ( boundry_check(testing_pos) ) {
                    if(wave_map.get( testing_pos ) == FREE) {
                        wave_map.set(testing_pos, color);
                        colored_positions.push( testing_pos );
                    }
                }
            }
        }
    }
    return colored_positions;
}

unsigned char Map::wave(Map &wave_map, pos_t start){
    unsigned char color = 3;                // this means distance is (color - 2)

    std::queue<pos_t> search_list;         //list of pixels to search for.
    std::queue<pos_t> surrounding_points;
    std::queue<pos_t> colored_list;        //list of pixels colored by a single color.
    wave_map.set(start, color);             //set first value
    search_list.push(start);           //set first target

    bool wave_complete = false;
    pos_t current_pos;

    while ( !wave_complete ) {
        wave_complete = true;
        while ( search_list.size() > 0 ) {
            wave_complete = false; //prevent the loop to stop when there is more pixels to search for
            current_pos = search_list.front();
            search_list.pop();
            surrounding_points = wave_color( current_pos, color, wave_map); //this gives the surrounding coordinates
            while ( surrounding_points.size() > 0 ) {                       //append these coordinates to the list.
                colored_list.push( surrounding_points.front() );
                surrounding_points.pop();
            }
        }
        search_list = colored_list;
        while(!colored_list.empty()){
            colored_list.pop();
        }
        color++;
    }
    return color;
}
