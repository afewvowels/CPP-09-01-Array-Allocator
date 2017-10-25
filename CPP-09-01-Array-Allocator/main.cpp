//
//  main.cpp
//  CPP-09-01-Array-Allocator
//
//  Created by Keith Smith on 10/25/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a function that dynamically allocates an array of integers. The function should
//  accept an integer argument indicating the number of elements to allocate. The function
//  should return a pointer to the array.
//

#include <iostream>
#include <random>

using namespace std;

const int INT_MIN_ARR_VALUE = 0;
const int INT_MAX_ARR_VALUE = 12;

void getArraySize(int &);
int *getRandomNumbers(int);
int generateRandomNumber();

int main()
{
    int *ptrNumbers = nullptr;
    int intArraySize;
    
    getArraySize(intArraySize);
    
    ptrNumbers = getRandomNumbers(intArraySize);
    
    for(int count = 0 ; count < intArraySize ; count++)
    {
        cout << ptrNumbers[count] << endl;
    }
    
    delete [] ptrNumbers;
    ptrNumbers = nullptr;
    
    return 0;
}

void getArraySize(int &refSize)
{
    cout << "Please enter a positive integer value\n";
    cout << "for your array's size: ";
    cin >> refSize;
    while(!cin || refSize <= 0 || refSize >= 10000)
    {
        cout << "Please enter a number between 0 and 10,000: ";
        cin.clear();
        cin.ignore();
        cin >> refSize;
    }
}

int *getRandomNumbers(int num)
{
    int *arr = nullptr;
    
    if(num <= 0)
    {
        return nullptr;
    }
    
    arr = new int[num];
    
    for(int count = 0 ; count < num ; count++)
    {
        arr[count] = generateRandomNumber();
    }
    
    return arr;
}

int generateRandomNumber()
{
    int intResult;
    
    // Use random_device to generate seed
    random_device rd;
    
    // Use seed to set Mersenne twister engine
    mt19937 engine(rd());
    
    // Define distribution and type
    uniform_int_distribution<> distribution(INT_MIN_ARR_VALUE, INT_MAX_ARR_VALUE);
    
    // Generate a result in range of distribution with MTE engine
    intResult = distribution(engine);
    
    return intResult;
}
