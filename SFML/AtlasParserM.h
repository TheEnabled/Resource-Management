#pragma once
#include <fstream>

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
//#include <bits/stdc++.h>
#include <cstdlib>
#include <unordered_map>
//#include "../External/include/SFML/Graphics/Rect.hpp"
#include <SFML/Graphics.hpp>







bool comparePrefix(std::string word, std::string prefix);
bool containsChar(std::string word, char character);
std::unordered_map<std::string, sf::IntRect>* createDictionary();