#!/bin/sh
DIRECTORY="build"
if [ -d "$DIRECTORY" ]
then
    echo "$DIRECTORY exists on your filesystem."
else
  mkdir $DIRECTORY
fi
cd $DIRECTORY

# generate the build system
cmake ../

# manually copy over the library files we need to a folder in this build ...
cp "../../multithreaded-engine/build/src/db/libmultithreaded-engine-src-db.a" lib/.
cp "../../multithreaded-engine/build/src/util/libmultithreaded-engine-src-util.a" lib/.
cp "../../multithreaded-engine/build/src/receiver/libmultithreaded-engine-src-receiver.a" lib/.
cp "../../multithreaded-engine/build/src/thread_wrapper/libmultithreaded-engine-src-thread_wrapper.a" lib/.
cp "../../multithreaded-engine/build/src/transmitter/libmultithreaded-engine-src-transmitter.a" lib/.

# ... and add their names to end of the one-line list of library files in the link.txt file
truncate --size -1 ./CMakeFiles/multithreaded-test.dir/link.txt
LIBRARIES="\
lib/libmultithreaded-engine-src-db.a \
lib/libmultithreaded-engine-src-util.a \
lib/libmultithreaded-engine-src-receiver.a \
lib/libmultithreaded-engine-src-thread_wrapper.a \
lib/libmultithreaded-engine-src-transmitter.a " 
echo -n $LIBRARIES >> ./CMakeFiles/multithreaded-test.dir/link.txt

# run the build
make VERBOSE=1
