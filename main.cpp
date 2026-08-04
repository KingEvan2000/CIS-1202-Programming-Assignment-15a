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

int main()
{
    cout << "Exception classes created." << endl;
    return 0;
}