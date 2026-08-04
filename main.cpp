#include <iostream>
#include <stdexcept>

using namespace std;

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

char character(char start, int offset)
{
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z')))
    {
        throw invalidCharacterException();
    }

    char target = start + offset;

    if (start >= 'A' && start <= 'Z')
    {
        if (target < 'A' || target > 'Z')
        {
            throw invalidRangeException();
        }
    }
    else
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
    try
    {
        cout << character('a', 1) << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    try
    {
        cout << character('a', -1) << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    try
    {
        cout << character('Z', -1) << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}