/******************************************************************************
*
*       Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
*       All other product or service names are the property of their respective owners.
*       (C) Freescale Semiconductor, Inc. 2025
*
*       THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
*       BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
*       Freescale Semiconductor, Inc.
*
*       Description: OS property file
*
*       Note: The implementation that was used is: AUTOSAR_MPC574xG
*       System Generator for AUTOSAR OS/MPC574xG - Version: 4.0 Build 4.0.92
*
********************************************************************************/
/* OSPROP configuration file */

#ifndef OSPROP_H
#define OSPROP_H

/* Timing protection */
#define OSNTPTSKARRIV 0U                   /* The number of tasks with TIMEFRAME > 0  */
#define OSNTPTSKRESLOCKS 0U                /* number of all resource locking time configurations for TASKs */
#define OSNTPISRRESLOCKS 0U                /*  number of all resource locking time configurations for ISRs cat.2 */
#define OSNTPTSKARRIVCORE0 0U              /* The number of tasks with TIMEFRAME > 0  */
#define OSNTPTSKRESLOCKSCORE0 0U           /* number of all resource locking time configurations for TASKs */
#define OSNTPISRRESLOCKSCORE0 0U           /*  number of all resource locking time configurations for ISRs cat.2 */
#define OSNTPTSKARRIVCORE1 0U              /* The number of tasks with TIMEFRAME > 0  */
#define OSNTPTSKRESLOCKSCORE1 0U           /* number of all resource locking time configurations for TASKs */
#define OSNTPISRRESLOCKSCORE1 0U           /*  number of all resource locking time configurations for ISRs cat.2 */
#define OSNTPISRARRIV 0U                   /* The number of ISR2 with TIMEFRAME > 0  */
#define OSNTPTSKBGTS 0U                    /* The number of task with Execution Budget > 0 */
#define OSNTPISRBGTS 0U                    /* The number of ISR2 with Execution Time > 0 */
#define OSNTPBGTS 0U                       /* The number of task with execution budget  and ISR2 with execution time (OSNTPBGTS=OSNTPTSKBGTS+OSNTPISRBGTS) */
#define OSNTPTSKINTLOCKTIME 0U             /* The number of task with OS Interrupt Lock Time */
#define OSNTPISRINTLOCKTIME 0U             /* The number of ISR2 with OS Interrupt Lock Time */
#define OSNTPTSKRESLOCKTIME 0U             /* The number of task with at least one Resource Lock Time */
#define OSNTPISRRESLOCKTIME 0U             /* The number of ISR2 with at least one Resource Lock Time */
#define OSNTPCORE0TSKRESLOCKTIME 0U        /* The number of task with at least one Resource Lock Time */
#define OSNTPCORE0ISRRESLOCKTIME 0U        /* The number of ISR2 with at least one Resource Lock Time */
#define OSNTPCORE1TSKRESLOCKTIME 0U        /* The number of task with at least one Resource Lock Time */
#define OSNTPCORE1ISRRESLOCKTIME 0U        /* The number of ISR2 with at least one Resource Lock Time */

/* Multi-Core */

#define OSNCORES 1U                        /* The number of cores in the system */
#define OS_MASTER_CORE 0U                  /* The Master Core number */
#define OSNSPINLOCKS 0U                    /* The number number of spinlocks */
#define OSNTASKSCORE0 2U                   /* The number of tasks assigned to core 0 */
#define OSNTASKSCORE1 0U                   /* The number of tasks assigned to core 1 */
#define OSNISRCORE0 0U                     /* equal to summ of number ISR, system timers and TPTimer */
#define OSNISRCORE1 0U                     /* equal to summ of number ISR, system timers and TPTimer */
#define OSNUSERISRCORE0 0U                 /* The number of ISR2s assigned to core 0 */
#define OSNUSERISRCORE1 0U                 /* The number of ISR2s assigned to core 1 */
#define OSNCTRSCORE0 1U                    /* The number of counters assigned to core 0 */
#define OSNCTRSCORE1 0U                    /* The number of counters assigned to core 1 */
#define OSNRESSCORE0 0U                    /* The number of RESOURCEs with task priority assigned to core 0 */
#define OSNRESSCORE1 0U                    /* The number of RESOURCEs with task priority assigned to core 1 */
#define OSNISRRESSCORE0 0U                 /* The number of RESOURCEs with ISR priority assigned to core 0 */
#define OSNISRRESSCORE1 0U                 /* The number of RESOURCEs with ISR priority assigned to core 1 */

/* IOC */

#define OSNIOCBUFFERS 0U                   /* The number of "LastIsBest" non-grouped communications */
#define OSNIOCQUEUES 0U                    /* The number of "Queued" non-grouped communications */
#define OSNIOCGROUPBUFFERS 0U              /* The number of "LastIsBest" grouped  communications */
#define OSNIOCGROUPQUEUES 0U               /* The number of "Queued" grouped communications */
#define OSNIOCCALLBACKS 0U                 /* The number of IOC communication objects with callbacks */

/* Implementation */

#define OSMPC574xG

/* Target MCU */

#ifndef OSMPC5748G
#define OSMPC5748G                         /* Target MCU */

#endif

/* Applications */

