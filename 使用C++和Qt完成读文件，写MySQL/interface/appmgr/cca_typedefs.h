#ifndef CCA_TYPEDEFS_INCLUDED
#define CCA_TYPEDEFS_INCLUDED 
/*
**++
**  FILENAME: CCA_TYPEDEFS.H
**
**  PURPOSE: 
**
**      This file defines the standard base types for use in CCA software. The
**	criteria for inclusion in this file are as follows:
**	
**	- We want to define those types that are low level yet not associated
**	with a specific API. Except for the types defined herein, any other
**	types that are used should be either as a result of a formal API (in
**	which case the type will be obtained through the API's header file),
**	or internal to an implementation. 
**
**	- We will only define types when there is a clear advantage and
**	reason for the type. For example, we will not define an INT type that
**	is merely "int" by definition. This would buy us nothing. On the
**	other hand defining a type that is by definition always 16 bits
**	regardless of the platform is of value, and is exactly the class of
**	types defined herein.
**
**	- We will prefix the type names with CCA_. This should provide us
**	confidence that the types will not collide with types dragged in by
**	any future 3rd party interfaces.
**
**	NOTE: conditional logic for 64 bit systems will be added later. Such
**	logic will be required in order to define the bit specific types
**	properly in a 64 bit environment.
**
**  MODIFICATION HISTORY:
**
**      11/18/93:  Created.  [krm]
**      12/5/94:   Removed casting to CCA_BOOL in definition of TRUE and FALSE,
**	           as it conflicts with more common definitions of these
**		   macros. EM7865 [krm]    
**	02/24/95:  Added CCA_LONG_HANDLE to accomodate memory addresses
**		   on any platform (CCA_HANDLE is restricted to 32 bits
**		   max).  [pzm]
**	5/31/96:   Add CCA_USERARG typedef, so that we can eliminate the
**	           confusion concerning whether the userarg is passed by
**		   reference or value - it is passed by value in C. [krm]
** 6/21/02:  Changed typdef of CCA_LONG_HANDLE from unsigned long to size_t
**           to support Window 64bit where a the size of a long is only 
**           32 bits [apj]
**	[@history_entry@]...
**
**--
*/
/*
//N ===========================================================================
//N  
//N   Copyright Notice
//N  
//N  Copyright (c) 1993, 2003 ALSTOM EAI Corporation.All Rights Reserved.
//N  
//N  ALSTOM EAI CORPORATION PROPRIETARY AND TRADE-SECRET INFORMATION.  
//N  DO NOT COPY, STORE IN A RETRIEVAL SYSTEM, TRANSMIT OR DISCLOSE TO
//N  ANY THIRD PARTY WITHOUT THE PRIOR WRITTEN PERMISSION FROM AN OFFICER
//N  OF ALSTOM EAI CORPORATION.
//N   
//N  _________________________________________________________________
//N  
//N  Trademarks
//N  
//N  ESCA and HABITAT  are registered trademarks of ALSTOM EAI Corporation.
//N  The e-terra family of products and services are trademarks and/or 
//N  service marks of ALSTOM EAI Corporation.
//N   
//N  Other product and company names in these materials may be trademarks
//N  or registered trademarks of other companies, and are the property 
//N  of their respective owners.  They are used only for explanation and 
//N  to the respective owners?benefit, without intent to infringe.  
//N  
//N  For information about technical support and other ALSTOM EAI Corporation
//N  customer support services, see http://www.esca.com.
//N  
//N ===========================================================================
*/

/*
**  As this file does not contain any function prototypes, there is no need
**  to do extern "C" for C++ users.
*/

