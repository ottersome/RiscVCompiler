#!/bin/bash


runInDirRecursive(){
    for single in $(ls $1)
    do
#        echo "Working with ${single}"
        if [[ -d $single ]]; then
            #runInDirRecursive $single
            echo $single
        else
            echo "Running ${single}"
            echo $(./parser < $single) 
        fi
    done
}

runInDirRecursive "./testcases/no-parsing-error/*"
