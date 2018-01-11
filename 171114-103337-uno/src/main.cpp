#include "Navigation/Navigation.hpp"
#include "Functions.hpp"

int main()
{
    // init function
    init_begin();

    // Start navigation
    Navigation *navigation = new Navigation();
    navigation->startStartScreen();

    while (1)
    {
    }

    return 0;
}