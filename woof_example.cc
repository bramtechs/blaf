#include "woof.hh"

struct Point
{
    int x, y;
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    return os << "Point(" << p.x << ", " << p.y << ")";
}

int main(int argc, char** argv)
{
	woof::setPrefix("woof");
    woof::log("log message", 10, "hello world");
	woof::info("info message", 0.5);
    woof::warn("warning message", Point { 10, 5 });
    woof::error("error message", false);
    WOOF_DEBUG("debug message", "only compiled in debug mode");
}