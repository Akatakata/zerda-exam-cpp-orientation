// #pragma once
#ifndef ARGUMENTHANDLER_H
#define ARGUMENTHANDLER_H

class ArgumentHandler {
private:
  int arg;
  char* argv;
  std::string selector;
public:
  ArgumentHandler(int argc, char** argv);
  ~ArgumentHandler();
  void check_file_selector();
};

#endif

