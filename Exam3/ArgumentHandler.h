// #pragma once
#ifndef ARGUMENTHANDLER_H
#define ARGUMENTHANDLER_H
#include <string>
#include "FileHandler.h"

using namespace std;

class ArgumentHandler {
private:
  int argc;
  char** argv;
  FileHandler* files;
  string input_selector;
  string shift_selector;
  string output_selector;
  string second_selector;
  string third_selector;
public:
  ArgumentHandler(int _argc, char** _argv);

  void check_file_selector();
  void check_number_of_args();
  void check_second_selector();
};

#endif

