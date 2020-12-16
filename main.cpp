#include <iostream>
#include "Subject.h"
#include "Wrapper.h"
#include "Engine.h"
#include <map>

int main() {
	Subject subj;

	Wrapper wrapper(&subj, &Subject::f3, { {"arg1", 1}, {"arg2", 2} });
	Engine engine;
	engine.register_command(&wrapper, "command1");
	std::cout << engine.execute("command1", { {"arg2", 5}, {"arg1", 9} }) << std::endl;


	Wrapper wrapper1(&subj, &Subject::f1, { {"1", 1}, {"2", 1}, {"3", 1}, {"4", 1}, {"5", 1} });
	engine.register_command(&wrapper1, "command2");
	std::cout << engine.execute("command2", { { "3", 9 }, { "1", 1 }, { "5", 3 }, { "2", 3 }, { "4", 11 } }) << std::endl;

	std::cout << engine.execute("command2") << std::endl;
	return 0;
}