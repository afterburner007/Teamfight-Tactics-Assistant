
#include <windows.h>
#include <tchar.h>
#include <assert.h>
#include <shellapi.h>

const TCHAR szOperation[] = _T("open");
const TCHAR szURL[] = _T("https://www.qq.com/");
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmd, int
	nShow)
{
	HINSTANCE hRslt = ShellExecute(NULL, szOperation,
		szURL, NULL, NULL, SW_SHOWNORMAL);

	assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

	return 0;
}