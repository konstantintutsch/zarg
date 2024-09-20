#!/bin/bash

rsync -rvz --progress --delete ./build/doc/html/ konstantin@konstantintutsch.com:/mnt/HC_Volume_101048932/zarg
