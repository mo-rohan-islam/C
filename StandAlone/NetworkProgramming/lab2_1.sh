#!/bin/bash

echo -n "Enter PID: "
read pid

memory_consumption=$(pmap $(($pid)) | tail -1 | awk '/[0-9]K/{print $2}')
echo "$(($pid)) consumes $memory_consumption"

