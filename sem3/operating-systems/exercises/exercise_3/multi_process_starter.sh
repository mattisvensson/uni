#!/bin/bash
echo "Parent process (PID: $$) starting three child processes..."

./generic_process.sh A 2 &
CHILD1=$!
echo "Child A started with PID: $CHILD1"

./generic_process.sh B 3 &
CHILD2=$!
echo "Child B started with PID: $CHILD2"

./generic_process.sh C 4 &
CHILD3=$!
echo "Child C started with PID: $CHILD3"

echo "Parent process waiting for all children to finish..."
wait $CHILD1 $CHILD2 $CHILD3
echo "Parent process: All children finished"
