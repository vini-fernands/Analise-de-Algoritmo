/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   moedas.cpp
 * Author: vinicius
 */

#include <stdio.h>
#include <stdlib.h>

float fibonacci(int n);
float fibonacci_r(int n);

int main()
{
    printf("%f\n", fibonacci(80));
    return 0;
}

float fibonacci(int n){
    float fibonaccio[n];
    int i;

    fibonaccio[0] = 0.0;
    fibonaccio[1] = 1.0;

    for( i= 2; i < n; i++){
        fibonaccio[i] = fibonaccio[i-1] + fibonaccio[i-2];
    }

    return fibonaccio[i-1];
}

float fibonacci_r(int n){
    if(n == 0){
        return 0.0;
    }
    else if(n == 1){
        return 1.0;
    }
    else
        return fibonacci_r(n-1) + fibonacci_r(n-2);
}
