#!/bin/env bash

days=(Jan Feb Mar Aprl May Jun Jul Aug Sep Oct Nov Dec)

#echo "Da el mes de iniciio en numero (enero = 1) : " 
read mesinicio 
#echo "Da el mes de fin en numero (diciembre = 12) : " 
read mesfin 

for i in "${days[@]:$mesinicio:$mesfin}"; do
       cat bitacora.txt  | grep $i | sort 
done