/*	  
**  There is wide spread use of handles throughout CCA APIs. Each of those
**  handles should be defined using this type. This means that those APIs
**  should define there own type that is based on this type. For example:
**
**  typedef CCA_HANDLE OSAL_LOCKHANDLE;
**
**  NOTE:  This applies to "handles" only.  Handles must be
**  distinguished from pointers because on a 64 bit platform, you could
**  not hold a memory address in a 32 bit integer.  Handles are used here
**  extensively because they allow a 32 bit value to be passed back into a
**  FORTRAN routine (and FORTRAN is only capable of handling a 32 bit
**  integer).  If you need to represent a memory address within a handle,
**  you must use CCA_LONG_HANDLE.  That type will always be large enough to
**  store an address on the host platform.  Its length is not fixed, but is
**  at least 32 bits AND it can NOT be passed back to a FORTRAN routine.
*/	

#include <stddef.h> /* to resolve size_t */
  
typedef unsigned int   CCA_HANDLE; 
typedef size_t CCA_LONG_HANDLE;

/*	  
**  CCA_USERARG - The CCA API standard calls for a "userarg" whenever a
**  callback is involved. The purpose of a userarg is to provide a mechanism
**  for the user to pass data from the initiating function to the callback
**  function.  The type of a userarg is generic and is guarenteed to be large
**  enough to hold an address in C, and an INTEGER*4 in Fortran.
*/	  
typedef void *		    CCA_USERARG;

/*	  
**  The following are intended for use within protocols, where the number of
**  bytes is critical. When building protocols, the definition of the message
**  structures must be exact, and operating system independent. That is why
**  these types exist. The protocol must identify whether the data within is
**  in big endian or little endian.
*/	  


/*	  
**  VAX C does not support signed char - it is the default.
*/	  
#if defined(VAXC)
typedef char		    CCA_INT8;
#else
typedef signed char	    CCA_INT8;
#endif

typedef unsigned char	    CCA_UINT8;

typedef short int	    CCA_INT16;
typedef unsigned short int  CCA_UINT16;	    

typedef int		    CCA_INT32;
typedef unsigned int	    CCA_UINT32;	    

/*	  
**  The following type is for use in describing boolean values. We define it as
**  a type so that it is available in a standard way to all APIs. Its length is
**  not fixed, thus it should not be used in protocols. The bool value should
**  be interpreted (i.e. tested) using standard C logical expressions. i.e. 0
**  equals false, and anything else is TRUE. However, it is strongly
**  recommended that when a CCA_BOOL type is used that it is used to represent
**  only two values - true or false - do not make use of the knowledge that a
**  all non-zero values are treated the same!
*/	  
typedef int	            CCA_BOOL;

/*	  
**  The following macros should be used to set CCA_BOOL types. As the TRUE
**  state is multi-valued, code should never test for a CCA_BOOL value being
**  equal to "TRUE"!
**
**  Prior to ANSI C these macros were defined in stdio.h. The assumption we
**  are making now is that in the future, if a third party product defines
**  TRUE and FALSE, they will also do it in the same manner as C used to.
**  Otherwise our only option is to define a CCA_TRUE and CCA_FALSE macro,
**  which somehow feels ugly.
*/	  
#ifndef GTRUE 
#define GTRUE  1
#else
#if GTRUE != 1
/*	  
**  We do not simply allow any non-zero value, because it would then not work
**  for setting bit fields. For example, if TRUE = 2, then an assignment of
**  int k:1  k = TRUE would result in k = 0.
*/	  
#error "Intrinsic definition of TRUE is different than CCA_TYPEDEF value of 1"
#endif 
#endif

#ifndef GFALSE
#define GFALSE 0 
#else
#if GFALSE != 0
#error "Intrinsic definition of FALSE is different than CCA_TYPEDEF value of 0"
#endif 
#endif

/*
**  This is temporary and will be removed when SCF is finished.
*/
typedef unsigned int CCA_STATUS;

/*
**  VAX C has enhanced octaword-aligned memory management functions;
**  we will use these if using VAX C.
*/
#if defined(VAXC)

#define malloc  VAXC$MALLOC_OPT
#define calloc	VAXC$CALLOC_OPT
#define free	VAXC$FREE_OPT
#define	cfree	VAXC$CFREE_OPT
#define realloc	VAXC$REALLOC_OPT

#endif		/* end VAX C test block */

/*
**  End of CCA_TYPEDEFS.H.
*/
#endif 
