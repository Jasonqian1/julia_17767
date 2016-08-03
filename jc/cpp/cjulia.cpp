// cjulia.cpp : Defines the exported functions for the DLL application.
//

#include "com_gs_tdriver.h"
#include <julia.h>
#include <sstream>
#include <fstream>
#include <string>
#include <execinfo.h>
#include <signal.h>
#include <iostream>
using namespace std;
#define TRACE_DEPTH 50

#define JULIA 1 

void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    printf("Caught segfault[%d] at address %p\n", signal,si->si_addr);
    void *trace[50];
   int depth;

   FILE* fp;
   depth=backtrace(trace,TRACE_DEPTH);
   const char* tracelog=getenv("/home/jqian2/Julia/jc/java/trace_log.txt");
   fp = fopen(tracelog,"w");
   backtrace_symbols_fd(trace,depth,fileno(fp));
   fclose(fp);
}

JNIEXPORT jstring JNICALL Java_com_gs_tdriver_Call_1julia
  (JNIEnv * env, jobject obj, jstring, jstring)
{
    struct sigaction sa;

    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = segfault_sigaction;
    sa.sa_flags   = SA_SIGINFO;
    //sigaction(SIGSEGV, &sa, NULL);

    jstring result;
    stringstream s;
    double rdv=0.889;
    const char* juliaroot=getenv("JULIA_BIN_DIR");

    jl_init(juliaroot);
    jl_value_t *ret = (jl_value_t*)jl_eval_string("sqrt(2.0)");
    if (jl_is_float64(ret)) {
	rdv = jl_unbox_float64(ret);
    }

    jl_atexit_hook(0);

    s<<rdv;
    result = env->NewStringUTF(s.str().c_str());
    return result;

}
