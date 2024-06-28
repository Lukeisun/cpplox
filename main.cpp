#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
void run_file(std::string path) {
	std::cout << "IN RUN" << std::endl;
	std::ifstream in(path.c_str(), std::ios::binary);
	if(!in.good()) {
		exit(EXIT_FAILURE);
	}
	int length = std::filesystem::file_size(std::filesystem::path(path));
	std::vector<char> buffer(length);
	in.read(buffer.data(), length);
	std::cout << "len: " << length << std::endl;
	for (auto b : buffer) {
		std::cout << char(b) << std::endl;
	}
}
void run_prompt() { 
	std::cout << "> ";
	for(std::string line; std::getline(std::cin, line);){
		std::cout << "line: " << line << std::endl;
		std::cout << "> ";
	}
}
int main(int argc, char* argv[]) {
	if (argc > 2) {
		std::cout << "Usage: jlox [script]";
		exit(64);
	} else if (argc == 2) {
		run_file(argv[1]);	
	} else {
		run_prompt();
	}
	std::cout << "Hello!\n";
}
