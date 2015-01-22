/* Initializer/finalizer sample for MSVC and GCC.
2010 Joe Lowe. Released into the public domain.
*/

//callig methods before and after main()

#include <stdio.h>

#ifdef _MSC_VER

#define CCALL __cdecl
#pragma section(".CRT$XCU",read)
#define INITIALIZER(f) \
   static void __cdecl f(void); \
   __declspec(allocate(".CRT$XCU")) void (__cdecl*f##_)(void) = f; \
   static void __cdecl f(void)

#elif defined(__GNUC__)

#define CCALL
#define INITIALIZER(f) \
   static void f(void) __attribute__((constructor)); \
   static void f(void)

#endif

static void CCALL finalize(void)
{
	printf("finalize\n");
}

INITIALIZER(initialize)
{
	printf("initialize\n");
	atexit(finalize);
}


int CCALL main(int argc, const char*const* argv)
{
	printf("main\n");
	return 0;
}
