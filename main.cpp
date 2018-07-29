#include <iostream>



int main(int argc, char ** argv)
{
  std::cout << "Hello world" << std::endl;

  int arr[25];
  for(int i = 0; i < 25; i++)
  {
    arr[i] = i * 2;
  }

  return EXIT_SUCCESS;
}