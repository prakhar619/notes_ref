#!/bin/bash

#CMD used
#	iwconfig
#		essid
#		signal strength
#		bit rate
#		Frequency
#		Access point mac
	
#	ifconfig
#		ip address
#			ipv4
#			ipv6
#			netmask
	
#	lshw -C network				hardware listener	(network,processor,disk)
#		nic vendor
#		capacity
#		width
#		clock
#		product
	
#	Scan
#		iwlist wlo1 scan
#			mac address
#			freq
#			quality
#			sig lvl
#			essid
#			wpa version
#			ieee 802.11iwpa2
	
#		iw dev wlo1 scan




echo "WIFI INFO"

echo "Connected Wifi Information"
iwconfig wlo1
echo -e "\n"
echo "IP Address"
ifconfig wlo1
echo -e "\n"
echo "WIFI NIC Information"
lshw -C network
echo "Scan All WIFI Networks(y/n):"
read INP
if [ $INP = "y" ]
then
iwlist wlo1 scan
fi






