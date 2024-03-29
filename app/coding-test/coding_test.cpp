#include "coding_test.h"

void execute_test(int test_number) 
{
    switch (test_number) 
    {
        case 1: leet_test_0001(); break;
        case 2: leet_test_0002(); break;
        case 88: leet_test_0088(); break;
        case 773: leet_test_0773(); break;
        case 945: leet_test_0945(); break;
        case 1195: leet_test_1195(); break;
        case 1302: leet_test_1302(); break;
        default: std::cout << "Test case not found.\n";
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Please provide a test number.\n";
        return 1;
    }

    int test_number = std::stoi(argv[1]);
    execute_test(test_number);

    return 0;
}