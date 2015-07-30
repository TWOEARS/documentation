#!/bin/bash
VERSION="$(git symbolic-ref HEAD 2>/dev/null)" || VERSION="(unnamed branch)"
VERSION=${VERSION##refs/heads/}
if [ ${VERSION}=='master' ]; then VERSION=latest; fi
echo ${VERSION}
