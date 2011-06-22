// ****************************************************************************
// Prelude
// ****************************************************************************
// this file must be passed to the -macros option of the C/C++ parsers in pfff

// ****************************************************************************
// MacroString
// ****************************************************************************

/* String macros are normally handle quite well by the lalr(k) technique,
 * but sometimes it's not enough. For instance in the XX YY case, it could
 * be considered as a declaration with XX being a typedef, so we would
 * have an ambiguity. So by adding a few special cases (e.g. KERN_WARNING
 * for the linux kernel), we can catch more correct string-macros.
 * I need to have at least one witness, a string.
 */
//#define KERN_WARNING "WARNING"

/* EX_TABLE & co. 
 *
 * Replaced by a string. We can't put everything as comment
 * because it can be part of an expression where we wait for
 * something, where we wait for a string. So at least we 
 * must keep the EX_TABLE token and transform it as a string.
 *
 * normally not needed if have good stringification of macro 
 * but those macros are sometimes used multiple times 
 * as in EX_TABLE(0b) EX_TABLE(1b)  and we don't detect
 * it well yet.
 */

//#define EX_TABLE(x)  "TOTO"


// ****************************************************************************
// MacroIterator
// ****************************************************************************

// foreach

// ****************************************************************************
// MacroDeclarator
// ****************************************************************************

// also static DECLARATOR(x);

// also LIST_HEAD stuff 
// used in qemu, freebsd

// ****************************************************************************
// MacroStmt
// ****************************************************************************

// with or without parameters, but no ';'

// ****************************************************************************
// MacroField
// ****************************************************************************

// ****************************************************************************
// MacroInitializer
// ****************************************************************************

// no PTVirg or shortcut for array designator

// ****************************************************************************
// MacroAttributes
// ****************************************************************************

//#define __init YACFE_ATTRIBUTE

// TODO: could perhaps generalize via "__.*"

// linkage

// params (IN, OUT)

// windows: WINAPI, STDCALL, ...
#define WINAPI
#define  __cdecl

// ****************************************************************************
// MacroKeywordAlias
// ****************************************************************************

// const, often defined via macro for backward compatibility with old compiler
// I guess.

// private/public

#define __asm__ asm
#define __attribute __attribute__
#define __volatile__ volatile
#define __restrict __restrict__

#define CONST const

// ****************************************************************************
// Prototype
// ****************************************************************************

// __P

// PARAMS

// ****************************************************************************
// Declarator
// ****************************************************************************

/* cf gcc-linux.h
 * A trick to suppress uninitialized variable warning without generating any
 * code
 */

// #define uninitialized_var(x) x = x
// as in u16 uninitialized_var(ioboard_type);	/* GCC be quiet */ 

// ****************************************************************************
// Misc
// ****************************************************************************

// LIST_HEAD

// GENTEST, GENHEADER

// structure
// MACHINE_START 

// higher order, ASSERTCMP

// parts of stuff, start of stuff

// begin end wierd, as in C++ firefox and NS_DECLARE_BEGIN/END with code in
// the middle

// testcase, reflexivity on name

// IDENT in sparse, wierd case

// if-like macros

//#define G_BEGIN_DECLS

// ****************************************************************************
// git stuff
// ****************************************************************************

#define internal_function
#define NOINLINE
#define FORCEINLINE
#define THROWSPEC
#define NORETURN
#define NORETURN_PTR
#define MAYBE_UNUSED

#define __MINGW_NOTHROW
#define WSAAPI

#define for_each_string_list_item(a,b) for(;;)

// ****************************************************************************
// sparse stuff
// ****************************************************************************

//YACFE_MACROITERATOR
#define FOR_EACH_PTR(a,b) for(;;)
#define FOR_EACH_PTR_NOTAG(a,b) for(;;)
#define FOR_EACH_PTR_REVERSE(a,b) for(;;)

#define RECURSE_PTR_REVERSE(a,b) for(;;)

//#define DO_END_FOR_EACH_REVERSE(a,b,c,d)

#define __percpu
#define SENTINEL_ATTR

#define __user

#define FORMAT_ATTR(a)
#define NORETURN_ATTR

// ****************************************************************************
// Facebook stuff
// ****************************************************************************
// should be moved in a facebook.h at some point instead of abusing macros.h

#define FBUNIT_TEST(a) void a()
#define FBUNIT_FIXTURE_TEST(a, b) void a()
#define FBUNIT_DASHBOARD_OWNER(a)
#define FBUNIT_DASHBOARD_EMAILS(a)

#define BOOST_AUTO_TEST_CASE(a) void a()
#define BOOST_STATIC_ASSERT(a)

#define TEST_F(a,b) void a()
#define TESTFUN(a) void a()
#define BENCHFUN(a) a

// boost?
#define FOR_EACH(a,b) for(;;)
#define FOR_EACH_R(a,b) for(;;)
#define FOR_EACH_RANGE(a,b,c) for(;;) 
#define MY_FOR_EACH(a,b) for(;;) 
#define MY_FOR_EACH_REVERSED(a,b) for(;;)
#define PATRICIA_WALK(a,b) for(;;)

// boost too?
#define lexical_cast static_cast
#define dynamic_pointer_cast static_cast

// google gflags
#define DEFINE_bool(a,b,c) int a = b
#define DEFINE_int32(a,b,c) int a = b
#define DEFINE_int64(a,b,c) int a = b
#define DEFINE_string(a,b,c) int a = b

#define EC_DECLARE_HOOK(module,type,name,typedefargs,declargs,callargs,handleret) void name(void)

#define ON_ERROR(a) if(a)
#define DBLOG(a, stmt) stmt

#define DISALLOW_EVIL_CONSTRUCTORS(a)


#define _T(s) s

#define SOAP_FMAC1
#define SOAP_FMAC2
#define SOAP_FMAC3
#define SOAP_FMAC4

#define THRIFT_NOEXCEPT

#define REMOTE_CATCH(a,b) catch() { }
