/****************************************************
Course		: CO4352 Advanced Algorithms
Name		: YAPA.YMTL
Index no.	: 17_ENG_119
Asgmnt No.	: 01 (Red Black Tree)
Date		: 
****************************************************/

#include <iostream>
#include <vector>

using namespace std;



//Enum that save colors of a node
enum colors { BLACK , RED };

//Structure save data of a node
struct node
{
    int value;
    colors color;
    
    
    node* leftChildAddress;
    node* rightChildAddress;

    node()
    {
        color = BLACK;
        leftChildAddress = NULL;
        rightChildAddress = NULL;
    }

};


class RBT
{
private:
    node* start;
    bool isLeafNode(node*);//Function to check whether given node is a leaf node(return true), or not (return false)
    vector<node> nodes;
public:
    RBT();
    bool leftRotation(node*);
    bool rightRotation(node*);

    void test()
    {
        cout<<" test node "<<isLeafNode(start);
    }

};





int main()
{
    RBT ob;
    ob.test();
    return 0;
}


RBT::RBT()
{
    node temp;
    nodes.push_back(temp);
    start = &nodes[0];
}

bool RBT::isLeafNode(node* n)
{
    return (!n->leftChildAddress && !n->rightChildAddress);
}

bool RBT::leftRotation(node* n)
{
    if(n->rightChildAddress)
    {
        node* temp = n;

        n = temp->rightChildAddress;

        temp->rightChildAddress = n->leftChildAddress;

        n->leftChildAddress = temp;

        return true;
    }

    return false;
}

bool RBT::rightRotation(node* n)
{
    if(n->leftChildAddress)
    {
        node* temp = n;

        n = temp->leftChildAddress;

        temp->leftChildAddress = n->rightChildAddress;

        n->rightChildAddress = temp;

        return true;
    }
    return false;
}