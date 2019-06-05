#ifndef APPMGR_H_INCLUDED
#define APPMGR_H_INCLUDED
/*
**++
**  FILENAME:  appmgr.h
**
**
**      Eric Fleuret
**      Sean MacLellan
**
**  REVIEWERS:
**
**      {@tbs@}
**
**  DESCRIPTION:
**
**      Header file for the APPMGR API.
**
**      Defines the following:
**      - APPMGR-specific constants
**      - APPMGR-specific structures
**      - APPMGR API function prototypes
**
**  DESIGN ISSUES:
**
**			    NOTE FOR GAIA 4.x USERS:
**	    The only functions herein that are supported on GAIA 4.x 
**	    are the get_family, get_application, and syncabort functions.
**	    Any attempt to use any of the other functions will fail, and
**	    no support for them is implied by their being listed here, or
**	    the presence of object code that satisfies links to them.
**				    END NOTE
**				    
**  MODIFICATION HISTORY:
**
**	23-FEB-1996: Overhauled names to conform to RCSE naming conventions.
**		     [EWC].
**	27-FEB-1996: Added OpenVMS specific includes and modified
**		     APPMGR_VMS_PRIV_SET to use VMS "privdef" union (as
**		     defined in prvdef.h). [EWC]
**	01-MAY-1996: Added include of APPMGR status codes. [NOK]
**	01-MAY-1996: Change struct tag name to 'openvms' to avoid
**		     compilation error. [RSP]
**	22-MAY-1996: Added appmgr_get_application_name and
**		     appmgr_get_family_name. [NOK]
**	18-JUN-1996: Added appmgr_task_is_up() [erf]
**	09-JUL-1996: Added ".h" to "prcdef" and "prvdef".  [tsc]
**	09-JAN-1997: Task Information structure now contains the static
**		     task name and the application/family context. [HA6780]
**		     Change APPMGR_LOCATION_MAXLEN to 128 according to
**		     the specifications, and consequently increase
**		     APPMGR_FILESPEC_MAXLEN. [HA6885] [nok]
**	10-FEB-1997: Added appmgr_get_console_name. [RCSE069] [nok]
**	11-APR-1997: Reviewed comments of APPMGR_TASK_ATTRIBUTES. [HA7098] [nok]
**	28-APR-1997: Added exit status text argument to the taskdown
**		     callback. [HA7229] [nok]
**	04-JUL-1997: Added parent_taskid to task information block. 
**                   [ha7470][nok]
**      10-SEP-1997: Added member_alignment on VMS. [tsc] [SPR FG2001]
**	02-OCT-1997: Removed batch queue feature for OpenVMS.  [tsc]
**		     [SPR FG2001]
**	06-OCT-1997: Added JTQUOTA quota.  Remove special user: include files
**		     for VMS [tsc] [SPR FG2001]
**	13-OCT-1997: Added AppmgrRemoveSelfFromRegistry to remove own
**		     process from the registry.  [tsc] [SPR FG2001, RCSE101]
**	14-OCT-1997: Added AppmgrDeleteTaskRegistry.  [tsc] [SPR FG2001,
**		     RCSE101]
**	21-OCT-1997: Moved AppmgrRemoveSelfFromRegistry and
**		     AppmgrDeleteTaskRegistry to APPMGR_NOTPUBLIC.H.  [tsc]
**		     [SPR FG2001, RCSE101]
**      13-APR-1998: Change "lim" in quota names to "lm".  [tsc]
**      04-FEB-2002: Add 64 bit structure to hold Creation time to solve
**                   Windows PID recycling [erc] HAB_PDCR_9564
**	[@history_entry@]...
**--
*/
/*
//N ===========================================================================
//N  
//N   Copyright Notice
//N  
//N  Copyright (c) 1996, 2003 XUJI SRDI Corporation.All Rights Reserved.
//N  
//N  XUJI SRDI CORPORATION PROPRIETARY AND TRADE-SECRET INFORMATION.  
//N  DO NOT COPY, STORE IN A RETRIEVAL SYSTEM, TRANSMIT OR DISCLOSE TO
//N  ANY THIRD PARTY WITHOUT THE PRIOR WRITTEN PERMISSION FROM AN OFFICER
//N  OF XUJI SRDI CORPORATION.
//N   
//N  _________________________________________________________________
//N  
//N  Trademarks
//N  
//N  SRDI and GAIA  are registered trademarks of XUJI SRDI Corporation.
//N  The Xsphere family of products and services are trademarks and/or 
//N  service marks of XUJI SRDI Corporation.
//N   
//N  Other product and company names in these materials may be trademarks
//N  or registered trademarks of other companies, and are the property 
//N  of their respective owners.  They are used only for explanation and 
//N  to the respective owners’ benefit, without intent to infringe.  
//N  
//N  For information about technical support and other XUJI SRDI Corporation
//N  customer support services, see http://www.xjec.com.
//N  
//N ===========================================================================
*/
#ifdef APPMGR_DLL_COMPILE
#define APPMGR_EXTERN __declspec(dllexport)
#else	    			/* Not a WIN32 DLL */
#define APPMGR_EXTERN extern
#endif				/* End of WIN32  compile test block */


