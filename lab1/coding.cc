#include "coding.h"

/* For any character c, encode(c) is a character different from c */
unsigned char Coding::encode(unsigned char c) {
	return ++c;
}
/* For any character c, decode(encode(c)) == c */
unsigned char Coding::decode(unsigned char c) {
	return --c;
}