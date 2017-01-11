#include "Decript.h"
#include <cctype>
#include <iostream>

const std::string alphabet = "abcdefghijklmnopqrstuvwxyz"; 

Decript::Decript() {
}

Decript::~Decript() {
}

std::string Decript::decripting(std::string text, int shift) {
  int size = alphabet.length();
  for (int i = 0; i < text.length(); i++) {
    if (std::isalpha(text[i]) == false) {
      changed_text[i] = text[i];
    } else {
      int loc = alphabet.find(text[i]);
      if (loc + shift > size) {
        loc = loc + shift - size;
      } else if (loc + shift < 0) {
        loc = size - loc + shift;
      }
      changed_text[i] = alphabet[loc + shift];
      if (isupper(text[i])) {
        toupper(changed_text[i]);
      }
    }
    std::cout << changed_text[i];
  }
  return changed_text;
}

std::string Decript::get_changed_text() {
  return changed_text;
}