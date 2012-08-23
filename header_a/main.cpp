#include <iostream>
#include "func.h"

int main()
{
    void (*ptr)(void);
    ptr = func;
    ptr();
    return 0;
}

