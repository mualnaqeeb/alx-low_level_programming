#ifndef variadic_functions_h
#define variadic_functions_h
#include <stdarg.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
/**
 * struct types_t - Struct types
 *
 * @types: The operator
 * @f: The function associated
 */

typedef struct types
{
	char z;
	void (*f)(va_list);
} types_t;

#endif

