#!/bin/sh
cd multithreaded-engine
./build.sh
cd ../multithreaded-test
./build.sh
./run.sh
cd ../multithreaded-engine
./run.sh
