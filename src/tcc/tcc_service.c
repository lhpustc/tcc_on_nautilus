#include "tcc.h"
//tcc_run(TCCState*, int, char**);
int handle_tcc_script(char *tcc_program) {

// nk_vc_printf("\nBegin handle_tcc_script 0..");
	TCCState *s;
	int (*func)();
	int ret;
    
    nk_vc_printf("Initiate TCC State...");
	s = tcc_new();
	if (!s) {
		nk_vc_printf("\nCould not create tcc state\n");
		return NULL;
	}
	tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
	nk_vc_printf("Done\n");

    nk_vc_printf("Compile program...");
	if (tcc_compile_string(s,tcc_program) == -1) {
		nk_vc_printf("\nCould not compile program\n");
		return NULL;
	}
    nk_vc_printf("Done\n");

    nk_vc_printf("Run program...");
	ret = tcc_run(s,0,"");
	nk_vc_printf("Done\n");

	return ret;

	// nk_vc_printf("\n-------------------\nResult from user input is %d\n-------------\n",tcc_run(s,0,""));
}
