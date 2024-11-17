#ifndef _DEFER_H_
#define _DEFER_H_

#include <functional>

namespace defer {
class Defer {
private:
    std::function<void(void)> on_exit;
private:
    Defer(const Defer&);
    Defer(Defer&&);
    Defer& operator=(const Defer&);
    Defer& operator=(Defer&&);

public:
    Defer(std::function<void(void)> code)
        : on_exit(code)
    {
    }
    ~Defer() { on_exit(); }
};

} // namespace defer

#define DEFER__CONCAT(x, y) x##y
#define DEFER_CONCAT(x, y) DEFER__CONCAT(x, y)
#define defer(...) \
    auto DEFER_CONCAT(_defer_, __COUNTER__) = defer::Defer([&]() { __VA_ARGS__; })

#endif // _DEFER_H_
