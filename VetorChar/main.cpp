#include <iostream>
#include <stdio.h>

  main(){
    int size = 5, y =size-1;
    char palavra[size], reverso[size];

    for(int x = 0; x < size; x++){
      printf("Digite uma letra: ");
      scanf("%c",&palavra[x]);
      getchar();
      reverso[y] = palavra[x];
      y--;
   }
   printf("\n");

    for(int x = 0; x < size; x++){
      printf("palavra: %c reverso: %c\n", palavra[x], reverso[x]);
    }
    getchar();
}

