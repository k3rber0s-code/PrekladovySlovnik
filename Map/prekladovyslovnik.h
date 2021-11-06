#pragma once
#include <map>
#include <vector>
#include <iostream>

class PrekladovySlovnik {
public:
	PrekladovySlovnik() {
		forward_dict = CreateDictionary();
		backward_dict = CreateDictionary();
	}

	typedef std::map<std::string, std::vector<std::string>> Map;
	typedef std::vector<std::string> Translations;

	using Map = std::map<std::string, std::vector<std::string>>;
	using Translations = std::vector < std::string>;


	void AddWord(std::string word, Translations translations);
	void DelWord(std::string word);
	void DelTranslation(std::string word, std::string translation);
	void FindWord(std::string word);
	void PrefixFind(std::string prefix);
	void ReverseFind(std::string translation);

	//const bool is_in_map(Map* m, std::string element) { return( m.count(element) > 0); }

private:
	Map CreateDictionary();
	std::map<std::string, Translations> forward_dict;
	std::map<std::string, Translations> backward_dict;

};