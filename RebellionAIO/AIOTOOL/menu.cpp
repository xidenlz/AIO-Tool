#include "menu.h"

const char CWAether[29] = "camo_zm_t9mastery_darkmatter";
const char CWUltra[30] = "camo_mp_t9mastery_darkmatter";
const char CWGold[24] = "camo_mp_t9mastery_gold";
const char CWDiamond[27] = "camo_mp_t9mastery_diamond";
const char CWPDiamond[27] = "camo_zm_t9mastery_diamond";
const char CW_Reset[19] = "camo_mp_t9tier1_01";
const char Cherry[19] = "camo_mp_t9tier5_05";

const char Damascus[9] = "camo_11c";
const char Obisidian[9] = "camo_11d";
const char Gold[12] = "camo_11a";
const char MW_Reset[9] = "camo_01a";
const char MW_Diamond[9] = "camo_11b";

const char VGGold[12] = "s4_camo_11a";
const char VGDiamond[12] = "s4_camo_11b";
const char VGAtomic[12] = "s4_camo_11c";
const char VGGoldenViper[15] = "s4_camo_11a_zm";
const char VGPlagueDiamond[15] = "s4_camo_11b_zm";
const char VGDarkAether[15] = "s4_camo_11c_zm";
const char VG_Reset[12] = "s4_camo_01a";
const char ZM_Reset[128] = "s4_camo_01a_zm";
const char Overkill[22] = "specialty_munitions_2";
const char Ghost[20] = "specialty_guerrilla";
const char DoubleTime[17] = "specialty_hustle";
const char Spotter[25] = "specialty_tactical_recon";
const char BattleHardened[21] = "specialty_tac_resist";
const char KillChain[22] = "specialty_heavy_metal";
const char Scavenger[24] = "pecialty_scavenger_plus";
const char Shrapnel[25] = "specialty_extra_shrapnel";
const char HighAlert[23] = "specialty_surveillance";
const char TuneUp[19] = "specialty_tune_up";
const char Restock[18] = "specialty_restock";
const char ColdBlooded[21] = "specialty_covert_ops";
const char EOD[15] = "specialty_eod";
const char Tracker[21] = "specialty_huntmaster";
const char BountyHunter[20] = "specialty_mercenary";
const char Amped[18] = "specialty_warhead";
const char Hardline[19] = "specialty_hardline";
const char QuickFix[20] = "specialty_quick_fix";
const char PointMan[21] = "specialty_strategist";
const char CombatScout[27] = "specialty_br_advancedscout";
const char Tempered[24] = "specialty_br_reinforced";


ImFont* MainCaps;
ImFont* Main;
ImFont* FMenu;
ImFont* newnew;
float color_menu[4]{ 166 / 255.f, 0 / 255.f , 255 / 255.f, 1.0f };
char customtag[5] = "";

void TextCentered(std::string text) {
	auto windowWidth = ImGui::GetWindowSize().x;
	auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

	ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
	ImGui::Text(text.c_str());
}

