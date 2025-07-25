#include <httplib.h>

#ifdef _WIN64
#include <Windows.h>
#endif

// #include <occi.h>
#include <spdlog/spdlog.h>
#include <iostream>

using std::cout;
using std::endl;

void test_spdlog() {
    cout << "Testing spdlog..." << endl;

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical(
        "Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug);  // Set *global* log level to debug
    spdlog::debug("This message should be displayed..");

    // change log pattern
    // spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    // Compile time log levels
    // Note that this does not change the current log level, it will only
    // remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");
    std::cout << std::endl;
}

void test_httplib() {
    cout << "Testing httplib..." << endl;

    spdlog::info("Retreiving content from a URL using httplib...");
    httplib::Client cli("http://yhirose.github.io");

    auto res = cli.Get("/hi");
    spdlog::info("Response:\n{}", res->body);
    std::cout << std::endl;
}

// void test_occi() {
//     cout << "Testing OCCI..." << endl;

//     const std::string username = "system";
//     const std::string password = "password";
//     const std::string url = "localhost:1521/XEPDB1";

//     try {
//         oracle::occi::Environment* env =
//             oracle::occi::Environment::createEnvironment();
//         oracle::occi::Connection* conn =
//             env->createConnection(username, password, url);
//         spdlog::info("Connected to Oracle Database: {}", url);
//         env->terminateConnection(conn);
//         oracle::occi::Environment::terminateEnvironment(env);
//     } catch (const oracle::occi::SQLException& e) {
//         spdlog::error("OCCI Error: {}", e.getMessage());
//     }
// }

int main() {
    test_spdlog();
    test_httplib();
    // test_occi();
    spdlog::info("Test completed successfully.");
    return 0;
}