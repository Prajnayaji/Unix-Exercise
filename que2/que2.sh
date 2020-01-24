#! /bin/bash
cat sidekiq.log | grep RuntimeError: | cut -d " " -f 6,7 | sort -k 2 -n 
