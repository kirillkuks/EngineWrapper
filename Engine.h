#pragma once
#include <string>
#include <map>
#include "Wrapper.h"

struct Engine {
	Engine();
	bool register_command(Wrapper*, std::string const&);
	int execute(std::string const&, std::map<std::string, int>);
	int execute(std::string const&);
private:
	std::map<std::string, Wrapper*> commands;
};