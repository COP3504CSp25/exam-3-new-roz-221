#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <vector>

float consultMax(const std::string& search_term, const std::map<std::string, std::vector<float>>& data) {
    float max = -1.0;
    //std::map<std::string, std::vector<float>>::iterator iter = data.begin();
    auto iter = data.begin();
    for (iter; iter != data.end(); ++iter) {
        if (iter->first == search_term) {
            for (int i = 0; i < iter->second.size(); ++i) {
                if (iter->second.at(i) > max) { max = iter->second.at(i); }
            }
        }
    }
    return max;
}

std::map<std::string, float> returnMaxMap(const std::map<std::string, std::vector<float>>& in_map) {
    std::map<std::string, float> maxes;
    //std::map<std::string, float>::iterator it = in_map.begin();
    auto it = in_map.begin();
    for (it; it != in_map.end(); ++it) {
        float max = (it->second).at(0);
        for (int j = 0; j < (it->second).size(); ++j) {
            if (it->second.at(j) > max) {
                max = it->second.at(j);
            }
        }
        maxes.insert({it->first, max});
    }
    return maxes;
}