#pragma once


// this should be off_t, but conflict with c++'s header
// I don't know why, fuck that 
typedef int64_t sceoff_t;

typedef int64_t ssize_t;


//////////////////////////////////////////////////////////////////////////

#define SCE_DUMMY_USERID 0x12345

typedef int SceUserServiceUserId;

