#include <stdio.h>
#include <iostream>
#include <string>
#include "safety/cc20_multi.cpp"
int main(int argc, char *argv[])
{
  size_t file_len=14;
  char * data = "tesing secret\n";
  char outstr[50] ;
  std::string pswd_data = "1234"; 
  cmd_enc((uint8_t*)data,(size_t)file_len,(uint8_t*)outstr,((std::string)pswd_data));
  std::cout<<outstr<<std::endl;
  std::cout<<"Encryption end"<<std::endl;
  return 0;
}