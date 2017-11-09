/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conta.cpp
 * Author: vinicius
 */

#include <stdio.h>
#include <stdlib.h>

void conta(float num);

int main(){

    conta(0.95);
    return 0;
}

void conta(float num){
    int vet[6];
    int conta[] = {100, 50, 25, 10, 5, 1};
    int i;

    for(i=0; i < 6; i++){
        vet[i] = 0;
    }

    num *= 100.0;
    while(num != 0){
        if(num >= 100){
            num -= 100;
            vet[0]++;
            continue;
        }else if(num >= 50){
            num -= 50;
            vet[1]++;
            continue;
        }else if(num >= 25){
            num -= 25;
            vet[2]++;
            continue;
        }else if(num >= 10){
            num -= 10;
            vet[3]++;
            continue;
        }else if(num >= 5){
            num -= 5;
            vet[4]++;
            continue;
        }else{
            num --;
            vet[5]++;
            continue;
        }
    }

    for(i=0; i < 6; i++){
        printf("%d Moedas de %d centavos\n",vet[i], conta[i]);
    }



}

