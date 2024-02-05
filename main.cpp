#include <algorithm>
#include <chrono>
#include <cstdint>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

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
void append_to_file(std::string filepath, std::string to_append) {
    std::ofstream outf{filepath};
    if (!outf) {
        std::cerr << "Unable to open file for writing\n";
        return;
    }
    outf << to_append;
    return;
}
int32_t add_commit(std::string filepath, std::string message) {
    // git add .file
    // git commit -m "message"
    std::string addcmd = "git add ";
    addcmd = addcmd + filepath;
    int32_t result = system(addcmd.c_str());
    std::string commit = "git commit -m \'";
    std::string suffix = message + "\'";
    commit = commit + suffix;

    std::cout << commit << std::endl;

    return system(commit.c_str());
}

int32_t alter_authorDate(std::tm &timeInfo) {

    std::stringstream ss;
    ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S\'");
    std::string formattedTimeString = ss.str();
    std::string commitAmmend = "git commit --amend --no-edit --date=\'";
    commitAmmend = commitAmmend + formattedTimeString;

    std::cout << " === : " << commitAmmend << std::endl;

    return system(commitAmmend.c_str());
}
int32_t alter_commiterDate(std::tm &timeInfo) {
    std::stringstream ss;
    ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S\'");
    std::string formattedTimeString = ss.str();
    std::string commitAmmend = "GIT_COMMITTER_DATE=\'";
    commitAmmend =
        commitAmmend + formattedTimeString + " git commit --amend --no-edit";

    std::cout << commitAmmend << std::endl;

    return system(commitAmmend.c_str());
}
void modifyFile(std::string filepath, std::string appendthis) {
    std::ofstream outputFile(filepath, std::ios::app);
    if (outputFile.is_open()) {
        outputFile << appendthis << std::endl;

        outputFile.close();

    } else {
        std::cerr << "Error opening file" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    // TODO parse integral from argv
    // cpr::Response r = cpr::Get(cpr::Url{"https::/api"})
    srand((unsigned)time(NULL));
    std::chrono::system_clock::time_point this_moment =
        std::chrono::system_clock::now();
    std::chrono::seconds secondsEpoch =
        std::chrono::duration_cast<std::chrono::seconds>(
            this_moment.time_since_epoch());
    char *commits = (getCmdOption(argv, argc + argv, "-n"));

    std::time_t unixTime = secondsEpoch.count();

    std::time_t lastYear = unixTime - 31556926;

    std::chrono::system_clock::time_point tp =
        std::chrono::system_clock::from_time_t(lastYear);
    // std::tm timeInfo = *std::localtime(&lastYear);
    int32_t commit_no = 999;

    for (int i = 0; i < commit_no; i++) {
        std::tm timeInfo = *std::localtime(&lastYear);
        std::string filepath = "./README.md";
        modifyFile(filepath, "anita max wynn");
        std::int32_t result = add_commit("./README.md", "not even randomized");
        if (result < 0) {
            std::cout << "Commit failed " << std::endl;
            break;
            // this seems heavily excessive
        }
        result = alter_authorDate(timeInfo);
        if (result < 0) {
            std::cout << "altering author date failed " << std::endl;
            break;
        }
        result = alter_commiterDate(timeInfo);
        int random = rand() % 5;
        int increment = 28880;
        if (random > 0) {
            increment = 84600 / random;
        }
        lastYear = lastYear + increment;
    }

    char *commitMessage;
}
