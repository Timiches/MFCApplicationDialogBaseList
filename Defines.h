#pragma once

#define MIN_BIRTH_YEAR 1950
#define MAX_BIRTH_YEAR 2020
#define MIN_MARK 0
#define MAX_MARK 100
#define BUF_SIZE 4096

#ifdef _UNICODE
#define tostream std::wostream
#define tistream std::wistream
#define tcout std::wcout
#define tcin std::wcin
#else
#define tostream std::ostream
#define tistream std::istream
#define tcout std::cout
#define tcin std::cin
#endif

#define ERROR_NULL_TEXT _T("NO_TEXT")

// MFC defines

#define FACULTY 10
#define GROUP 11

#define CREATE 12
#define CHANGE 13

#define _LENGTH(VAR, BT)\
		sizeof(VAR) >> (sizeof(BT) >> 1)
#define MIN_BUF_SIZE 100