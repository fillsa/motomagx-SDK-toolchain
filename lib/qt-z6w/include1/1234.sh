#bin/sh

FILES1=`ls | awk '{print $3}'`
FILES2=`ls`
OK=`rename $FILES2 $FILES1`
