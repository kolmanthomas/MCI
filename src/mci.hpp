#pragma once

#include <functional>
#include <iostream>
#include <vector>
#include <random>

// #include "simdxorshift128plus.h"
// #include <immintrin.h>

// RVO is guaranteed here after C++17
inline static std::vector<float> generate_rand_nums(
    size_t const runs,
    float const x0,
    float const x1
) 
{
    // Allocate space ahead of time
    std::vector<float> rand_nums (runs);

    std::random_device rd; 
    std::minstd_rand rng(rd());
    std::uniform_real_distribution<> dist(x0, x1);

    for (size_t i = 0; i < runs; i += 1) {
        rand_nums[i] = static_cast<float>(dist(rng));
        //std::clog << "\rGenerated: " << (float) i / (float) runs << std::flush;
    }
    //std::clog << "\rDone          \n" << std::endl;

    return rand_nums;
}


// Handles 1D integrals for now.
inline static float mci(
    float (*integrand)(float),
    std::vector<std::pair<float, float>> domain,
    size_t runs
)
{
    std::vector<float> rand_nums = generate_rand_nums(runs, domain[0].first, domain[0].second);

    float res = 0;
    for (size_t i = 0; i < runs; i += 1) {
        res += integrand(rand_nums[i]);
        //std::clog << "\rProgress: " << (float) i / (float) runs << std::flush;
    }
    res = res / static_cast<float>(runs) * (domain[0].second - domain[0].first);
    return res;
}
