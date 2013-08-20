#ifndef _IPXE_SYSLOG_H
#define _IPXE_SYSLOG_H

/** @file
 *
 * Syslog protocol
 *
 */

FILE_LICENCE ( GPL2_OR_LATER );

#include <syslog.h>

/** Syslog server port */
#define SYSLOG_PORT 514

/** Syslog line buffer size
 *
 * This is a policy decision
 */
#define SYSLOG_BUFSIZE 128

/** Syslog default facility
 *
 * This is a policy decision
 */
#define SYSLOG_DEFAULT_FACILITY 0 /* kernel */

/** Syslog default severity
 *
 * This is a policy decision
 */
#define SYSLOG_DEFAULT_SEVERITY LOG_INFO

/** Syslog priority */
#define SYSLOG_PRIORITY( facility, severity ) ( 8 * (facility) + (severity) )

#endif /* _IPXE_SYSLOG_H */
