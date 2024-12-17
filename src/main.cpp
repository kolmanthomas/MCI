#include <iostream>
#include <random>

#include <vector>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

/*
* Monte Carlo Estimator
*/
int main(int argc, const char **argv)
{

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<> dist(-1, 1);


    std::vector<std::pair<float, float>> m;
    int count = 0;
    int runs = 100000;
    for (int i = 0; i < runs; i++) {
        std::pair pair(dist(rd), dist(rd));
        m.push_back(pair);
        if ((pair.first*pair.first + pair.second*pair.second) < 1) {
            count += 1; 
        }
        std::cout << "First value: " << m[i].first << ", and second value: " << m[i].second << std::endl;
    }

    // Ratio of points within circle to 
    float ratio = float(count) / float(runs);

    // Area of circle
    std::cout << "Area of the circle is: " << ratio * 4 << std::endl;


}



