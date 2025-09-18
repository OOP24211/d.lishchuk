#include "Read_Words.h"
#include "Writing_to_csv.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>


int main(int argc, char* argv[]) {
    if(argc != 2){
        std::cout<<"Error of count arguments"<<std::endl;
        return 1;
    }
    std::ifstream file_input("argv[0]");
    std::ofstream file_output("argv[1]");
    if(!file_input or !file_output){
        std::cout<<"Error: No such files on this directory"<<std::endl;
        return 1;
    }
    std::string str;
    std::vector<std::string> word_list;
    std::map<std::string,int> double_arr_frequency;
    int word_cnt = 0;
    while(std::getline(file_input,str)){
        read::reading_words(str, word_list);
        word_cnt+= word_list.size();
        for(int i = 0; i< word_list.size(); i++){
            double_arr_frequency[word_list[i]]++;
        }
        word_list.clear();
        word_list.shrink_to_fit();
    }
    file_input.close();
    double_arr_frequency_to_csv(file_output,double_arr_frequency, word_cnt);
    file_output.close();
    return 0;
}
