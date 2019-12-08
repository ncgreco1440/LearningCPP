#!/bin/bash
# creates a new C++ Project

WORKING_DIR=$PWD
BASEDIR=$(dirname "$0")
PROJECT_NAME=$1
echo "Creating new Project: ${PROJECT_NAME}..."
PROJECT_EXISTS=`find -maxdepth 1 -type d -name ${PROJECT_NAME}`

if [ -n "$PROJECT_EXISTS" ]; then
    echo "A project named ${PROJECT_NAME} already exists"
else
    mkdir $PROJECT_NAME;
    sleep 1; # the cp will execute before mkdir has actually finished or something of the sort.
    cp -r $BASEDIR/templates/cpp/. $WORKING_DIR/$PROJECT_NAME;
    cd $WORKING_DIR/$PROJECT_NAME;
    code .
fi