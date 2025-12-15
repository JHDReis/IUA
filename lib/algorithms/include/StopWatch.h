
#ifndef IUA_STOPWATCH_H
#define IUA_STOPWATCH_H
#include <memory>
#include <string>

class StopWatch {
    class Impl;
    std::unique_ptr<Impl> _impl;

public:
    explicit StopWatch(const std::string& message);

    ~StopWatch();

    // do not allow copy or move
    StopWatch(const StopWatch& other) = delete;
    StopWatch(StopWatch&& other) noexcept = delete;

    StopWatch& operator=(const StopWatch& other) = delete;
    StopWatch& operator=(StopWatch&& other) noexcept = delete;
};

#endif // IUA_STOPWATCH_H
