#include <iostream>

void c2F(double& res){

    res = res * 9/5 + 32;
  }

int main(){
  double temp = 0;

  std::cout << "Digite a Temperatura: ";
  std::cin >> temp;

  std::cout << "Temperatura em Celsios: " << temp <<"\n";
  c2F(temp);
  std::cout << "Temperatura em Fahrenheit: " << temp <<"\n";

  return 0;
}
