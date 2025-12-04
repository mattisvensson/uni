#!/bin/bash
# Generic process script
# Usage: ./generic_process.sh <process_id> <sleep_time>

if [ $# -ne 2 ]; then
    echo "Usage: $0 <process_id> <sleep_time>"
    exit 1
fi

PROCESS_ID=$1
SLEEP_TIME=$2

echo "Starting process $PROCESS_ID (PID: $$) with sleep time $SLEEP_TIME seconds"
sleep $SLEEP_TIME
echo "Hier Prozess $PROCESS_ID"
sleep $SLEEP_TIME
echo "Hier Prozess $PROCESS_ID"
echo "Process $PROCESS_ID finished"