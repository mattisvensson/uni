#!/bin/bash
# Script that creates background processes and demonstrates process management
# Usage: ./process_manager.sh <sleep_time>

SLEEP_TIME=${1:-3}

echo "=== Starting Background Process Management Demo ==="
echo "Sleep time: $SLEEP_TIME seconds"
echo

# Make scripts executable
chmod +x generic_process.sh process1.sh process2.sh

echo "1. Starting two background processes..."
./generic_process.sh 1 $SLEEP_TIME &
PID1=$!
echo "Started process 1 with PID: $PID1"

./generic_process.sh 2 $SLEEP_TIME &
PID2=$!
echo "Started process 2 with PID: $PID2"

echo
echo "2. Showing process status while processes are sleeping..."
sleep 1  # Give processes time to start

echo "Current processes (using ps):"
ps aux | grep -E "(generic_process|process[12])" | grep -v grep

echo
echo "Process tree (using pstree for current user):"
pstree -p $$

echo
echo "3. Waiting a bit, then killing process 1 early..."
sleep $(($SLEEP_TIME / 2))  # Wait half the sleep time

if kill -0 $PID1 2>/dev/null; then
    echo "Killing process 1 (PID: $PID1) early..."
    kill $PID1
    echo "Process 1 killed"
else
    echo "Process 1 already finished"
fi

echo
echo "4. Checking remaining processes:"
ps aux | grep -E "(generic_process|process[12])" | grep -v grep

echo
echo "5. Waiting for remaining processes to finish..."
wait $PID2 2>/dev/null
echo "All background processes finished"

echo
echo "=== Creating a process that starts three child processes ==="

# Create a script that starts three background processes
cat > multi_process_starter.sh << 'EOF'
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
EOF

chmod +x multi_process_starter.sh

echo "Starting multi-process starter in background..."
./multi_process_starter.sh &
MULTI_PID=$!

sleep 2
echo
echo "Process status during multi-process execution:"
ps aux | grep -E "(multi_process_starter|generic_process)" | grep -v grep

echo
echo "Process tree showing parent-child relationships:"
pstree -p $MULTI_PID 2>/dev/null || pstree -p $$

wait $MULTI_PID
echo
echo "=== Demo completed ==="