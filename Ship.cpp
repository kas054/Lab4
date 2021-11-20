//
// Created by PC on 15.11.2021.
//

#include "Ship.h"

#include <utility>

namespace Ships{
    Ship::Ship(std::string new_type, std::string name, double max_velocity, double max_life, double cost) {
        ship_type = std::move(new_type);
        this->name = std::move(name);
        properties[0] = max_velocity;
        properties[2] = max_life;
        properties[4] = cost;
    }

    void Ship::set_velocity(double velocity){
        if (velocity > this->get_property(0)) velocity = get_property(0); // properties[0] - max velocity
        else if (velocity < 0) velocity = 0;
        this->properties[1] = velocity; // properties[1] - current velocity
    }

    double Ship::get_property(int i) const {
        double answer;
        if (0 > i || i > count_properties() - 1) answer = 0;
        else answer = properties[i];
        return answer;
    }

    Transport_ship::Transport_ship( std::string new_type, std::string name, double max_velocity,
    double max_life, double cost, double max_cargo, double coef_decrease): Ship::Ship(new_type,name,max_velocity, max_life, cost){
        cargo[0] = max_cargo;
        cargo[2] = coef_decrease;
    }

    double Transport_ship::get_info_cargo(int i) const {
        double answer;
        if (0 > i || i > count_properties() - 1) answer = 0;
        else answer = cargo[i];
        return answer;
    }

    double Transport_ship::possible_speed(){ // максимально возможная скорость при текущей загрузке корабля
        return (cargo[1] / cargo[0]) * get_property(0) * cargo[3];
    }

    double Transport_ship::set_cur_speed(double new_speed){
        this->
    }
}