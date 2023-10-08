#!/bin/bash

# Test the ls command
ls_output=$(ls)
expected_output=$(ls)

if [ "$ls_output" = "$expected_output" ]; then
	echo "ls command test passed"
else
	echo "ls command test failed"
fi
