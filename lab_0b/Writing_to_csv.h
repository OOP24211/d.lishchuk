#include <vector>
#include <string>
#include <map>
class Write {
private:
    std::multimap<int, std::string, std::greater<>> sorted_double_arr;
public:
    void double_arr_frequency_to_csv(std::ofstream &file, std::map<std::string, int> &double_arr, int word_cnt);
};
