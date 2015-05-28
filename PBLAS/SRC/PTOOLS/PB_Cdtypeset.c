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

__thread int     __dsetup=0;
__thread PBTYP_T __dTypeStruct;
__thread double  __dzero, __done, __dnegone;


PBTYP_T * PB_Cdtypeset()
{
/*
*  Purpose
*  =======
*
*  PB_Cdtypeset on the first call initializes a static structure contai-
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
//   static PBTYP_T __dTypeStruct;
//   static double  zero, one, negone;
/* ..
*  .. Executable Statements ..
*
*/
   if( __dsetup ) return( &__dTypeStruct );

   __dsetup = 1;

   __dTypeStruct.type = DREAL;
   __dTypeStruct.usiz = sizeof( double );
   __dTypeStruct.size = sizeof( double );

   __dzero   = ZERO;
   __done    =  ONE;
   __dnegone = -ONE;

   __dTypeStruct.zero      = (char *) (&__dzero);
   __dTypeStruct.one       = (char *) (&__done);
   __dTypeStruct.negone    = (char *) (&__dnegone);

   __dTypeStruct.Cgesd2d   = Cdgesd2d;
   __dTypeStruct.Cgerv2d   = Cdgerv2d;
   __dTypeStruct.Cgebs2d   = Cdgebs2d;
   __dTypeStruct.Cgebr2d   = Cdgebr2d;
   __dTypeStruct.Cgsum2d   = Cdgsum2d;

   __dTypeStruct.Fmmadd    = dmmadd_;
   __dTypeStruct.Fmmcadd   = dmmcadd_;
   __dTypeStruct.Fmmtadd   = dmmtadd_;
   __dTypeStruct.Fmmtcadd  = dmmtcadd_;
   __dTypeStruct.Fmmdda    = dmmdda_;
   __dTypeStruct.Fmmddac   = dmmddac_;
   __dTypeStruct.Fmmddat   = dmmddat_;
   __dTypeStruct.Fmmddact  = dmmddact_;

   __dTypeStruct.Fcshft    = dcshft_;
   __dTypeStruct.Frshft    = drshft_;

   __dTypeStruct.Fvvdotu   = dvvdot_;
   __dTypeStruct.Fvvdotc   = dvvdot_;

   __dTypeStruct.Fset      = dset_;

   __dTypeStruct.Ftzpad    = dtzpad_;
   __dTypeStruct.Ftzpadcpy = dtzpadcpy_;
   __dTypeStruct.Ftzscal   = dtzscal_;
   __dTypeStruct.Fhescal   = dtzscal_;
   __dTypeStruct.Ftzcnjg   = dtzscal_;

   __dTypeStruct.Faxpy     = daxpy_;
   __dTypeStruct.Fcopy     = dcopy_;
   __dTypeStruct.Fswap     = dswap_;

   __dTypeStruct.Fgemv     = dgemv_;
   __dTypeStruct.Fsymv     = dsymv_;
   __dTypeStruct.Fhemv     = dsymv_;
   __dTypeStruct.Ftrmv     = dtrmv_;
   __dTypeStruct.Ftrsv     = dtrsv_;
   __dTypeStruct.Fagemv    = dagemv_;
   __dTypeStruct.Fasymv    = dasymv_;
   __dTypeStruct.Fahemv    = dasymv_;
   __dTypeStruct.Fatrmv    = datrmv_;

   __dTypeStruct.Fgerc     = dger_;
   __dTypeStruct.Fgeru     = dger_;
   __dTypeStruct.Fsyr      = dsyr_;
   __dTypeStruct.Fher      = dsyr_;
   __dTypeStruct.Fsyr2     = dsyr2_;
   __dTypeStruct.Fher2     = dsyr2_;

   __dTypeStruct.Fgemm     = dgemm_;
   __dTypeStruct.Fsymm     = dsymm_;
   __dTypeStruct.Fhemm     = dsymm_;
   __dTypeStruct.Fsyrk     = dsyrk_;
   __dTypeStruct.Fherk     = dsyrk_;
   __dTypeStruct.Fsyr2k    = dsyr2k_;
   __dTypeStruct.Fher2k    = dsyr2k_;
   __dTypeStruct.Ftrmm     = dtrmm_;
   __dTypeStruct.Ftrsm     = dtrsm_;

   return( &__dTypeStruct );
/*
*  End of PB_Cdtypeset
*/
}
