#ifndef SCF_H_DEFINED
#define SCF_H_DEFINED
/*
**++
**  FILE: SCF.H
**
**  FACILITY:  SCF
**
**  MODULE DESCRIPTION:
**
**      C include file that contains the external function prototypes and 
**	constants of the Status Code Facility API.
**
**  AUTHORS:
**
**      DJA
**
**  REVIEWERS:
**
**	     JLC
**
**  CREATION DATE:  20-Dec-1993
**
**  DESIGN ISSUES:
**
**	[@tbs@]...
**
**  [@optional module tags@]...
**
**  MODIFICATION HISTORY:
**
**	4-MAR-1994:	Removed constant MIFCON_MAXSTSTXTLEN (moved to
**			MIF_DEFS.H) [EWC]
**	05-APR-1995:	Renamed SCF_TEXT_LEN in SCF_TEXT_MAXLEN - SPR EM7928
**			[BZM]
**	13-MAR-1996:	Moved start of extern "C" block past #include. [EWC]
**	06-MAR-1997	Added SCF_EXTERN for DLL build on NT. [pms]
**	29-Dec-1997	Removed special user: include files for VMS. [pms]
**      30-OCT-2001:    Added the #undef for the SCF_DEFAULT that is defined by Windows
**                      before we define our own to remove warning.[mdd] HAB_PDCR_9412
**	[@history_entry@]...
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
//N  to the respective owners’ benefit, without intent to infringe.  
//N  
//N  For information about technical support and other ALSTOM EAI Corporation
//N  customer support services, see http://www.esca.com.
//N  
//N ===========================================================================
*/

#ifdef SCF_DLL_COMPILE
#define SCF_EXTERN __declspec(dllexport)
#else	    			/* Not a WIN32 DLL */
#define SCF_EXTERN extern
#endif				/* End of WIN32  compile test block */
/*
**
**  INCLUDE FILES
**
*/

#include <stdio.h>

#include "cca_typedefs.h"	/* common CCA typedefs and constants */
#include "scf_scf.h"		/* SCF status codes */


