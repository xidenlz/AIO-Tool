#include "sdk.h"

HWND process::hwnd;
__int64 Com_DDL_LoadAsset(__int64 file) {
	uintptr_t address = g_vars->baseModule + g_vars->goffsets.ddl_loadasset;
	return ((__int64 (*)(__int64))address)(file);
}

__int64 DDL_GetRootState(__int64 state, __int64 file) {
	uintptr_t address =g_vars->baseModule + g_vars->goffsets.ddl_getrootstate;
	return ((__int64 (*)(__int64, __int64))address)(state, file);
}

bool CL_PlayerData_GetDDLBuffer(__int64 context, int controllerindex, int stats_source, unsigned int statsgroup) {
	uintptr_t address =g_vars->baseModule + g_vars->goffsets.ddl_getdllbuffer;
	return ((bool (*)(__int64, int, int, unsigned int))address)(context, controllerindex, stats_source, statsgroup);
}

__int64 DDL_MoveToName(__int64 fstate, __int64 tstate, __int64 path) {
	uintptr_t address =g_vars->baseModule + g_vars->goffsets.ddl_movetoname;
	return ((__int64 (*)(__int64, __int64, __int64))address)(fstate, tstate, path);
}

char DDL_SetInt(__int64 fstate, __int64 context, unsigned int value) {
	uintptr_t address =g_vars->baseModule + g_vars->goffsets.ddl_setint;
	return ((char (*)(__int64, __int64, unsigned int))address)(fstate, context, value);
}
BOOL CALLBACK process::EnumWindowCallBack(HWND hWnd, LPARAM lParam)
{
	DWORD dwPid = 0;
	GetWindowThreadProcessId(hWnd, &dwPid);
	if (dwPid == lParam)
	{
		hwnd = hWnd;
		return FALSE;
	}
	return TRUE;
}

HWND process::get_process_window()
{
	if (hwnd)
		return hwnd;

	EnumWindows(process::EnumWindowCallBack, GetCurrentProcessId());

	if (hwnd == NULL)
		Exit();

	return hwnd;
}

HWND process::get_process_window(DWORD procID)
{
	if (hwnd)
		return hwnd;

	EnumWindows(process::EnumWindowCallBack, procID);

	if (hwnd == NULL)
		Exit();

	return hwnd;
}


namespace g_game
{
	void ui_header()
	{
		if (g_vars->msettings.b_menuEnable)
		{
			ImGuiIO& io = ImGui::GetIO();
			ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.65f));
			ImGui::Begin("A", reinterpret_cast<bool*>(true), ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
			ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_Always);
			ImGui::SetWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y), ImGuiCond_Always);
			int dwWidth = GetSystemMetrics(SM_CXSCREEN) / 4;
			int dwHeight = GetSystemMetrics(SM_CYSCREEN) / 2;

		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
			ImGui::Begin("A", reinterpret_cast<bool*>(true), ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
			ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_Always);
			ImGui::SetWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y), ImGuiCond_Always);
			int dwWidth = GetSystemMetrics(SM_CXSCREEN) / 4;
			int dwHeight = GetSystemMetrics(SM_CYSCREEN) / 2;
			

		}
	}

	void ui_end()
	{
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		window->DrawList->PushClipRectFullScreen();
		ImGui::End();
		ImGui::PopStyleColor();
	}

	void init(ImFont* font)
	{
		ui_header();
		ui_end();
	}
}

void unlock()
{
	uintptr_t num = (g_vars->baseModule + g_vars->goffsets.unlock_offsets + 0xC);
	int num2 = mem::readMemory<int>(num);

	uintptr_t unlock_base = num + num2 + 4 - g_vars->baseModule;
	uintptr_t numP = (g_vars->baseModule + unlock_base + 0x60);

	memcpy((BYTE*)numP, (BYTE*)xorstr_("\x48\x83\xC4\x08\x48\x8B\x5C\x24\x30\x48\x8B\x74\x24\x38\x48\x83\xC4\x20\x5F\x48\xC7\xC0\x01\x00\x00\x00\xC3"), 28);
	mem::writeMemory<uintptr_t>(g_vars->baseModule + unlock_base + 8, numP);
	mem::writeMemory<uintptr_t>(g_vars->baseModule + unlock_base, g_vars->baseModule + unlock_base);
}

void CL_PlayerData_SetCustomClanTag(const char* clanTag)
{
	//74 ?? 48 8d 15 ?? ?? ?? ?? 8b cf e8 ?? ?? ?? ?? 48 8b 5c 24 30
	uintptr_t address = g_vars->baseModule + g_vars->goffsets.clantag_offset;
	((void(*)(int, const char*))address)(0, clanTag);
}

dvar_s* Dvar_FindVarByName(const char* dvarName)
{
	//[48 83 EC 48 49 8B C8 E8 ?? ?? ?? ?? + 0x7] resolve call.
	return reinterpret_cast<dvar_s * (__fastcall*)(const char* dvarName)>(g_vars->baseModule + g_vars->goffsets.Dvar_FindVarByName)(dvarName);
}

uintptr_t Dvar_SetBool_Internal(dvar_s* a1, bool a2)
{
	//E8 ? ? ? ? 80 3D ? ? ? ? ? 4C 8D 35 ? ? ? ? 74 43 33 D2 F7 05 ? ? ? ? ? ? ? ? 76 2E
	return reinterpret_cast<std::ptrdiff_t(__fastcall*)(dvar_s * a1, bool a2)>(g_vars->baseModule + g_vars->goffsets.Dvar_SetBoolInternal)(a1, a2);
}

uintptr_t Dvar_SetInt_Internal(dvar_s* a1, unsigned int a2)
{
	//40 53 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 0F B6 41 09 48 8B D9
	return reinterpret_cast<std::ptrdiff_t(__fastcall*)(dvar_s * a1, unsigned int a2)>(g_vars->baseModule + g_vars->goffsets.Dvar_SetInt_Internal)(a1, a2);
}

uintptr_t Dvar_SetBoolByName(const char* dvarName, bool value)
{
	//"48 89 ? ? ? 57 48 81 EC ? ? ? ? 0F B6 ? 48 8B"
	int64(__fastcall * Dvar_SetBoolByName_t)(const char* dvarName, bool value); //48 89 5C 24 ? 57 48 81 EC ? ? ? ? 0F B6 DA
	return reinterpret_cast<decltype(Dvar_SetBoolByName_t)>(g_vars->baseModule + g_vars->goffsets.Dvar_SetBoolByName)(dvarName, value);
}

uintptr_t Dvar_SetFloat_Internal(dvar_s* a1, float a2)
{
	//E8 ? ? ? ? 45 0F 2E C8 RESOLVE CALL
	return reinterpret_cast<std::ptrdiff_t(__fastcall*)(dvar_s * a1, float a2)>(g_vars->baseModule + g_vars->goffsets.Dvar_SetFloat_Internal)(a1, a2);
}

uintptr_t Dvar_SetIntByName(const char* dvarname, int value)
{
	uintptr_t(__fastcall * Dvar_SetIntByName_t)(const char* dvarname, int value); //48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 8B DA 48 8B F9
	return reinterpret_cast<decltype(Dvar_SetIntByName_t)>(g_vars->baseModule + g_vars->goffsets.Dvar_SetIntByName)(dvarname, value);
}