#ifndef _RANGE_H_
#define _RANGE_H_

class Range {
public:
	Range(int, int);
	Range(const Range&);
	int left, right;
};

#endif