/*
** Include Files 
*/

#if defined(__VMS) || defined(VMS) /* VMS compile */

/* include VMS privilege and process symbols. */

#include <prvdef.h>
#include <prcdef.h>

#pragma member_alignment save
#pragma member_alignment

#endif /* defined(__VMS) || defined(VMS) */

#include "cca_typedefs.h"  /* for CCA type definitions */
#include "scf.h"           /* for SCF type definitions */
#include "scf_appmgr.h"    /* for APPMGR status codes */

/*
** Define APPMGR constants that a user may require.      
*/
#define APPMGR_VERSION 1

#define APPMGR_APPLICATION_MAXLEN	8   /* Maximum length for application
					       name context */
#define APPMGR_FAMILY_MAXLEN		8   /* Maximum length for family
					       name context */
					       
#define APPMGR_CONSOLE_MAXLEN	APPMGR_FAMILY_MAXLEN /* Maximum length for the
						        console name */

#define APPMGR_TASK_NAME_MAXLEN         12    /* Maximum length for naming  */
                                              /* an APPMGR task             */
#define APPMGR_TARGET_NAME_MAXLEN       12    /* Maximum length for naming  */
                                              /* an APPMGR target           */
                                              /* environment                */
#define APPMGR_RUNTIME_NAME_MAXLEN   APPMGR_TASK_NAME_MAXLEN + 1 +    \
				     APPMGR_APPLICATION_MAXLEN + 1 + \
				     APPMGR_FAMILY_MAXLEN 
                                              /* Maximum length for naming  */
                                              /* an APPMGR task             */

#define APPMGR_DESCRIPTION_MAXLEN       40    /* Maximum length for a       */
                                              /* description field          */
#define APPMGR_COMMAND_LINE_MAXLEN     255    /* Maximum length for the     */
                                              /* command line               */

#define APPMGR_SPAWN_M 0x01

#define APPMGR_NULL_PROCESS_ID 0

#define APPMGR_EXIT_STATUS_TEXT_MAXLEN 132    /* Maximum length of the text */
					      /* string returned to the     */
					      /* taskdown callback.         */

/*
**  Other constants used to define the task attributes. 
*/ 
#define APPMGR_FILENAME_MAXLEN 64     /* Maximum length for a file name   */

#define APPMGR_FILESPEC_MAXLEN 192     /* Maximum length for a file        */
                                       /* specification (location + file   */
                                       /* name)                            */

#define APPMGR_LOCATION_MAXLEN 128      /* Maximum length for specifying a  */
                                        /* file location.                   */

/*
** APPMGR typedefs
*/
typedef CCA_HANDLE APPMGR_TASKDEF_HANDLE;  /* Handle to be used to specify */
                                           /* the task definition          */

typedef CCA_HANDLE APPMGR_TASK_HANDLE;  /* Handle to be used to specify a */
					/* task object. */

typedef CCA_UINT32 APPMGR_TASKID;      /* APPMGR Task Identifier   */

typedef int APPMGR_PID;                /* Process Identifier       */

typedef struct {
        long dwLowDateTime;             /* This is order value is returned  */
        long dwHighDateTime;            /* by GetProcessTimes.              */
} APPMGR_TIME64;

typedef enum { APPMGR_WIN32_PRIO_IDLE = 1,  /* Priority in NT */
               APPMGR_WIN32_PRIO_NORMAL,
               APPMGR_WIN32_PRIO_HIGH,
               APPMGR_WIN32_PRIO_REALTIME } APPMGR_WIN32_PRIORITY;

typedef enum { APPMGR_UNIX_SCHED_ROUNDROBIN = 1, /* Schedule policy */
               APPMGR_UNIX_SCHED_FIFO,           /* on OSF/1        */
               APPMGR_UNIX_SCHED_OTHER } APPMGR_UNIX_SCHEDULING_POLICY;


/*
** APPMGR structures
*/
                                   
/*
**  The following structure identifies the VMS quotas that 
**  can be specifed when creating a VMS process.
*/
typedef struct 
{
    int astlm;
    int biolm;
    int bytlm;
    int cpulm;
    int diolm;
    int enqlm;
    int fillm;
    int jtquota;
    int pgflquota;
    int prclm;
    int tqelm;
    int wsquota;
    int wsextent;
    int wsdefault;
    
} APPMGR_VMS_QUOTA_SET;

