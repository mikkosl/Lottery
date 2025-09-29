// Lottery.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    constexpr int num_numbers = 7;
    constexpr int min_value = 1;
    constexpr int max_value = 40;

    // Create a vector with all possible numbers
    std::vector<int> numbers(max_value);
    std::iota(numbers.begin(), numbers.end(), min_value);

    // Set up random device and generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Shuffle the numbers
    std::shuffle(numbers.begin(), numbers.end(), gen);

    // Select the first 7 numbers
    std::vector<int> lottery_numbers(numbers.begin(), numbers.begin() + num_numbers);

    // Sort for display
    std::sort(lottery_numbers.begin(), lottery_numbers.end());

    std::cout << "Finnish Lottery Numbers: ";
    for (int n : lottery_numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
	std::cin.get();

    return 0;
}
