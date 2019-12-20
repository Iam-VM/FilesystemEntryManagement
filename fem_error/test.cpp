#include <iostream>


enum class Operation
{

};

int main()
{
  Operation o = Operation::create;

  if (o == 1)
  {
    std::cout<<"copy"<<"\n";
  }


  return 0;
}
