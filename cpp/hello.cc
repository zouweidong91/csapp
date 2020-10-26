#include <iostream>
#include <vector>
// using namespace std;
 
// 变量声明
extern int a, b;
extern int c;
extern float f;
  
int main ()
{
  // 变量定义
  typedef long long int64;
  std::vector<int64> a, b;
  int c;
  float f;
 
  // 实际初始化
  // a = 10;
  // b = 077;
  // c = a + b;
 
  std::cout << c << std::endl ;
 
  f = 70.0/3.0;
  std::cout << f << std::endl ;
 
  return 0;
}


// g++ hello.cc -o hello.o
// ./hello.o