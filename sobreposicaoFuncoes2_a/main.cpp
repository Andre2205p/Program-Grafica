#include <iostream>

void multiplicacao(int a, int b, int& res){
    res = a * b;
}

void multiplicacao(float a, float b, float& res){
    res = a * b + 1;
}

void multiplicacao(double a, double b, double& res){
    res = a * b + 2;
}

int main(){
  int iA = 2, iB = 2, iRes;
  float fA = 2.2, fB = 2.2, fRes;
  double dA = 2.2, dB = 2.2, dRes;


  multiplicacao(iA, iB, iRes);
  std::cout << "Int:" << iRes << "\n";

  multiplicacao(fA, fB, fRes);
  std::cout << "float: " << fRes << "\n";

  multiplicacao(dA, dB, dRes);
  std::cout << "double: " << dRes << "\n";

  return 0;
}

