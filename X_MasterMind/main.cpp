#include <iostream>
#include "masterMind.cpp"

int main(int argc, char const *argv[])
{
    masterMind prova = masterMind();
    
    prova.readNewMove();
    return 0;
}
