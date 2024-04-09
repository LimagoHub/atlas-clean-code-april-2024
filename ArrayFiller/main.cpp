#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <memory>



int main() {
    constexpr int collection_size = INT32_MAX / 4;
    std::chrono::high_resolution_clock::time_point start_;
    std::chrono::high_resolution_clock::time_point end_;

    auto feld = std::make_shared<std::vector<int>>(collection_size);


    start_ = std::chrono::high_resolution_clock::now();
    for (int  i = 0; i < collection_size ; ++i) {
        feld->at(i) = rand();
    }

    end_ = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_).count() << std::endl;


    return 0;
}
