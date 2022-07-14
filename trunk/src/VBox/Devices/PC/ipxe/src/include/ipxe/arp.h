#ifndef _IPXE_ARP_H
#define _IPXE_ARP_H

/** @file
 *
 * Address Resolution Protocol
 *
 */

FILE_LICENCE ( GPL2_OR_LATER );

#include <ipxe/tables.h>
#include <ipxe/netdevice.h>

/** A network-layer protocol that relies upon ARP */
struct arp_net_protocol {
	/** Network-layer protocol */
	struct net_protocol *net_protocol;
	/** Check existence of address
	 *
	 * @v netdev	Network device
	 * @v net_addr	Network-layer address
	 * @ret rc	Return status code
	 */
	int ( * check ) ( struct net_device *netdev,
			  const void *net_addr );
};

/** ARP protocol table */
#define ARP_NET_PROTOCOLS \
	__table ( struct arp_net_protocol, "arp_net_protocols" )

/** Declare an ARP protocol */
#define __arp_net_protocol __table_entry ( ARP_NET_PROTOCOLS, 01 )

extern struct net_protocol arp_protocol __net_protocol;

extern int arp_tx ( struct io_buffer *iobuf, struct net_device *netdev,
		    struct net_protocol *net_protocol, const void *net_dest,
		    const void *net_source, const void *ll_source );

#endif /* _IPXE_ARP_H */
