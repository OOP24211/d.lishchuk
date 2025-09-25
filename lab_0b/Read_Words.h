#include <string>
#include <vector>
class Read
{
    private:
        std::string word;
        int character_id;
    public:
        void reading_words(std::string str, std::vector<std::string> &word_list);
};
