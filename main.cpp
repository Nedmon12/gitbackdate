#include <algorithm>
#include <cstdio>
#include <iostream>

// helpers
bool cmdOptionExists(char **begin, char **end, const std::string &option) {
    return std::find(begin, end, option) != end;
}

char *getCmdOption(char **begin, char **end, const std::string &option) {
    char **itr = std::find(begin, end, option);
    if (itr != end && ++itr != end) {
        return *itr;
    }
    return 0;
}
// helpers

// gitbackD options
// duration
// randomized -r
// remote link
//
//

void execute_command(std::string command) {
    // why can't my linter understand
    // cstdio system
    int result = system(command);
    if (result < 0) {
        std::cout << "Erorr: Don't know what to do with yet";
    }
}

void populate_timeline(std::string_view starter, std::string_view ender,
                       int timezone, int commits) {}

void set_remote(std::string remote) {}
void commit(std::string message, std::string date) {}
void push_to_remote() { std::string name; }

// look at my code monkey
void modify_file() {}
int main(int argc, char *argv[]) {
    // options
    //-d [time duration]
    //-r remote
    //
    std::cout << "Not ready yet obv" << std::endl;

    char *echo = getCmdOption(argv, argv + argc, "-o");
    if (echo) {
        char cmd[100];
        sprintf(cmd, "echo %s \n", echo);
    }
    // if (!duration) {
    //   //return 0 because I legit don't know how to handle it
    //   //TOIMP
    //   return 0;
    // }

    // if cmdOptionExists(argv, argv+argc, "-r") {
    //   //Randomized
    // }

    ////define command string builder
    // std::string cmd = "git {options}"
    // redi::ipstream proc("git -r ", redi::pstreams::pstdout |
    // redi:pstreams::pstderr);

    return 0;
}
