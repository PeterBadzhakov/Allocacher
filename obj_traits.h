#pragma once

template<typename T>
class obj_traits
{
public:

    typedef T type;

    template<typename U>
    struct rebind
    {
        typedef obj_traits<U> other;
    };

    // Constructor
    obj_traits(void) {}

    // Copy Constructor
    template<typename U>
    obj_traits(obj_traits<U> const& other) {}

    // Address of object
    type* address(type& obj) const { return &obj; }
    type const* address(type const& obj) const { return &obj; }

    // Construct object
    void construct(type* ptr, type const& ref) const
    {
        // In-place copy construct
        new(ptr) type(ref);
    }

    // Destroy object
    void destroy(type* ptr) const
    {
        // Call destructor
        ptr->~type();
    }
};

