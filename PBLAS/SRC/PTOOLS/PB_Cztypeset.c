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


__thread int     __zsetup=0;
__thread PBTYP_T __zTypeStruct;
__thread cmplx16 __zzero, __zone, __znegone;


PBTYP_T * PB_Cztypeset()
{
/*
*  Purpose
*  =======
*
*  PB_Cztypeset on the first call initializes a static structure contai-
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
//   static PBTYP_T __zTypeStruct;
//   static cmplx16 zero, one, negone;
/* ..
*  .. Executable Statements ..
*
*/
   if( __zsetup ) return( &__zTypeStruct );

   __zsetup = 1;

   __zTypeStruct.type = DCPLX;
   __zTypeStruct.usiz = sizeof( double  );
   __zTypeStruct.size = sizeof( cmplx16 );

   __zzero  [REAL_PART] = ZERO;
   __zzero  [IMAG_PART] = ZERO;
   __zone   [REAL_PART] =  ONE;
   __zone   [IMAG_PART] = ZERO;
   __znegone[REAL_PART] = -ONE;
   __znegone[IMAG_PART] = ZERO;

   __zTypeStruct.zero      = ((char *) __zzero);
   __zTypeStruct.one       = ((char *) __zone);
   __zTypeStruct.negone    = ((char *) __znegone);

   __zTypeStruct.Cgesd2d   = Czgesd2d;
   __zTypeStruct.Cgerv2d   = Czgerv2d;
   __zTypeStruct.Cgebs2d   = Czgebs2d;
   __zTypeStruct.Cgebr2d   = Czgebr2d;
   __zTypeStruct.Cgsum2d   = Czgsum2d;

   __zTypeStruct.Fmmadd    = zmmadd_;
   __zTypeStruct.Fmmcadd   = zmmcadd_;
   __zTypeStruct.Fmmtadd   = zmmtadd_;
   __zTypeStruct.Fmmtcadd  = zmmtcadd_;
   __zTypeStruct.Fmmdda    = zmmdda_;
   __zTypeStruct.Fmmddac   = zmmddac_;
   __zTypeStruct.Fmmddat   = zmmddat_;
   __zTypeStruct.Fmmddact  = zmmddact_;

   __zTypeStruct.Fcshft    = zcshft_;
   __zTypeStruct.Frshft    = zrshft_;

   __zTypeStruct.Fvvdotu   = zvvdotu_;
   __zTypeStruct.Fvvdotc   = zvvdotc_;

   __zTypeStruct.Fset      = zset_;

   __zTypeStruct.Ftzpad    = ztzpad_;
   __zTypeStruct.Ftzpadcpy = ztzpadcpy_;
   __zTypeStruct.Ftzscal   = ztzscal_;
   __zTypeStruct.Fhescal   = zhescal_;
   __zTypeStruct.Ftzcnjg   = ztzcnjg_;

   __zTypeStruct.Faxpy     = zaxpy_;
   __zTypeStruct.Fcopy     = zcopy_;
   __zTypeStruct.Fswap     = zswap_;

   __zTypeStruct.Fgemv     = zgemv_;
   __zTypeStruct.Fsymv     = zsymv_;
   __zTypeStruct.Fhemv     = zhemv_;
   __zTypeStruct.Ftrmv     = ztrmv_;
   __zTypeStruct.Ftrsv     = ztrsv_;
   __zTypeStruct.Fagemv    = zagemv_;
   __zTypeStruct.Fasymv    = zasymv_;
   __zTypeStruct.Fahemv    = zahemv_;
   __zTypeStruct.Fatrmv    = zatrmv_;

   __zTypeStruct.Fgerc     = zgerc_;
   __zTypeStruct.Fgeru     = zgeru_;
   __zTypeStruct.Fsyr      = zsyr_;
   __zTypeStruct.Fher      = zher_;
   __zTypeStruct.Fsyr2     = zsyr2_;
   __zTypeStruct.Fher2     = zher2_;

   __zTypeStruct.Fgemm     = zgemm_;
   __zTypeStruct.Fsymm     = zsymm_;
   __zTypeStruct.Fhemm     = zhemm_;
   __zTypeStruct.Fsyrk     = zsyrk_;
   __zTypeStruct.Fherk     = zherk_;
   __zTypeStruct.Fsyr2k    = zsyr2k_;
   __zTypeStruct.Fher2k    = zher2k_;
   __zTypeStruct.Ftrmm     = ztrmm_;
   __zTypeStruct.Ftrsm     = ztrsm_;

   return( &__zTypeStruct );
/*
*  End of PB_Cztypeset
*/
}
