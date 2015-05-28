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

__thread int     __isetup=0;
__thread PBTYP_T __iTypeStruct;
__thread int     __izero, __ione, __inegone;


PBTYP_T * PB_Citypeset()
{
/*
*  Purpose
*  =======
*
*  PB_Citypeset on the first call initializes a static structure contai-
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
//   static PBTYP_T __iTypeStruct;
//   static int     zero, one, negone;
/* ..
*  .. Executable Statements ..
*
*/
   if( __isetup ) return( &__iTypeStruct );

   __isetup = 1;

   __iTypeStruct.type = INT;
   __iTypeStruct.usiz = sizeof( int );
   __iTypeStruct.size = sizeof( int );
   __izero   =  0;
   __ione    =  1;
   __inegone = -1;

   __iTypeStruct.zero      = (char *) (&__izero);
   __iTypeStruct.one       = (char *) (&__ione);
   __iTypeStruct.negone    = (char *) (&__inegone);

   __iTypeStruct.Cgesd2d   = Cigesd2d;
   __iTypeStruct.Cgerv2d   = Cigerv2d;
   __iTypeStruct.Cgebs2d   = Cigebs2d;
   __iTypeStruct.Cgebr2d   = Cigebr2d;
   __iTypeStruct.Cgsum2d   = Cigsum2d;

   __iTypeStruct.Fmmadd    = immadd_;
   __iTypeStruct.Fmmcadd   = immadd_;
   __iTypeStruct.Fmmtadd   = immtadd_;
   __iTypeStruct.Fmmtcadd  = immtadd_;
   __iTypeStruct.Fmmdda    = immdda_;
   __iTypeStruct.Fmmddac   = immdda_;
   __iTypeStruct.Fmmddat   = immddat_;
   __iTypeStruct.Fmmddact  = immddat_;

   __iTypeStruct.Fcshft    = NULL;
   __iTypeStruct.Frshft    = NULL;

   __iTypeStruct.Fvvdotu   = NULL;
   __iTypeStruct.Fvvdotc   = NULL;

   __iTypeStruct.Fset      = NULL;

   __iTypeStruct.Ftzpad    = NULL;
   __iTypeStruct.Ftzpadcpy = NULL;

   __iTypeStruct.Ftzscal   = NULL;
   __iTypeStruct.Fhescal   = NULL;
   __iTypeStruct.Ftzcnjg   = NULL;

   __iTypeStruct.Faxpy     = NULL;
   __iTypeStruct.Fcopy     = NULL;
   __iTypeStruct.Fswap     = NULL;

   __iTypeStruct.Fgemv     = NULL;
   __iTypeStruct.Fsymv     = NULL;
   __iTypeStruct.Fhemv     = NULL;
   __iTypeStruct.Ftrmv     = NULL;
   __iTypeStruct.Ftrsv     = NULL;
   __iTypeStruct.Fagemv    = NULL;
   __iTypeStruct.Fasymv    = NULL;
   __iTypeStruct.Fahemv    = NULL;
   __iTypeStruct.Fatrmv    = NULL;

   __iTypeStruct.Fgerc     = NULL;
   __iTypeStruct.Fgeru     = NULL;
   __iTypeStruct.Fsyr      = NULL;
   __iTypeStruct.Fher      = NULL;
   __iTypeStruct.Fsyr2     = NULL;
   __iTypeStruct.Fher2     = NULL;

   __iTypeStruct.Fgemm     = NULL;
   __iTypeStruct.Fsymm     = NULL;
   __iTypeStruct.Fhemm     = NULL;
   __iTypeStruct.Fsyrk     = NULL;
   __iTypeStruct.Fherk     = NULL;
   __iTypeStruct.Fsyr2k    = NULL;
   __iTypeStruct.Fher2k    = NULL;
   __iTypeStruct.Ftrmm     = NULL;
   __iTypeStruct.Ftrsm     = NULL;

   return( &__iTypeStruct );
/*
*  End of PB_Citypeset
*/
}