#define OSNAPPS 1U                         /* number of OS-applications */
#define OSNTRUSTEDFUNCTIONS 0U             /* number of trusted functions */
#define OSNNOTTRUSTEDAPPS 0U               /* number of not trusted applications */
#define OSNNOTTRUSTEDAPPSCORE0 0U          /* number of not trusted applications of the first core */
#define OSNNOTTRUSTEDAPPSCORE1 0U          /* number of not trusted applications of the second core */
#define OSNMEMDATA0 0U                     /* number of nontrusted application with data in region #0 */
#define OSNMEMDATA1 0U                     /* number of nontrusted application with data in region #1 */
#define OSNMEMDATA2 0U                     /* number of nontrusted application with data in region #2 */

/* Scalability Class */

#define OSSC1                              /* Scalability Class */

/* Conformance Class */

#define OSBCC1                             /* Conformance Class */

/* Scheduler Policy */

#define OSFULLPREEMPT                      /* preemptive schedule pollicy is set */
#define OSNOFASTTERMINATE                  /* FastTerminate attribute is set to FALSE */
#define OSRES_SCHEDULER                    /* USERESSCHEDULER attribute has TRUE value */
#define OSORTIDEBUGLEVEL 0U                /* value of DEBUG_LEVEL attribute */

/* Hook routines */

#define OSHOOKSHUTDOWN                     /* SHUTDOWNHOOK is set to TRUE */

/* ISRs categories support */

#define OSNOISR1                           /* no defined ISR category 1 */
#define OSNOISR2                           /* no defined ISR category 2 */

/* Interrupt management */

#define OSISRENTRYEXIT                     /* ISR entry/exit frames must be implemented */

/* Timing protection */


/* Communication mechanism */


/* Counters and Alarms mechanisms */

#define OSNHWCTRSCORE0 1U                  /* The number of system timers of type HWCOUNTER (0, 1 or 2) assigned to core 0 */
#define OSNHWCTRSCORE1 0U                  /* The number of system timers of type HWCOUNTER (0, 1 or 2) assigned to core 1 */
#define OSHWCOUNTER                        /* Shall be defined if any timer is HWCOUNTER */
#define OSSYSTIMER                         /* SysTimer has the HWCOUNTER or SWCOUNTER value */
#define OSNSYSTMRS 1U                      /* The number of timers, excluding TP Timer */
#define OSTIMeMIOS                         /* Hardware for System/Second timer */
#define OSTIMCHAN 0U                       /* Hardware channel for System timer */
#define OSeMIOSGLOBALPRESCALER 249U        /* value of eMIOS.GlobalMIOSPrescaler or eMIOS0.GlobalMIOSPrescaler */
#define OSSYSTIMFREEZE                     /* Freeze in SysTimer is set to TRUE */
#define OSTIMPRESCALER 3U                  /* The Prescaler value of the timer */
#define OSALMACTIVTASK                     /* at least one alarm has the ACTION = ACTIVATETASK */
#define OSALMCALLBACK                      /* at least one alarm has the  the ACTION = ALARMCALLBACK */
#define OSNAPPMODES 1U                     /* equal to number of APPMODES objects */
#define OSNTSKS 2U                         /* equal to number of TASK objects */
#define OSNXTSKS 0U                        /* equal to number of extended TASK objects */
#define OSNISRRESS 0U                      /* number of RESOURCEs which are used by ISRs */
#define OSNRESS 1U                         /* The number of RESOURCEs with task priority, STANDARD or LINKED plus resscheduler */
#define OSRESOURCE                         /* at least one resource with task priority and RESOURCEPROPERTY = STANDARD (including RES_SCHEDULER) is defined */
#define OSNCTRS 1U                         /* equal to number of COUNTER objects */
#define OSCOUNTER                          /* defined if at least one COUNTER object defined  */
#define OSNUSERALMS 2U                     /* equal to number of ALARM objects */
#define OSNALMS 2U                         /* equal to number of ALARM and SCHEDULETABLES objects */
#define OSALARM                            /* at least one ALARM object defined */
#define OSNAUTOALMS 1U                     /* equal to number of auto-start alarms */
#define OSNMSGS 0U                         /* equal to the number of MESSAGE objects */
#define OSNNONTRUSTEDTSKS 0U               /* Number of tasks which belongs to nontrusted applications  */
#define OSNNONTRUSTEDISR 0U                /* Number of user's ISR2 which belongs to nontrusted applications  */
#define OSNUSERISR 0U                      /* The number of ISR2s */
#define OSNISR 1U                          /* equal to summ of number ISR, system timers and TPTimer */
#define OSHIGHISRPRIO 1U                   /* equal to the highest ISR(category 2)/SysTimer/SecondTimer (ISR)PRIORITY */
#define OSNIPLS 1U                         /* equal to number of different ISR priorities including timers */
#define OSTIMER1 0U                        /* Index for a SysTimer */

/* Schedule table */

#define OSNSCTS 0U                         /* equal to the number of scheduletables */
#define OSNAUTOSCTS 0U                     /* The number of autostart scheduletables */
#define OSNALMACTSCORE0 0U                 /* The number of crosscore action */
#define OSNALMACTSCORE1 0U                 /* The number of crosscore action */
#endif /* OSPROP_H */

