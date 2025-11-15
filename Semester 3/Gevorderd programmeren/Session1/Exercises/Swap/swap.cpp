#include<iostream>

void swap_by_ptr(int* p1, int* p2){
  int t = *p1;

  *p1 = *p2;
  *p2 = t;
}

void swap_by_ref(int& r1, int& r2)
{
  int t = r1;
  int t1 = r2;

  r1 = t1;
  r2 = t;
}

void swap_ptr_by_ref(int*& pr1, int*& pr2){
  int *t_0 = pr1;
  int *t_1 = pr2;

  pr1 = t_1;
  pr2 = t_0;
}

int main(){
  int* i_1 = new int();
  int* i_2 = new int();

  *i_1 = 55;
  *i_2 = 23;

  std::cout << "Before swap: "<< std::endl << "variable 1 = " << *i_1 << ", variable 2 = " << *i_2 << std::endl;

  swap_ptr_by_ref(i_1, i_2);
    
  std::cout << "After swap: "<< std::endl << "variable 1 = " << *i_1 << ", variable 2 = " << *i_2 << std::endl;

  delete i_1;
  delete i_2;
}
