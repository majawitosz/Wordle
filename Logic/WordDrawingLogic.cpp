//
// Created by Maja on 5/9/2024.
//

#include "WordDrawingLogic.h"
int WordDrawingLogic::rand_int(int low, int high){
    static std::default_random_engine re{ std::random_device{}() };
    using Dist = std::uniform_int_distribution<int>;
    static Dist uid{};
    return uid(re, Dist::param_type{ low,high });
}