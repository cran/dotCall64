#include<R.h>
#include<Rinternals.h>
#include<R_ext/Rdynload.h>
#include<stdio.h>


/* See http://cran.r-project.org/doc/manuals/R-exts.html#C_002dlevel-messages */
#ifdef ENABLE_NLS
#include <libintl.h>
#define _(String) dgettext ("pkg", String)
/* replace pkg as appropriate */
#else
#define _(String) (String)
#endif



/*

The following lines are copied from R source: src/main/dotcode.c:1685-2277

*/

void dotCall64_callFunction(DL_FUNC fun, int nargs, void **cargs) {
	switch (nargs) {
	case 0:
		/* Silicon graphics C chokes here */
		/* if there is no argument to fun. */
		fun(0);
		break;
	case 1:
		fun(cargs[0]);
		break;
	case 2:
		fun(cargs[0], cargs[1]);
		break;
	case 3:
		fun(cargs[0], cargs[1], cargs[2]);
		break;
	case 4:
		fun(cargs[0], cargs[1], cargs[2], cargs[3]);
		break;
	case 5:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4]);
		break;
	case 6:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5]);
		break;
	case 7:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6]);
		break;
	case 8:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7]);
		break;
	case 9:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8]);
		break;
	case 10:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9]);
		break;
	case 11:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10]);
		break;
	case 12:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11]);
		break;
	case 13:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12]);
		break;
	case 14:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13]);
		break;
	case 15:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14]);
		break;
	case 16:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15]);
		break;
	case 17:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16]);
		break;
	case 18:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17]);
		break;
	case 19:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18]);
		break;
	case 20:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19]);
		break;
	case 21:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20]);
		break;
	case 22:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21]);
		break;
	case 23:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22]);
		break;
	case 24:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23]);
		break;
	case 25:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24]);
		break;
	case 26:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25]);
		break;
	case 27:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26]);
		break;
	case 28:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27]);
		break;
	case 29:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28]);
		break;
	case 30:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29]);
		break;
	case 31:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30]);
		break;
	case 32:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31]);
		break;
	case 33:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32]);
		break;
	case 34:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33]);
		break;
	case 35:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34]);
		break;
	case 36:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35]);
		break;
	case 37:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36]);
		break;
	case 38:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37]);
		break;
	case 39:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38]);
		break;
	case 40:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39]);
		break;
	case 41:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40]);
		break;
	case 42:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41]);
		break;
	case 43:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42]);
		break;
	case 44:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43]);
		break;
	case 45:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44]);
		break;
	case 46:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45]);
		break;
	case 47:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46]);
		break;
	case 48:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47]);
		break;
	case 49:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48]);
		break;
	case 50:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49]);
		break;
	case 51:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50]);
		break;
	case 52:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51]);
		break;
	case 53:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52]);
		break;
	case 54:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53]);
		break;
	case 55:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54]);
		break;
	case 56:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
				cargs[55]);
		break;
	case 57:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
				cargs[55], cargs[56]);
		break;
	case 58:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
				cargs[55], cargs[56], cargs[57]);
		break;
	case 59:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
				cargs[55], cargs[56], cargs[57], cargs[58]);
		break;
	case 60:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
				cargs[55], cargs[56], cargs[57], cargs[58], cargs[59]);
		break;
	case 61:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
				cargs[55], cargs[56], cargs[57], cargs[58], cargs[59],
				cargs[60]);
		break;
	case 62:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
				cargs[55], cargs[56], cargs[57], cargs[58], cargs[59],
				cargs[60], cargs[61]);
		break;
	case 63:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
				cargs[55], cargs[56], cargs[57], cargs[58], cargs[59],
				cargs[60], cargs[61], cargs[62]);
		break;
	case 64:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
				cargs[55], cargs[56], cargs[57], cargs[58], cargs[59],
				cargs[60], cargs[61], cargs[62], cargs[63]);
		break;
	case 65:
		fun(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
				cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
				cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
				cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
				cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
				cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
				cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
				cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
				cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
				cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
				cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
				cargs[55], cargs[56], cargs[57], cargs[58], cargs[59],
				cargs[60], cargs[61], cargs[62], cargs[63], cargs[64]);
		break;
	default:
		error(_("too many arguments, sorry"));
	}
}
