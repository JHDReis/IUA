
#ifndef IUA_STOPWATCH_H
#define IUA_STOPWATCH_H
#include <memory>
#include <source_location>

class StopWatch
{
    class Impl;
    std::unique_ptr<Impl> _impl;

public:
    explicit StopWatch(const std::string_view message, const std::source_location& location = std::source_location::current());

    ~StopWatch();

    // do not allow copy or move
    StopWatch(const StopWatch& other) = delete;
    StopWatch(StopWatch&& other) noexcept = delete;

    StopWatch& operator=(const StopWatch& other) = delete;
    StopWatch& operator=(StopWatch&& other) noexcept = delete;
};

#endif // IUA_STOPWATCH_H
