#include <iostream>

void max(int a, int b, int & res){

    res = a > b ? a : b;
  }

int main(){
  int idade1, idade2, resultado;

  std::cout << "Digite idade1: ";
  std::cin >> idade1;

  std::cout << "Digite idade2: ";
  std::cin >> idade2;

  max(idade1, idade2, resultado);

  std::cout << "resultado: " << resultado <<"\n";

  return 0;
}
