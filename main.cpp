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

// do I need to define a struct?
// std::chrono::seconds
// to_unixepoch(std::chrono::time_point<std::chrono::system_clock> tp) {
//     return std::chrono::duration_cast<std::chrono::seconds>(tp);
// }
// class Codebase {
//   public:
//     Codebase() {
//         // parse info from ,git
//     }
//
//   private:
//     static std::string remote_address;
//
//   public:
//     void set_remote(std::string remote) { this->remote_address = remote; }
//     void push_to_remote() {
//         if (remote_address.length() == 0) {
//             std::cout << "remote address unspecified";
//             return;
//         }
//         system("git push -u origin");
//     }
//     void init() {
//         system("git init");
//         system("git branch -M main");
//     }
// };
//
// class Commit {
//   public:
//     Commit(std::string message, date::year_month_day commitDate,
//            std::string_view timezone, std::string hh_mm_ss) {
//         using namespace date;
//         this->message = message;
//         this->commitDate = commitDate;
//         // sprintf(cmd, "echo %s \n", echo);
//
//         sprintf(this->unix_timestamp, "%s %s %d %s %d", weekday{commitDate},
//                 month{commitDate}, commitDate.day(), hh_mm_ss.c_str(),
//                 static_cast<int>(commitDate.year()));
//
//         // weekday{commitDate}
//         // parse unit_timestamp here
//     }
//
//     std::string message;
//     // we only want to hold DD:MM:YYYY time will be randomized
//     // std::chrono::system_clock::time_point authorDate;
//
//     date::year_month_day commitDate;
//     const std::string timezone;
//     std::string ammended_date;
//     char *unix_timestamp;
//
//     // std::chrono:year_month_day a c++20 thing
//     // std::chrono::year_month_day
//     // commitDate{std::chrono::floor<std::chrono::days>(now)};
//     // std::chrono::system_clock::from_time_t(0);
// };
// // helpers
// bool cmdOptionExists(char **begin, char **end, const std::string &option) {
//     return std::find(begin, end, option) != end;
// }
//
// char *getCmdOption(char **begin, char **end, const std::string &option) {
//     char **itr = std::find(begin, end, option);
//     if (itr != end && ++itr != end) {
//         return *itr;
//     }
//     return 0;
// }
// // helpers
//
// // gitbackD options
// // duration
// // randomized -r
// // remote link
// //
// //
//
// void execute_command(std::string command) {
//     // why can't my linter understand
//     // cstdio system
//     int result = system(command);
//     if (result < 0) {
//         std::cout << "Erorr: Don't know what to do with yet";
//     }
// }
//
// void populate_timeline(std::string_view starter, std::string_view ender,
//                        int timezone, int commits) {
//     std::string commit_message = "artificially generated";
//     int counter = 1;
//     while (counter < commits) {
//         // Commit(std::string message, date::year_month_day commitDate,
//         // std::string_view timezone, std::string hh_mm_ss)
//         // Commit commit(commit_message,);
//     }
// }

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
    std::tm timeInfo = *std::localtime(&unixTime);
    std::stringstream ss;
    ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");
    std::string formattedTimeString = ss.str();
    std::cout << "The final string looks like" << std::endl
              << formattedTimeString;
    // sprintf(commitMessage, "git commit --amend --no-edit
    // --date=%s",formattedTimeString);

    // std::chrono::system_clock::time_point tp =
    // std::chrono::system_clock::from_time_t(lastYear); while (unixTime >
    // lastYear) {
    //     lastYear = lastYear + 86400;
    //
    // }
}
