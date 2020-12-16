#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <map>
#include "Subject.h"

struct Wrapper {
public:
	template<typename... Args>
	Wrapper(Subject* subj_, int(Subject::* func)(Args...), std::vector<std::pair<std::string, int>> const& v) : args{ v }, default_args{ v }, subj{ subj_ } {
		create_func(func);
	}

	bool set_args(std::map<std::string, int> new_args) {
		for (auto& p : args) {
			if (new_args.find(p.first) != new_args.end()) {
				p.second = new_args[p.first];
			}
			else {
				return false;
			}
		}
		return true;
	}

	bool set_default_args() {
		for (size_t i = 0; i < default_args.size(); ++i) {
			args[i] = default_args[i];
		}
		return true;
	}

	int calculate() {
		return lm();
	}

private:
	template<typename... Args, size_t... N>
	void create_func(int(Subject::* func)(Args...), std::index_sequence<N...>) {
		lm = std::bind(func, subj, std::cref(args[N].second)...);
	}

	template<typename... Args>
	void create_func(int(Subject::* func)(Args...)) {
		create_func(func, std::make_index_sequence<sizeof...(Args)>());
	}

private:
	Subject* subj;
	std::function<int(void)> lm;
	std::vector<std::pair<std::string, int>> args;
	std::vector<std::pair<std::string, int>> default_args;
};