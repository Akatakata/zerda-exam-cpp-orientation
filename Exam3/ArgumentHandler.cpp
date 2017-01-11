#include <string>
#include <iostream>
#include <stdlib.h>
#include "ArgumentHandler.h"

const char* shift = "-s";
const char* output = "-o";

ArgumentHandler::ArgumentHandler(int _argc, char** _argv) {
  argc = _argc;
  argv = _argv;
  check_number_of_args();
  files = new FileHandler;
  crypting = new Decript;
  files->read_from_file(input_selector.c_str());
  crypting->decripting(files->get_content(), shift_number);
  files->write_to_file(output_file.c_str(), crypting->get_changed_text());
}

ArgumentHandler::~ArgumentHandler() {
  delete files;
  delete crypting;
}

void ArgumentHandler::check_file_selector() {
  input_selector = argv[1];
  int found_txt_in_selector = input_selector.find(".txt");
  if (found_txt_in_selector > input_selector.length()) {
    cerr << "No filename is provided." << endl;
  }
}

void ArgumentHandler::check_selectors() { // this is bad
  second_selector = argv[2];
  third_selector = argv[4];
  if (second_selector == "-s" && third_selector == "-o") {
    shift_selector = second_selector;
    shift_number = atoi(argv[3]);
    output_selector = third_selector;
    output_file = argv[5];
  } else if (second_selector == "-o" && third_selector == "-s") {
    output_selector = second_selector;
    output_file = argv[3];
    shift_selector = third_selector;
    shift_number = atoi(argv[5]);
  } else {
    cerr << "Error: wrong arguments." << endl;
  }
  if (second_selector != "-s" && third_selector != "-s") {
    cerr << "No shift is provided." << endl;
  }
  if (second_selector != "-o" && third_selector != "-o") {
    cerr << "No filename is provided." << endl;
  }
}

void ArgumentHandler::check_number_of_args() {
  if (argc == 6) {
    check_file_selector();
    check_selectors();
  } else if (argc != 6 ) {
    cerr << "Error: the number of arguments is not correct." << endl;
  }
}