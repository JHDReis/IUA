#include "StopWatch.h"
#include <filesystem>
#include <source_location>
#include <spdlog/fmt/chrono.h>
#include "spdlog/spdlog.h"
#include "spdlog/stopwatch.h"

using namespace std::chrono;

class StopWatch::Impl : spdlog::stopwatch
{
public:
    explicit Impl(const std::string_view message, const std::source_location& location = std::source_location::current())
    {
        const std::filesystem::path path(location.file_name());
        _message << path.filename().c_str() << " : " << location.function_name() << " [" << location.line() << ":" << location.column() << "] : " << message;
    }

    ~Impl()
    {
        const auto ms = duration_cast<milliseconds>(this->elapsed());
        spdlog::info("{} took {}", _message.str(), ms);
    }

private:
    std::stringstream _message{};
};

StopWatch::StopWatch(const std::string_view message, const std::source_location& location) : _impl(std::make_unique<Impl>(message, location)) {}

StopWatch::~StopWatch() = default;
