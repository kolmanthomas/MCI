#include <iostream>
#include <vector>
#include <cmath>

#include <boost/math/quadrature/naive_monte_carlo.hpp>

#include "simdxorshift128plus.h"

#include "mci.hpp"

float f(float x) {
    return std::sqrt(1 - x * x);
}

/*
* Monte Carlo Estimator
*/

int main(int argc, const char **argv)
{ 
    /*
    auto g = [](std::vector<double> const & x)
    {
        //constexpr const double A = 1.0 / (M_PI * M_PI * M_PI);
        return std::sqrt(9 - x[0] * x[0]);
    };
    std::vector<std::pair<double, double>> bounds{{-3, 3}};
    double error_goal = 0.001;
    boost::math::quadrature::naive_monte_carlo<double, decltype(g)> mc(g, bounds, error_goal);
    std::future<double> task = mc.integrate();

    while (task.wait_for(std::chrono::seconds(1)) != std::future_status::ready)
    {
        // The user must decide on a reasonable way to display the progress depending on their environment:
        display_progress(mc.progress(),
                         mc.current_error_estimate(),
                         mc.current_estimate(),
                         mc.estimated_time_to_completion());
        if (some_signal_heard()
        {
            mc.cancel();
            std::cout << "\nCancelling because this is too slow!\n";
        }
    }
    double y = task.get();
    std::cout << "Integral: " << y << std::endl;

    auto integrand = [](float x)
    {
        return std::sqrt(1 - x * x);
    };
    */

    float (*integrand)(float);
    integrand = &f;

    // Timing routine
    // std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();


    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    //mci(integrand, {{-1, 1}}, 262144);
    float res = mci(integrand, {{-1, 1}}, 16777216);
    // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // std::cout << "Time     // Area of circle
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time elapsed: " << elapsed.count() / 1000000.0f << " seconds " << std::endl;
    std::cout << "Area of the circle is: " << res * 2 << std::endl;
}



