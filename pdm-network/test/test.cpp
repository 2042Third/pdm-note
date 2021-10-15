//
// Created by 18604 on 10/15/2021.
//
#include "../pdm-network.h"
#include <string>
#include <winsock2.h>
#include <windows.h>
#include <curl/curl.h>

#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
  string user_name = "networking_test";
  string test_file = "pdm_rc.conf";
  if (argc == 2){
    test_file = argv[1];
  }
  pdm_network test(user_name);
  test.upload_sync_multi(test_file);
  test.download_sync(test_file);
  return 0;
}