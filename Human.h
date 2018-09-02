#ifndef HUMAN_H
#define HUMAN_H
#include "GameObject.h"

class Human : public GameObject
{
    public:
        Human(int x, int y);
        virtual ~Human();

    protected:

    private:
};

#endif // HUMAN_H