typedef struct 
{
#if defined(__VMS) || defined(VMS) /* VMS compile */
    union prvdef  privmask;
#else
    CCA_UINT32   dummy[2];    /* Not used on Unix and NT */                  
#endif
} APPMGR_VMS_PRIV_SET;


/*
**  The following struture contains all the task attributes that APPMGR can
**  handle when creating a task. Some of these attributes  are operating system
**  specific and therefore a union is used. It is expected that only Procman may
**  modify some of theses attributes prior to start a task.
**  Note that these attributes match the application definition file statements.
*/
typedef struct
{
    /*
    **	Portable attributes.
    */

    /*	The name used when appmgr_get_task_attributes is called. */

    char  static_name_str  [ APPMGR_TASK_NAME_MAXLEN + 1]; 
 
    /*	The run-time name displayed by the Task Viewer. */

    char  runtime_name_str [ APPMGR_RUNTIME_NAME_MAXLEN + 1];

    /*	A short description of the task displayed by the Task Viewer. */

    char  description_str [ APPMGR_DESCRIPTION_MAXLEN + 1];
    
    /*	The executable name without the path location. */ 

    char  image_name_str [ APPMGR_FILENAME_MAXLEN + 1];

    /*	A flag indicating whether the image is a shell script
        or a binary executable (default). */

    CCA_BOOL  image_is_script;

    /*	The stdin, stdout and stderr file names without the path
	location. Ignored if their operating system specific
	equivalent are defined. */

    char    input_file_str[ APPMGR_FILENAME_MAXLEN + 1];
    char    output_file_str[ APPMGR_FILENAME_MAXLEN + 1];
    char    error_file_str[ APPMGR_FILENAME_MAXLEN + 1];

    /*
    **	Operating System specific attributes.
    */

    union
    {
	/*
	**  UNIX
	*/
        struct 
        {
	    /*	Overwrites the default location of the image.
		Default is $HABUSER_BINDIR */
	                                                              
            char    location_str[ APPMGR_LOCATION_MAXLEN + 1];

	    /*	Overwrites the default file specification for the stdin,
	        stdout and stderr files. Default is based on the path
		location of the image and the filename provided in the
		portable equivalent attributes. */

            char    input_file_str[ APPMGR_FILESPEC_MAXLEN + 1];
            char    output_file_str[ APPMGR_FILESPEC_MAXLEN + 1];
            char    error_file_str[ APPMGR_FILESPEC_MAXLEN + 1];

	    /* The POSIX.4 scheduling policies:
	       - Timesharing (OTHER) 
	       - Round-Robin (RR)
	       - First-in First-out (FIFO) */

            APPMGR_UNIX_SCHEDULING_POLICY policy;

	    /* The POSIX.4 Realtime Interface priority value */

            int     priority;

        } digital_unix;

	/*
	**  OpenVMS
	*/
        struct 
        {     
	    /*	Overwrites the default location of the image.
		Default is HABUSER$BINDIR */
	                                                              
            char    location_str[ APPMGR_LOCATION_MAXLEN + 1];
            

	    /*	Overwrites the default file specification for the stdin,
	        stdout and stderr files. Default is based on the path
		location of the image and the filename provided in the
		portable equivalent attributes. */

            char    input_file_str[ APPMGR_FILESPEC_MAXLEN + 1];
            char    output_file_str[ APPMGR_FILESPEC_MAXLEN + 1];
            char    error_file_str[ APPMGR_FILESPEC_MAXLEN + 1];

            int     priority; /* The priority (from 1 to 31). */

            int     uicmem; /*	The member portion of the UIC assigned
				to the task. */

            int     initmem;		  /* INITMEM */
            CCA_BOOL    image_dump;	  /* IMGDMP */
            CCA_BOOL    aws_disabled;     /* DISAWS */
            CCA_BOOL    noswap;		  /* PWSWAPM */
            CCA_BOOL    start_hibernated; /* HIBER */
            CCA_BOOL    rapport_task;	  /* RAPPORT */
	    CCA_BOOL	ssfexcu;	  /* system service failure 
	                                     exception mode */
            APPMGR_VMS_PRIV_SET  privileges;
            APPMGR_VMS_QUOTA_SET quotas;

        } openvms;

	/*
	**  WindowsNT
	*/
        struct 
        {
	    /*	Overwrites the default location of the image.
		Default is HABUSER_BINDIR */
	                                                              
            char    location_str[ APPMGR_LOCATION_MAXLEN + 1];
              

	    /*	Overwrites the default file specification for the stdin,
	        stdout and stderr files. Default is based on the path
		location of the image and the filename provided in the
		portable equivalent attributes. */

            char    input_file_str[ APPMGR_FILESPEC_MAXLEN + 1];
            char    output_file_str[ APPMGR_FILESPEC_MAXLEN + 1];
            char    error_file_str[ APPMGR_FILESPEC_MAXLEN + 1];

	    /*	The priority. Choices are: Idle, Normal, High, Real-time */

            APPMGR_WIN32_PRIORITY  priority;
        } win32;
    }   os;
} APPMGR_TASK_ATTRIBUTES;

