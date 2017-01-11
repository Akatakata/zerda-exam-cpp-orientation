#include <string>
#include <iostream>
#include "ArgumentHandler.h"

const char* shift = "-s";
const char* output = "-o";

ArgumentHandler::ArgumentHandler(int _argc, char** _argv) {
  argc = _argc;
  argv = _argv;
  check_number_of_args();
  files = new FileHandler;
  files->read_from_file(input_selector.c_str());
  files->write_to_file("out.txt", files->get_content());
}


void ArgumentHandler::check_file_selector() {
  input_selector = argv[1];
  int found_txt_in_selector = input_selector.find(".txt");
  if (found_txt_in_selector > input_selector.length()) {
    cerr << "No filename is provided." << endl;
  }
}

void ArgumentHandler::check_second_selector() { // this is bad
  second_selector = argv[2];
  third_selector = argv[4];
  if (second_selector == "-s") {
    shift_selector = second_selector;
    if (third_selector == "-o") {
      output_selector = third_selector;
    } else {
      cerr << "No filename is provided." << endl;
    }
  } else if (second_selector == "-o") {
    output_selector = second_selector;
    if (third_selector == "-s") {
      shift_selector = third_selector;
    } else {
      cerr << "No shift is provided." << endl;
    }
  } else {
    cerr << "Error: wrong arguments." << endl;
  }
}

void ArgumentHandler::check_number_of_args() {
  if (argc == 6) {
    check_file_selector();
    check_second_selector();
  } else if (argc != 6 ) {
    cerr << "error" << endl;
    cout << argc << endl;
  }
}