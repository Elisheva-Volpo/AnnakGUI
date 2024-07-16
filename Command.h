//#pragma once
//
//#include <string>
//#include <vector>
//using namespace std;
//
//class Command
//{
//public:
//    Command(const std::string& _name) : name(_name) { }
//
//    string name;
//    vector<string> arguments;
//    vector< vector<string> > data;
//
//    static const std::string WORLD;
//    static const std::string START;
//    static const std::string INPUT;
//    static const std::string ASSERTS;
//
//};


#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Command {
public:
    static const string WORLD;
    static const string START;
    static const string INPUT;
    static const string ASSERTS;

    Command(const string& name) : name(name) {}

    string name;
    vector<vector<string>> data;
    vector<string> arguments;
};

#endif // COMMAND_H

