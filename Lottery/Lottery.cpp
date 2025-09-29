// Lottery.cpp : Defines the entry point for the application.
//

#include "Lottery.h"

// Helper function to convert a vector of numbers to a string for uniqueness
std::string numbers_to_string(const std::vector<int>& numbers) {
    std::string result;
    for (int n : numbers) {
        result += std::to_string(n) + ",";
    }
    return result;
}

//       Generates a single unique lottery row
std::vector<int> generate_lottery_row(int num_numbers, int min_value, int max_value, std::mt19937& gen) {
    std::vector<int> numbers(max_value);
    std::iota(numbers.begin(), numbers.end(), min_value);
    std::shuffle(numbers.begin(), numbers.end(), gen);
    std::vector<int> lottery_numbers(numbers.begin(), numbers.begin() + num_numbers);
    std::sort(lottery_numbers.begin(), lottery_numbers.end());
    return lottery_numbers;
}

// Prints a lottery row
void print_lottery_row(int row_number, const std::vector<int>& lottery_numbers) {
    std::cout << "Row " << row_number << ": ";
    for (int n : lottery_numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// Handles the main lottery generation logic
void generate_lottery_rows(int num_rows, int num_numbers, int min_value, int max_value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::set<std::string> unique_rows;
    int generated = 0;
    while (generated < num_rows) {
        std::vector<int> lottery_numbers = generate_lottery_row(num_numbers, min_value, max_value, gen);
        std::string key = numbers_to_string(lottery_numbers);
        if (unique_rows.insert(key).second) {
            print_lottery_row(generated + 1, lottery_numbers);
            ++generated;
        }
    }
}

int main()
{
    constexpr int num_numbers = 7;
    constexpr int min_value = 1;
    constexpr int max_value = 40;
    int num_rows = 0; // Number of rows to generate

    std::cout << "Hello!" << endl;
    std::cout << "Enter number of lottery rows to generate: ";
    std::cin >> num_rows;

    generate_lottery_rows(num_rows, num_numbers, min_value, max_value);

    std::cout << "Press Enter to exit...";
    std::cin.get();
    std::cin.get();
    return 0;
}
