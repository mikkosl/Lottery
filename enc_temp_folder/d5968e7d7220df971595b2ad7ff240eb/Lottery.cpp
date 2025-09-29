// Lottery.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <set>
#include <string>

using namespace std;

// Helper function to convert a vector of numbers to a string for uniqueness
std::string numbers_to_string(const std::vector<int>& numbers) {
    std::string result;
    for (int n : numbers) {
        result += std::to_string(n) + ",";
    }
    return result;
}

int main()
{
    constexpr int num_numbers = 7;
    constexpr int min_value = 1;
    constexpr int max_value = 40;
    int num_rows = 0; // Number of rows to generate

    std::cout << "Enter number of lottery rows to generate: ";
    std::cin >> num_rows;

    // Set up random device and generator
    std::random_device rd;
    std::mt19937 gen(rd());

    std::set<std::string> unique_rows;

    int generated = 0;
    while (generated < num_rows) {
        // Create a vector with all possible numbers
        std::vector<int> numbers(max_value);
        std::iota(numbers.begin(), numbers.end(), min_value);

        // Shuffle the numbers
        std::shuffle(numbers.begin(), numbers.end(), gen);

        // Select the first 7 numbers
        std::vector<int> lottery_numbers(numbers.begin(), numbers.begin() + num_numbers);

        // Sort for display and uniqueness
        std::sort(lottery_numbers.begin(), lottery_numbers.end());

        // Convert to string for uniqueness check
        std::string key = numbers_to_string(lottery_numbers);

        // If this row is unique, print and store it
        if (unique_rows.insert(key).second) {
            std::cout << "Row " << (generated + 1) << ": ";
            for (int n : lottery_numbers) {
                std::cout << n << " ";
            }
            std::cout << std::endl;
            ++generated;
        }
        // Otherwise, generate a new row
    }

    std::cout << "Press Enter to exit...";
    std::cin.get();
    std::cin.get();
    return 0;
}
