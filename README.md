# Multithreaded System

## Specs

* Linux distro "Pop!_OS 21.10"
* cmake version 3.18.4
* The CXX compiler identification is GNU 11.2.0

## Description

This system is capable of responding to external signals by creating more threads to get work done.

There are 2 projects in this system.

* multithreaded-engine: builds executable multithreaded-engine which is a data processor that responds to externally transmitted signals
* multithreaded-test: builds executable multithreaded-test which is a unit test program using google test

## Build & Run

You can build & run both projects with the single script [pipeline.sh](pipeline.sh).

You can also build & run just the multithreaded-engine project with the 2 scripts [engine build.sh](multithreaded-engine/build.sh) and [engine run.sh](multithreaded-engine/run.sh).

You can also build & run just the multithreaded-test project with the 2 scripts [test build.sh](multithreaded-test/build.sh) and [test run.sh](multithreaded-test/run.sh).  Note that the test build depends upon the engine build having been completed already.

## Sending a signal

* 
* 
* 
* 

### Output Logging

When you run the engine using the run.sh script it will automatically redirect program stdout to the io/output/output.txt file.

You will also find a sample version of this output file there.

[Sample Output](multithreaded-engine/io/output/output_sample.txt)
