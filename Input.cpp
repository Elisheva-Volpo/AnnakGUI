#include "Input.h"
#include "Command.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include <queue>

using namespace std;

Input::Input(int i) {
    world.reset(new Command(Command::WORLD));

    // Open the input file named "input.txt"
    inputFile.open("input.txt");

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    parse_and_store();
    buildStart();
}

Input::~Input() {
    // Close the file if it's open
    if (inputFile.is_open()) {
        inputFile.close();
    }
}

string Input::next_line() {
    string line;
    if (getline(inputFile, line)) {
        return line;
    }
    return ""; // Return empty string if EOF
}

void Input::parse_and_store() {
    string line = next_line();
    vector<shared_ptr<Command>>* command_list = &start;
    bool parsing_world = false;
    bool asserts_reached = false;

    while (!line.empty()) {
        strip(line);
        if (line.rfind("+", 0) == 0) {
            // Command block reached (e.g.: World, Infrastructure, etc...)
            string name = line.substr(1);
            parsing_world = false;

            if (name == Command::WORLD) {
                parsing_world = true;
            }
            else if (name == Command::START) {
                command_list = &start;
            }
            else if (name == Command::INPUT) {
                command_list = &steps;
            }
            else if (name == Command::ASSERTS) {
                asserts_reached = true;
            }
            else {
                throw runtime_error("Unknown Input Command found: " + name);
            }
        }
        else {
            if (asserts_reached) {
                asserts.push_back(line);
            }
            else if (parsing_world) {
                auto row = split(line);
                world->data.push_back(row);
            }
            else {
                auto command = parse_command(line);
                command_list->push_back(command);
            }
        }
        // Read next input line
        line = next_line();
    }
}

shared_ptr<Command> Input::parse_command(string line) {
    auto strings = split(line);
    shared_ptr<Command> command(new Command(strings[0]));
    command->arguments.insert(command->arguments.end(), strings.begin() + 1, strings.end());
    return command;
}

void Input::print_start_commands() const {
    for (const auto& command : start) {
        cout << "Command: " << command->name << " Arguments: ";
        for (const auto& arg : command->arguments) {
            cout << arg << " ";
        }
        cout << endl;
    }
}

void Input::buildCity(int i, int j) {
    /*world->data[i][j] = "8";
    world->data[i+1][j] = "8";
    world->data[i][j+1] = "8";
    world->data[i+1][j+1] = "8";*/

}

void Input::buildVillage(int i, int j) {
    /*for (int a = i; a < i + 4; a++) {
        for (int b = j; b < j + 4; j++) {
            world->data
        }
    }*/
}

void Input::buildRoad(int i, int j) {
    world->data[i][j] = "7";
}

void Input::buildStart() {
    for (auto& resource : start) {
        CommandName commandName = getCommandName(resource->name);
        if (commandName == Input::CommandName::Build) {
            const auto& args = resource->arguments;
            BuildName whatToBuild = getBuildName(args[0]);
            int val1 = std::stoi(args[1]);
            int val2 = std::stoi(args[2]);
            switch (whatToBuild) {
            case Input::BuildName::City:
                buildCity(val1 / 5, val2 / 5);
                break;
            case Input::BuildName::Village:
                buildVillage(val1 / 5, val2 / 5);
                break;
            case Input::BuildName::Road:
                buildRoad(val1 / 5, val2 / 5);
                break;
            default:
                break;
            }
        }
    }
}

Input::CommandName Input::getCommandName(const string& name) {
    static const unordered_map<string, Input::CommandName> commandNameMap = {
        {"Resource", Input::CommandName::Resource},
        {"People", Input::CommandName::People},
        {"Build", Input::CommandName::Build}
    };
    auto it = commandNameMap.find(name);
    return it != commandNameMap.end() ? it->second : Input::CommandName::Unknown;
}

Input::BuildName Input::getBuildName(const string& name) {
    static const unordered_map<string, Input::BuildName> buildNameMap = {
        {"City", Input::BuildName::City},
        {"Village", Input::BuildName::Village},
        {"Road", Input::BuildName::Road}
    };
    auto it = buildNameMap.find(name);
    return it != buildNameMap.end() ? it->second : Input::BuildName::Unknown;
}
