#!/bin/bash
# Main script for the operating systems exercise
# Demonstrates background process management

echo "=== Operating Systems Exercise 3 ==="
echo "Choose an option:"
echo "1. Run process manager demo"
echo "2. Run 200 sequential processes"
echo "3. Simple two background processes demo"
echo

read -p "Enter choice (1-3): " choice

case $choice in
    1)
        echo "Running process manager demo..."
        chmod +x process_manager.sh
        ./process_manager.sh 3
        ;;
    2)
        echo "Running 200 sequential processes..."
        for i in {1..200}
        do
            echo "Execution $i"
            ./process1.sh
        done
        ;;
    3)
        echo "Simple background processes demo..."
        chmod +x process1.sh process2.sh
        
        # Start two background processes
        ./process1.sh 1 2 &
        PID1=$!
        ./process2.sh 2 2 &
        PID2=$!
        
        echo "Started processes with PIDs: $PID1, $PID2"
        
        # Show process status
        sleep 1
        echo "Process status:"
        ps aux | grep -E "process[12]" | grep -v grep
        
        # Wait for processes to finish
        wait $PID1 $PID2
        echo "All processes finished"
        ;;
    *)
        echo "Invalid choice"
        exit 1
        ;;
esac
