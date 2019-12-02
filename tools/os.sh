#!/bin/bash
# OS - figure out what Operating System we are on.
# Leverage the OSTYPE variable. This will only work within bash-type clis
# so cmd prompt will not yeild appropriate results.


case "$OSTYPE" in
    solaris*)   echo "SOLARIS" ;;
    darwin*)    echo "OSX" ;;
    linux*)     echo "LINUX" ;;
    bsd*)       echo "BSD" ;;
    msys*)      echo "WINDOWS" ;;
    *)          echo "UNKNOWN"
esac