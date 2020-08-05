#include <string>
#include <map>
#include <vector>

struct Config {
    std::string column; // column of data base - must be "product" or "provider"
    std::string name;   // name of product or provider
    std::string path;   // path to output file
};

class DataBase {
public:
    DataBase() = default;
    DataBase(const DataBase&) = default;
    DataBase(DataBase&&) = default;
    
    DataBase& operator=(DataBase&) = default;
    void print(const Config& confg) const;

    void addProvider(std::string& name, std::string& provider);
    void addProduct(std::string& name, std::string& product);

private:
    void printProduct(const std::string& path, const std::string& name) const;
    void printProvider(const std::string& path, const std::string& name) const;
    void printData(const std::string& path, const std::vector<std::string>& data) const;

    std::map<std::string, std::vector<std::string> > providers;
    std::map<std::string, std::vector<std::string> > products;
};