/*	  
**  Allow C++ users to include this file without specifying the include file
**  as an external C include file.
*/	  
#ifdef	__cplusplus
extern "C"
{
#endif

/*	 
**
** SCF API CONSTANTS	
**
*/	 

/* Maximum length of a SCF text status */

#define SCF_TEXT_MAXLEN		132

/*
** THE FOLLOWING ONE MUST NOT BE USED - NO MORE SUPPORTED
** WILL BE REMOVED IN THE NEXT RELEASE
*/
#define SCF_TEXT_LEN 		132	


#define SCF_TXT      0x0001
#define SCF_ID       0x0002
#define SCF_SEV      0x0004
#define SCF_FAC      0x0008
#undef SCF_DEFAULT //Windows has its own version of this in richedit.h that we do not want to use
#define SCF_DEFAULT  (SCF_FAC|SCF_SEV|SCF_ID|SCF_TXT)

/*	 
**
** OTHER CONSTANTS	
**
*/

/*
**  The following constants are used as bitmask values on the "options"
**  argument passed in the ScfGetText API routine. 
**  These bitmask values are reserved for internal use (to handle error 
**  conditions) and cannot be specified in the "options" argument of the 
**  ScfGetText API routine. 
**  They enable :
**  - to append the hexadecimal value of the status in the text string 
**  associated with the status value (SCF_APPEND)
**  - to set a special first character, signaling that an error treatment
**  has occured during the translation of the status (SCF_SIGNAL)
**
*/
#define SCF_APPEND   0x10	/* internal use only : */
#define SCF_SIGNAL   0x20	/* internal use only : */

/* 
**  Bitmask of the user options 
*/
#define AEMSCF_USEROPTIONS  (SCF_FAC|SCF_SEV|SCF_ID|SCF_TXT) 
				/* internal use only : */ 


/*
**  The following constants are used to specify the first character
**  of the string containing the status description
*/
#define AEMSCF_ERROR_BEGIN_STRING	"*"	/* when an error has occured */
#define AEMSCF_NORMAL_BEGIN_STRING	""	

/* 
**  SCF version 
*/
#define SCF_VERSION "1.0"

/* 
**  The following constants reflect the internal structure 
**  of a status code (a 32 bits longword value). 
**  nb : internal use only
*/

/*
** Status bit mask values : these constants are typed using _MSK_
*/
#define AEMSCF_MSK_STS_CONTROL  0x30000000	/* SCF control bits */
#define AEMSCF_MSK_STS_STS_NO   0x00007FF8	/* status sequence number */
#define AEMSCF_MSK_STS_FAC_NO   0X01FF0000	/* facility sequence number */
#define AEMSCF_MSK_STS_SEVERITY 0x00000007	/* severity bits */

/*
** Severity bit mask values : these constants are typed using _MSK_
*/
#define AEMSCF_MSK_STS_WARNING 0x0         /* WARNING */
#define AEMSCF_MSK_STS_SUCCESS 0x1         /* SUCCES */
#define AEMSCF_MSK_STS_ERROR   0x2         /* ERROR */
#define AEMSCF_MSK_STS_INFO    0x3         /* INFORMATION : future use */
#define AEMSCF_MSK_STS_FATAL   0x4         /* FATAL ERROR */

/*                                                                         
** Shift values : these constants are typed using _SHFT_  
*/                                                                         
#define AEMSCF_SHFT_STS_CONTROL   28
#define AEMSCF_SHFT_STS_FAC_NO    16
#define AEMSCF_SHFT_STS_STS_NO     3
#define AEMSCF_SHFT_STS_SEVERITY   0
#define AEMSCF_SHFT_STS_SUCCESS    0
#define AEMSCF_SHFT_STS_ERROR      1
#define AEMSCF_SHFT_STS_FATAL      2

/* 
**
**  SCF API DATA TYPES
**
*/
   typedef CCA_UINT32 SCF_STATUS;

/*
**
**  EXTERNAL FUNCTION PROTOTYPES
**
**  note : ScfGood returns TRUE if the value corresponds to an informational 
**	   VMS message.
*/

    /* Test status severity is good */
    extern CCA_BOOL   ScfGood ( SCF_STATUS status );
					
    /* Test status severity is bad */
    extern CCA_BOOL   ScfBad  ( SCF_STATUS status );	
					
    /* Test status severity is success */
    extern CCA_BOOL   ScfSuccess ( SCF_STATUS status );	

    /* Test status severity is warning */
    extern CCA_BOOL   ScfWarning ( SCF_STATUS status ); 

    /* Test status severity is error */
    extern CCA_BOOL   ScfError   ( SCF_STATUS status );	

    /* Test status severity is fatal */
    extern CCA_BOOL   ScfFatal   ( SCF_STATUS status );	


/*
**  ScfGetText : returns a text string, containing the full status code name 
**		 and text associated with a status code value.
*/
    extern SCF_STATUS   ScfGetText ( SCF_STATUS status, char text_out_str[], 
				     size_t text_out_len, int options );



/*
**  DEFINE MACROS TO HANDLE THE TEST OF STATUSES 
**
**  Fortran functions have the same name as C macros.
**  In order to avoid conflicts when compiling the fortran binding we
**  condition these macros using AEMSCF_FORTRAN_BINDING_DEFINED
*/

#ifndef AEMSCF_FORTRAN_BINDING_DEFINED


#define SCF_GOOD(status) ( ((status) & AEMSCF_MSK_STS_SUCCESS) ? TRUE:FALSE )  
#define SCF_BAD(status)  ( ((status) & AEMSCF_MSK_STS_SUCCESS) ? FALSE:TRUE ) 

#define SCF_SUCCESS(status) (((status) & AEMSCF_MSK_STS_SUCCESS) ? TRUE:FALSE)  
#define SCF_WARNING(status) (((status) & AEMSCF_MSK_STS_SEVERITY) ? FALSE:TRUE) 
#define SCF_ERROR(status)   (((status) & AEMSCF_MSK_STS_ERROR) ? TRUE:FALSE )  
#define SCF_FATAL(status)   (((status) & AEMSCF_MSK_STS_FATAL) ? TRUE:FALSE )  

#else

#define SCFGOOD(status) ( ((status) & AEMSCF_MSK_STS_SUCCESS) ? TRUE:FALSE )  
#define SCFBAD(status)  ( ((status) & AEMSCF_MSK_STS_SUCCESS) ? FALSE:TRUE ) 

#define SCFSUCCESS(status) ( ((status) & AEMSCF_MSK_STS_SUCCESS) ? TRUE:FALSE)  
#define SCFWARNING(status) ( ((status) & AEMSCF_MSK_STS_SEVERITY) ? FALSE:TRUE) 
#define SCFERROR(status)   ( ((status) & AEMSCF_MSK_STS_ERROR) ? TRUE:FALSE )  
#define SCFFATAL(status)   ( ((status) & AEMSCF_MSK_STS_FATAL) ? TRUE:FALSE )  

#endif


#ifdef	__cplusplus
}   /* end of external C C++ block */
#endif

/*
**
**  End of SCF.H
**
*/
#endif
