#include <stdio.h>


int func(){
  printf("func(): %d\n", 5);
  return 0;
}

int main(int argc, char *argv){
  func(1,2,3,4);// call func();
  return 0;
}