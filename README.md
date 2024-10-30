# woof

Tiny C++ logging library using streams.

## Example usage

```c++
struct Point
{
    int x, y;
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    return os << "Point(" << p.x << ", " << p.y << ")";
}

woof::setPrefix("woof");
woof::log("log message", 10, "hello world");
woof::warn("warning message", Point { 10, 5 });
woof::error("error message", false);
WOOF_DEBUG("debug message", "only compiled in debug mode");
```

output:
```
woof: log message 10 hello world
woof warn: warning message Point(10, 5)
woof error: error message 0
woof debug: debug message only compiled in debug mode
```