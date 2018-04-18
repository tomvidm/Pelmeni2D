#pragma once

#include <array>

namespace p2d { namespace math {

    struct EclideanCoordinate {
        int x;
        int y;
    };

    struct HilbertCoordinate {
        int c;
    };

    enum class HilbertDirection : unsigned {
        UP, RIGHT, DOWN, LEFT
    };

    template <unsigned N>
    class HilbertCurve {
    
    private:
     
    }; // class HilbertCurve
}
}