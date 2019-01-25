#include "MarkovAlgorithm.h"

// Инициализируем статические члены класса MarkovAlgorithm.
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
			int pos = temp.find(" -> "); // Находим позицию разделителя двух компонентов подстановки.
			if (pos == -1)
				return -1; // -1 - неверный формат данных в файле (нет разделителя).

			symb = temp.substr(0, pos); // Заменяемые символы стоят до разделителя.
			subst = temp.substr(pos + 4); // Заменяющие - после разделителя.

			symbols.push_back(symb);
			substitutions.push_back(subst);
		}
		fin.close();
		return 0; // Заполнение векторов с подстановками прошло успешно.
	}
	else return 1; // Файл не открыт.
}