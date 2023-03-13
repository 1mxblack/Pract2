#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <tchar.h>
#include <strsafe.h>

void ErrorExit(LPTSTR lpszFunction)
{ 
    // Retrieve the system error message for the last-error code

    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError();

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0, NULL);

    // Display the error message and exit the process

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
    StringCchPrintf((LPTSTR)lpDisplayBuf, LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"),
        lpszFunction, dw, lpMsgBuf);
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
    ExitProcess(dw);
}

int main() {
    WIN32_FIND_DATA FindBuf;

    int prov = 0, res = 1;
    int i = 0, a = 0, k = 0;
    TCHAR newfilename[256], help[30];
    HANDLE resdir;
     resdir = FindFirstFile(_T("C:\\c\\*"), &FindBuf);
    if (resdir != INVALID_HANDLE_VALUE) {
        while (res != 0) {
            res = FindNextFile(resdir, &FindBuf);
            if (!(FindBuf.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                help == FindBuf.cFileName;
                prov = 1;
                while (help[i]) {
                    if (help[i] >= '0' && help[i] <= '9') {
                        k++;
                    }
                    else {
                        prov = 0;
                    }
                    i++;
                }
                i = 0;
                if (prov == 1) {
                    a = _tstoi(help);
                    if (a < 0) {
                        ErrorExit((LPTSTR)_T("Error of _wtoi\n"));
                        res = 1;
                    }
                    else {
                        if ((a > 0) && (a <= 999)) {
                            a = a + 1000;
                            if (_tprintf(newfilename, 5, _T("%d\n"), a) < 1) {
                                ErrorExit((LPTSTR)_T("Error of _tprintf\n"));
                                res = 1;
                            }
                            if (MoveFile(FindBuf.cFileName, newf b  ilename) == 0) {
                                ErrorExit((LPTSTR)_T("Error of rename\n"));
                            }
                            else {
                                _tprintf(_T("The tename is access: %s", newfilename));
                            }
                        }
                    }
                }
            }
        }
        _tprintf(_T("Program completed"));
    }
    else {
        ErrorExit((LPTSTR)_T("Error of reading directory\n"));
    }
    return res;
}
 