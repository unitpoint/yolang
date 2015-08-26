#ifndef __YODEF_H__
#define __YODEF_H__

#include <cstdlib>

#ifndef __APPLE__
#include <malloc.h>
#else
#include <malloc/malloc.h>
#endif

#include <assert.h>

#if defined _DEBUG && !defined YO_RELEASE && !defined YO_DEBUG
#define YO_DEBUG
#endif

#ifdef YO_DEBUG

#define YO_ASSERT assert

#define YO_DBG_FILEPOS_DECL , const char * dbg_filename, int dbg_line
#define YO_DBG_FILEPOS_PARAM , dbg_filename, dbg_line
#define YO_DBG_FILEPOS , __FILE__, __LINE__

#define YO_DBG_FILEPOS_START_DECL const char * dbg_filename, int dbg_line
#define YO_DBG_FILEPOS_START_PARAM dbg_filename, dbg_line
#define YO_DBG_FILEPOS_START __FILE__, __LINE__

#else

#define YO_ASSERT(a)

#define YO_DBG_FILEPOS_DECL
#define YO_DBG_FILEPOS_PARAM
#define YO_DBG_FILEPOS

#define YO_DBG_FILEPOS_START_DECL
#define YO_DBG_FILEPOS_START_PARAM
#define YO_DBG_FILEPOS_START

#endif // YO_DEBUG

#define YO_INT8 signed char
#define YO_BYTE unsigned char
#define YO_INT16 short
#define YO_U16 unsigned short

#if defined __GNUC__ 
#include <inttypes.h>

#define YO_INT32 int32_t
#define YO_INT64 int64_t
#define YO_U32 uint32_t
#define YO_U64 uint64_t

#elif defined IW_SDK

#define YO_INT32 int32
#define YO_INT64 int64
#define YO_U32 uint32
#define YO_U64 uint64

#else

#define YO_INT32 __int32
#define YO_INT64 __int64
#define YO_U32 unsigned __int32
#define YO_U64 unsigned __int64

#endif

#endif // __YODEF_H__
