#pragma once
#include <string>
#include <vector>
#include <fstream>

class MarkovAlgorithm {
public:
	static std::vector <std::string> symbols;
	static std::vector <std::string> substitutions;

	static int SetArraysOfSubstitutions(std::string);
};