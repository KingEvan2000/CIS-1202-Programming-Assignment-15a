// Evan Wei
// CIS 1202
// August 3, 2026

#include <iostream>
#include <stdexcept>

using namespace std;

// Custom exception classes
class invalidCharacterException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "invalidCharacterException";
    }
};

class invalidRangeException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "invalidRangeException";
    }
};

// Function prototype
char character(char start, int offset)
{
    // Check if start is a letter
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z')))
    {
        throw invalidCharacterException();
    }

    char target = start + offset;

    // Prevent upper/lower case transitions
    if (start >= 'A' && start <= 'Z')
    {
        if (target < 'A' || target > 'Z')
        {
            throw invalidRangeException();
        }
    }
    else if (start >= 'a' && start <= 'z')
    {
        if (target < 'a' || target > 'z')
        {
            throw invalidRangeException();
        }
    }

    return target;
}

int main()
{
    // Test 1
    try
    {
        cout << "character('a', 1) returns '" << character('a', 1) << "'" << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    // Test 2
    try
    {
        cout << "character('a', -1) returns '" << character('a', -1) << "'" << endl;
    }
    catch (exception& e)
    {
        cout << "character('a', -1) throws " << e.what() << endl;
    }

    // Test 3
    try
    {
        cout << "character('Z', -1) returns '" << character('Z', -1) << "'" << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    // Test 4
    try
    {
        cout << "character('?', 5) returns '" << character('?', 5) << "'" << endl;
    }
    catch (exception& e)
    {
        cout << "character('?', 5) throws " << e.what() << endl;
    }

    // Test 5
    try
    {
        cout << "character('A', 32) returns '" << character('A', 32) << "'" << endl;
    }
    catch (exception& e)
    {
        cout << "character('A', 32) throws " << e.what() << endl;
    }

    return 0;
}