//
//  main.cpp
//  Big number mutiplication
//
//  Created by Leroy on 02/03/2020.
//  Copyright © 2020 Leroy. All rights reserved.
//

#include <iostream>
#include <memory.h>

#define SIZE 14

int* multi(int* , int , int* , int );
void print(int* );
using namespace std;


int main(int argc, const char * argv[]) {
    
    int num1[SIZE] = {1,2,3,4,5,6,7,8,9,1,1,1,1,1}; //First big num = 11111987654321
    int num2[SIZE] = {1,1,1,2,2,2,3,3,3,4,4,4,5,5}; //Second big num = 55444333222111
    
    int* ret = multi(num1, SIZE, num2, SIZE);
    
    print(ret);
    
    delete ret;
    
    return 0;
}

int* multi(int* num1, int size1, int* num2, int size2){
    
    int size = size1 + size2;               //position is decided by num1 + num2
    int* ret = new int [size];
    int i = 0;
    memset(ret, 0, sizeof(int)* size);      //Initialize
    
    for(i = 0;i < size2; i++){
        int k = i;
        for(int j = 0;j < size1; j++)
            ret[k++] += num2[i] * num1[j];         //Multi
    }
    
    for(i = 0; i < size; ++i){
        if(ret[i] >= 10){
            ret[i+1] += ret[i]/10;              //Carry
            ret[i] %= 10;
        }
    }
    return ret;
    
}
void print(int* num){
    for(int i = SIZE*2 - 2; i>=0; i--)      //Array start from 0
            cout<<num[i];
    
       
    cout<<endl;
}
