//
// Created by PC on 15.11.2021.
//

#ifndef LAB4_3SEM_SHIP_H
#define LAB4_3SEM_SHIP_H
#include "Armament.h"
namespace Ship {
    class Ship {
    private:
        std::string ship_type;
        std::string name;
        struct Basic::Capitan capitan;
        int properties[5] = {0};
        // max_velocity, cur_velocity, max_life, cur_life, cost
    public:
        Ship() {};
        Ship(std::string type, std::string name,
             int max_velocity, int max_life, int cost);

        int get_property(int i) const { return properties[i]; }

        std::string get_type() const { return ship_type; }

        std::string get_name() const { return name; }

        void change_property(int i, int new_value);

        void change_type(std::string new_type) { ship_type = new_type; }

        void change_name(std::string new_name) { name = new_name; }

        void set_velocity(int velocity);

        void get_damage(int damage);
    };

    class Transport_ship: public virtual Ship {
    private:
        int cargo[3] = {0};
        //max_cargo, cur_cargo, coef_decrease;
    public:
        void set_cargo(int new_value) { cargo[0] = new_value; }
        void set_coef_decrease(int new_value) { cargo[2] = new_value; }
        int evalute_max_speed();
    };

    class Security_ship: public virtual Ship {
    private:
        Basic::Armament *armaments[4] = {nullptr};
        // Расположение орудий: корма, нос, правый борт, левый борт
    public:
        void change_armament(int i, int property, int new_value, std::string type = ""); // номер оружия, свойство оружия, новое значение, тип оружия
        Basic::Armament get_info_armament(int i) const;
        void change_place(int old_place, int new_place);
        void shoot(Basic::Coordinate coordinate);
    };

    class Military_transport_ship: public Security_ship, public Transport_ship {};
}

#endif //LAB4_3SEM_SHIP_H
