#! /bin/bash
cat qyou.log | grep 'ERROR Request' | cut -d " " -f 16 > failed_status.txt

cat qyou.log | grep 'ERROR Request' | cut -d " " -f 7 > failed_api_calls.txt

cat failed_api_calls.txt | cut -b 41- | tr "&" " " > failed_parameters.txt
