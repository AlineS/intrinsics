/**
 * Aline Santana Cordeiro - ascordeiro@inf.ufpr.br
 * LSE - Embedded Sistems Laboratory - 2018
 * PPGInf - Federal University of Paraná
 */

#include "vima.hpp"

__v32s *a32s64, *b32s64, *c32s64, *a32s2K, *b32s2K, *c32s2K, b32s = 1;
__v32u *a32u64, *b32u64, *c32u64, *a32u2K, *b32u2K, *c32u2K, b32u = 1;
__v64s *a64s32, *b64s32, *c64s32, *a64s1K, *b64s1K, *c64s1K;
__v64u *a64u32, *b64u32, *c64u32, *a64u1K, *b64u1K, *c64u1K;
__v32f *a32f64, *b32f64, *c32f64, *a32f2K, *b32f2K, *c32f2K, b32f = 1.0;
__v64d *a64d32, *b64d32, *c64d32, *a64d1K, *b64d1K, *c64d1K, b64d = 1.0;

int main() {
    srand(time(NULL));

    a32s64 = (__v32s *)malloc(sizeof(__v32s) * VM64I);
    b32s64 = (__v32s *)malloc(sizeof(__v32s) * VM64I);
    c32s64 = (__v32s *)malloc(sizeof(__v32s) * VM64I);

    a32u64 = (__v32u *)malloc(sizeof(__v32u) * VM64I);
    b32u64 = (__v32u *)malloc(sizeof(__v32u) * VM64I);
    c32u64 = (__v32u *)malloc(sizeof(__v32u) * VM64I);

    for (int i = 0; i < VM64I; i++) {
        a32s64[i] = 1 + (1 + (rand() % 10)); b32s64[i] = 1 + (rand() % 10);
        a32u64[i] = 1 + (1 + (rand() % 10)); b32u64[i] = 1 + (rand() % 10);
    }

// --------------------------------------------------------------------------

    a32s2K = (__v32s *)malloc(sizeof(__v32s) * VM2KI);
    b32s2K = (__v32s *)malloc(sizeof(__v32s) * VM2KI);
    c32s2K = (__v32s *)malloc(sizeof(__v32s) * VM2KI);

    a32u2K = (__v32u *)malloc(sizeof(__v32u) * VM2KI);
    b32u2K = (__v32u *)malloc(sizeof(__v32u) * VM2KI);
    c32u2K = (__v32u *)malloc(sizeof(__v32u) * VM2KI);

    for (int i = 0; i < VM2KI; i++) {
        a32s2K[i] = 1 + (rand() % 10); b32s2K[i] = 1 + (rand() % 10);
        a32u2K[i] = 1 + (rand() % 10); b32u2K[i] = 1 + (rand() % 10);
    }

// --------------------------------------------------------------------------

    a64s32 = (__v64s *)malloc(sizeof(__v64s) * VM32L);
    b64s32 = (__v64s *)malloc(sizeof(__v64s) * VM32L);
    c64s32 = (__v64s *)malloc(sizeof(__v64s) * VM32L);

    a64u32 = (__v64u *)malloc(sizeof(__v64u) * VM32L);
    b64u32 = (__v64u *)malloc(sizeof(__v64u) * VM32L);
    c64u32 = (__v64u *)malloc(sizeof(__v64u) * VM32L);

    for (int i = 0; i < VM32L; i++) {
        a64s32[i] = 1 + (rand() % 10); b64s32[i] = 1 + (rand() % 10);
        a64u32[i] = 1 + (rand() % 10); b64u32[i] = 1 + (rand() % 10);
    }

// --------------------------------------------------------------------------

    a64s1K = (__v64s *)malloc(sizeof(__v64s) * VM1KL);
    b64s1K = (__v64s *)malloc(sizeof(__v64s) * VM1KL);
    c64s1K = (__v64s *)malloc(sizeof(__v64s) * VM1KL);

    a64u1K = (__v64u *)malloc(sizeof(__v64u) * VM1KL);
    b64u1K = (__v64u *)malloc(sizeof(__v64u) * VM1KL);
    c64u1K = (__v64u *)malloc(sizeof(__v64u) * VM1KL);

    for (int i = 0; i < VM1KL; i++) {
        a64s1K[i] = 1 + (rand() % 10); b64s1K[i] = 1 + (rand() % 10);
        a64u1K[i] = 1 + (rand() % 10); b64u1K[i] = 1 + (rand() % 10);
    }

// --------------------------------------------------------------------------

    a32f64 = (__v32f *)malloc(sizeof(__v32f) * VM64I);
    b32f64 = (__v32f *)malloc(sizeof(__v32f) * VM64I);
    c32f64 = (__v32f *)malloc(sizeof(__v32f) * VM64I);

    a32f2K = (__v32f *)malloc(sizeof(__v32f) * VM64I);
    b32f2K = (__v32f *)malloc(sizeof(__v32f) * VM64I);
    c32f2K = (__v32f *)malloc(sizeof(__v32f) * VM64I);

    for (int i = 0; i < VM64I; i++) {
        a32f64[i] = 1 + (rand() % 10); b32f64[i] = 1 + (rand() % 10);
        a32f2K[i] = 1 + (rand() % 10); b32f2K[i] = 1 + (rand() % 10);
    }

// --------------------------------------------------------------------------

    a64d32 = (__v64d *)malloc(sizeof(__v64d) * VM32L);
    b64d32 = (__v64d *)malloc(sizeof(__v64d) * VM32L);
    c64d32 = (__v64d *)malloc(sizeof(__v64d) * VM32L);

    a64d1K = (__v64d *)malloc(sizeof(__v64d) * VM32L);
    b64d1K = (__v64d *)malloc(sizeof(__v64d) * VM32L);
    c64d1K = (__v64d *)malloc(sizeof(__v64d) * VM32L);

    for (int i = 0; i < VM32L; i++) {
        a64d32[i] = (((__v64d)rand() / (__v64d)(RAND_MAX)) * 10.0) - ((__v64d)rand() / (__v64d)(RAND_MAX)*10.0);
        b64d32[i] = (((__v64d)rand() / (__v64d)(RAND_MAX)) * 10.0) - ((__v64d)rand() / (__v64d)(RAND_MAX)*10.0);
        a64d1K[i] = (((__v64d)rand() / (__v64d)(RAND_MAX)) * 10.0) - ((__v64d)rand() / (__v64d)(RAND_MAX)*10.0);
        b64d1K[i] = (((__v64d)rand() / (__v64d)(RAND_MAX)) * 10.0) - ((__v64d)rand() / (__v64d)(RAND_MAX)*10.0);
    }

// --------------------------------------------------------------------------

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 01 *");
    printf("%s\n", "***************");

    _vim64_iadds(a32s64, b32s64, c32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 02 *");
    printf("%s\n", "***************");

    _vim2K_iadds(a32s2K, b32s2K, c32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 03 *");
    printf("%s\n", "***************");

    _vim64_iaddu(a32u64, b32u64, c32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 04 *");
    printf("%s\n", "***************");

    _vim2K_iaddu(a32u2K, b32u2K, c32u2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 05 *");
    printf("%s\n", "***************");

    _vim64_isubs(a32s64, b32s64, c32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 06 *");
    printf("%s\n", "***************");

    _vim2K_isubs(a32s2K, b32s2K, c32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 07 *");
    printf("%s\n", "***************");

    _vim64_isubu(a32u64, b32u64, c32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 08 *");
    printf("%s\n", "***************");

    _vim2K_isubu(a32u2K, b32u2K, c32u2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 09 *");
    printf("%s\n", "***************");

    _vim64_iabss(b32s64, c32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 10 *");
    printf("%s\n", "***************");

    _vim2K_iabss(b32s2K, c32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 11 *");
    printf("%s\n", "***************");

    _vim64_imaxs(a32s64, b32s64, c32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 12 *");
    printf("%s\n", "***************");

    _vim2K_imaxs(a32s2K, b32s2K, c32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 13 *");
    printf("%s\n", "***************");

    _vim64_imins(a32s64, b32s64, c32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 14 *");
    printf("%s\n", "***************");

    _vim2K_imins(a32s2K, b32s2K, c32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 15 *");
    printf("%s\n", "***************");

    _vim64_icpys(a32s64, c32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 16 *");
    printf("%s\n", "***************");

    _vim2K_icpys(a32s2K, c32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 17 *");
    printf("%s\n", "***************");

    _vim64_icpyu(a32u64, c32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 18 *");
    printf("%s\n", "***************");

    _vim2K_icpyu(a32u2K, c32u2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 19 *");
    printf("%s\n", "***************");

    _vim64_iandu(a32u64, b32u64, c32u64);

    /*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 20 *");
    printf("%s\n", "***************");

    _vim2K_iandu(a32u2K, b32u2K, c32u2K);

/*****************************************************************************/
    printf("%s\n", "***************");
    printf("%s\n", "* Operação 21 *");
    printf("%s\n", "***************");

    _vim64_iorun(a32u64, b32u64, c32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 22 *");
    printf("%s\n", "***************");

    _vim2K_iorun(a32u2K, b32u2K, c32u2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 23 *");
    printf("%s\n", "***************");

    _vim64_ixoru(a32u64, b32u64, c32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 24 *");
    printf("%s\n", "***************");

    _vim2K_ixoru(a32u2K, b32u2K, c32u2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 25 *");
    printf("%s\n", "***************");

    _vim64_inots(a32s64, b32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 26 *");
    printf("%s\n", "***************");

    _vim2K_inots(a32s2K, b32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 27 *");
    printf("%s\n", "***************");

    _vim64_islts(a32s64, b32s64, c32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 28 *");
    printf("%s\n", "***************");

    _vim2K_islts(a32s2K, b32s2K, c32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 29 *");
    printf("%s\n", "***************");

    _vim64_isltu(a32u64, b32u64, c32u64);

    /*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 30 *");
    printf("%s\n", "***************");

    _vim2K_isltu(a32u2K, b32u2K, c32u2K);

    /*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 31 *");
    printf("%s\n", "***************");

    _vim64_icmqs(a32s64, b32s64, c32s64);    

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 32 *");
    printf("%s\n", "***************");

    _vim2K_icmqs(a32s2K, b32s2K, c32s2K);

/*****************************************************************************/
    printf("%s\n", "***************");
    printf("%s\n", "* Operação 33 *");
    printf("%s\n", "***************");

    _vim64_icmqu(a32u64, b32u64, c32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 34 *");
    printf("%s\n", "***************");

    _vim2K_icmqu(a32u2K, b32u2K, c32u2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 35 *");
    printf("%s\n", "***************");

    _vim64_isllu(a32u64, b32u64, c32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 36 *");
    printf("%s\n", "***************");

    _vim2K_isllu(a32u2K, b32u2K, c32u2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 37 *");
    printf("%s\n", "***************");

    _vim64_isrlu(a32u64, b32u64, c32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 38 *");
    printf("%s\n", "***************");

    _vim2K_isrlu(a32u2K, b32u2K, c32u2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 39 *");
    printf("%s\n", "***************");

    _vim64_isras(a32s64, b32s64, c32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 40 *");
    printf("%s\n", "***************");

    _vim2K_isras(a32s2K, b32s2K, c32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 41 *");
    printf("%s\n", "***************");

    _vim64_idivs(a32s64, b32s64, c32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 42 *");
    printf("%s\n", "***************");

    _vim2K_idivs(a32s2K, b32s2K, c32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 43 *");
    printf("%s\n", "***************");

    _vim64_idivu(a32u64, b32u64, c32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 44 *");
    printf("%s\n", "***************");

    _vim2K_idivu(a32u2K, b32u2K, c32u2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 45 *");
    printf("%s\n", "***************");

    _vim32_idivs(a64s32, b64s32, c64s32);

    /*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 46 *");
    printf("%s\n", "***************");

    _vim1K_idivs(a64s1K, b64s1K, c64s1K);

    /*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 47 *");
    printf("%s\n", "***************");

    _vim32_idivu(a64u32, b64u32, c64u32);

    /*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 48 *");
    printf("%s\n", "***************");

    _vim1K_idivu(a64u1K, b64u1K, c64u1K);

    /*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 49 *");
    printf("%s\n", "***************");

    _vim64_imuls(a32s64, b32s64, c32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 50 *");
    printf("%s\n", "***************");

    _vim2K_imuls(a32s2K, b32s2K, c32s2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 51 *");
    printf("%s\n", "***************");

    _vim64_imulu(a32u64, b32u64, c32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 52 *");
    printf("%s\n", "***************");

    _vim2K_imulu(a32u2K, b32u2K, c32u2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 53 *");
    printf("%s\n", "***************");

    _vim32_imuls(a64s1K, b64s1K, c64s1K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 54 *");
    printf("%s\n", "***************");

    _vim1K_imuls(a64s1K, b64s1K, c64s1K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 55 *");
    printf("%s\n", "***************");

    _vim32_imulu(a64u32, b64u32, c64u32);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 56 *");
    printf("%s\n", "***************");

    _vim1K_imulu(a64u1K, b64u1K, c64u1K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 57 *");
    printf("%s\n", "***************");

    _vim64_icumu(a32u64, &b32u);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 58 *");
    printf("%s\n", "***************");

    _vim2K_icumu(a32u2K, &b32u);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 59 *");
    printf("%s\n", "***************");

    _vim64_icums(a32s64, &b32s);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 60 *");
    printf("%s\n", "***************");

    _vim2K_icums(a32s2K, &b32s);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 61 *");
    printf("%s\n", "***************");

    _vim64_imovs(b32s, a32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 62 *");
    printf("%s\n", "***************");

    _vim2K_imovs(b32s, a32s64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 63 *");
    printf("%s\n", "***************");

    _vim64_imovu(b32u, a32u64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 64 *");
    printf("%s\n", "***************");

    _vim2K_imovu(b32u, a32u64);


/*****************************************************************************
 * FLOATING-POINT SINGLE PRECISION INSTRUCTIONS
 *****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 65 *");
    printf("%s\n", "***************");

    _vim64_fadds(a32f64, b32f64, c32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 66 *");
    printf("%s\n", "***************");

    _vim2K_fadds(a32f2K, b32f2K, c32f2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 67 *");
    printf("%s\n", "***************");

    _vim64_fsubs(a32f64, b32f64, c32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 68 *");
    printf("%s\n", "***************");

    _vim2K_fsubs(a32f2K, b32f2K, c32f2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 69 *");
    printf("%s\n", "***************");

    _vim64_fabss(a32f64, b32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 70 *");
    printf("%s\n", "***************");

    _vim2K_fabss(a32f2K, b32f2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 71 *");
    printf("%s\n", "***************");

    _vim64_fmaxs(a32f64, b32f64, c32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 72 *");
    printf("%s\n", "***************");

    _vim2K_fmaxs(a32f2K, b32f2K, c32f2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 73 *");
    printf("%s\n", "***************");

    _vim64_fmins(a32f64, b32f64, c32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 74 *");
    printf("%s\n", "***************");

    _vim2K_fmins(a32f2K, b32f2K, c32f2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 75 *");
    printf("%s\n", "***************");

    _vim64_fcpys(a32f64, b32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 76 *");
    printf("%s\n", "***************");

    _vim2K_fcpys(a32f2K, b32f2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 77 *");
    printf("%s\n", "***************");

    _vim64_fslts(a32f64, b32f64, c32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 78 *");
    printf("%s\n", "***************");

    _vim2K_fslts(a32f2K, b32f2K, c32f2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 79 *");
    printf("%s\n", "***************");

    _vim64_fcmqs(a32f64, b32f64, c32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 80 *");
    printf("%s\n", "***************");

    _vim2K_fcmqs(a32f2K, b32f2K, c32f2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 81 *");
    printf("%s\n", "***************");

    _vim64_fdivs(a32f64, b32f64, c32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 82 *");
    printf("%s\n", "***************");

    _vim2K_fdivs(a32f2K, b32f2K, c32f2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 83 *");
    printf("%s\n", "***************");

    _vim64_fmuls(a32f64, b32f64, c32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 84 *");
    printf("%s\n", "***************");

    _vim2K_fmuls(a32f2K, b32f2K, c32f2K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 85 *");
    printf("%s\n", "***************");

    _vim64_fcums(a32f64, &b32f);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 86 *");
    printf("%s\n", "***************");

    _vim2K_fcums(a32f2K, &b32f);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 87 *");
    printf("%s\n", "***************");

    _vim64_fmovs(b32f, a32f64);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 88 *");
    printf("%s\n", "***************");

    _vim2K_fmovs(b32f, a32f2K);

/*****************************************************************************
 * FLOATING-POINT SINGLE PRECISION INSTRUCTIONS
 *****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 89 *");
    printf("%s\n", "***************");

    _vim32_dadds(a64d32, b64d32, c64d32);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 90 *");
    printf("%s\n", "***************");

   _vim1K_dadds(a64d1K, b64d1K, c64d1K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 91 *");
    printf("%s\n", "***************");

    _vim32_dsubs(a64d32, b64d32, c64d32);
    
/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 92 *");
    printf("%s\n", "***************");

    _vim1K_dsubs(a64d1K, b64d1K, c64d1K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 93 *");
    printf("%s\n", "***************");

    _vim32_dabss(a64d32, b64d32);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 94 *");
    printf("%s\n", "***************");

    _vim1K_dabss(a64d1K, b64d1K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 95 *");
    printf("%s\n", "***************");

    _vim32_dmaxs(a64d32, b64d32, c64d32);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 96 *");
    printf("%s\n", "***************");

    _vim1K_dmaxs(a64d1K, b64d1K, c64d1K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 97 *");
    printf("%s\n", "***************");

    _vim32_dmins(a64d32, b64d32, c64d32);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 98 *");
    printf("%s\n", "***************");

    _vim1K_dmins(a64d1K, b64d1K, c64d1K);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 99 *");
    printf("%s\n", "***************");

    _vim32_dcpys(a64d32, b64d32);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 100 *");
    printf("%s\n", "****************");

    _vim1K_dcpys(a64d1K, b64d1K);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 101 *");
    printf("%s\n", "****************");

    _vim32_dslts(a64d32, b64d32, c64d32);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 102 *");
    printf("%s\n", "****************");

    _vim1K_dslts(a64d1K, b64d1K, c64d1K);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 103 *");
    printf("%s\n", "****************");

    _vim32_dcmqs(a64d32, b64d32, c64d32);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 104 *");
    printf("%s\n", "****************");

    _vim1K_dcmqs(a64d1K, b64d1K, c64d1K);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 105 *");
    printf("%s\n", "****************");

    _vim32_ddivs(a64d32, b64d32, c64d32);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 106 *");
    printf("%s\n", "****************");

    _vim1K_ddivs(a64d1K, b64d1K, c64d1K);

    /*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 107 *");
    printf("%s\n", "****************");

    _vim32_dmuls(a64d32, b64d32, c64d32);
    
/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 108 *");
    printf("%s\n", "****************");

    _vim1K_dmuls(a64d1K, b64d1K, c64d1K);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 109 *");
    printf("%s\n", "****************");

    _vim32_dcums(a64d32, &b64d);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 110 *");
    printf("%s\n", "****************");

    _vim1K_dcums(a64d1K, &b64d);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 111 *");
    printf("%s\n", "****************");

    _vim32_dmovs(b64d, a64d32);

/*****************************************************************************/

    printf("%s\n", "****************");
    printf("%s\n", "* Operação 112 *");
    printf("%s\n", "****************");

    _vim1K_dmovs(b64d, a64d1K);

    return 0;
}
