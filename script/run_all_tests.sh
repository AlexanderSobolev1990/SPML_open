#!/bin/bash

outputfile="tests_output_log.txt"
rm -f "${outputfile}" # Delete file if exists
###############################################################################
# Run tests and duplicate output to outputfile:
./test_spml_compare | tee -a ${outputfile}
./test_spml_lap | tee -a ${outputfile}

###############################################################################
# Output test results with their names:
echo
echo "#########################################################################"
echo "RESULTS PER TEST:"
echo "#########################################################################"
echo
grep -i 'Start testing\|Totals:' ${outputfile}
###############################################################################
# Summarize passed/failed tests:
echo
echo "#########################################################################"
echo "TEST SUMMARY:"
echo "#########################################################################"
echo
grep ' passed'      ${outputfile} | awk -F , '{ print $1 }' | grep -o -E '[0-9]+' | awk '{ SUM += $1 } END { print "passed tests        : " SUM }'
grep ' failed'      ${outputfile} | awk -F , '{ print $2 }' | grep -o -E '[0-9]+' | awk '{ SUM += $1 } END { print "failed tests        : " SUM }'
grep ' skipped'     ${outputfile} | awk -F , '{ print $3 }' | grep -o -E '[0-9]+' | awk '{ SUM += $1 } END { print "skipped tests       : " SUM }'
grep ' blacklisted' ${outputfile} | awk -F , '{ print $4 }' | grep -o -E '[0-9]+' | awk '{ SUM += $1 } END { print "blacklisted tests   : " SUM }'
grep 'ms'           ${outputfile} | awk -F , '{ print $5 }' | grep -o -E '[0-9]+' | awk '{ SUM += $1 } END { print "total time [minutes]: " SUM/1000/60 }'