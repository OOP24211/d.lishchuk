#include "Writing_to_csv.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>

void Write::double_arr_frequency_to_csv(std::ofstream& file, std::map<std::string,int>& double_arr, int word_cnt){
    for(const auto& i : double_arr){
        sorted_double_arr.insert({i.second,i.first});
    }
    for(const auto& i : sorted_double_arr){
        file << "\xEF\xBB\xBF" << i.second << ";" << i.first << ";" << (i.first*100.0)/word_cnt<< "\n";
    }

}
