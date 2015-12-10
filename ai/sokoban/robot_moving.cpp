#include "map.h"

#define FORWARD_COST 1.092
#define LEFT_COST    0.9517
#define RIGHT_COST   0.78
#define BACK_COST    2.69

std::string robot_moves(std::string moves, char previous);

struct robot_cost_comparator_functor {
  bool operator() (const robot_move a, const robot_move b) const {
    return a.cost > b.cost;
  }
};

std::queue<robot_move> Map::add_connected_moves(robot_move m, std::vector<std::vector<float>> &cost_map){
    std::queue<robot_move> connected_positions;
    pos_t testing_pos;
    float current_cost = m.cost;
    char current_direction = m.direction;
    testing_pos = m.pos + above;
    if (cost_map[testing_pos.x][testing_pos.y] == FREE ){
        switch (current_direction) {
            case 'N':
                connected_positions.push(robot_move(current_cost + FORWARD_COST, testing_pos, 'N'));
                break;
            case 'S':
                connected_positions.push(robot_move(current_cost + BACK_COST, testing_pos, 'N'));
                break;
            case 'E':
                connected_positions.push(robot_move(current_cost + RIGHT_COST + FORWARD_COST, testing_pos, 'N'));
                break;
            case 'W':
                connected_positions.push(robot_move(current_cost + LEFT_COST + FORWARD_COST, testing_pos, 'N'));
                break;
            default:
                break;
        }
    }
    testing_pos = m.pos + below;
    if (cost_map[testing_pos.x][testing_pos.y] == FREE ){
        switch (current_direction) {
            case 'N':
                connected_positions.push(robot_move(current_cost + BACK_COST, testing_pos, 'S'));
                break;
            case 'S':
                connected_positions.push(robot_move(current_cost + FORWARD_COST, testing_pos, 'S'));
                break;
            case 'E':
                connected_positions.push(robot_move(current_cost + LEFT_COST + FORWARD_COST, testing_pos, 'S'));
                break;
            case 'W':
                connected_positions.push(robot_move(current_cost + RIGHT_COST + FORWARD_COST, testing_pos, 'S'));
                break;
            default:
                break;
        }
    }
    testing_pos = m.pos + left;
    if (cost_map[testing_pos.x][testing_pos.y] == FREE ){
        switch (current_direction) {
            case 'N':
                connected_positions.push(robot_move(current_cost + LEFT_COST + FORWARD_COST, testing_pos, 'W'));
                break;
            case 'S':
                connected_positions.push(robot_move(current_cost + RIGHT_COST + FORWARD_COST, testing_pos, 'W'));
                break;
            case 'E':
                connected_positions.push(robot_move(current_cost + BACK_COST, testing_pos, 'W'));
                break;
            case 'W':
                connected_positions.push(robot_move(current_cost + FORWARD_COST, testing_pos, 'W'));
                break;
            default:
                break;
        }
    }
    testing_pos = m.pos + right;
    if (cost_map[testing_pos.x][testing_pos.y] == FREE ){
        switch (current_direction) {
            case 'N':
                connected_positions.push(robot_move(current_cost + LEFT_COST + FORWARD_COST, testing_pos, 'E'));
                break;
            case 'S':
                connected_positions.push(robot_move(current_cost + RIGHT_COST + FORWARD_COST, testing_pos, 'E'));
                break;
            case 'E':
                connected_positions.push(robot_move(current_cost + FORWARD_COST, testing_pos, 'E'));
                break;
            case 'W':
                connected_positions.push(robot_move(current_cost + BACK_COST, testing_pos, 'E'));
                break;
            default:
                break;
        }
    }
    return connected_positions;
}

