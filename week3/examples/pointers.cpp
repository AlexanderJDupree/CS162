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
        std::cout << "Vector2 copied!" << std::endl;
    }

    // Destructor
    ~Vector2()
    {
        std::cout << "Vector2 destroyed" << std::endl;
    }

    friend std::ostream& operator << (std::ostream& out, Vector2& vector)
    {
        out << "X: " << vector.x << "\tY: " << vector.y << std::endl;

        return out;
    }

};

template<typename T>
class List {

public:

    List() : head(NULL), cur(NULL), temp(NULL) {};
    void addNode(T* data)
    {
        temp = new Node;
        temp->data = data;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            cur = temp;
            temp = NULL;
        }
        else
        {
            cur->next = temp;
            cur = temp;
        }
    }
    void delEnd()
    {
        nodePtr previous;
        temp = head;
        while (temp->next != cur)
        {
            previous = temp;
            temp = temp->next;
        }
        delete cur;
        cur = previous;
        
        return;
    };
    
       T* begin()
    {
        return head;
    }

    T* end()
    {
        return cur;
    }

    void printList()
    {
        temp = head;
        while (temp != NULL)
        {
            std::cout << *temp->data;
            temp = temp->next;
        }
        return;
    }

private:

    typedef struct Node {
        T* data;
        Node* next;
    }* nodePtr;

    nodePtr cur;
    nodePtr temp;
    nodePtr head;
};


int main()
{ 
    Vector2 pos(1, 2);
    Vector2 pos2(2, 4);
    Vector2 pos3(3, 6);

    List<Vector2> vectors;

    vectors.addNode(&pos);
    vectors.addNode(&pos2);
    vectors.addNode(&pos3);

    vectors.printList();
    vectors.delEnd();
    vectors.printList();
    

    return 0;
}
