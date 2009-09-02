/*============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

===============================================================================*/
/****************************************************************************

   Copyright (C) 2009 William Hart

*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <mpir.h>
#include "flint.h"
#include "ulong_extras.h"

int main(void)
{
   int result;
   printf("sqrt....");
   fflush(stdout);

   for (ulong i = 0; i < 100000UL; i++)
   {
      mp_limb_t a, s1, s2;
      mpz_t a_m, s2_m;
      mp_limb_signed_t exp;

      mpz_init(a_m);
      mpz_init(s2_m);
      
      a = n_randtest();
      
      s1 = n_sqrt(a);

      mpz_set_ui(a_m, a);
      mpz_sqrt(s2_m, a_m);
      s2 = mpz_get_ui(s2_m);
      
      result = (s1 == s2);

      if (!result)
      {
         printf("FAIL\n");
         printf("a = %lu, s1 = %ld, s2 = %lu\n", a, s1, s2); 
         abort();
      }

      mpz_clear(a_m);
      mpz_clear(s2_m);
   }

   for (ulong i = 0; i < 100000UL; i++)
   {
      mp_limb_t a, s1, s2, bits;
      mpz_t a_m, s2_m;
      mp_limb_signed_t exp;

      mpz_init(a_m);
      mpz_init(s2_m);
      
      bits = n_randint(33);
      a = n_randbits(bits);
      a = a*a;
      a += (n_randint(100) - 50);
      s1 = n_sqrt(a);

      mpz_set_ui(a_m, a);
      mpz_sqrt(s2_m, a_m);
      s2 = mpz_get_ui(s2_m);
      
      result = (s1 == s2);

      if (!result)
      {
         printf("FAIL2\n");
         printf("a = %lu, s1 = %ld, s2 = %lu\n", a, s1, s2); 
         abort();
      }

      mpz_clear(a_m);
      mpz_clear(s2_m);
   }

   printf("PASS\n");
   return 0;
}