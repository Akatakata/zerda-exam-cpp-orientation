#include "Decript.h"
#include <cctype>
#include <iostream>

const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

Decript::Decript() {
}

Decript::~Decript() {
}

void Decript::set_changed_text(std::string text) {
  changed_text = text;
}

void Decript::decripting(std::string text, int shift) {
  int size = alphabet.length();
  std::string changed = "";
  for (int i = 0; i < text.length(); i++) {
    if (std::isalpha(text[i]) == false) {
      changed += text[i];
    } else {
      int loc = alphabet.find(text[i]);
      if (loc + shift > size) {
        loc = loc + shift - size ;
      } else if (loc + shift < 0) {
        loc = size - loc + shift;
      }
      changed += alphabet[loc + shift];
    }
  }
  repair_uppercase(text);
  set_changed_text(changed);
}

void Decript::repair_uppercase(std::string text) {
  for (int i = 0; i < text.length(); i++) {
    if (isupper(text[i])) {
      toupper(changed_text[i]);
    }
  }
}

std::string Decript::get_changed_text() {
  return changed_text;
}