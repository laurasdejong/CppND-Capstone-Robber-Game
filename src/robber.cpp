#include "robber.h"
#include <cmath>
#include <iostream>
#include <random>

void Robber::PayRobbersGuild(){
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1,5); // source: Udacity Program a Concurrent Traffic Light

    AddGold(-distr(eng));
}
