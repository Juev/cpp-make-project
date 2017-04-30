#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "version.h"

using namespace std;

void printHelp(string programName) {
    cout << "Create simple C++ project with Cmake." << endl
         << "Using:" << endl;
    cout << "$ " << programName << " [--help|-h] [--version|-v] [project-name]" << endl;
    cout << "Default project name: template" << endl;
    exit(0);
}

void printVersion() {
    cout << "Version: " << VERSION_MAJOR << "." << VERSION_MINOR << endl;
    exit(0);
}

int main(int argc, char const *argv[]) {
    string projectName = "template";
    for (auto i = 0; i < argc; ++i) {
        string tmp = argv[i];
        if (tmp == "--help" || tmp == "-h") {
            printHelp(argv[0]);
        } else if (tmp == "--version" || tmp == "-v") {
            printVersion();
        } else {
            projectName = argv[i];
        }
    }

    const int dir_err = mkdir("source", S_IRWXU | S_IRWXG);
    if (dir_err != 0) {
        cout << "Error creating directory source!" << endl;
        exit(1);
    }
    ofstream cmakeFile("CMakeList.txt");
    cmakeFile << "cmake_minimum_required(VERSION 3.7)" << endl
              << "project(" << projectName << ")" << endl
              << "set(CMAKE_CXX_STANDARD 14)" << endl << endl
              << "set(SOURCE_FILES source/main.cpp)" << endl
              << "add_executable(" << projectName << " ${SOURCE_FILES})" ;
    cmakeFile.close();

    ofstream sourceFile("source/main.cpp");
    sourceFile << "#include <iostream>" << endl << endl
               << "using namespace std;" << endl << endl
               << "int main(int argc, char const* argv[]) {" << endl
               << "    cout << \"Hello world!\" << endl;" << endl
               << "    return 0;" << endl
               << "}";
    sourceFile.close();
    return 0;
}