std::vector<std::vector<float>> Map::find_robot_moves(Map &copy_map, node* N){
    std::vector< std::vector<float> > cost_map(width, std::vector<float>(height) );

    copy_map = *this;
    for(auto n : N->diamonds){
        copy_map.set(n, DIAMOND);
    }
    for(int x = 0; x < width; ++x){
        for(int y = 0; y < height; ++y){
            cost_map[x][y] = data[x][y];
        }
    }
    for(auto n : N->diamonds){
        cost_map[n.x][n.y] = DIAMOND;
    }

    float distance = 3;                // this means distance is (color - 3)

    std::priority_queue<robot_move,std::vector<robot_move>,robot_cost_comparator_functor> open_list;

    std::queue<robot_move> surrounding_points;
    cost_map[N->man.x][N->man.y] = distance;
    if( N->parent == nullptr){
        open_list.push(robot_move(distance, N->man, 'N'));
        open_list.push(robot_move(distance, N->man, 'S'));
        open_list.push(robot_move(distance, N->man, 'E'));
        open_list.push(robot_move(distance, N->man, 'W'));
    } else {
        for(size_t i = 0; i < N->diamonds.size(); ++i){
            if(N->man == N->parent->diamonds.at(i) ){
                pos_t displacement = N->diamonds.at(i) - N->parent->diamonds.at(i);
                if(       displacement == above){ open_list.push(robot_move(distance, N->man, 'N'));
                } else if(displacement == below){ open_list.push(robot_move(distance, N->man, 'S'));
                } else if(displacement == right){ open_list.push(robot_move(distance, N->man, 'E'));
                } else if(displacement == left){  open_list.push(robot_move(distance, N->man, 'W'));
                }
            }
        }
    }
    robot_move current_move;

    while( !open_list.empty() ) {
        current_move = open_list.top();
        open_list.pop();
        if( cost_map[current_move.pos.x][current_move.pos.y] == FREE ){
            cost_map[current_move.pos.x][current_move.pos.y] = current_move.cost;
            copy_map.set(current_move.pos, current_move.direction);
        }
        surrounding_points = add_connected_moves( current_move, cost_map);
        while( !surrounding_points.empty() ) {
            open_list.push( surrounding_points.front() );
            surrounding_points.pop();
        }
    }

    char entry = 'q';
    //remove all unreachables
    for(auto i : N->diamonds){
        float min = 1e6;
        for(int x = -1; x <= 1; ++x){
            for(int y = -1; y <=1; ++y){
                if( (x == 0) ^ (y == 0) ){
                    if( (cost_map[i.x+x][i.y+y] >= 3) && (cost_map[i.x+x][i.y+y] < 1e6) ){
                        min = cost_map[i.x+x][i.y+y];
                        entry = copy_map.get(pos_t(i.x+x,i.y+y));
                    }
                }
            }
        }
        if(min == 1e6){
        cost_map[i.x][i.y] = 1e6;
        }
    }
    //add cost to all reachable diamonds
    for(auto i : N->diamonds){
        float min = 1e6;
        float turn_penalty = 0;
        if( cost_map[i.x][i.y] == DIAMOND){
            for(int x = -1; x <= 1; ++x){
                for(int y = -1; y <=1; ++y){
                    if( (x==0) ^ (y==0) ){
                        if( (cost_map[i.x+x][i.y+y] >= 3) && (cost_map[i.x+x][i.y+y] < min) && (copy_map.get(pos_t(i.x+x,i.y+y)) != DIAMOND) && ( (copy_map.get(pos_t(i.x-x,i.y-y)) > 3) || (copy_map.get(pos_t(i.x-x,i.y-y)) == FREE) ) ){
                            min = cost_map[i.x+x][i.y+y];
                            entry = copy_map.get(pos_t(i.x+x,i.y+y));
                            pos_t direction = pos_t(x,y); //eg. if there is a free spot on the right and the entry is facing north, the robot have to turn left
                            switch(entry){
                                case 'N':
                                    if(     direction == above){ turn_penalty = 0; }
                                    else if(direction == right){ turn_penalty = LEFT_COST; }
                                    else if(direction == left ){ turn_penalty = RIGHT_COST; }
                                    break;
                                case 'S':
                                    if(     direction == below){ turn_penalty = 0; }
                                    else if(direction == right){ turn_penalty = RIGHT_COST; }
                                    else if(direction == left ){ turn_penalty = LEFT_COST; }
                                    break;
                                case 'E':
                                    if(     direction == above){ turn_penalty = LEFT_COST; }
                                    else if(direction == below){ turn_penalty = RIGHT_COST; }
                                    else if(direction == right){ turn_penalty = 0; }
                                    break;
                                case 'W':
                                    if(     direction == above){ turn_penalty = RIGHT_COST; }
                                    else if(direction == below){ turn_penalty = LEFT_COST; }
                                    else if(direction == left ){ turn_penalty = 0; }
                                default:
                                    break;
                            }
                            if(N->man != i+direction && turn_penalty > 0){
                                turn_penalty += BACK_COST;
                            }
                        }
                    }
                }
            }
            cost_map[i.x][i.y] = min + FORWARD_COST + turn_penalty;
        }
    }
    for(int x = 1; x < width-1; ++x){
        for(int y = 1; y < height-1; ++y){
            if(cost_map[x][y] != 1e6)
            copy_map.set(pos_t(x,y),cost_map[x][y]);
        }
    }
    return move(cost_map);
}
