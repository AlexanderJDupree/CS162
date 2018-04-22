/*******************************************************************************
 * File: pointers.cpp
 * Description: 
 * Author: Alexander DuPree
 * Compiler:  GNU GCC 5.4.0
 * Date: 2018-04-19
 *******************************************************************************/

#include <iostream>

struct Vector2
{
    int x;
    int y;

    // Default
    Vector2() : x(0), y(0) {}

    // Initilizer constructor
    Vector2(int x, int y) : x(x), y(y) {}

    // Copy
    Vector2(const Vector2& oldVector)
    {
        this->x = oldVector.x;
        this->y = oldVector.y;
    }

    // Destructor
    ~Vector2()
    {
        std::cout << "Vector2 destroyred" << std::endl;
    }

private:

    struct Node
    {
        Vector2* data;
        Node* next;
    };

    Node* cur;
    Node* temp;
    Node* head;

};

int main()
{ 
    Vector2 pos(1, 2);

    std::cout << pos.x << std::endl;

    return 0;
}
