#include "dllmain.h"
#include <sys/stat.h>

HANDLE hMainThread = NULL;

//#ifndef  NDEBUG
void Log_(const char* fmt, ...) {
	char		text[4096];
	va_list		ap;
	va_start(ap, fmt);
	vsprintf_s(text, fmt, ap);
	va_end(ap);

	std::ofstream logfile(xorstr_("C:\\aiotool\\debug\\aio_debuglog.logs"), std::ios::app);
	if (logfile.is_open() && text)	logfile << text << std::endl;
	logfile.close();
}
//#endif
bool IsPathExist(const std::string& s)
{
	struct stat buffer;
	return (stat(s.c_str(), &buffer) == 0);
}

//bool find_sigs()
//{
//	uintptr_t _skipB = 0x500000;
//	uintptr_t _skipA = 0x0; //0x5000000;
//	uintptr_t  searchStart = (uintptr_t)mem::modinfo(mem::info::modbase) + _skipB;
//	uintptr_t searchEnd = searchStart + ((uintptr_t)mem::modinfo(mem::info::imagesize) - _skipB);
//
//	auto validaddr = [](__int64 addr, LPCSTR name = "func") -> bool
//	{
//		if (!addr)
//		{
//			LOGS("failed {} @ : {:#x}", name, addr);
//			return false;
//		}
//		return true;
//	};
//
//	auto resolve_xor = [](__int64 addr) -> __int64 {
//		return *(int*)(addr + 2) + addr + 6;
//	};
//
//	bool result = true;
//
//
//	g_vars->goffsets.unlock_offsets = Scanner::Scanner(xorstr_("33 FF 48 8D 15 ? ? ? ? 48 89 05 ? ? ? ? 48 8D 0D"), xorstr_("unlockAll")).getaddr();
//	LOGS_ADDR(g_vars->goffsets.unlock_offsets);
//	return result;
//}
uint64_t BASEIMAGE = reinterpret_cast<uint64_t>(GetModuleHandleA(NULL));
uint64_t DecryptClientInfo(uint64_t baseModuleAddr, uint64_t peb)
{
	uint64_t rax = baseModuleAddr, rbx = baseModuleAddr, rcx = baseModuleAddr, rdx = baseModuleAddr, rdi = baseModuleAddr, rsi = baseModuleAddr, r8 = baseModuleAddr, r9 = baseModuleAddr, r10 = baseModuleAddr, r11 = baseModuleAddr, r12 = baseModuleAddr, r13 = baseModuleAddr, r14 = baseModuleAddr, r15 = baseModuleAddr;
	rbx = *(uint64_t*)(baseModuleAddr + 0x14E64228);
	if (!rbx)
		return rbx;
	rcx = peb;              //mov rcx, gs:[rax]
	r8 = baseModuleAddr;    rdx = baseModuleAddr + 0xEFB5;          //lea rdx, [0xFFFFFFFFFDE559C9]
	rax = 0;                //and rax, 0xFFFFFFFFC0000000
	rax = _rotl64(rax, 0x10);               //rol rax, 0x10
	rax ^= *(uint64_t*)(baseModuleAddr + 0x74430B8);             //xor rax, [0x0000000005289ABB]
	rax = ~rax;             //not rax
	rbx *= *(uint64_t*)(rax + 0x7);              //imul rbx, [rax+0x07]
	rax = 0xB19319AD50983E0B;               //mov rax, 0xB19319AD50983E0B
	rbx *= rax;             //imul rbx, rax
	rax = rcx + 0x1;                //lea rax, [rcx+0x01]
	rax *= rdx;             //imul rax, rdx
	rbx += rax;             //add rbx, rax
	rax = r8 + 0xbba7;              //lea rax, [r8+0xBBA7]
	rax += rcx;             //add rax, rcx
	rbx ^= rax;             //xor rbx, rax
	rax = rbx;              //mov rax, rbx
	rax >>= 0x1C;           //shr rax, 0x1C
	rbx ^= rax;             //xor rbx, rax
	rax = rbx;              //mov rax, rbx
	rax >>= 0x38;           //shr rax, 0x38
	rbx ^= rax;             //xor rbx, rax
	rax = rbx;              //mov rax, rbx
	rax >>= 0x20;           //shr rax, 0x20
	rbx ^= rax;             //xor rbx, rax
	return rbx;
}
void init()
{
	g_vars = new global_vars();
	g_vars->procID = utility::GetProcId(L"ModernWarfare.exe");
	g_vars->hProc = OpenProcess(PROCESS_ALL_ACCESS, NULL, g_vars->procID);
	g_vars->baseModule = (QWORD)(iat(GetModuleHandleA).get()("ModernWarfare.exe"));
	g_vars->hWind = process::get_process_window();

}
uint64_t get_client_info()
{
	auto baseModuleAddr = g_vars->baseModule;
	auto Peb = __readgsqword(0x60);
	uint64_t rax = baseModuleAddr, rbx = baseModuleAddr, rcx = baseModuleAddr, rdx = baseModuleAddr, rdi = baseModuleAddr, rsi = baseModuleAddr, r8 = baseModuleAddr, r9 = baseModuleAddr, r10 = baseModuleAddr, r11 = baseModuleAddr, r12 = baseModuleAddr, r13 = baseModuleAddr, r14 = baseModuleAddr, r15 = baseModuleAddr;
	rbx = *(uintptr_t*)(baseModuleAddr + 0x14C81128);
	if (!rbx)
		return rbx;
	rcx = Peb;              //mov byte ptr [rsp+0x50], 0x86
	rdx = baseModuleAddr;   rax = rbx;              //mov rax, rbx
	rax >>= 0x7;            //shr rax, 0x07
	rbx ^= rax;             //xor rbx, rax
	rax = rbx;              //mov rax, rbx
	rax >>= 0xE;            //shr rax, 0x0E
	rbx ^= rax;             //xor rbx, rax
	rax = rbx;              //mov rax, rbx
	rax >>= 0x1C;           //shr rax, 0x1C
	rbx ^= rax;             //xor rbx, rax
	rax = 0x6BC54B00D87A8337;               //mov rax, 0x6BC54B00D87A8337
	rcx = rbx;              //mov rcx, rbx
	rcx >>= 0x38;           //shr rcx, 0x38
	rcx ^= rbx;             //xor rcx, rbx
	rcx -= rdx;             //sub rcx, rdx
	rcx *= rax;             //imul rcx, rax
	rbx = rcx;              //mov rbx, rcx
	rax = 0;                //and rax, 0xFFFFFFFFC0000000
	rbx >>= 0x28;           //shr rbx, 0x28
	rax = _rotl64(rax, 0x10);               //rol rax, 0x10
	rbx ^= rcx;             //xor rbx, rcx
	rax ^= *(uintptr_t*)(baseModuleAddr + 0x7261115);             //xor rax, [0x00000000051D5409]
	rax = ~rax;             //not rax
	rbx *= *(uintptr_t*)(rax + 0x17);             //imul rbx, [rax+0x17]
	rax = 0x39CC568E4F13F499;               //mov rax, 0x39CC568E4F13F499
	rbx *= rax;             //imul rbx, rax
	return rbx;
}
__declspec(dllexport)HRESULT present_hk(IDXGISwapChain3* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!pSwapChain)
		return ori_present(pSwapChain, SyncInterval, Flags);
	if (d3d12::pCommandQueue == nullptr)
	{
		ori_present(pSwapChain, SyncInterval, Flags);
	}

	DXGI_SWAP_CHAIN_DESC sdesc;
	pSwapChain->GetDesc(&sdesc);
	if (sdesc.OutputWindow == GetForegroundWindow())
	{
		Main = imgui::start(
			reinterpret_cast<IDXGISwapChain3*>(pSwapChain),
			reinterpret_cast<ID3D12CommandQueue*>((d3d12::pCommandQueue)), nullptr, 16.0f);

		imgui::imgui_frame_header();

		if (GetAsyncKeyState(VK_END) & 1)
			kiero::shutdown();

		if (GetAsyncKeyState(VK_INSERT) & 1)
			g_vars->msettings.b_menuEnable = !g_vars->msettings.b_menuEnable;

		if (g_vars->msettings.b_menuEnable)
		{
			ImGui::GetIO().MouseDrawCursor;
			menu->DrawMenu();
		}
		if (g_vars->msettings.UAV)
		{
			uintptr_t uavstruct = *(uintptr_t*)(BASEIMAGE + 0x1DAC7F90);


			*(int*)(uavstruct + 0x309) = 33619969;
		}
		if (g_vars->msettings.NOREC)
		{
			uint64_t characterInfo_ptr = get_client_info();

			if (characterInfo_ptr)
			{
				// up, down
				uint64_t r12 = characterInfo_ptr;
				r12 += 0x7D760;
				uint64_t rsi = r12 + 0x4;
				DWORD edx = *(uint64_t*)(r12 + 0xC);
				DWORD ecx = (DWORD)r12;
				ecx ^= edx;
				DWORD eax = (DWORD)((uint64_t)ecx + 0x2);
				eax *= ecx;
				ecx = (DWORD)rsi;
				ecx ^= edx;
				DWORD udZero = eax;
				//left, right
				eax = (DWORD)((uint64_t)ecx + 0x2);
				eax *= ecx;
				DWORD lrZero = eax;
				*(DWORD*)(r12) = udZero;
				*(DWORD*)(rsi) = lrZero;

			}
		}
		imgui::imgui_no_border();

		imgui::imgui_frame_end();
	}
	return ori_present(pSwapChain, SyncInterval, Flags);
}

