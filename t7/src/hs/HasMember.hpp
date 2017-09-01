#pragma once

/*************************************************************************************************************
**************************************************************************************************************
  See http://binglongx.com/2014/10/10/sfinae-to-check-existence-of-member-type-variable-or-function/

Usage example:

    HS_HAS_MEMBER_TYPE(Abc)
    HS_HAS_MEMBER_TYPE(Def)
    HS_HAS_MEMBER(hij)
    HS_HAS_MEMBER(klm)

    struct C { 
        using Abc = int; 
        float hij;
    };

    static_assert(hasMemberType_Abc<C>::value, "");
    static_assert(!hasMemberType_Def<C>::value, "");

    static_assert(hasMember_hij<C>::value, "");
    static_assert(!hasMember_klm<C>::value, "");

*************************************************************************************************************/

// checker class templates
#define HS_HAS_MEMBER_TYPE(MemberType) \
    namespace { \
        template<class T> class hasMemberType_##MemberType \
                { \
            struct big { char a[2]; }; \
            template<class C> static big  probe(typename C::MemberType*); \
            template<class C> static char probe(...); \
        public: \
            static const bool value = sizeof(probe<T>(nullptr)) > 1; \
                }; \
        }

#define HS_HAS_MEMBER(Member)   \
    namespace { \
        template<class T> class hasMember_##Member \
                { \
            struct big { char a[2]; }; \
            template<class C> static big  probe(decltype(&C::Member)); \
            template<class C> static char probe(...); \
        public: \
            static const bool value = sizeof(probe<T>(nullptr)) > 1; \
                }; \
        }
