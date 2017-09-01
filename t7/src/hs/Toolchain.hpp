#pragma once


/*************************************************************************************************************
**************************************************************************************************************
    Toolchain / Compiler detection

    HS_TOOLCHAIN_MSC       Microsoft Visual C++
        HS_MSC_VERSION         Version of MSC
    HS_TOOLCHAIN_GCC       Gnu Compiler Collection
        HS_GCC_VERSION         Version of GCC
    HS_TOOLCHAIN_CLANG     Clang/LLVM
        HS_CLANG_VERSION       Version of Clang

*************************************************************************************************************/

#undef HS_TOOLCHAIN_MSC
    #undef HS_MSC_VERSION
#undef HS_TOOLCHAIN_GCC
    #undef HS_GCC_VERSION
#undef HS_TOOLCHAIN_CLANG
    #undef HS_CLANG_VERSION

#if defined(_MSC_VER)
    #define HS_TOOLCHAIN_MSC
    // MSC 1800 for MSVC 12.0 in Visual Studio 2013; MSC 1700 for MSVC 11.0 in Visual Studio 2012
    #define HS_MSC_VERSION _MSC_VER
#elif defined(__GNUC__)
    #define HS_TOOLCHAIN_GCC
    // GNU Compiler Collection Version: 4.9.1 ==> 40901
    #define HS_GCC_VERSION (__GNUC__ * 10000  + __GNUC_MINOR__ * 100  + __GNUC_PATCHLEVEL__)
#elif defined(__clang__)
    #define HS_TOOLCHAIN_CLANG
    // Clang Version: 3.5.12 ==> 30512
    #define HS_CLANG_VERSION (__clang_major__ * 10000  + __clang_minor__ * 100  + __clang_patchlevel__)
#else
    #error unknown toolchain
#endif // toolchain

