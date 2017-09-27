#!/bin/bash

ls -l | while read l
do
  if [ "`echo $l | cut -c3`" = "w" ]
  then
    echo `echo $l | rev | cut -d' ' -f1 | rev`
  fi
done
