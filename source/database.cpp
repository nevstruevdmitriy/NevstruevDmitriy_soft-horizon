#include <database.h>
#include <fstream>

void DataBase::print(const Config& config) const {
    if (config.column == "product") {
        printProduct(config.path, config.name);
        return;
    }
    if (config.column == "provider") {
        printProvider(config.path, config.name);
        return;
    }

    printf("Unnown column %s\n", config.column.c_str());
}

int DataBase::getVersion() const {
    return version;
}

void DataBase::setVersion(int version_) {
    version = version_;
}

void DataBase::addProduct(std::string& name, std::string& product) {
    products[name].push_back(product);
}

void DataBase::addProvider(std::string& name, std::string& provider) {
    providers[name].push_back(provider);
}

void DataBase::printProduct(const std::string& path, const std::string& name) const {
    if (products.find(name) != products.end()) {
        printData(path, products.at(name));
    }
}

void DataBase::printProvider(const std::string& path, const std::string& name) const {
    if (providers.find(name) != providers.end()) {
        printData(path, providers.at(name));
    }
}

void DataBase::printData(const std::string& path, const std::vector<std::string>& data) const {
    std::ofstream out;

    out.open(path.c_str(), std::ios_base::app);

    if (!out.is_open()) {
        printf("error open %s, can not find dirrectory\n", path.c_str());
        return;
    }

    for (size_t i = 0; i < data.size(); ++i) {
        out << data[i] << std::endl;
    }

    out.close();
}