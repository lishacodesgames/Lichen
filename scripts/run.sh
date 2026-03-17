#!/usr/bin/env bash

if [ -z "$1" ]; then
   echo "Usage: ./scripts/run.sh <preset> (from root)"
   exit 1
fi   

PRESET=$1
EXEC=./bin/$PRESET/Sandbox/Sandbox

if [ ! -f "$EXEC" ]; then
   echo "Executable not found: $EXEC"
   exit 1
fi

"$EXEC"