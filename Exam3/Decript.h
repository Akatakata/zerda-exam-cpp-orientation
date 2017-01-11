// #pragma once
#ifndef DECRIPT_H
#define DECRIPT_H
#include <string>
class Decript {
private:
  std::string changed_text;
public:
  Decript();
  ~Decript();
  std::string decripting(std::string text, int shift);
  std::string get_changed_text();
};
#endif
