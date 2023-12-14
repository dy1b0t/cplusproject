#ifndef ITEMFREQUENCY_H
#define ITEMFREQUENCY_H

#include <string>
#include <map>

class ItemFrequency {
private:
    std::map<std::string, int> itemFrequency;

public:
    void addItemFrequency(const std::string& item, int count);
    int getItemFrequency(const std::string& item) const;
    void printAllFrequencies() const;
    void printHistogram() const;
    void saveToFile(const std::string& filename) const;
};

#endif //ITEMFREQUENCY_H