/*
**  The following defines the task information structure that is
**  used when calling the the AppmgrGetCurrentTaskInfo or the 
**  AppmgrGetTaskInfo functions.
*/
typedef struct
{
    APPMGR_PID processid;     /* The process id obtained from the */
                              /* operating system                 */

    APPMGR_TASKID taskid;     /* The task identifier that must have been */
                              /* obtained from an earlier call to the    */
                              /* AppmgrStartTask function or from another*/
                              /* process that did create the task.       */

    APPMGR_TASKID parent_taskid;	/* The task identifier of the parent */
					/* of the task.			     */

    char runtime_name_str [APPMGR_RUNTIME_NAME_MAXLEN+1];
			      /* The run-time name of the task */

    char description_str [APPMGR_DESCRIPTION_MAXLEN+1];
			      /* A short description of the task */

    char static_name_str [APPMGR_TASK_NAME_MAXLEN + 1];
			      /* The plain static name of the task */

    char application_str [APPMGR_APPLICATION_MAXLEN + 1];
    char family_str [APPMGR_FAMILY_MAXLEN + 1];
			      /* The HABITAT application and family context */

} APPMGR_TASK_INFORMATION;

#if defined(__VMS) || defined(VMS) /* VMS compile */
#pragma member_alignment restore
#endif


/*
** Callback typedefs
*/

typedef void (*APPMGR_TASKDOWN_CALLBACK) ( 
                               APPMGR_TASKID	taskid,
                               SCF_STATUS	exit_status,
			       const char	exit_status_str[],
                               CCA_USERARG	userarg );


#if defined(__cplusplus)
extern "C"
{
#endif

APPMGR_EXTERN SCF_STATUS AppmgrGetTaskAttributes (
                               const char              application_name_str[],
                               const char              task_name_str[],
                               APPMGR_TASKDEF_HANDLE  *taskdef_handle_ptr,
                               APPMGR_TASK_ATTRIBUTES *task_attributes_ptr,
                               int                     version );

APPMGR_EXTERN SCF_STATUS AppmgrModifyTaskAttributes (
                                APPMGR_TASKDEF_HANDLE   taskdef_handle,
                                APPMGR_TASK_ATTRIBUTES *task_attributes_ptr );

APPMGR_EXTERN SCF_STATUS AppmgrStartTask (  
                             APPMGR_TASKDEF_HANDLE    taskdef_handle,
                             APPMGR_TASKID           *taskid_ptr,
                             const char              *command_line_str,
                             char                   **environment_str_ptr,
                             APPMGR_TASKDOWN_CALLBACK taskdown_callback,
                             void                    *userarg_ptr,
                             const char               family_str[],
                             int                      options );

APPMGR_EXTERN SCF_STATUS AppmgrStopTask ( APPMGR_TASKID taskid );

APPMGR_EXTERN CCA_BOOL AppmgrTaskIsUp (
                               const char              task_name_str[],
                               const char              application_name_str[],
                               const char              family_str[],
	                       APPMGR_TASKID          *taskid_ptr );

APPMGR_EXTERN void AppmgrSyncAbort ( const char task_name_str[] );

APPMGR_EXTERN SCF_STATUS AppmgrGetCurrentTaskInfo (
                                APPMGR_TASK_INFORMATION *task_information_ptr,
                                int                      version );

APPMGR_EXTERN SCF_STATUS AppmgrGetTaskInfo (
                                APPMGR_TASK_INFORMATION *task_information_ptr,
                                int                      version );

APPMGR_EXTERN SCF_STATUS AppmgrGetApplicationName ( char application_str[],
						    size_t application_size );
APPMGR_EXTERN SCF_STATUS AppmgrGetFamilyName ( char family_str[],
					       size_t family_size );
					       
APPMGR_EXTERN SCF_STATUS AppmgrGetConsoleName ( char console_str[],
					        size_t console_size );

#if defined(__cplusplus)
}
#endif

#endif /* APPMGR_H_INCLUDED */


