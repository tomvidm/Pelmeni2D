#pragma once

namespace p2d { namespace math {

    /*
        Calculating the combinations of n choose k normally requires
        computing factorials which will quickly overflow without 
        arbitrary precision numbers. This algorithm circumvents this (reduces risk)
        by ignoring the terms that cancel eachother. 

        This implementation also uses a lookup table for lower values of n,
        to speed up the algorithm for commonly used values.
    */
    template <typename T>
    T combinations(T n, T k) {
        using ulong = unsigned long;
        static const std::vector<std::vector<ulong>> lookup = {
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1},
            {1, 5, 10, 10, 5, 1},
            {1, 6, 15, 20, 15, 6, 1},
            {1, 7, 21, 35, 35, 21, 7, 1},
            {1, 8, 28, 56, 70, 56, 28, 8, 1}
        };
        if (n <= lookup.size() && k <= lookup[n].size()) {
            return lookup[n][k];
        } else {                        // Proceed with calculation
            T result = n;               // Start with highest multiplier
            T d = 1;                    // Keep track of lower multipliers
            while (--n > k) {           // Keep going until n == k
                result *= n;            // multiply numerator term
                result /= ++d;          // divide denominator term
            } // while
            return result;              // return
        } // if else
    } // combinations
} // namespace math
} // namespace p2d