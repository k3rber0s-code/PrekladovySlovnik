#include <iostream>
#include <vector>
#include "prekladovyslovnik.h"

int main(int argc, char* argv) {
	PrekladovySlovnik ps;
	std::vector<std::string> t1 = { "hi", "hello" };
	std::vector<std::string> t2 = { "jabko", "jablicko" };

	ps.AddWord("cau", t1);
	ps.AddWord("ahoj", t1);
	ps.AddWord("apple", t2);

	std::cout << "=======ps.PrefixFind();" << std::endl;
	ps.PrefixFind("");
	std::cout << "=======ps.PrefixFind(a);" << std::endl;
	ps.PrefixFind("a");

	std::cout << "=======ps.FindWord(ahoj);" << std::endl;
	ps.FindWord("ahoj");
	std::cout << "=======ps.ReverseFind(hi);" << std::endl;
	ps.ReverseFind("hi");

	std::cout << "=======ps.DelTranslation(ahoj, hi);" << std::endl;
	ps.DelTranslation("ahoj", "hi");

	std::cout << "=======ps.FindWord(ahoj);" << std::endl;
	ps.FindWord("ahoj");
	std::cout << "=======ps.ReverseFind(hi);" << std::endl;
	ps.ReverseFind("hi");

	std::cout << "=======ps.DelTranslation(ahoj, hello);" << std::endl;
	ps.DelTranslation("ahoj", "hello");

	std::cout << "=======ps.FindWord(ahoj);" << std::endl;
	ps.FindWord("ahoj");
	std::cout << "=======ps.ReverseFind(hi);" << std::endl;
	ps.ReverseFind("hi");
	std::cout << "=======ps.FindWord(apple);" << std::endl;
	ps.FindWord("apple");
	std::cout << "=======ps.DelWord(apple);" << std::endl;
	ps.DelWord("apple");
	std::cout << "=======ps.FindWord(apple);" << std::endl;
	ps.FindWord("apple");
	std::cout << "=======ps.ReverseFind(jablicko);" << std::endl;
	ps.ReverseFind("jablicko");




}