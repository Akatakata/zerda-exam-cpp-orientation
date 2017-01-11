#include <fstream>
#include <sstream>
#include "FileHandler.h"

FileHandler::FileHandler() {}

void FileHandler::read_from_file(const char* filename) {
  std::ifstream infile;
  infile.open(filename);
  if (!infile.is_open()) {
    _is_exists = false;
    content = "";
  } else if (infile.is_open()) {
    _is_exists = true;
    std::stringstream buffer;
    buffer << infile.rdbuf();
    content = buffer.str();
    infile.close();
  }
}

bool FileHandler::is_exists() {
  return _is_exists;
}

std::string FileHandler::get_content() {
  return content;
}

void FileHandler::write_to_file(const char* filename, std::string text) {
  std::ofstream outfile;
  outfile.open(filename);
  outfile << text;
  outfile.close();
}