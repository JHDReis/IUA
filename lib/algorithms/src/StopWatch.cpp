
#include "StopWatch.h"
#include "spdlog/spdlog.h"
#include <spdlog/fmt/chrono.h>
#include "spdlog/stopwatch.h"
#include <utility>

#if defined(__linux__)               // Linux
    #define FUNCTION_NAME __PRETTY_FUNCTION__
#else
    #define FUNCTION_NAME __func__      // Fallback to __func__ if OS is not Linux
#endif

using namespace std::chrono;

class StopWatch::Impl : spdlog::stopwatch {
public:
    explicit Impl(std::string message): _message(std::move(message)) {}

    ~Impl()
    {
        const auto ms = duration_cast<milliseconds>(this->elapsed());
        spdlog::info("[{}] : {} took {} ms", FUNCTION_NAME, _message, ms);
    }

private:
    std::string _message{};
};

StopWatch::StopWatch(const std::string& message)
    : _impl(std::make_unique<Impl>(message))
{}

StopWatch::~StopWatch() = default;
