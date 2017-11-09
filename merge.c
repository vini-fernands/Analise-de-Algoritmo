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
#include <cstdlib>

void intercala(int p, int q, int r, int v[]);
void mergesort_i (int n, int v[]);


int main(){
    int vet[] = {5,4,3,2,1};
    int n = 5;
    mergesort_i(n, vet);
    int i;
    for(i = 0; i < n; i++){
        printf("vet[%d] = %d\n", i, vet[i]);
    }
    return 0;
}

void mergesort_i (int n, int v[])
{
   int p, r;
   int b = 1;
   while (b < n) {
      p = 0;
      while (p + b < n) {
         r = p + 2*b;
         if (r > n) r = n;
         intercala (p, p+b, r, v);
         p = p + 2*b;
      }
      b = 2*b;
   }
}


void intercala (int p, int q, int r, int v[]){
   int i, j, k;
   int w[r-p];

   for (i = p; i < q; i++)  w[i-p] = v[i];
   for (j = q; j < r; j++)  w[(r-p)+q-1-j] = v[j];
   i = 0; j = r-p-1;
   for (k = p; k < r; k++)
      if (w[i] <= w[j]) v[k] = w[i++];
      else v[k] = w[j--];
}
