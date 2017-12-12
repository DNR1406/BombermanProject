#include "include.h"

int main()
{
    init();
    Serial.begin(9600);

    init_in_out_put();
    init_single_Sample();

    Navigation *navigation = new Navigation();
    navigation->startStartScreen();

    while (1)
    {
    }

    return 0;
}

