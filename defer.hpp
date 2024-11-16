#ifndef _DEFER_H_
#define _DEFER_H_

#include <functional>
#include <iostream>

namespace defer {
class Defer {
private:
    std::function<void(void)> on_exit;

public:
    Defer(std::function<void(void)> code)
        : on_exit(code)
    {
    }
    ~Defer()
    {
        on_exit();
    }
};

} // namespace defer

#define DEFER__CONCAT(x, y) x##y
#define DEFER_CONCAT(x, y) DEFER__CONCAT(x, y)
#define defer(...) \
    auto DEFER_CONCAT(_defer_, __COUNTER__) = defer::Defer([&]() { __VA_ARGS__; })

#endif // _DEFER_H_
