#! /bin/bash

echo enter your year
read varyear
echo you year is $varyear
if [$varyear%4==0] && [$varyear%100!=100]
then
	echo It is a leap year
else
	echo It is not a leap year
fi
