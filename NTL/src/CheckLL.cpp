

#define NTL_HAVE_LL_TYPE
// DIRT: we need to define this here so that ctools.h
// does not undefine the LL type macros

#include <NTL/ctools.h>

#ifdef NTL_DISABLE_LONGLONG
#error "LL_TYPE disabled"
#endif

void touch(unsigned long& x);
void touch(long& x);

int main()
{
   if (sizeof(NTL_ULL_TYPE) != 2*sizeof(long)) return -1;

   unsigned long x1 = -1L; 
   unsigned long x2 = -1L; 
   unsigned long x3 = -1L;
   unsigned long x4 = -1L;

   touch(x1);
   touch(x2);
   touch(x3);
   touch(x4);

   NTL_ULL_TYPE xx = ((NTL_ULL_TYPE) x1)*((NTL_ULL_TYPE) x2);
   NTL_ULL_TYPE yy = xx - ((((NTL_ULL_TYPE) x3) << (NTL_BITS_PER_LONG+1)) + 1); 

   if (yy != 0) 
      return -1;

   if (xx/x3 != x4)
      return -1;

   return 0;
}



