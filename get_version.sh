#!/bin/bash
VERSION=$(git rev-parse --abbrev-ref HEAD) # get curent branch name
if [ ${VERSION}=='master' ]; then VERSION=latest; fi
echo ${VERSION}
