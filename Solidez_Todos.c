/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Solidez_Todos.cpp
 * Author: vinicius
 */

#include <stdio.h>

int main(){
    int tam = 8;
    int vetor[] = {20,-30,15,-10,30,-20,-30,30};
    int i;
    for (i = 0; i < tam; i++){
        printf("%d\n", vetor[i]);
    }

    printf ("\n\nSolidez: %d\n\n",solidez1(vetor, 0,tam-1));
    printf ("\n\nSolidez: %d\n\n",solidez2(vetor, 0,tam-1));
    printf ("\n\nSolidez: %d\n\n",solidez3(vetor, 0,tam-1));
    
    return 0;
}


int solidez1(int A[], int p, int r){
    int x = A[r];
    int q;
    int j;
    for(q = r-1; q >= p ; q--){

        int soma = 0;

        for(j = q; j <= r; j++){
            soma = soma  + A[j];
            if(soma > x){
                x = soma;
            }
        }
    }
    return x;

}

int solidez2(int vet[], int p, int r){
    int q, s, i, j, x;
    int x1, x2, y1, y2;
    y1 = 0;
    y2 = 0;
    x1 = 0;
    x2 = 0;
    x = 0;
    s=0;
    q = 0;
    if(p == r){
        return vet[p];
     }
    else{
        q = (p+r)/2;
        x1 = solidez2(vet, p, q);
        x2 = solidez2(vet, q+1, r);

        s = vet[q];
        y1 = s;

        for(i = q -1 ; i > p; i--){
            s += vet[i];
            if( s > y1) y1 = s;
            s = vet[q+1];
            y2 = s;
        }
        for(j = q+2; j <= r; j++){
            s += vet[j];
            if(s > y2) y2 = s;
        }
        if(x1 > x2 && x1 > y1+y2){
            x = x1;
        }if(x2 > x1 && x2 > y1+y2){
            x = x2;
        }if(y1+y2 > x1 && y1+y2 > x2 )x = y1+y2;



        return x;

     }

}


int solidez3(int a[], int p, int r){
    int q, x;
    int f[r];

    f[p] = a[p];
    for(q = p+1; q <= r; q++){
        if(f[q-1] > 0){
            f[q] = f[q-1] + a[q];

        }else{
            f[q] = a[q];
        }
    }
    x = f[p];
    for(q = p+1; q <= r; q++){
        if(f[q] > x){
            x = f[q];
        }
    }
    return x;

}


