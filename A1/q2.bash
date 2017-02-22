#!/bin/bash

COUNT=`ls | wc -w`
i=1

while [ 1 ]
do
	while [ `ps | grep -c "eog"` = $1 ] #timer
		do
		sleep 1
	done
	
	while [ 1 ]
		do
		if [ $COUNT = $i ] #resets loop
			then
			i=1
		fi
		FILENAME=`ls -1 | head -$i | tail -1`
		if [ ${FILENAME: -4} == ".dat" ] #if filename at index i of directory is .dat
			then
			NOEXT="${FILENAME%.*}" #filename without extension
			j=`expr "$i" "+" "1"`
			if [ `ls -1 | head -$j | tail -1` == "$NOEXT.jpg" ]
				then
				eog -n `ls -1 | head -$j | tail -1` & #opens image
				((i++))
				break
			fi
		fi			
	((i++))
	done
done

