#include <database.h>
#include <set>
#include <string>
#include <map>
#include <vector>

class Solution {
public:
    Solution(const std::string& input, const std::string& output, const std::string& conf);
    bool updateDirrectory(const std::string& path);

private:
    bool addFile(const std::string& path);
    bool addConfig(const std::string& path);

    void print() const;

    std::vector<std::string> parse(const std::string& line, char separator) const;

    std::vector<Config> config;
    std::map<std::string, DataBase> files;
};