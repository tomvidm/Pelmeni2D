#include <random>

#include "math/Random.hpp"

namespace p2d { namespace math {
    int rand(int a, int b) {
        static std::random_device rd;  //Will be used to obtain a seed for the random number engine
        static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dis(a, b);
        return dis(gen);
    }
}
}