void cMenu::DrawMenu()
{
	
	ImVec4* colors = ImGui::GetStyle().Colors;
	
	colors[ImGuiCol_FrameBg] =				 ImColor(26,26,26, 150);
	colors[ImGuiCol_Border] = ImColor(0, 0, 0, 255);
	colors[ImGuiCol_CheckMark] =             ImVec4(color_menu[0], color_menu[1], color_menu[2], 1.0f);
	colors[ImGuiCol_Header] =                ImVec4(color_menu[0], color_menu[1], color_menu[2], 1.0f);
	colors[ImGuiCol_HeaderHovered] =         ImVec4(color_menu[0], color_menu[1], color_menu[2], 0.86f);
	colors[ImGuiCol_HeaderActive] =          ImVec4(color_menu[0], color_menu[1], color_menu[2], 1.00f);
	colors[ImGuiCol_SliderGrab] =            ImVec4(color_menu[0], color_menu[1], color_menu[2], 0.74f);
	colors[ImGuiCol_SliderGrabActive] =      ImVec4(color_menu[0], color_menu[1], color_menu[2], 1.00f);
	colors[ImGuiCol_ScrollbarGrab] =         ImVec4(color_menu[0], color_menu[1], color_menu[2], 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] =  ImVec4(color_menu[0], color_menu[1], color_menu[2], 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] =   ImVec4(color_menu[0], color_menu[1], color_menu[2], 1.00f);
	colors[ImGuiCol_Button] =                ImVec4(color_menu[0], color_menu[1], color_menu[2], 1.00f);
	colors[ImGuiCol_WindowBg] = ImColor(21, 21, 21, 255);
	ImGui::SetNextWindowSize({ 650, 450 });
	ImGuiStyle* style = &ImGui::GetStyle();
	style->FramePadding = ImVec2(0,0);
	style->ItemSpacing = ImVec2(10, 2);
	style->IndentSpacing = 12;
	style->ScrollbarSize = 5;

	style->WindowRounding = 4;
	style->FrameRounding = 4;
	style->PopupRounding = 4;
	style->ScrollbarRounding = 6;
	style->GrabRounding = 4;
	style->TabRounding = 4;
	style->WindowPadding = {0,0};
	style->ChildRounding = 4;

	style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style->WindowMenuButtonPosition = ImGuiDir_Right;
	style->DisplaySafeAreaPadding = ImVec2(0,0);

	static bool checkbypass = false;
	static bool profanitybypass = false;
	static bool swapwz = false;


	if (ImGui::Begin("Big Paste :) - Frosty#2948", &g_vars->msettings.b_menuEnable, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse))
	{

		ImGui::PushFont(newnew);

		ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(166, 0, 255, 255).Value);
		ImGui::BeginChild("Header", { ImGui::GetContentRegionAvail().x, 15 });
		{
			TextCentered("GhostServices VIP AIO");
		}
		ImGui::EndChild();
		ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(166, 0, 255, 255).Value);
		ImGui::BeginChild("line", { ImGui::GetContentRegionAvail().x, 1 });

		ImGui::EndChild();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();

		ImGui::PopFont();


		ImGui::PushFont(newnew);

		static bool ownercheck = false;

		ImGui::BeginChild("##LAYOUT", ImVec2(0, 0)); {


			ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);

			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(31, 31, 31, 255).Value);

			ImGui::BeginChild("1", { ImGui::GetContentRegionAvail().x / 2, 250 }, true);
			{
				ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(24, 24, 24, 255).Value);
				ImGui::BeginChild("www", { ImGui::GetContentRegionAvail().x, 15 });
				{
					TextCentered("commands");
				}
				ImGui::EndChild();
				ImGui::PopStyleColor();

				ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);

				ImGui::Checkbox(xorstr_("Disable Owner Check"), &ownercheck);
				if (g_vars->msettings.b_brightmax) {
					dvar_set2("NRQQOMLOQL", 0);
					dvar_set2("RRTLRKKTT", 0);
					dvar_set2("MKQPRPLQKL", 0);
				}
					

					ImGui::Checkbox(xorstr_("Full Bright"), &g_vars->msettings.b_brightmax);
					if (g_vars->msettings.b_brightmax) {
						dvar_set2("NQKKOONQPR", 0);
						dvar_set2("MTLMSQMNTR", 0);
						dvar_set2("RNPPKQOTN", 0);
						dvar_set2("LKOLRONRNQ", 0);
						dvar_set2("LTOKRMRTMM", 0);
					}
					else
					{
						dvar_set2("NQKKOONQPR", 1);
						dvar_set2("MTLMSQMNTR", 1);
						dvar_set2("RNPPKQOTN", 1);
						dvar_set2("LKOLRONRNQ", 1);
						dvar_set2("LTOKRMRTMM", 1);
					}
					ImGui::Dummy(ImVec2(0.0f, 1.0f));

					ImGui::Checkbox("Loot Check bypass", &checkbypass);
					ImGui::Checkbox("Profanity bypass", &profanitybypass);
					ImGui::Checkbox("Swap MP/WZ loadouts", &swapwz);

					ImGui::Dummy(ImVec2(0.0f, 1.0f));

					ImGui::Checkbox(xorstr_("Third Person"), &g_vars->msettings.b_thirdperson);
					if (g_vars->msettings.b_thirdperson)
					{
						dvar_set2("NOSLRNTRKL", 1);
					}
					else
					{
						dvar_set2("NOSLRNTRKL", 0);
					}

					ImGui::Dummy(ImVec2(0.0f, 1.0f));
					ImGui::Checkbox(xorstr_("Disable Flash Bangs"), &g_vars->msettings.b_no_flashbang);
					if (g_vars->msettings.b_no_flashbang)
					{
						dvar_set2("cg_drawShellshock", 0);
					}
					else
					{
						dvar_set2("cg_drawShellshock", 1);
					}
					ImGui::Dummy(ImVec2(0.0f, 1.0f));
					/*ImGui::Checkbox(xorstr_("No Recoil "), &NOREC);
					ImGui::Dummy(ImVec2(0.0f, 1.0f));*/
					ImGui::Checkbox(xorstr_("Unlimited Sprint"), &g_vars->msettings.b_sprint);
					if (g_vars->msettings.b_sprint)
					{
						dvar_set2("NNQTKSTRPK", 20);
						dvar_set2("MSOOMPMPQS", 1);
					}
					else
					{
						dvar_set2("MSOOMPMPQS", 0);
					}
					ImGui::Dummy(ImVec2(0.0f, 1.0f));
					ImGui::Checkbox(xorstr_("Heartcheat"), &g_vars->msettings.b_heartcheat);
					if (g_vars->msettings.b_heartcheat)
					{
						dvar_set2("NSKNMSMOLP", 2);
						dvar_set2("NLLRSSOQMQ", 10000);
					}
					else
					{
						dvar_set2("NSKNMSMOLP", 5);
						dvar_set2("NLLRSSOQMQ", 500);
					}

				}
				ImGui::EndChild();
				ImGui::PopStyleColor();

				ImGui::SameLine();


				ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(31, 31, 31, 255).Value);

				ImGui::BeginChild("2", { ImGui::GetContentRegionAvail().x - 5, 75 }, true);
				{
					ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(24, 24, 24, 255).Value);
					ImGui::BeginChild("WWWWW", { ImGui::GetContentRegionAvail().x, 15 });
					{
						TextCentered("fov");
					}
					ImGui::EndChild();
					ImGui::PopStyleColor();

					if (g_vars->msettings.b_fov) {
						dvar_set2("NSSLSNKPN", g_vars->msettings.f_fov);
					}
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
					ImGui::SetCursorPosY(ImGui::GetContentRegionAvail().y / 2);

					ImGui::SetNextItemWidth(298.0f);
					ImGui::SliderFloat(xorstr_("##FOVSLIDER"), &g_vars->msettings.f_fov, 1.0f, 2.0f, "%.1f");
					ImGui::Dummy(ImVec2(0.0f, 1.0f));
				}
				ImGui::EndChild();

				//misc
				ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(31, 31, 31, 255).Value);

				ImGui::SetCursorPosX(336);
				ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 170);

				ImGui::BeginChild("3", { 308, 120 }, true);
				{
					ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(24, 24, 24, 255).Value);
					ImGui::BeginChild("wwwwwwwwwwwww", { ImGui::GetContentRegionAvail().x, 15 });
					{
						TextCentered("misc");
					}
					ImGui::EndChild();
					ImGui::PopStyleColor();


					ImGui::Dummy(ImVec2(0.0f, 1.0f));
					ImGui::Dummy(ImVec2(0.0f, 1.0f));
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
					if (ImGui::Button(xorstr_("Skip Intro"), ImVec2(144, 20)))
					{
						dvar_set2(xorstr_("LSPSKLPNQT"), 1);
					}
					ImGui::SameLine();
					if (ImGui::Button(xorstr_("Start Private Match"), ImVec2(144, 20)))
					{
						dvar_set2(xorstr_("LOQQOSNQKN"), 1);
						dvar_set2(xorstr_("PKMLMMTSN"), 1);
					}
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
					if (ImGui::Button(xorstr_("Boost FPS"), ImVec2(298, 20)))
					{
						dvar_set2("OPOTTRRNQ", 0);
						dvar_set2("NNRQTQNLRL", 0);
						dvar_set2("NNTOQLMSLO", 3);
						dvar_set2("NTROOKOSPM", 3);
						dvar_set2("NNKRMTSNPL", 0);
						dvar_set2("MOLLKMTMRS", 0);
						dvar_set2("MQOPRPQLQL", 0);
						dvar_set2("NLNKQNROQM", 0);
						dvar_set2("LTOKRMRTMM", 0);
					}

				}
				ImGui::EndChild();


				ImGui::SetCursorPosX(336);
				ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);

				ImGui::BeginChild("4", { 308, 90 }, true);
				{
					ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(24, 24, 24, 255).Value);
					ImGui::BeginChild("wwewwewe", { ImGui::GetContentRegionAvail().x, 15 });
					{
						TextCentered("unlocks");
					}
					ImGui::EndChild();
					ImGui::PopStyleColor();


					ImGui::Dummy(ImVec2(0.0f, 1.0f));
					ImGui::Dummy(ImVec2(0.0f, 1.0f));
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
					if (ImGui::Button(xorstr_("Unlock All"), ImVec2(298, 20)))
					{
						unlock();
					}
					ImGui::Spacing();
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
					if (ImGui::Button(xorstr_("Unlock Reverse Camos"), ImVec2(298, 20)))
					{

					}
				}
				ImGui::EndChild();


				ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(31, 31, 31, 255).Value);
				ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
				ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 40);

				ImGui::BeginChild("5", { ImGui::GetContentRegionAvail().x / 2, 150 }, true);
				{
					ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(24, 24, 24, 255).Value);
					ImGui::BeginChild("frr", { ImGui::GetContentRegionAvail().x, 15 });
					{
						TextCentered("force save");
					}
					ImGui::EndChild();
					ImGui::PopStyleColor();
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
					ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
					if (ImGui::Button(xorstr_("Save operator"), ImVec2(310, 20)))
					{

					}
					ImGui::Spacing();
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
					ImGui::TextDisabled("more coming soon...");
				}
				ImGui::EndChild();

				ImGui::SetCursorPosX(336);
				ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 105);

				ImGui::BeginChild("6", { 308, 101 }, true);
				{
					ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(24, 24, 24, 255).Value);
					ImGui::BeginChild("easfasfasf", { ImGui::GetContentRegionAvail().x, 15 });
					{
						TextCentered("info");
					}
					ImGui::EndChild();
					ImGui::PopStyleColor();

					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
					ImGui::Text("Status:"); ImGui::SameLine(45.0f); ImGui::TextColored(ImColor(0, 255, 0, 255), "Safe");
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
					//ImGui::Text("User: xem");
					//ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
					//ImGui::Text("Expiry: Lifetime");
					//ImGui::Text(" ");
					//ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);

					ImGui::Text(" ");
					ImGui::Text(" ");
					ImGui::Text(" ");

					ImGui::TextDisabled("Big Paste :)");

				}
				ImGui::EndChild();


			}
			ImGui::Spacing();


			ImGui::EndChild();


			ImGui::PopFont();
		}
	}