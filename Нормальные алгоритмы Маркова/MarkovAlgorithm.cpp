#include "MarkovAlgorithm.h"

// �������������� ����������� ����� ������ MarkovAlgorithm.
std::vector <std::string> MarkovAlgorithm::symbols;
std::vector <std::string> MarkovAlgorithm::substitutions;

int MarkovAlgorithm::SetArraysOfSubstitutions(std::string fileName) {
	std::ifstream fin(fileName, std::ios::in);
	if (fin.is_open()) {
		symbols.clear();
		substitutions.clear();

		std::string temp;
		std::string symb;
		std::string subst;
		while (getline(fin, temp)) {
			int pos = temp.find(" -> "); // ������� ������� ����������� ���� ����������� �����������.
			if (pos == -1)
				return -1; // -1 - �������� ������ ������ � ����� (��� �����������).

			symb = temp.substr(0, pos); // ���������� ������� ����� �� �����������.
			subst = temp.substr(pos + 4); // ���������� - ����� �����������.

			symbols.push_back(symb);
			substitutions.push_back(subst);
		}
		fin.close();
		return 0; // ���������� �������� � ������������� ������ �������.
	}
	else return 1; // ���� �� ������.
}