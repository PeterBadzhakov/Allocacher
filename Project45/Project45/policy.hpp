#pragma once

#include <iostream>          

template <typename T, size_type block_size>
class policy {
	// TODO: convert to typedef
	using type = T;                            
	using value_type = type;                   
	using pointer = value_type*;               
	using reference = value_type&;             
	using const_reference = const value_type&; 
	using size_type = std::size_t;             
	using difference_type = std::ptrdiff_t;

	constexpr static size_type bucket_size = 64;
	constexpr static size_type bucket_count = block_size / bucket_size;
	using bucket = std::stack<type, std::array<uint8_t, bucket_size>>;
	using sequence = std::array<bucket, bucket_count>;

	constexpr bool taken = true;
	constexpr bool garbage = false;
	using slot_status = bool;

private:
	// Main block is split into array of stacks.
	sequence address_space;
	
	struct metadata
	{
		// Current bucket to fill until full.
		bucket* cur_bucket;
		// Sorted sequence, least empty first.
		// Keep pairs of bucket and their empty space left.
		std::array<std::pair<bucket* ptr, size_type>, bucket_count> heuristic;
		// Flag each slot in each bucket.
		std::array<std::array<slot_status, bucket_size>, bucket_count> status_bitmap;
	};

#ifdef _DEBUG
	struct d_metadata
	{
		/*
		...
		*/
	};
#endif
};