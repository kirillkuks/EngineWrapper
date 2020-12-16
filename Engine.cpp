#include "Engine.h"

Engine::Engine() {}

bool Engine::register_command(Wrapper* wrapper, std::string const& name) {
	if (commands.find(name) == commands.end()) {
		commands.insert(std::make_pair(name, wrapper));
		return true;
	}
	return false;
}

int Engine::execute(std::string const& name, std::map<std::string, int> args) {
	if (commands.find(name) != commands.end()) {
		Wrapper* wrapper = commands[name];
		if (wrapper->set_args(args)) {
			return wrapper->calculate();
		}
	}
	return 0;
}

int Engine::execute(std::string const& name) {
	if (commands.find(name) != commands.end()) {
		Wrapper* wrapper = commands[name];
		wrapper->set_default_args();
		return wrapper->calculate();
	}
	return 0;
}