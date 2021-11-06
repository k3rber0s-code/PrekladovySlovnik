#include "prekladovyslovnik.h"
#include <algorithm>


std::map<std::string, std::vector<std::string>> PrekladovySlovnik::CreateDictionary()
{
	return std::map<std::string, std::vector<std::string>>();
}

void PrekladovySlovnik::AddWord(std::string word, Translations translations)
{
	Map::iterator it = forward_dict.find(word);
	if (it != forward_dict.end()) {
		for (auto&& x : translations) {
			forward_dict[word].push_back(x);

			Map::iterator it2 = backward_dict.find(x);
			if (it2 != backward_dict.end()) {
				backward_dict[x].push_back(word);
			}
			else {
				Translations reverse_translations = { word };
				backward_dict.insert(std::pair<std::string, Translations>(x, reverse_translations));
			}
		}
	}
	else {
		forward_dict.insert(std::pair<std::string, Translations>(word, translations));
		for (auto&& x : translations) {
			Map::iterator it2 = backward_dict.find(x);
			if (it2 != backward_dict.end()) {
				backward_dict[x].push_back(word);
			}
			else {
				Translations reverse_translations = { word };
				backward_dict.insert(std::pair<std::string, Translations>(x, reverse_translations));
			}
		}
	}
}

void PrekladovySlovnik::DelWord(std::string word)
{
	for (auto&& x : forward_dict[word]) {
		Translations::iterator it = find(backward_dict[x].begin(), backward_dict[x].end(), word);
		backward_dict[x].erase(it);
	}
	forward_dict.erase(word);
}


void PrekladovySlovnik::DelTranslation(std::string word, std::string translation)
{
	// delete forward translation
	Map::iterator it = forward_dict.find(word);
	if (it != forward_dict.end()) {
		Translations::iterator it2 = find(forward_dict[word].begin(), forward_dict[word].end(), translation);
		forward_dict[word].erase(it2);
	}
	if (forward_dict[word].size() == 0) {
		forward_dict.erase(word);
	}

	// delete backward translation
	Map::iterator it3 = backward_dict.find(translation);
	if (it3 != backward_dict.end()) {
		Translations::iterator it4 = find(backward_dict[translation].begin(), backward_dict[translation].end(), word);
		backward_dict[translation].erase(it4);
	}
	if (backward_dict[translation].size() == 0) {
		backward_dict.erase(translation);
	}


	//TODO - DEL WORD IF NO TRANSLATIONS LEFT
}

void PrekladovySlovnik::FindWord(std::string word)
{
	if (forward_dict.count(word) != 0) {

		std::cout << word << " ";
		for (auto&& x : forward_dict[word]) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
}

void PrekladovySlovnik::PrefixFind(const std::string pref)
{
	const char* firstAfterPrefix = (pref + "0").c_str();
	auto prefixedEndIt = forward_dict.lower_bound(firstAfterPrefix);

	for (auto it = prefixedEndIt; it != std::end(forward_dict) && it->first.compare(0, pref.size(), pref) == 0; ++it) {
		FindWord(it->first);
	}
}

bool CompareString(std::string a, std::string b) {
	return a < b;
}

void PrekladovySlovnik::ReverseFind(std::string translation)
{
	std::sort(backward_dict[translation].begin(), backward_dict[translation].end(), CompareString);
	for (auto&& x : backward_dict[translation]) {
		if (!x.empty()) {
			std::cout << x << " ";
		}
	}
	std::cout << std::endl;
}
