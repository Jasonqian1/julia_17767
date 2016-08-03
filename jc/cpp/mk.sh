rm *.o
rm *.so

JULIA_DIR=/home/jqian2/Julia/julia-2e358ce975

JNI_ROOT=/home/jqian2/GServer/jdk1.7.0_71/include

JULIA_INC=$JULIA_DIR/include/julia
JULIA_LIB=$JULIA_DIR/lib/julia


g++ -c -g -W -O3 -m64 -fPIC cjulia.cpp -I$JULIA_INC -I$JNI_ROOT -I$JNI_ROOT/linux

echo g++ -O3 -g -shared -m64 -WI -fPIC -o./libcjulia.so cjulia.o -L$JULIA_LIB -ljulia 
g++ -O3 -g -shared -m64 -WI -fPIC -o./libcjulia.so cjulia.o -L$JULIA_LIB -ljulia 

