// #pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>

class FileHandler {
  std::string content;
  bool _is_exists;
public:
  FileHandler();
  bool is_exists();
  std::string get_content();
  void read_from_file(const char* filename);
  void write_to_file(const char* filename, std::string text);
};
#endif
