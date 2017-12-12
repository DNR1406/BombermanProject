#include "include.h"

int main()
{
    init_begin();
    Serial.begin(9600);

    Navigation *navigation = new Navigation();
    navigation->startStartScreen();

    while (1)
    {
    }

    return 0;
}



