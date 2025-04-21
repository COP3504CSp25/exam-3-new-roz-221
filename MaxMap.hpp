#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <vector>

float consultMax(const std::string& search_term, const std::map<std::string, std::vector<float>>& data) {
    float max = -1;
    std::map<std::string, std::vector<float>>::iterator iter = data.begin();
    for (iter; iter != data.end(); ++iter) {
        if (iter->first == search_term) {
            for (int i = 0; i < (iter->second).size(); ++i) {
                if (data[iter->first].at(i) >= max) { max = data[iter->first].at(i); }
            }
        }
    }
    return max;
}

std::map<std::string, float> returnMaxMap(const std::map<std::string, std::vector<float>>& in_map) {
    std::map<std::string, float> maxes;
    std::map<std::string, float>::iterator it = in_map.begin();
    for (it; it != map.end(); ++it) {
        float max = (iter->second).at(0);
        for (int j = 0; j < (iter->second).size(); ++j) {
            if (iter->second.at(j) >= max) {
                max = iter->second.at(j);
            }
        }
        maxes.insert({iter->first, max});
    }
    return maxes;
}