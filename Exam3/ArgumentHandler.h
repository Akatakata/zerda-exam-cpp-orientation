// #pragma once
#ifndef ARGUMENTHANDLER_H
#define ARGUMENTHANDLER_H
#include <string>
#include "FileHandler.h"
#include "Decript.h"

using namespace std;

class ArgumentHandler {
private:
  int argc;
  char** argv;
  FileHandler* files;
  Decript* crypting;
  string input_selector;
  string shift_selector;
  int shift_number;
  string output_selector;
  string output_file;
  string second_selector;
  string third_selector;
public:
  ArgumentHandler(int _argc, char** _argv);
  ~ArgumentHandler();
  void check_file_selector();
  void check_number_of_args();
  void check_selectors();
};

#endif

