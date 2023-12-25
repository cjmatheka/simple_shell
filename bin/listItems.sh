#!/bin/bash

listItems()
{
    # Check if a directory is provided, otherwise use the current directory
    local dir="${1:-.}"

    # List files and directories in a formatted way
    for file in "$dir"/*; do
        # Extract file/directory name from the path
        local name=$(basename "$file")
        echo "$name"
    done
}
