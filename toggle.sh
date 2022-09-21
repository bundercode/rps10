#!/bin/bash

if [ "$1" == "light" ] || test -z "$1"
then
	if [ "$(grep "Lights:" status.txt | awk '{print $2;}')" == 'off' ]
	then
		sed -i.bak 's/off/on/g' status.txt
	else
		sed -i.bak 's/on/off/g' status.txt
	fi
elif [ "$1" == "pump" ]
then
	if [ "$(grep "Pump:" status.txt | awk '{print $2;}')" == 'off' ]
	then
		sed -i.bak 's/off/on/g' status.txt
	else
		sed -i.bak 's/on/off/g' status.txt
	fi
fi
rm status.txt.bak

#./rps10
python toggle.py
