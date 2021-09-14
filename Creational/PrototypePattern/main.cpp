#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include "prototype.h"

//The Main method
int main()
{
    Matematik matKagit1(60, 20, "Klasik");
    matKagit1.getSinavBilgisi();
    Matematik matKagit2(matKagit1);//Deep Copy
    matKagit2.getSinavBilgisi();
    return 0;
}