#include "Read_Words.h"
#include <vector>
#include <string>
namespace read {
    void reading_words(std::string str, std::vector<std::string> &word_list) {
        std::string word;
        for (int i = 0; i < str.length(); i++) {
            int character_id = (unsigned char) str[i];
            if (character_id == 208) {
                character_id = (unsigned char) str[i + 1];
                if ((character_id > 143 and character_id < 192) or character_id == 129) {
                    if (character_id < 174) {
                        if (character_id < 160) {
                            character_id += 32;
                            word += static_cast<char>(208);
                            word += static_cast<char>(character_id);
                        } else {
                            character_id -= 32;
                            word += static_cast<char>(209);
                            word += static_cast<char>(character_id);
                        }

                    } else {
                        word += str[i];
                        word += str[i + 1];
                    }
                } else {
                    if (!word.empty()) {
                        word_list.push_back(word);
                        word.erase();
                    }
                }
                i++;
                continue;
            }
            if (character_id == 209) {
                word += str[i];
                character_id = (unsigned char) str[i + 1];
                if ((character_id > 127 and character_id < 144) or character_id == 145) word += str[i + 1];
                else {
                    if (!word.empty()) {
                        word_list.push_back(word);
                        word.erase();
                    }
                }
                i++;
                continue;
            }
            if (character_id < 48 or (character_id > 57 and character_id < 65) or
                (character_id > 90 and character_id < 97) or (character_id > 122)) {
                if (!word.empty()) {
                    word_list.push_back(word);
                    word.erase();
                }
            } else {
                if (character_id > 64 and character_id < 91) {
                    word += static_cast<char>(character_id + 32);
                } else {
                    word += str[i];
                }
            }
        }
        if (!word.empty()) {
            word_list.push_back(word);
            word.erase();
        }
    }
}