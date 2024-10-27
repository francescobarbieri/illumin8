#!/bin/bash

SRC_DIRS="src/core src/scenes src/materials src/renderers src/objects src/display src/shapes src/helpers"
DEST_DIR="include/Illumin8"

echo "Starting to copy headers..."

for dir in $SRC_DIRS; do
    cp $dir/*.h $DEST_DIR/ 2>> script.log
done

echo "Headers copied successfully to $DEST_DIR"