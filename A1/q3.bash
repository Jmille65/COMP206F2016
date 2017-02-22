#!/bin/bash

CONTENTS=`ls | wc -w`
i=1
LIST=""
LISTJPG=""

if [ "$1" == "alpha" ]
	then
	echo "alpha sorting selected"
	while [ "$i" -le "$CONTENTS" ]
		do
		FILENAME=`ls -1 | head -$i | tail -1`
		if [ ${FILENAME: -4} == ".dat" ] #if filename at index i of directory is .dat
			then
			NOEXT="${FILENAME%.*}" #filename without extension
			j=`expr "$i" "+" "1"`
			if [ `ls -1 | head -$j | tail -1` == "$NOEXT.jpg" ]
				then
				LIST=`echo "$LIST$NOEXT"`
				LIST="$LIST\n"
				LISTJPG="$LISTJPG$NOEXT.jpg "
			fi
		fi
		((i++))
	done
fi
if [ "$1" == "weight" ]
	then
	echo "weight sorting selected"
	while [ "$i" -le "$CONTENTS" ]
		do
		FILENAME=`ls -1 | head -$i | tail -1`
		if [ "${FILENAME: -4}" == ".dat" ] #if filename at index i of directory is .dat
			then
			NOEXT="${FILENAME%.*}" #filename without extension
			WANDL=`cut -d' ' -f1,1 < $FILENAME`
			WANDL=`echo ${WANDL::-2}`
			echo "$NOEXT $WANDL" >> jkf
		fi
		((i++))
	done
	sort -n -k 2,2 jkf > jkf2 #can't figure out if sort sorts in place and if that would disturb the sorting, safer to put to jkf2
	j=1
	JKFLINES=`cat jkf2 | wc -l`
	while [ "$j" -le "$JKFLINES" ]
		do
		LINE=`cat jkf2 | head -$j | tail -1`
		NAME=`echo $LINE | cut -d' ' -f1,1`
		LIST="$LIST$NAME\n"
		LISTJPG="$LISTJPG$NAME.jpg "
		((j++))
	done
	rm jkf jkf2
fi		
if [ "$1" == "length" ]
	then
	echo "length sorting selected"
	while [ "$i" -le "$CONTENTS" ]
		do
		FILENAME=`ls -1 | head -$i | tail -1`
		if [ "${FILENAME: -4}" == ".dat" ] #if filename at index i of directory is .dat
			then
			NOEXT="${FILENAME%.*}" #filename without extension
			WANDL=`cut -d' ' -f2,2 < $FILENAME`
			WANDL=`echo ${WANDL::-1}`
			echo "$NOEXT $WANDL" >> jkf
		fi
		((i++))
	done
	sort -n -k 2,2 jkf > jkf2 #can't figure out if sort sorts in place and if that would disturb the sorting, safer to put to jkf2
	j=1
	JKFLINES=`cat jkf2 | wc -l`
	while [ "$j" -le "$JKFLINES" ]
		do
		LINE=`cat jkf2 | head -$j | tail -1`
		NAME=`echo $LINE | cut -d' ' -f1,1`
		LIST="$LIST$NAME\n"
		LISTJPG="$LISTJPG$NAME.jpg "
		((j++))
	done
	rm jkf jkf2
fi

echo -e $LIST #Final displays
convert $LISTJPG -append results.jpg #creates image file from LISTJPG
