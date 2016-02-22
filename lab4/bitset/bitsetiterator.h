/*
 * A BitsetIterator is an iterator for Bitsets.
 * Postfix ++, ==, and -> are not implemented.
 */
#include <iostream>
#ifndef BITSET_ITERATOR_H
#define BITSET_ITERATOR_H

#include "bitreference.h"
#include <iterator>

class BitsetIterator : public std::iterator<std::forward_iterator_tag, bool> {
public:
	BitsetIterator(Bitset::BitStorage* pb, std::size_t p) : ref(pb, p) {}
	
	bool operator!=(const BitsetIterator& bsi) const {
		// std::cout <<  "!=" << std::endl;
		return bsi.ref.pos!=ref.pos;
	}
	
	BitsetIterator& operator++() {
		// std::cout <<  "++" << std::endl;
		++(ref.pos);
		return *this;
	}
	
	BitReference operator*() {
		// std::cout <<  "*" << std::endl;
		return ref;
	}
	
	BitsetIterator& operator=(const BitsetIterator& rhs) {
		// std::cout <<  "=" << std::endl;
		ref.p_bits = rhs.ref.p_bits;
		ref.pos = rhs.ref.pos;
		return *this;
	}
private:
	BitReference ref;
};

#endif

