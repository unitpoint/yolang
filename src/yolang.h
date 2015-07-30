#ifndef __YOLANG_H__
#define __YOLANG_H__

#ifndef __APPLE__
#include <malloc.h>
#else
#include <malloc/malloc.h>
#endif

#include <assert.h>
#include "yoparser.h"

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

#endif // __YOLANG_H__
