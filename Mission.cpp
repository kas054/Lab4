//
// Created by PC on 21.11.2021.
//

#include "Mission.h"
using namespace Basic;
namespace Menu{

    Basic::Coordinate Mission::get_coord_A_B(int i) const {
        Basic::Coordinate answer;
        if (i == 0) answer =  coordinates_A;
        else if (i == 1) answer = coordinates_B;
        else throw "No such base";
        return answer;
    }

    void Mission::set_coord_A_B(int i, int x, int y){
        if (i == 0) {
            coordinates_A.x = x;
            coordinates_A.y = y;
        }
        else if (i == 1){
            coordinates_B.x = x;
            coordinates_B.y = y;
        }
        else throw "No such base";
    }

    // Изменение характеристик корабля по его названию
    void Mission::change_ship_property(int c_p, std::string name, int ship_property_index, double new_value){
        Ships::Ship *cur_ship;
        switch(c_p) {
            case 0:
                cur_ship = convoy->description_ship(name);
            case 1:
                cur_ship = pirates->description_ship(name);
        }
        cur_ship->change_property(ship_property_index, new_value);
    }

    void  Mission::change_name_ship(int c_p, std::string name, std::string new_name){
        Ships::Ship *cur_ship;
        switch(c_p) {
            case 0:
                cur_ship = convoy->description_ship(name);
            case 1:
                cur_ship = pirates->description_ship(name);
        }
        cur_ship->change_name(new_name);
    }

    void Mission::change_ship_type(int c_p, std::string name, std::string new_type){
        Ships::Ship *cur_ship;
        switch(c_p) {
            case 0:
                cur_ship = convoy->description_ship(name);
            case 1:
                cur_ship = pirates->description_ship(name);
        }
        cur_ship->change_type(new_type);
    }

    void Mission::change_ship_cap(int c_p, std::string name, Basic::Capitan new_cap){
        Ships::Ship *cur_ship;
        switch(c_p) {
            case 0:
                cur_ship = convoy->description_ship(name);
            case 1:
                cur_ship = pirates->description_ship(name);
        }
        cur_ship->change_cap(new_cap);
    }

    Ships::Ship *Mission::get_ship(int c_p, std::string name) const{
        Ships::Ship *cur_ship = nullptr;
        switch(c_p) {
            case 0:
                cur_ship = convoy->description_ship(name);
            case 1:
                cur_ship = pirates->description_ship(name);
        }
        return cur_ship;
    }

    void Mission::buy_ship(std::string ship_type){
        std::map <std::string, Ships::Ship> :: iterator it;
        Ships::Ship *new_ship;
        int cost;
        it = (config->ship).find(ship_type);

        if (it == (config->ship).end()) throw "No such ship";

        new_ship = new Ships::Ship;
        *new_ship = it->second;
        cost = new_ship->get_property(4);

        //max_money - spend_money > 0 && max_count_ship_c > current_size of convoy
        if ((this->get_properties(0) - this->get_properties(1)) > 0 && (this->get_properties(6) > convoy->get_count())) {
            convoy->add_ship(new_ship, get_coord_A_B(0)); // помещаем корабль на базу А
            this->set_properties(1, cost + this->get_properties(1)); // change spend_money
        }
        else throw "You do not have money or free place in convoy";
    }

    void Mission::sell_ship(int c_p, std::string name){
        Table <std::string, Info> :: Iterator it;
        int cost;
        it = convoy->find(name);

        if (it == convoy->end()) throw "No such ship";

        cost = (*it).info.ship->get_property(4);
        this->set_properties(1, this->get_properties(1) - cost); // change spend_money
        convoy->del_ship(name);
    }

    void Mission::del_ship(int c_p, std::string name){ // remove from Basic_config
        Table <std::string, Info> :: Iterator it;
        std::string type;
        switch (c_p){
            case 0:
                it = convoy->find(name);
                if (it == convoy->end()) throw "No such ship";
            case 1:
                it = pirates->find(name);
                if (it == pirates->end()) throw "No such ship";
        }
        type = (*it).info.ship->get_type();
        
        std::map<std::string, Ships::Ship> :: iterator map_it;
        

    }

}
