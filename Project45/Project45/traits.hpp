#pragma once

template <typename X>
class object_traits
{
public:
	using type = X;

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