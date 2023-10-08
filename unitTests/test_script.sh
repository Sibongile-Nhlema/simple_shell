#!/bin/bash

# Define the commands to be executed
commands=("ls" "pwd" "echo Hello, World!" "date")

# Execute the commands in the normal shell and store the output
normal_output=""
for command in "${commands[@]}"; do
	normal_output+="Command: $command\n"
	normal_output+="Output:\n"
	normal_output+=$(eval "$command")
	normal_output+="\n\n"
done

# Execute the commands in your simple shell and store the output
simple_output=""
for command in "${commands[@]}"; do
	simple_output+="Command: $command\n"
	simple_output+="Output:\n"
	simple_output+=$(./your_simple_shell "$command")
	simple_output+="\n\n"
done

# Compare the output of both shells
if [[ "$normal_output" == "$simple_output" ]]; then
	echo "Both shells produce the same output."
else
	echo "There are differences between the shells' output."
	echo "Normal Shell Output:"
	echo "$normal_output"
	echo "Simple Shell Output:"echo "
	echo "$simple_output"
fi
