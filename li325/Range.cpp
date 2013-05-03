#include "Range.h"

Range::Range(int left, int right) {
	this->left = left;
	this->right = right;
}
Range::Range(const Range& src) {
	left = src.left;
	right = src.right;
}