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

__thread int     __csetup=0;
__thread PBTYP_T __cTypestruct;
__thread cmplx   __czero, __cone, __cnegone;


PBTYP_T * PB_Cctypeset()
{
/*
*  Purpose
*  =======
*
*  PB_Cctypeset on the first call initializes a static structure contai-
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
//   static PBTYP_T __cTypestruct;
//   static cmplx   zero, one, negone;
/* ..
*  .. Executable Statements ..
*
*/
   if( __csetup ) return( &__cTypestruct );

   __csetup = 1;

   __cTypestruct.type = SCPLX;
   __cTypestruct.usiz = sizeof( float );
   __cTypestruct.size = sizeof( cmplx );

   __czero  [REAL_PART] = ZERO;
   __czero  [IMAG_PART] = ZERO;
   __cone   [REAL_PART] =  ONE;
   __cone   [IMAG_PART] = ZERO;
   __cnegone[REAL_PART] = -ONE;
   __cnegone[IMAG_PART] = ZERO;

   __cTypestruct.zero      = ((char *) __czero);
   __cTypestruct.one       = ((char *) __cone);
   __cTypestruct.negone    = ((char *) __cnegone);

   __cTypestruct.Cgesd2d   = Ccgesd2d;
   __cTypestruct.Cgerv2d   = Ccgerv2d;
   __cTypestruct.Cgebs2d   = Ccgebs2d;
   __cTypestruct.Cgebr2d   = Ccgebr2d;
   __cTypestruct.Cgsum2d   = Ccgsum2d;

   __cTypestruct.Fmmadd    = cmmadd_;
   __cTypestruct.Fmmcadd   = cmmcadd_;
   __cTypestruct.Fmmtadd   = cmmtadd_;
   __cTypestruct.Fmmtcadd  = cmmtcadd_;
   __cTypestruct.Fmmdda    = cmmdda_;
   __cTypestruct.Fmmddac   = cmmddac_;
   __cTypestruct.Fmmddat   = cmmddat_;
   __cTypestruct.Fmmddact  = cmmddact_;

   __cTypestruct.Fcshft    = ccshft_;
   __cTypestruct.Frshft    = crshft_;

   __cTypestruct.Fvvdotu   = cvvdotu_;
   __cTypestruct.Fvvdotc   = cvvdotc_;

   __cTypestruct.Fset      = cset_;

   __cTypestruct.Ftzpad    = ctzpad_;
   __cTypestruct.Ftzpadcpy = ctzpadcpy_;
   __cTypestruct.Ftzscal   = ctzscal_;
   __cTypestruct.Fhescal   = chescal_;
   __cTypestruct.Ftzcnjg   = ctzcnjg_;

   __cTypestruct.Faxpy     = caxpy_;
   __cTypestruct.Fcopy     = ccopy_;
   __cTypestruct.Fswap     = cswap_;

   __cTypestruct.Fgemv     = cgemv_;
   __cTypestruct.Fsymv     = csymv_;
   __cTypestruct.Fhemv     = chemv_;
   __cTypestruct.Ftrmv     = ctrmv_;
   __cTypestruct.Ftrsv     = ctrsv_;
   __cTypestruct.Fagemv    = cagemv_;
   __cTypestruct.Fasymv    = casymv_;
   __cTypestruct.Fahemv    = cahemv_;
   __cTypestruct.Fatrmv    = catrmv_;

   __cTypestruct.Fgerc     = cgerc_;
   __cTypestruct.Fgeru     = cgeru_;
   __cTypestruct.Fsyr      = csyr_;
   __cTypestruct.Fher      = cher_;
   __cTypestruct.Fsyr2     = csyr2_;
   __cTypestruct.Fher2     = cher2_;

   __cTypestruct.Fgemm     = cgemm_;
   __cTypestruct.Fsymm     = csymm_;
   __cTypestruct.Fhemm     = chemm_;
   __cTypestruct.Fsyrk     = csyrk_;
   __cTypestruct.Fherk     = cherk_;
   __cTypestruct.Fsyr2k    = csyr2k_;
   __cTypestruct.Fher2k    = cher2k_;
   __cTypestruct.Ftrmm     = ctrmm_;
   __cTypestruct.Ftrsm     = ctrsm_;

   return( &__cTypestruct );
/*
*  End of PB_Cctypeset
*/
}
