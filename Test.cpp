//
//  Test.cpp
//  EECS448-Lab07
//
//  Created by Cesar Avalos on 4/29/16.
//  Copyright © 2016 Cesar Avalos. All rights reserved.
//

#include "Test.h"
#include <iostream>
#include "LinkedList.h"
#include <vector>


std::string booleanToYesNo(bool anyBoolean)
{
    if(anyBoolean)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

// Print the integer vector
void printVector(std::vector<int> vec)
{
    std::cout << "Printing vector \n";
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << "\n";
    }
}


// Test that by default, things are assumed not working
int testComplete()
{
    bool addFront    = false;
    bool addBack     = false;
    bool removeBack  = false;
    bool removeFront = false;
    bool isEmpty     = false;
    bool size        = false;
    bool search      = false;
    
    
    //Test one - addFront ---------------------
    std::cout << "Testing LinkedList class \n";
    LinkedList<int>* list = new LinkedList<int>();
    
    list->addFront(8);
    list->addFront(6);
    
    std::vector<int> listVec = list->toVector();
    if(listVec[0] == 6 && listVec[1] == 8)
    {
        addFront = true;
    }
    
    //Clear the list
    delete list;
    list = new LinkedList<int>();
    
    //Test Two - addBack -----------------------
    list->addBack(8);
    list->addBack(6);
    
    listVec = list->toVector();
    if(listVec[0] == 8 && listVec[1] == 6)
    {
        addBack = true;
    }
    
    //Clear the list
    delete list;
    list = new LinkedList<int>();
    
    //Test Three - removeBack ------------------
    if(addFront)
    {
        list->addFront(8);
        list->addFront(6);
    }
    else if(addBack)
    {
        list->addBack(6);
        list->addBack(8);
    }
    else
    {
        std::cout << "addBack and addFront are not working, the test has concluded this linkedList does not work \n";
        return 0;
    }
    
    list->removeBack();
    listVec = list->toVector();
    if(listVec[0] == 6 && listVec.size() == 1)
    {
        removeBack = true;
    }
    
    //Clear the list
    delete list;
    list = new LinkedList<int>();
    
    //Test Four - removeFront ------------------
    if(addFront)
    {
        list->addFront(8);
        list->addFront(6);
    }
    else if(addBack)
    {
        list->addBack(6);
        list->addBack(8);
    }
    else
    {
        std::cout << "addBack and addFront are not working, the test has concluded this linkedList does not work \n";
        return 0;
    }
    
    list->removeFront();
    listVec = list->toVector();
    if(listVec[0] == 8 && listVec.size() == 1)
    {
        removeFront = true;
    }
    
    
    //Clear the list
    delete list;
    list = new LinkedList<int>();
    
    //Test Four - isEmpty, size, and search (non-modifying functions) ------------------
    if(addFront)
    {
        list->addFront(8);
        list->addFront(6);
    }
    else if(addBack)
    {
        list->addBack(6);
        list->addBack(8);
    }
    //by now if either addFront or addBack were not working, the program would've stopped executing
    if(list->size() == 2)
    {
        size = true;
    }
    
    if(list->search(8) && list->search(6))
    {
        search = true;
    }
    
    if(removeBack)
    {
        list->removeBack();
        list->removeBack();
    }
    else if(removeFront)
    {
        list->removeFront();
        list->removeFront();
    }
    else
    {
        std::cout << "removeFront and removeBack are not working, the test has concluded this linkedList is too faulty to continue \n";
        return 0;
    }
    
    if(list->isEmpty() == true)
    {
        isEmpty = true;
    }
    
    std::cout << "Test conclusions: \n";
    std::cout << "1) is addFront working properly?: " << booleanToYesNo(addFront) << "\n";
    std::cout << "2) is addBack working properly?: " << booleanToYesNo(addBack) << "\n";
    std::cout << "3) is removeBack working properly?: " << booleanToYesNo(removeBack) << "\n";
    std::cout << "4) is removeFront working properly?: " << booleanToYesNo(removeFront) << "\n";
    std::cout << "5) is search working properly?: " << booleanToYesNo(search) << "\n";
    std::cout << "6) is isEmpty working properly?: " << booleanToYesNo(isEmpty) << "\n";
    std::cout << "7) is size working properly?: " << booleanToYesNo(size) << "\n";
    
    delete list;

    return 0;
}