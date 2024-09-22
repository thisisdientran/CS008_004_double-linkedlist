#ifndef CS8_FALL24_TEST_H
#define CS8_FALL24_TEST_H

#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

void test_template(){
    try{
        if(4>3)
            std::cout << "4>3 is real \n";
        else
            throw(3);
    }
    catch(int num){
        std::cout << "4>3 is a lie \n";
    };
};

void test_create_node(){
    try{
        LinkedList<int> list;
        int num = 4;
        list.createNode(4);
        std::cout << list;
        
    }catch(int num){
    }
}

void run_all_test(){
    test_template();
    test_create_node();
}

#endif