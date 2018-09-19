#!/bin/bash

if test ! -f ex2
then
                                                  
    echo 0 > ex2
fi


for i in `seq 1 100`;
do

	LASTNUMBER=`tail -1 ex2`
	LASTNUMBER=$((LASTNUMBER+1))

	echo $LASTNUMBER >> ex2
done 
