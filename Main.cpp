#include <iostream>
#include <set>
using std::set;

#include "allocator.h"

struct Example
{
    int value;

    Example(int v) :
        value(v)
    {}

    bool operator<(Example const& other) const
    {
        return value < other.value;
    }
};

int main(int argc, char* argv[])
{
    // Increase scope
    {
        std::set<Example, std::less<Example>, fmi::allocator<Example, heap<Example> > > foo;

        foo.insert(Example(3));
        foo.insert(Example(1));
        foo.insert(Example(4));
        foo.insert(Example(2));
    }
    // Leaving scope
    return 0;
}

