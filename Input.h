#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "Command.h" // Assuming you have a Command class
#include "Utility.h" // Assuming you have utility functions strip and split

using namespace std;

class Input {
public:
    Input(int i);
    ~Input();

    enum class CommandName {
        Resource,
        People,
        Build,
        Unknown
    };
    enum class BuildName {
        City,
        Road,
        Village,
        Unknown
    };
    string next_line();
    void parse_and_store();
    shared_ptr<Command> parse_command(string line);
    void print_start_commands() const; // New member function to print start commands
    void buildCity(int i, int j);
    void buildVillage(int i, int j);
    void buildRoad(int i, int j);
    static BuildName getBuildName(const string& name);
    static CommandName getCommandName(const string& name);
    inline shared_ptr<Command>& getWorld() {
        return world;
    }

private:
    ifstream inputFile;
    shared_ptr<Command> world;
    vector<shared_ptr<Command>> start;
    vector<shared_ptr<Command>> steps;
    vector<string> asserts;
    void buildStart();
};

#endif // INPUT_H

