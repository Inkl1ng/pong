#pragma once

#ifndef PONG_RANDOM_HPP
#define PONG_RANDOM_HPP

#include <random>

namespace Pong
{
    namespace Random
    {
        inline std::mt19937 mt{std::random_device{}()};

        // generates a random interger on the interval [min, max] (inclusive)
        inline int get_rand_int(int min, int max)
        {
            return std::uniform_int_distribution{min, max}(mt);
        }

        // generatrs a random number of type T on the interval [min, max] (inclusive)
        template <typename T>
        inline T get_rand(T min, T max)
        {
            return std::uniform_real_distribution<T>{min, max}(mt);
        }
    }
}

#endif