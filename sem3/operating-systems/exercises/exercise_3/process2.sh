#!/bin/bash
# Parameters: process_id sleep_time
PROCESS_ID=${1:-2}
SLEEP_TIME=${2:-2}

sleep $SLEEP_TIME
echo "Hier Prozess $PROCESS_ID"
sleep $SLEEP_TIME
echo "Hier Prozess $PROCESS_ID"
