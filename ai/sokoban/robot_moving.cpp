#include "map.h"

#if 1 //timing based on meassurements
    #define FORWARD_COST 1.092
    #define LEFT_COST    1.9517
    #define RIGHT_COST   0.78
    #define BACK_COST    2.69
#else //wavefront cost
    #define FORWARD_COST 1
    #define LEFT_COST    0
    #define RIGHT_COST   0
    #define BACK_COST    0
#endif
std::string robot_moves(std::string moves, char previous);

float Map::robot_move_time(node* N){
    Map copy;
    //TODO: make a better path planning than using wavefront.
    //Alternative would be to give the
    std::string moves;
    char previous;// = moves[0];
    if(N->parent != nullptr){
        moves = calculate_path(copy,N);
        std::string par_path = calculate_path(copy,N->parent);
        previous = par_path[par_path.size()-1];
    }
    std::string path = robot_moves(moves, previous);

    float cost = 0;
    for(size_t i = 0; i < path.length(); ++i){
        switch(path[i]){
            case 'f':
                cost += FORWARD_COST;
                break;
            case 'l':
                cost += LEFT_COST;
                break;
            case 'r':
                cost += RIGHT_COST;
                break;
            case 'b':
                cost += BACK_COST;
                break;
            default:
                break;
        }
    }
    return cost;
}

std::string robot_moves(std::string moves, char previous){
    std::string output;
    const char follow_line = 'f', turn_left = 'l', turn_right = 'r', move_back = 'b';
    const char preferred_turn = 'r'; //in cases where the robot should turn around it doesn't mater which direction it happens.
    bool running = true;
    char current = moves[0];
    int index = 0;
    char initial = current;
    while(running){
        switch(current){
        case 'l':
            switch(previous){
            case 'l':
                output += follow_line;
                break;
            case 'u':
                output += turn_left;
                output += follow_line;
                break;
            case 'd':
                output += turn_right;
                output += follow_line;
                break;
            case 'r':
                output += preferred_turn;
                output += preferred_turn;
                output += follow_line;
                break;
            case 'L':
                std::cout << "error: " << initial << moves << " " << previous << current;
                running = false;
                break;
            case 'U':
                output += move_back;
                output += turn_right;
                output += follow_line;
                break;
            case 'D':
                output += move_back;
                output += turn_left;
                output += follow_line;
                break;
            case 'R':
                output += move_back;
                output += follow_line;
                break;
            default:
                break;
            }
            break;
        case 'u':
            switch(previous){
            case 'l':
                output += turn_right;
                output += follow_line;
                break;
            case 'u':
                output += follow_line;
                break;
            case 'd':
                output += preferred_turn;
                output += preferred_turn;
                output += follow_line;
                break;
            case 'r':
                output += turn_left;
                output += follow_line;
                break;
            case 'L':
                output += move_back;
                output += turn_left;
                output += follow_line;
                break;
            case 'U':
                std::cout << "error: " << initial << moves << " " << previous << current;
                running = false;
                break;
            case 'D':
                output += move_back;
                output += follow_line;
                break;
            case 'R':
                output += move_back;
                output += turn_right;
                output += follow_line;
                break;
            default:
                break;
            }
            break;
        case 'd':
            switch(previous){
            case 'l':
                output += turn_left;
                output += follow_line;
                break;
            case 'u':
                output += preferred_turn;
                output += preferred_turn;
                output += follow_line;
                break;
            case 'd':
                output += follow_line;
                break;
            case 'r':
                output += turn_right;
                output += follow_line;
                break;
            case 'L':
                output += move_back;
                output += turn_right;
                output += follow_line;
                break;
            case 'U':
                output += move_back;
                output += follow_line;
                break;
            case 'D':
                std::cout << "error: " << initial << moves << " " << previous << current;
                running = false;
                break;
            case 'R':
                output += move_back;
                output += turn_left;
                output += follow_line;
                break;
            default:
                break;
            }
            break;
        case 'r':
            switch(previous){
            case 'l':
                output += preferred_turn;
                output += preferred_turn;
                output += follow_line;
                break;
            case 'u':
                output += turn_right;
                output += follow_line;
                break;
            case 'd':
                output += turn_left;
                output += follow_line;
                break;
            case 'r':
                output += follow_line;
                break;
            case 'L':
                output += move_back;
                output += follow_line;
                break;
            case 'U':
                output += move_back;
                output += turn_left;
                output += follow_line;
                break;
            case 'D':
                output += move_back;
                output += turn_right;
                output += follow_line;
                break;
            case 'R':
                std::cout << "error: " << initial << moves << " " << previous << current;
                running = false;
                break;
            default:
                break;
            }
            break;
        case 'L':
            switch(previous){
            case 'l':
                output += follow_line;
                break;
            case 'u':
                output += turn_left;
                output += follow_line;
                break;
            case 'd':
                output += turn_right;
                output += follow_line;
                break;
            case 'r':
                output += preferred_turn;
                output += preferred_turn;
                output += follow_line;
                break;
            case 'L':
                output += follow_line;
                break;
            case 'U':
                output += move_back;
                output += turn_right;
                output += follow_line;
                break;
            case 'D':
                output += move_back;
                output += turn_left;
                output += follow_line;
                break;
            case 'R':
                output += move_back;
                output += follow_line;
                break;
            default:
                break;
            }
            break;
        case 'U':
            switch(previous){
            case 'l':
                output += turn_right;
                output += follow_line;
                break;
            case 'u':
                output += follow_line;
                break;
            case 'd':
                output += preferred_turn;
                output += preferred_turn;
                output += follow_line;
                break;
            case 'r':
                output += turn_left;
                output += follow_line;
                break;
            case 'L':
                output += move_back;
                output += turn_left;
                output += follow_line;
                break;
            case 'U':
                output += follow_line;
                break;
            case 'D':
                output += move_back;
                output += follow_line;
                break;
            case 'R':
                output += move_back;
                output += turn_right;
                output += follow_line;
                break;
            default:
                break;
            }
            break;
        case 'D':
            switch(previous){
            case 'l':
                output += turn_left;
                output += follow_line;
                break;
            case 'u':
                output += preferred_turn;
                output += preferred_turn;
                output += follow_line;
                break;
            case 'd':
                output += follow_line;
                break;
            case 'r':
                output += turn_right;
                output += follow_line;
                break;
            case 'L':
                output += move_back;
                output += turn_right;
                output += follow_line;
                break;
            case 'U':
                output += move_back;
                output += follow_line;
                break;
            case 'D':
                output += follow_line;
                break;
            case 'R':
                output += move_back;
                output += turn_left;
                output += follow_line;
                break;
            default:
                break;
            }
            break;
        case 'R':
            switch(previous){
            case 'l':
                output += preferred_turn;
                output += preferred_turn;
                output += follow_line;
                break;
            case 'u':
                output += turn_right;
                output += follow_line;
                break;
            case 'd':
                output += turn_left;
                output += follow_line;
                break;
            case 'r':
                output += follow_line;
                break;
            case 'L':
                output += move_back;
                output += follow_line;
                break;
            case 'U':
                output += move_back;
                output += turn_left;
                output += follow_line;
                break;
            case 'D':
                output += move_back;
                output += turn_right;
                output += follow_line;
                break;
            case 'R':
                output += follow_line;
                break;
            default:
                break;
            }
            break;
        default:
            running = false;
            break;
        }
        previous = current;
        current = moves[++index];
    }
    return output;
}
