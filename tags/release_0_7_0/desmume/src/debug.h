#ifndef DEBUG_H
#define DEBUG_H

#include "types.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { DEBUG_STRING, DEBUG_STREAM , DEBUG_STDOUT, DEBUG_STDERR } DebugOutType;

typedef struct {
	DebugOutType output_type;
	union {
		FILE * stream;
		char * string;
	} output;
	char * name;
} Debug;

Debug * DebugInit(const char *, DebugOutType, char *);
void DebugDeInit(Debug *);

void DebugChangeOutput(Debug *, DebugOutType, char *);

void DebugPrintf(Debug *, const char *, u32, const char *, ...);

extern Debug * MainLog;

void LogStart(void);
void LogStop(void);

#ifdef DEBUG
#define LOG(...) DebugPrintf(MainLog, __FILE__, __LINE__, __VA_ARGS__)
#else
#define LOG(...)
#endif

#ifdef GPUDEBUG
#define GPULOG(...) DebugPrintf(MainLog, __FILE__, __LINE__, __VA_ARGS__)
#else
#define GPULOG(...)
#endif

#ifdef DIVDEBUG
#define DIVLOG(...) DebugPrintf(MainLog, __FILE__, __LINE__, __VA_ARGS__)
#else
#define DIVLOG(...)
#endif

#ifdef SQRTDEBUG
#define SQRTLOG(...) DebugPrintf(MainLog, __FILE__, __LINE__, __VA_ARGS__)
#else
#define SQRTLOG(...)
#endif

#ifdef CARDDEBUG
#define CARDLOG(...) DebugPrintf(MainLog, __FILE__, __LINE__, __VA_ARGS__)
#else
#define CARDLOG(...)
#endif

#ifdef DMADEBUG
#define DMALOG(...) DebugPrintf(MainLog, __FILE__, __LINE__, __VA_ARGS__)
#else
#define DMALOG(...)
#endif

#ifdef __cplusplus
}
#endif

#endif
