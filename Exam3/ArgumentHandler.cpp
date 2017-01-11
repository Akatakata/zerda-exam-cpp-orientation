#include <string>
#include <iostream>
#include "ArgumentHandler.h"

ArgumentHandler::ArgumentHandler(int argc, char** argv) {
  argc = argc;
  argv = argv;
  check_file_selector();
}

void ArgumentHandler::check_file_selector() {
  selector = argv[1];
  int found_txt_in_selector = selector.find(".txt");
  if (found_txt_in_selector > selector.length()) {
    std::cerr << "No filename is provided." << std::endl;
  }
}