//
// Created by PC on 21.11.2021.
//
#include "gtest/gtest.h"
#include "../Ship.h"
TEST(constructor, defaultConstructor)
{
    Ships::Ship a;
    ASSERT_EQ("", a.get_type());
    ASSERT_EQ("", a.get_name());
    for (int i = 0; i < a.count_properties(); i ++)
        ASSERT_EQ(0, a.get_property(i));

    Ships::Transport_ship b;
    ASSERT_EQ("", b.get_type());
    ASSERT_EQ("", b.get_name());
    for (int i = 0; i < b.count_properties(); i ++)
        ASSERT_EQ(0, b.get_property(i));

    for (int j = 0; j < b.get_size(); j ++){
        ASSERT_EQ(0, b.get_info_cargo(j));
    }

    Ships::Security_ship c;
    ASSERT_EQ("", b.get_type());
    ASSERT_EQ("", b.get_name());
    for (int i = 0; i < b.count_properties(); i ++)
        ASSERT_EQ(0, b.get_property(i));
    for (int i = 0; i < 4; i ++){
        ASSERT_EQ(nullptr, c.get_info_armament(i) );
    }

    Ships::Military_transport_ship d;
    ASSERT_EQ("", b.get_type());
    ASSERT_EQ("", b.get_name());
    for (int i = 0; i < b.count_properties(); i ++)
        ASSERT_EQ(0, b.get_property(i));
    for (int i = 0; i < 4; i ++){
        ASSERT_EQ(nullptr, c.get_info_armament(i) );
    }
    for (int j = 0; j < b.get_size(); j ++){
        ASSERT_EQ(0, b.get_info_cargo(j));
    }
}

TEST(constructor, initConstructor){
    std::string st = "type A";
    double number = 100;

    Ships::Ship a = Ships::Ship(st, st, number, number, number);
    Ships::Transport_ship b = Ships::Transport_ship(st, st, number, number, number, number, number);
    Ships::Military_transport_ship d = Ships::Military_transport_ship(st, st, number, number, number, number, number);
    Ships::Security_ship c = Ships::Security_ship(st, st, number, number, number);

    //Ships::Ship a;
    ASSERT_EQ(st, a.get_type());
    ASSERT_EQ(st, a.get_name());
    for (int i = 0; i < a.count_properties(); i ++)
        if (i == 0 || i == 2 || i == 4)
            ASSERT_EQ(number, a.get_property(i));
        else ASSERT_EQ(0, a.get_property(i));

   // Ships::Transport_ship b;
    ASSERT_EQ(st, b.get_type());
    ASSERT_EQ(st, b.get_name());
    for (int i = 0; i < a.count_properties(); i ++)
        if (i == 0 || i == 2 || i == 4)
            ASSERT_EQ(number, a.get_property(i));
        else ASSERT_EQ(0, a.get_property(i));

    for (int j = 0; j < b.get_size(); j ++){
        if (j == 1) ASSERT_EQ(0, b.get_info_cargo(j));
        else ASSERT_EQ(number, b.get_info_cargo(j));
    }

    //Ships::Security_ship c;
    ASSERT_EQ(st, b.get_type());
    ASSERT_EQ(st, b.get_name());
    for (int i = 0; i < a.count_properties(); i ++)
        if (i == 0 || i == 2 || i == 4)
            ASSERT_EQ(number, a.get_property(i));
        else ASSERT_EQ(0, a.get_property(i));
    for (int i = 0; i < 4; i ++){
        ASSERT_EQ(nullptr, c.get_info_armament(i) );
    }

    //Ships::Military_transport_ship d;
    ASSERT_EQ(st, b.get_type());
    ASSERT_EQ(st, b.get_name());
    for (int i = 0; i < a.count_properties(); i ++)
        if (i == 0 || i == 2 || i == 4)
            ASSERT_EQ(number, a.get_property(i));
        else ASSERT_EQ(0, a.get_property(i));
    for (int i = 0; i < 4; i ++){
        ASSERT_EQ(nullptr, c.get_info_armament(i) );
    }
    for (int j = 0; j < b.get_size(); j ++){
        if (j == 1) ASSERT_EQ(0, b.get_info_cargo(j));
        else ASSERT_EQ(number, b.get_info_cargo(j));
    }
}

TEST(method, setters){
    std::string st = "type A", st2 = "type B";
    double num1 = 100, num2 = 9;

    Ships::Military_transport_ship d = Ships::Military_transport_ship(st, st, num1, num1, num1, num1, num1);

    for (int i = -2; i < d.count_properties() + 3; i ++)
        d.change_property(i, num2);
    for (int i = -2; i < d.count_properties() + 3; i ++)
        if (0 > i || i > d.count_properties() - 1)
            ASSERT_EQ(0, d.get_property(i));
        else ASSERT_EQ(num2, d.get_property(i));

    d.set_coef_decrease(num2);
    d.set_max_cargo(num2);
    d.set_cur_speed(num2);
    d.set_cur_cargo(num2);
    for (int j = 0; j < d.get_size(); j ++){
        ASSERT_EQ(num2, d.get_info_cargo(j));
    }
}

