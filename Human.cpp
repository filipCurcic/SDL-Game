#include "Human.h"

Human::Human(int x, int y) : GameObject("assets/h1.png", "human")
{

    destinationRect.x = x;
    destinationRect.y = y;
}

Human::~Human()
{
    //dtor
}
