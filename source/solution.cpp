#include <solution.h>

#include <dirent.h>
#include <cstring>
#include <fstream>

Solution::Solution(const std::string& input, const std::string& output, const std::string& conf) {
    addDirrectory(input);
    addConfig(conf);
    print();
}

bool Solution::addDirrectory(const std::string& path) {
    DIR* dir = opendir(path.c_str());
    dirent* file;

    if (dir == nullptr) {
        return false;
    }

    while (true) {
        file = readdir(dir);
        if (file == nullptr) {
            break;
        }

        std::string name(file->d_name);

        if (file->d_type != DT_REG) {
            continue;
        }

        if (path.back() == '/') {
            addFile(path + name);
        } else {
            addFile(path + "/" + name);
        }
    }
    return true;
}
// [name, cost, provider, count]
bool Solution::addFile(const std::string& path) {
    DataBase new_database;

    std::string line;
    std::ifstream in(path);
    if (!in.is_open()) {
        return false;
    }

    while (getline(in, line)) {
        std::vector<std::string> array = parse(line, ',');
        
        if (array.size() < 4) {
            continue;
        }

        new_database.addProvider(array[2], line);
        new_database.addProduct(array[0], line);
    }
    in.close();

    files[path] = new_database;
    return true;
}

bool Solution::addConfig(const std::string& path) {
    std::string line;
    std::ifstream in(path);
    if (!in.is_open()) {
        return false;
    }

    while (getline(in, line)) {
        std::vector<std::string> array = parse(line, ' ');
        
        Config new_config;

        if (array.size() < 3) {
            continue;
        }

        new_config.column = array[0];
        new_config.name = array[1];
        new_config.path = array[2];

        config.push_back(new_config);
    }
    in.close();

    return true;
}

std::vector<std::string> Solution::parse(const std::string& line, 
                                         char separator) const {
    std::vector<std::string> result;
    std::string current;

    for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] == separator) {
            result.push_back(current);
            current = "";
        } else {
            current.push_back(line[i]);
        }
    }

    result.push_back(current);
    return result;
}

void Solution::print() const {
    for (size_t i = 0; i < config.size(); ++i) {
        std::remove(config[i].path.c_str());
    }

    for (auto& it : files) {
        for (size_t i = 0; i < config.size(); ++i) {
            it.second.print(config[i]);
        }
    }
}
