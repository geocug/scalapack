/* ---------------------------------------------------------------------
*
*  -- PBLAS auxiliary routine (version 2.0) --
*     University of Tennessee, Knoxville, Oak Ridge National Laboratory,
*     and University of California, Berkeley.
*     April 1, 1998
*
*  ---------------------------------------------------------------------
*/
/*
*  Include files
*/
#include "../pblas.h"
#include "../PBpblas.h"
#include "../PBtools.h"
#include "../PBblacs.h"
#include "../PBblas.h"

__thread int     __ssetup=0;
__thread PBTYP_T __sTypeStruct;
__thread float   __szero, __sone, __snegone;


PBTYP_T * PB_Cstypeset()
{
/*
*  Purpose
*  =======
*
*  PB_Cstypeset on the first call initializes a static structure contai-
*  ning typed information and returns a pointer to it.  The  other calls
*  to this routine just returns this pointer.
*
*  -- Written on April 1, 1998 by
*     R. Clint Whaley, University of Tennessee, Knoxville 37996, USA.
*
*  ---------------------------------------------------------------------
*/
/*
*  .. Local Scalars ..
*/
//   static int     setup=0;
//   static PBTYP_T __sTypeStruct;
//   static float   zero, one, negone;
/* ..
*  .. Executable Statements ..
*
*/
   if( __ssetup ) return( &__sTypeStruct );

   __ssetup = 1;

   __sTypeStruct.type = SREAL;
   __sTypeStruct.usiz = sizeof( float );
   __sTypeStruct.size = sizeof( float );

   __szero   = ZERO;
   __sone    =  ONE;
   __snegone = -ONE;

   __sTypeStruct.zero      = (char *) (&__szero);
   __sTypeStruct.one       = (char *) (&__sone);
   __sTypeStruct.negone    = (char *) (&__snegone);

   __sTypeStruct.Cgesd2d   = Csgesd2d;
   __sTypeStruct.Cgerv2d   = Csgerv2d;
   __sTypeStruct.Cgebs2d   = Csgebs2d;
   __sTypeStruct.Cgebr2d   = Csgebr2d;
   __sTypeStruct.Cgsum2d   = Csgsum2d;

   __sTypeStruct.Fmmadd    = smmadd_;
   __sTypeStruct.Fmmcadd   = smmcadd_;
   __sTypeStruct.Fmmtadd   = smmtadd_;
   __sTypeStruct.Fmmtcadd  = smmtcadd_;
   __sTypeStruct.Fmmdda    = smmdda_;
   __sTypeStruct.Fmmddac   = smmddac_;
   __sTypeStruct.Fmmddat   = smmddat_;
   __sTypeStruct.Fmmddact  = smmddact_;

   __sTypeStruct.Fcshft    = scshft_;
   __sTypeStruct.Frshft    = srshft_;

   __sTypeStruct.Fvvdotu   = svvdot_;
   __sTypeStruct.Fvvdotc   = svvdot_;

   __sTypeStruct.Fset      = sset_;

   __sTypeStruct.Ftzpad    = stzpad_;
   __sTypeStruct.Ftzpadcpy = stzpadcpy_;
   __sTypeStruct.Ftzscal   = stzscal_;
   __sTypeStruct.Fhescal   = stzscal_;
   __sTypeStruct.Ftzcnjg   = stzscal_;

   __sTypeStruct.Faxpy     = saxpy_;
   __sTypeStruct.Fcopy     = scopy_;
   __sTypeStruct.Fswap     = sswap_;

   __sTypeStruct.Fgemv     = sgemv_;
   __sTypeStruct.Fsymv     = ssymv_;
   __sTypeStruct.Fhemv     = ssymv_;
   __sTypeStruct.Ftrmv     = strmv_;
   __sTypeStruct.Ftrsv     = strsv_;
   __sTypeStruct.Fagemv    = sagemv_;
   __sTypeStruct.Fasymv    = sasymv_;
   __sTypeStruct.Fahemv    = sasymv_;
   __sTypeStruct.Fatrmv    = satrmv_;

   __sTypeStruct.Fgerc     = sger_;
   __sTypeStruct.Fgeru     = sger_;
   __sTypeStruct.Fsyr      = ssyr_;
   __sTypeStruct.Fher      = ssyr_;
   __sTypeStruct.Fsyr2     = ssyr2_;
   __sTypeStruct.Fher2     = ssyr2_;

   __sTypeStruct.Fgemm     = sgemm_;
   __sTypeStruct.Fsymm     = ssymm_;
   __sTypeStruct.Fhemm     = ssymm_;
   __sTypeStruct.Fsyrk     = ssyrk_;
   __sTypeStruct.Fherk     = ssyrk_;
   __sTypeStruct.Fsyr2k    = ssyr2k_;
   __sTypeStruct.Fher2k    = ssyr2k_;
   __sTypeStruct.Ftrmm     = strmm_;
   __sTypeStruct.Ftrsm     = strsm_;

   return( &__sTypeStruct );
/*
*  End of PB_Cstypeset
*/
}
