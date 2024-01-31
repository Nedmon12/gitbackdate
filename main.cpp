#include "date.h"
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
    std::chrono::system_clock::time_point this_moment =
        std::chrono::system_clock::now();
    std::chrono::seconds secondsEpoch =
        std::chrono::duration_cast<std::chrono::seconds>(
            this_moment.time_since_epoch());

    std::time_t unixTime = secondsEpoch.count();

    std::time_t lastYear = unixTime - 31556926;

    char *commitMessage;
    std::chrono::system_clock::time_point tp =
        std::chrono::system_clock::from_time_t(lastYear);
    std::tm timeInfo = *std::localtime(&lastYear);
    std::stringstream ss;
    ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S\'");
    std::string formattedTimeString = ss.str();
    std::string commitAmmend = "git commit --amend --no-edit --date=\'";
    commitAmmend = commitAmmend + formattedTimeString;
    std::cout << " === : " << commitAmmend << std::endl;
    int32_t result = system(commitAmmend.c_str());
    if (result > 0) {
        std::cout << "Command executed successfully" << std::endl;
    } else {
        std::cout << "Erroryans" << std::endl;
    }
    // sprintf(commitMessage, "git commit --amend --no-edit
    // --date=%s",formattedTimeString);

    // std::chrono::system_clock::time_point tp =
    // std::chrono::system_clock::from_time_t(lastYear); while (unixTime >
    // lastYear) {
    //     lastYear = lastYear + 86400;
    //
    // }
}