int GetLogonStatus(int status) {
	return reinterpret_cast<int(*)(int)>(g_vars->goffsets.Logon_Status)(status);
}

DWORD WINAPI  initthread(HMODULE hModule)
{
	hMainThread = GetCurrentThread();

	init();

	if (!IsPathExist(xorstr_("C:\\aiotool")))
	{
		CreateDirectoryA(xorstr_("C:\\aiotool"), NULL);
	}
	//#ifndef  NDEBUG
	if (g_vars->msettings.b_debugEnable)
	{
		if (!IsPathExist(xorstr_("C:\\aiotool\\Debug")))
		{
			CreateDirectoryA(xorstr_("C:\\aiotool\\Debug"), NULL);
		}
	}
	else
	{
		if (IsPathExist(xorstr_("C:\\aiotool\\Debug")))
		{
			std::filesystem::remove(xorstr_("C:\\aiotool\\Debug"));
		}
	}
//#endif NDEBUG

	if (g_vars->procID)
	{
		
	
		//find_sigs();
	g_vars->goffsets.unlock_offsets = utility::PatternScanEx(g_vars->hProc, g_vars->baseModule + 0x500000, 0x1F0000, xorstr_("\x33\xFF\x48\x8D\x15\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x48\x8D\x0D"), xorstr_("xxxxx????xxx????xxx")) - g_vars->baseModule;
//#ifndef  NDEBUG
	if (g_vars->msettings.b_debugEnable)
	LOGS_ADDR(g_vars->goffsets.unlock_offsets);
//#endif NDEBUG

		g_vars->goffsets.Dvar_FindVarByName = utility::FindOffset(g_vars->hProc, g_vars->baseModule + 0x2000000, 0x1F00000, xorstr_("\x48\x83\xEC\x48\x49\x8B\xC8\xE8\x00\x00\x00\x00"), xorstr_("xxxxxxxx????"), 1, 5, 7);
//#ifndef  NDEBUG
		if (g_vars->msettings.b_debugEnable)
		LOGS_ADDR(g_vars->goffsets.Dvar_FindVarByName);
//#endif NDEBUG

		g_vars->goffsets.Dvar_SetBoolInternal = utility::FindOffset(g_vars->hProc, g_vars->baseModule + 0x2000000, 0x1F00000, xorstr_("\xE8\x00\x00\x00\x00\x80\x3D\x00\x00\x00\x00\x00\x4C\x8D\x35\x00\x00\x00\x00\x74\x43\x33\xD2\xF7\x05\x00\x00\x00\x00\x00\x00\x00\x00\x76\x2E"), xorstr_("x????xx?????xxx????xxxxxx????????xx"), 1, 5, 0);
//#ifndef  NDEBUG
		if (g_vars->msettings.b_debugEnable)
		LOGS_ADDR(g_vars->goffsets.Dvar_SetBoolInternal);
//#endif NDEBUG

		g_vars->goffsets.Dvar_SetInt_Internal = utility::PatternScanEx(g_vars->hProc, g_vars->baseModule + 0x3000000, 0x1F00000, xorstr_("\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x33\xC4\x48\x89\x84\x24\x00\x00\x00\x00\x0F\xB6\x41\x09\x48\x8B\xD9"), xorstr_("xxxxx????xxx????xxxxxxx????xxxxxxx")) - g_vars->baseModule;
//#ifndef  NDEBUG
		if (g_vars->msettings.b_debugEnable)
		LOGS_ADDR(g_vars->goffsets.Dvar_SetInt_Internal);
//#endif NDEBUG

		g_vars->goffsets.Dvar_SetBoolByName = utility::PatternScanEx(g_vars->hProc, g_vars->baseModule + 0x3000000, 0x1F00000, xorstr_("\x48\x89\x5C\x24\x00\x57\x48\x81\xEC\x00\x00\x00\x00\x0F\xB6\xDA"), xorstr_("xxxx?xxxx????xxx")) - g_vars->baseModule;
//#ifndef  NDEBUG
		if (g_vars->msettings.b_debugEnable)
		LOGS_ADDR(g_vars->goffsets.Dvar_SetBoolByName);
//#endif NDEBUG

		g_vars->goffsets.Dvar_SetFloat_Internal = utility::FindOffset(g_vars->hProc, g_vars->baseModule + 0x6000000, 0x1F00000, xorstr_("\xE8\x00\x00\x00\x00\x45\x0F\x2E\xC8"), xorstr_("x????xxxx"), 1, 5, 0);
		if (g_vars->msettings.b_debugEnable)
			LOGS_ADDR(g_vars->goffsets.Dvar_SetFloat_Internal);
		
		g_vars->goffsets.camoAddr = utility::FindOffset(g_vars->hProc, g_vars->baseModule + 0x2000000, 0x1F00000, xorstr_("\x4C\x8B\x00\x00\x00\x00\x00\x4C\x8B\x00\x00\x00\x00\x00\x4D\x85\x00\x74\x00\x49\xB9"), xorstr_("xx?????xx?????xx?x?xx"),3,7,0);
		g_vars->goffsets.camoAddr += 0x28;
		//g_vars->goffsets.camoAddr = 0x11D6A318 + 0x28; 
		if (g_vars->msettings.b_debugEnable)


		LOGS_ADDR(g_vars->goffsets.camoAddr);




		g_vars->goffsets.ddl_setint = utility::FindOffset(g_vars->hProc, g_vars->baseModule + 0x4000000, 0x1F00000, xorstr_("\x44\x8B\xC0\x48\x8D\x55\xB7\x48\x8D\x4C\x24\x00\xE8\x00\x00\x00\x00"), xorstr_("xxxxxxxxxxx?x????"), 1, 5, 12);
		

		if (kiero::init(kiero::RenderType::D3D12) == kiero::Status::Success)
		{
			kiero::bind(54, (void**)&oExecuteCommandListsD3D12, imgui::hookExecuteCommandListsD3D12);
			kiero::bind(140, (void**)&ori_present, present_hk);
		
		}
	}
	else
	{
		return 0;
	}


	return 0;
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		initthread(module);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
	return TRUE;
}