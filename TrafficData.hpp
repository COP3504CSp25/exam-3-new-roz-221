#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, int> loadTrafficData(const std::string& filename) {
  std::map<std::string, int> trafficData;
  std::ifstream file(filename);
  std::string line;

  if (!file) {
    std::cout << "-1" << std::endl;
  }

  while(getline(file,line)) {
    std::istringstream ss(line);
    std::string airportCode;
    int passengers;

    if (getline(ss, airportCode) && (ss >> passengers)) {
      trafficData[airportCode] = passengers;
    }
  }

  file.close();
  return trafficData;
}

void updateTrafficData(const std::string& filename, std::map<std::string, int>& dataMap) {
  std::ifstream file(filename);
  std::string line;

  if (!file) {
    std::cout << "-1" << std::endl;
  }

  while(getline(file,line)) {
    std::istringstream ss(line);
    std::string airportCode;
    int passengers;

    // Will create/update as necessary already? idk
    if (getline(ss, airportCode) && (ss >> passengers)) {
      dataMap[airportCode] = passengers;
    }
  }

  file.close();
}