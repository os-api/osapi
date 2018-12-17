// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for OSAPI Protocols
//
// *****************************************************************************************

// Standard protocols PF_ / AF_
osapi_protocol_X( e_protocol_unspec, = 0 , 			"UNSPEC" 	)
osapi_protocol_X( e_protocol_local,  = 1 , 			"LOCAL" 	)
osapi_protocol_X( e_protocol_unix,   = e_protocol_local, 	"UNIX" 		)
osapi_protocol_X( e_protocol_file,   = e_protocol_local, 	"NONE" 		)
osapi_protocol_X( e_protocol_inet,  , 				"INET" 		)
osapi_protocol_X( e_protocol_ax25,  , 				"AX25" 		)
osapi_protocol_X( e_protocol_ipx,  , 				"IPX" 		)
osapi_protocol_X( e_protocol_appletalk,  , 			"APPLETALK" 	)
osapi_protocol_X( e_protocol_netrom,  , 			"NETROM" 	)
osapi_protocol_X( e_protocol_bridge,  , 			"BRIDGE" 	)
osapi_protocol_X( e_protocol_atmpvc,  , 			"ATMPVC" 	)
osapi_protocol_X( e_protocol_x25,  , 				"X25" 		)
osapi_protocol_X( e_protocol_inet6,  , 				"INET6" 	)
osapi_protocol_X( e_protocol_rose,  , 				"ROSE" 		)
osapi_protocol_X( e_protocol_decnet,  , 			"DECnet" 	)
osapi_protocol_X( e_protocol_netbeui,  , 			"NETBEUI" 	)
osapi_protocol_X( e_protocol_security,  , 			"SECURITY" 	)
osapi_protocol_X( e_protocol_key,  , 				"KEY" 		)
osapi_protocol_X( e_protocol_netlink,  , 			"NETLINK" 	)
osapi_protocol_X( e_protocol_route,  = e_protocol_netlink, 	"ROUTE" 	)
osapi_protocol_X( e_protocol_packet,  , 			"PACKET" 	)
osapi_protocol_X( e_protocol_ash,  , 				"ASH" 		)
osapi_protocol_X( e_protocol_econet,  , 			"ECONET" 	)
osapi_protocol_X( e_protocol_atmsvc,  , 			"ATMSVC" 	)
osapi_protocol_X( e_protocol_rds,  , 				"RDS" 		)
osapi_protocol_X( e_protocol_sna,  , 				"SNA" 		)
osapi_protocol_X( e_protocol_irda,  , 				"IRDA" 		)
osapi_protocol_X( e_protocol_pppox,  , 				"PPPOX" 	)
osapi_protocol_X( e_protocol_wanpipe,  , 			"WANPIPE" 	)
osapi_protocol_X( e_protocol_llc,  ,	 			"LLC" 		)
osapi_protocol_X( e_protocol_ib,  ,	 			"IB" 		)
osapi_protocol_X( e_protocol_mpls,  , 				"MPLS" 		)
osapi_protocol_X( e_protocol_can,  , 				"CAN" 		)
osapi_protocol_X( e_protocol_tpic,  , 				"TIPC" 		)
osapi_protocol_X( e_protocol_bluetooth,  , 			"BLUETOOTH" 	)
osapi_protocol_X( e_protocol_iucv,  , 				"IUCV" 		)
osapi_protocol_X( e_protocol_rxrpc,  , 				"RXRPC" 	)
osapi_protocol_X( e_protocol_isdn,  , 				"ISDN" 		)
osapi_protocol_X( e_protocol_phonet,  , 			"PHONET" 	)
osapi_protocol_X( e_protocol_ieee802154,  , 			"IEEE802154"	)
osapi_protocol_X( e_protocol_caif,  , 				"CAIF" 		)
osapi_protocol_X( e_protocol_alg,  ,	 			"ALG" 		)
osapi_protocol_X( e_protocol_nfc,  ,	 			"NFC" 		)
osapi_protocol_X( e_protocol_vsock,  , 				"VSOCK" 	)
osapi_protocol_X( e_protocol_kcm,  ,	 			"KCM" 		)
osapi_protocol_X( e_protocol_qipcrtc,  , 			"QIPCRTR" 	)
osapi_protocol_X( e_protocol_smc,  ,	 			"SMC" 		)
osapi_protocol_X( e_protocol_max,  , 				"MAX" 		)



// Protocol alias

osapi_protocol_X( e_protocol_ipv4, = e_protocol_inet, 		"INET" 		)
osapi_protocol_X( e_protocol_ipv6, = e_protocol_inet6,		"INET6" 	)
