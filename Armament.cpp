//
// Created by PC on 15.11.2021.
//

#include "Armament.h"

namespace Basic {
std::ostream &operator<<(std::ostream &s, const Armament &vec) {
    s << "Type of armament: " << vec.type << "\n";
    s << "damage\t" << "speed\t" << "range\t" << "max ammunition\t" << "cur_ammunition\t" << "cost\t\n";
    for (int i = 0; i < 6; i++) {
        s << (vec.properties)[i] << "\t\t";
    }
    s << std::endl;
    return s;
}

/*std::istream & operator >> (std::istream &in, Armament &vector)
{
    int count;
    double number;
    in >> count;
    for (int i = 0; i < count; i ++){
        in >> number;
        vector.addElement(number);
    }
    return in;
} */
}