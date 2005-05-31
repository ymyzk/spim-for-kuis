// SPIM S20 MIPS simulator.
// Definitions for the SPIM S20.
//
// Copyright (C) 1990-2004 by James Larus (larus@cs.wisc.edu).
// ALL RIGHTS RESERVED.
// Changes for DOS and Windows versions by David A. Carley (dac@cs.wisc.edu)
//
// SPIM is distributed under the following conditions:
//
//   You may make copies of SPIM for your own use and modify those copies.
//
//   All copies of SPIM must retain my name and copyright notice.
//
//   You may not sell SPIM or distributed SPIM in conjunction with a
//   commerical product or service without the expressed written consent of
//   James Larus.
//
// THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE.

/* $Header: /Software/SPIM/SPIM/PCSpim/StdAfx.h 1     1/02/05 8:03p Larus $ */

// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows 95 Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxtempl.h>		// MFC template classes

extern "C"
{
#include "..\CPU\spim.h"
#include "..\CPU\string-stream.h"
#include "..\CPU\spim-utils.h"
#include "..\CPU\inst.h"
#include "..\CPU\sym-tbl.h"
#include "..\CPU\reg.h"
#include "..\CPU\mem.h"
#include "..\CPU\scanner.h"
}


#ifdef STDAFX_CPP
#define GLOBAL
#else
#define GLOBAL extern
#endif

class CPCSpimView;

GLOBAL CPCSpimView *g_pView;
GLOBAL BOOL			g_fSaveWinPos;
GLOBAL BOOL			g_fLoadExceptionHandler;
GLOBAL BOOL			g_fRunning;
GLOBAL BOOL			g_fGenRegHex;
GLOBAL BOOL			g_fFPRegHex;
GLOBAL BOOL			g_checkUndefinedSymbols;
GLOBAL CString			g_strCmdLine;
