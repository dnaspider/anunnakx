#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <chrono>
#include <regex>
#include <codecvt>
#include <thread>

using namespace std;
using ctp = chrono::steady_clock::time_point;

struct Strand
{
	wstring in{};
	wstring g{};
	bool ft{};
};

struct Strand_out
{
	wstring out{};
};

#pragma region globals
wstring&& Kb_Key_A = L"a", Kb_Key_B = L"b", Kb_Key_C = L"c", Kb_Key_D = L"d", Kb_Key_E = L"e", Kb_Key_F = L"f", Kb_Key_G = L"g", Kb_Key_H = L"h", Kb_Key_I = L"i", Kb_Key_J = L"j", Kb_Key_K = L"k", Kb_Key_L = L"l", Kb_Key_M = L"m", Kb_Key_N = L"n", Kb_Key_O = L"o", Kb_Key_P = L"p", Kb_Key_Q = L"q", Kb_Key_R = L"r", Kb_Key_S = L"s", Kb_Key_T = L"t", Kb_Key_U = L"u", Kb_Key_V = L"v", Kb_Key_W = L"w", Kb_Key_X = L"x", Kb_Key_Y = L"y", Kb_Key_Z = L"z",
Kb_Key_0 = L"0", Kb_Key_1 = L"1", Kb_Key_2 = L"2", Kb_Key_3 = L"3", Kb_Key_4 = L"4", Kb_Key_5 = L"5", Kb_Key_6 = L"6", Kb_Key_7 = L"7", Kb_Key_8 = L"8", Kb_Key_9 = L"9",
Kb_Key_F1 = L"", Kb_Key_F2 = L">", Kb_Key_F3 = L"", Kb_Key_F4 = L"", Kb_Key_F5 = L"", Kb_Key_F6 = L"", Kb_Key_F7 = L"", Kb_Key_F8 = L"", Kb_Key_F9 = L"", Kb_Key_F10 = L"", Kb_Key_F11 = L"", Kb_Key_F12 = L"",
Kb_Key_Left = L"", Kb_Key_Up = L"", Kb_Key_Right = L"", Kb_Key_Down = L"",
Kb_Key_Esc = L"", Kb_Key_Space = L"", Kb_Key_Tab = L"", Kb_Key_Enter = L"", Kb_Key_Caps = L"", Kb_Key_Grave_Accent = L"", Kb_Key_Minus = L"", Kb_Key_Equal = L"", Kb_Key_Left_Bracket = L"", Kb_Key_Right_Bracket = L"", Kb_Key_Backslash = L"", Kb_Key_Semicolon = L"", Kb_Key_Quote = L"", Kb_Key_Comma = L"", Kb_Key_Period = L"", Kb_Key_Forwardslash = L"", Kb_Key_Menu = L"",
Kb_Key_Print_Screen = L"", Kb_Key_ScLk = L"", Kb_Key_Insert = L"", Kb_Key_Delete = L"", Kb_Key_Home = L"", Kb_Key_End = L"", Kb_Key_PgUp = L"", Kb_Key_PgDn = L"",
Kb_Key_Numpad_0 = L"", Kb_Key_Numpad_1 = L"", Kb_Key_Numpad_2 = L"", Kb_Key_Numpad_3 = L"", Kb_Key_Numpad_4 = L"", Kb_Key_Numpad_5 = L"", Kb_Key_Numpad_6 = L"", Kb_Key_Numpad_7 = L"", Kb_Key_Numpad_8 = L"", Kb_Key_Numpad_9 = L"", Kb_Key_Numlock = L"", Kb_Key_Numpad_Divide = L"", Kb_Key_Numpad_Multiply = L"", Kb_Key_Numpad_Minus = L"", Kb_Key_Numpad_Add = L"", Kb_Key_Numpad_Period = L"", Kb_Key_Numpad_Enter = L"",
Kb_Key_Pause = L">"
;
wstring database = L"c:\\anu\\db.txt",
settings = L"c:\\anu\\se.txt",
replacerDb = L"";
wstring&& editor = L"Visual Studio Code",
db = L"db.txt - ", se = L"se.txt - ",
editorSe = se + editor, editorDb = db + editor;
wstring strand = L"";
wstring qq = L"", qp = L"", qx = L"", qy = L"";
wstring repeats = L"";
wstring Loop_Insert_Text = L"";
wstring out = L"";
wstring chk = L"";
string delimiter = "\n"; //°";
vector<Strand> vstrand{};
vector<Strand_out> vstrand_out{};
size_t c = 0;
size_t found_io = 0, found_io_repeat = 0, follow = 0;
ctp c1{}, c2{}; //CtrlKey elapsed
double RgbScaleLayout = 1.00; //100%
double ic = 0; //<+> icp
int qxcc = 0, qycc = 0;
unsigned short out_speed = 0;
unsigned short frequency = 160;
unsigned short strand_length = 2;
unsigned short RSHIFTLSHIFT_Only = 0, rri = 0; //RSHIFTLSHIFT_Only 1 or 2 for L+ESC mode on; 2 for non <
unsigned short cKey = 29, cKeyMax = 700; // Scan code for VK_RCONTROL, CtrlKey elapsed
unsigned short repeat_key = 70; // Scan code for VK_SCROLL;
unsigned short PauseKey = 88; //Scan code for VK_F12
unsigned short repeat_switch = 0;
unsigned short debug = 0;
unsigned short mvdb = 0; //make vstrand to

unsigned short breaker{}, breaker_c{};
unsigned short clear{};
bool isWinKeyPressed{};
bool isLshiftPressed{};
bool isRshiftPressed{};
bool isCkey0Pressed{}; //cKey 0
bool isLctrlPressed{}; //cKey 29
bool isRctrlPressed{};
bool rshift_lshift{};
bool rshift_rctrl{};
bool repeated{};
bool ctrl_s{};

bool RSHIFTCtrlKeyToggle = 1;
bool multi_line = 0; //<x > \n\n
bool start_hidden = 0;
bool show_strand = 1;
bool auto_bs_repeat_key = 0;
bool ctrl_scan_only_mode = 0;
bool close_ctrl_mode = 1;
bool hold_shift = 0;
bool out_sleep = 1;
bool stop = 0, pause = 0;
bool utf_8 = 1, u8{};
bool ccm = 0; //close_ctrl_mode toggle

bool fallthrough_{};
bool clo{}; //clock
bool multi_run{1};

#pragma endregion

struct Multi_ {
	wstring out_,
		qq_,
		qp_,
		store_{};
	size_t
		c_{};
	double
		icp_{};
	bool
		br_{};
};

#pragma region protos
static void showOutsMsg(wstring, wstring, wstring, bool),
	run(wstring),
	repeat()
;

#pragma endregion

#pragma region subs
static std::wstring utf8_to_wstring(const std::string& str) {
	if (str.empty()) return {};
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	if (size_needed == 0) return {};
	std::wstring wstr(size_needed - 1, L'\0');
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size_needed);
	return wstr;
}

static std::string wstring_to_utf8(const std::wstring& wstr) {
	if (wstr.empty()) return {};
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	if (size_needed == 0) return {};
	std::string str(size_needed - 1, '\0');
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], size_needed, nullptr, nullptr);
	return str;
}

static ctp clockr(ctp& t) {
	return t = chrono::high_resolution_clock::now();
}

static void make_vdb_table() {
	ifstream f(database);

	if (!f) { f.close(); showOutsMsg(L"", L"\\0C\\" + database + L"\\0C\\\\4 not found!\\7\\n", L"", 1); return; }

	f.imbue(locale("en_us.utf8"));

	Strand s{};
	Strand_out s_o{};

	wstring cell;
	string cell0, cells;

	while (getline(f, multi_line ? cell0 : cells, delimiter[0])) {

		if (multi_line) {
			cells += cell0;
			if (cell0[0] && cell0[cell0.length() - 1] == '\\') {
				if (cell0.length() > 1 && cell0[cell0.length() - 2] == '\\') { cells.pop_back(); continue; }
				cells.pop_back();
			}
			else continue;
			multi_line = 0;
		}
		else {
			if (!cells[0] || cells[0] == ' ') continue;

			if (cells[1] == '\'' && cells.substr(0, 4) == "<'''")
				break;
		}

		cell = utf8_to_wstring(cells);

		if (delimiter[0] != '\n') cell = regex_replace(cell, wregex(L"\n"), L"");
		cell = regex_replace(cell, wregex(L"\t"), L"");

		//io
		s.in.clear(); s.g.clear(); s.ft = 0;
		s_o.out.clear();
		
		s.in = cell.substr(0, cell.find_first_of(L" -:>"));
		if (s.in[0] && s.in[s.in.length() - 1] == '\\' && delimiter[0] == '\n') { //multi_line
			multi_line = 1;
			s.in.pop_back();
			cells = wstring_to_utf8(s.in) + cells.substr(s.in.length() + 1);
			continue;
		}

		if (!s.g[0]) {
			s.g = cell.substr(s.in.length(), 1);
			if (s.g[0] && s.g[0] != '>') s.g += cell[s.in.length() + 1] == '>' ? L">" : L"";
		}

		s_o.out = cell.substr(s.in.length() + s.g.length());
		if (!s_o.out[0]) s.ft = 1;

		if (s.in[0] == '<')
			s.in += s.g;
		//io

		vstrand.push_back(s);
		vstrand_out.push_back(s_o);

	}
	f.close();

	vstrand.shrink_to_fit();
	vstrand_out.shrink_to_fit();
}

static wstring getTime(wstring& w) {
	auto np = chrono::system_clock::now();
	auto n = chrono::system_clock::to_time_t(np);
	char b[26];
	ctime_s(b, sizeof(b), &n);
	for (auto i = 0; i < 26; ++i) {
		if (b[i] == '\n') break;
		w += b[i];
	}
	return w;
}

static void cbSet(wstring& s) {
	auto length = 2 * (wcslen(s.c_str()) + 1);
	HGLOBAL h = GlobalAlloc(GMEM_DDESHARE, length);
	if (h != NULL) {
		auto x = GlobalLock(h);
		if (x != NULL) memcpy(x, s.c_str(), length);
		GlobalUnlock(h);
		OpenClipboard(0);
		EmptyClipboard();
		SetClipboardData(CF_UNICODETEXT, h);
		CloseClipboard();
	}
}

static auto cbGet(wstring cb = L"") {
	OpenClipboard(0);
	HANDLE b = GetClipboardData(CF_UNICODETEXT);
	if (b != nullptr) {
		wchar_t* t = static_cast<wchar_t*>(GlobalLock(b));
		if (t != nullptr) cb = t;
		GlobalUnlock(b);
	}
	CloseClipboard();
	return cb;
}

static void show_fg() {
	ShowWindow(GetConsoleWindow(), SW_RESTORE);
	SetForegroundWindow(GetConsoleWindow());
}

static void num_error(wstring error_msg = L"", wstring v = L"", wstring nan = L"NAN:") {
	wstring e = error_msg[0] ? L" " : L"";
	e += L"\\4";
	e += nan;
	e += L" \\7{\\4\\0C\\" + v + L"\\0C\\\\7}\\n";
	showOutsMsg(error_msg, e, L"", 1);
	c = out.length();
	show_fg();
}

static wstring check_if_num(wstring& s, wstring error_msg = L"") {
	if (debug == 2) return s;

	char d = 0;

	for (size_t x = 0; x < s.length(); ++x) {
		if (x == 0 && s[0] == '-') { if (s.length() == 1) { num_error(error_msg, s); s.clear(); break; } continue; }
		if (s[x] == '.') { ++d; if (d > 1 || s.length() == 1) { num_error(error_msg, s); s.clear(); break; } continue; }
		if (s[x] < '0' || s[x] > '9') { num_error(error_msg, s); s.clear(); break; }
	}

	return s;
}

static void kb(wchar_t b) { //out char
	INPUT ip[2]{}; ip[0].type = INPUT_KEYBOARD;
	ip[0].ki.dwFlags = KEYEVENTF_UNICODE;
	if (VkKeyScanW(b) == -1) { ip[0].ki.wScan = b; ip[0].ki.wVk = 0; }
	else { ip[0].ki.wVk = VkKeyScanW(b); }
	ip[1] = ip[0]; ip[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(2, ip, sizeof(ip[0]));
}

static void showOutsMsg(wstring s, wstring w, wstring s1 = L"", bool make_color = 1) {
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	size_t x = 0; bool t = 0;
	auto write = [&x, &t, &make_color](wstring w) {
		wcout << w;
		if (make_color) ++x;
		t = 1;
		};
	auto color = [&x, &t, &w, &hC, &make_color](WORD n) {
		if (make_color) SetConsoleTextAttribute(hC, n);
		if (!make_color) wcout << w.substr(x, 2);
		++x; t = 1;
		if (w[x] == '\\') --x;
		};
	if (s[0]) wcout << s;
	for (; x < w.length(); ++x) {
		if (w[x] == '\\') {
			t = 0;
			switch (w[x + 1]) {
			case'+':
			{ if (make_color) { write(to_wstring(ic)); ++ic; } } break; //<+>
			case'a':
			{ if (make_color) write(L"\a"); } break; //beep
			case'0': { /* \012\ */
				wstring n = w.substr(x + 2);
				if (n.find(L"\\") != string::npos) {
					n = n.substr(0, n.find(L"\\"));
					if (!n[0]) break;
					if (n == L"C") { x += 3; make_color = !make_color; t = 1; break; } /* \0C\ toggle make_color */
					if (make_color && check_if_num(n) == L"") { t = 1; break; }
					x += n.length() + 2;
					if (make_color) SetConsoleTextAttribute(hC, stoi(n));
					else wcout << L"\\0" << n << "\\";
					t = 1;
				}
				break;
			}
			case'1':
			case'B':
				color(1); break; //blu
			case'2':
			case'G':
				color(2); break; //gr
			case'3':
				color(3); break;
			case'4':
			case'R':
				color(4); break; //r
			case'5':
				color(5); break;
			case'6':
				color(6); break;
			case'7':
			case'W':
				color(7); break; //white
			case'8':
				color(8); break;
			case'9':
				color(9); break;
			case '\\':
				write(L"\\");
				break;
			case '\'':
				if (make_color) {
					x = w.length() - 1;
					t = 1;
				}
				break;
			case 'c':
			{ if (make_color) write(cbGet()); }
			break;
			case 'm':
			{ if (make_color) write(utf8_to_wstring(delimiter)); }
			break;
			case 'n':
				write(L"\n");
				if (!make_color) ++x;
				break;
			case 'T':
			{ if (make_color) { wstring w{}; getTime(w); write(w); } }
			break;
			case 't':
				write(L"\t");
				if (!make_color) ++x;
				break;
			case 'g':
				write(L">");
				if (!make_color) ++x;
				break;
			case 'i': //input
			if (make_color) {
				Strand _ = vstrand.at(found_io - 1);
				write(_.in);
				if (_.in[0] != '<')
					wcout << _.g;
			}
			break;
			case ',': //clock
				if (make_color) {
					if (clo) {
						clo = 0;
						clockr(c2);
						chrono::duration<double, milli> ts = c1 - c2;
						write(to_wstring(abs(static_cast<long>(ts.count()))));
					}
					else {
						clo = 1;
						clockr(c1);
						++x; t = 1;
					}
				}
				break;
			case '*':
				if (make_color) {
					multi_run = !multi_run;
					++x; t = 1;
				}
				break;
			}
			if (t) continue;
		}
		if (w[x] < 128) wcout << w[x];
		else { wcout << w.substr(x, 2); ++x; }
	}
	if (s1[0]) wcout << s1;
}

static void call_utf8() {
	u8 = 1;
	wcout.imbue(locale(wcout.getloc(), new codecvt_utf8_utf16<wchar_t>));
}

static void load_settings() {
	ifstream f(settings);

	if (!f) {
		f.close();
		showOutsMsg(L"", L"\\n\\4Settings \\7\\0C\\" + settings + L"\\0C\\\\4 not found!\\7\\n", L"", 1);
		return;
	}

	f.imbue(locale("en_US.utf8"));

	wstring cell; string cells; while (getline(f, cells)) {
		if (!cells[0] || cells[0] == ' ') continue;
		cell = utf8_to_wstring(cells);
		wstring se = cell.substr(0, cell.find_first_of(L":\t ")); se += ':';
		wstring v = (cell.substr(cell.find_first_of(L":\t ") + 1)); if (v.find_first_not_of(L"\t ") == string::npos) {//""
			if (v != L" ") v.clear();
		} if (se == cell + L":") v.clear();
		if (v[0] && v != L" ") v = v.substr(v.find_first_not_of(L"\t "));
		int x = 0; for (size_t i = 0; i <= se.length(); ++i) x += se[i];

		auto er = [se, v]() { showOutsMsg(L"", L"\\4Error\\7 in \\0C\\" + settings + L"\\0C\\ \\4[" + se + L" " + v + L"]\\7\\n", L"", 1); show_fg(); };
		switch (x) {
		case 545://Debug:
		{ if (v == L"0" || v == L"1" || v == L"2") debug = stoi(v); else er(); } break;
		case 353://UTF8:
		{
			if (se == L"UTF8:") {
				if (v == L"0" || v == L"1") {
					utf_8 = stoi(v);
					if (utf_8 && !u8) call_utf8();
					//num_error(L"Reload program for", L"1", L"UTF_8:")
					wcout.flush().clear();
				}
				else er();
			}
			break;
		}
		case 1536://RSHIFT+LSHIFT_Only:
		{ if (check_if_num(v) > L"") { RSHIFTLSHIFT_Only = stoi(v); rri = 0; } else er(); } break;
		case 1972://RSHIFT+CtrlKey_Toggle:
		{ if (check_if_num(v) > L"") RSHIFTCtrlKeyToggle = stoi(v); else er(); } break;
		case 865://PauseKey:
		{ if (check_if_num(v) > L"") PauseKey = stoi(v); else er(); } break;
		case 1708://Loop_Insert_Text:
		{ if (!v[0]) { v[0] = '>'; } if (v[v.length() - 1] != '>') v += '>'; Loop_Insert_Text = v; } break;
		case 1946://Kb_Key_Print_Screen:
			Kb_Key_Print_Screen = v; break;
		case 1083://Kb_Key_ScLk:
			Kb_Key_ScLk = v; break;
		case 783://Kb_Key_A:
			Kb_Key_A = v; break;
		case 784://Kb_Key_B:
			Kb_Key_B = v; break;
		case 785://Kb_Key_C:
			Kb_Key_C = v; break;
		case 786://Kb_Key_D:
			Kb_Key_D = v; break;
		case 787://Kb_Key_E:
			Kb_Key_E = v; break;
		case 788://Kb_Key_F:
			Kb_Key_F = v; break;
		case 789://Kb_Key_G:
			Kb_Key_G = v; break;
		case 790://Kb_Key_H:
			Kb_Key_H = v; break;
		case 791://Kb_Key_I:
			Kb_Key_I = v; break;
		case 792://Kb_Key_J:
			Kb_Key_J = v; break;
		case 793://Kb_Key_K:
			Kb_Key_K = v; break;
		case 794://Kb_Key_L:
			Kb_Key_L = v; break;
		case 795://Kb_Key_M:
			Kb_Key_M = v; break;
		case 796://Kb_Key_N:
			Kb_Key_N = v; break;
		case 797://Kb_Key_O:
			Kb_Key_O = v; break;
		case 798://Kb_Key_P:
			Kb_Key_P = v; break;
		case 799://Kb_Key_Q:
			Kb_Key_Q = v; break;
		case 800://Kb_Key_R:
			Kb_Key_R = v; break;
		case 801://Kb_Key_S:
			Kb_Key_S = v; break;
		case 802://Kb_Key_T:
			Kb_Key_T = v; break;
		case 803://Kb_Key_U:
			Kb_Key_U = v; break;
		case 804://Kb_Key_V:
			Kb_Key_V = v; break;
		case 805://Kb_Key_W:
			Kb_Key_W = v; break;
		case 806://Kb_Key_X:
			Kb_Key_X = v; break;
		case 807://Kb_Key_Y:
			Kb_Key_Y = v; break;
		case 808://Kb_Key_Z:
			Kb_Key_Z = v; break;
		case 766://Kb_Key_0:
			Kb_Key_0 = v; break;
		case 767://Kb_Key_1:
			Kb_Key_1 = v; break;
		case 768://Kb_Key_2:
			Kb_Key_2 = v; break;
		case 769://Kb_Key_3:
			Kb_Key_3 = v; break;
		case 770://Kb_Key_4:
			Kb_Key_4 = v; break;
		case 771://Kb_Key_5:
			Kb_Key_5 = v; break;
		case 772://Kb_Key_6:
			Kb_Key_6 = v; break;
		case 773://Kb_Key_7:
			Kb_Key_7 = v; break;
		case 774://Kb_Key_8:
			Kb_Key_8 = v; break;
		case 775://Kb_Key_9:
			Kb_Key_9 = v; break;
		case 837://Kb_Key_F1:
			Kb_Key_F1 = v; break;
		case 838://Kb_Key_F2:
			Kb_Key_F2 = v; break;
		case 839://Kb_Key_F3:, EditorDb:
		{
			if (se == L"EditorDb:") editorDb = v;
			else if (se == L"Kb_Key_F3:") Kb_Key_F3 = v;
		} break;
		case 840://Kb_Key_F4:
			Kb_Key_F4 = v; break;
		case 841://Kb_Key_F5:
			Kb_Key_F5 = v; break;
		case 842://Kb_Key_F6:
			Kb_Key_F6 = v; break;
		case 843://Kb_Key_F7:
			Kb_Key_F7 = v; break;
		case 844://Kb_Key_F8:
			Kb_Key_F8 = v; break;
		case 845://Kb_Key_F9:
			Kb_Key_F9 = v; break;
		case 885://Kb_Key_F10:
			Kb_Key_F10 = v; break;
		case 886://Kb_Key_F11:
			Kb_Key_F11 = v; break;
		case 887://Kb_Key_F12:
			Kb_Key_F12 = v; break;
		case 1113://Kb_Key_Left:
			Kb_Key_Left = v; break;
		case 1126://Kb_Key_Down:
			Kb_Key_Down = v; break;
		case 1210://Kb_Key_Space:
			Kb_Key_Space = v; break;
		case 1228://Kb_Key_Enter: | Kb_Key_Right: | Kb_Key_Pause:
		{
			if (se == L"Kb_Key_Enter:") Kb_Key_Enter = v;
			else if (se == L"Kb_Key_Right:") Kb_Key_Right = v;
			else if (se == L"Kb_Key_Pause:") Kb_Key_Pause = v;
		} break;
		case 1109://Kb_Key_Caps:
			Kb_Key_Caps = v; break;
		case 1904://Kb_Key_Grave_Accent:
			Kb_Key_Grave_Accent = v; break;
		case 1242://Kb_Key_Minus:
			Kb_Key_Minus = v; break;
		case 1222://Kb_Key_Equal:
			Kb_Key_Equal = v; break;
		case 1908://Kb_Key_Left_Bracket:
			Kb_Key_Left_Bracket = v; break;
		case 1626://Kb_Key_Backslash:
			Kb_Key_Backslash = v; break;
		case 1655://Kb_Key_Semicolon:
			Kb_Key_Semicolon = v; break;
		case 1244://Kb_Key_Quote:
			Kb_Key_Quote = v; break;
		case 1211://Kb_Key_Comma:
			Kb_Key_Comma = v; break;
		case 1329://Kb_Key_Period:
			Kb_Key_Period = v; break;
		case 1982://Kb_Key_Forwardslash:
			Kb_Key_Forwardslash = v; break;
		case 1123://Kb_Key_Menu:
			Kb_Key_Menu = v; break;
		case 1347://Kb_Key_Insert:
			Kb_Key_Insert = v; break;
		case 1111://Kb_Key_Home:
			Kb_Key_Home = v; break;
		case 997://Kb_Key_End: | Kb_Key_Tab:
		{
			if (se == L"Kb_Key_End:") Kb_Key_End = v;
			else if (se == L"Kb_Key_Tab:") Kb_Key_Tab = v;
		} break;
		case 1079://Kb_Key_PgDn:
			Kb_Key_PgDn = v; break;
		case 1474://Kb_Key_Numpad_0:
			Kb_Key_Numpad_0 = v; break;
		case 1475://Kb_Key_Numpad_1:
			Kb_Key_Numpad_1 = v; break;
		case 1476://Kb_Key_Numpad_2:
			Kb_Key_Numpad_2 = v; break;
		case 1477://Kb_Key_Numpad_3:
			Kb_Key_Numpad_3 = v; break;
		case 1478://Kb_Key_Numpad_4:
			Kb_Key_Numpad_4 = v; break;
		case 1479://Kb_Key_Numpad_5:
			Kb_Key_Numpad_5 = v; break;
		case 1480://Kb_Key_Numpad_6:
			Kb_Key_Numpad_6 = v; break;
		case 1481://Kb_Key_Numpad_7:
			Kb_Key_Numpad_7 = v; break;
		case 1482://Kb_Key_Numpad_8:
			Kb_Key_Numpad_8 = v; break;
		case 1483://Kb_Key_Numpad_9:
			Kb_Key_Numpad_9 = v; break;
		case 1447://Kb_Key_Numlock:
			Kb_Key_Numlock = v; break;
		case 2023://Kb_Key_Numpad_Divide: | Kb_Key_Right_Bracket:
		{
			if (se == L"Kb_Key_Numpad_Divide:") Kb_Key_Numpad_Divide = v;
			else if (se == L"Kb_Key_Right_Bracket:") Kb_Key_Right_Bracket = v;
		} break;
		case 2290://Kb_Key_Numpad_Multiply:
			Kb_Key_Numpad_Multiply = v; break;
		case 1950://Kb_Key_Numpad_Minus:
			Kb_Key_Numpad_Minus = v; break;
		case 1691://Kb_Key_Numpad_Add:
			Kb_Key_Numpad_Add = v; break;
		case 2037://Kb_Key_Numpad_Period:
			Kb_Key_Numpad_Period = v; break;
		case 1936://Kb_Key_Numpad_Enter:
			Kb_Key_Numpad_Enter = v; break;
		case 2066://DbMultiLineDelimiter:
			delimiter = wstring_to_utf8(v);
			
			if (v[0] == '\\')
				delimiter = '\n';
			else if (delimiter[0] < 0)
				delimiter = delimiter.substr(1);

			break;
		case 673://Editor:
			editor = v; break;
		case 857://EditorSe:
			editorSe = v; break;
		case 1003://ShowInput:
		{ if (v == L"0" || v == L"1") show_strand = stoi(v); else er(); } break;
		case 847://Database:
		{ if (v.length() > 0) { database = v; database = regex_replace(database, wregex(L"/"), L"\\"); db = database.substr(database.find_last_of('\\') + 1) + L" - "; } else er(); } break;
		case 907://Settings:
		{ if (v.length() > 0) { settings = v; settings = regex_replace(settings, wregex(L"/"), L"\\"); se = settings.substr(settings.find_last_of('\\') + 1) + L" - "; } else er(); } break;
		case 1038://ReplacerDb:
			replacerDb = v; break;
		case 1313://Kb_Key_Delete:
			if (se == L"Kb_Key_Delete:") Kb_Key_Delete = v; break;
		case 1354://CloseCtrlMode:
		{ if (v == L"0" || v == L"1") close_ctrl_mode = stoi(v); else er(); } break;
		case 1659://CtrlScanOnlyMode:
		{ if (v == L"0" || v == L"1") ctrl_scan_only_mode = stoi(v); else er(); } break;
		case 1196://InputLength:
		{ if (check_if_num(v) > L"") strand_length = stoi(v); else er(); } break;
		case 915://Kb_Key_Up:
			Kb_Key_Up = v; break;
		case 1172://StartHidden:
		{ if (v == L"0" || v == L"1") start_hidden = stoi(v); else er(); } break;
		case 760://CtrlKey: (vk_enum max)
		{
			if (v.find(' ') != string::npos) {
				wstring max = v.substr(v.find(' ') + 1); if (max.find(' ') != string::npos || max[0] == 0) { er(); break; }
				v = v.substr(0, v.find(' '));
				if (check_if_num(max, L"CtrlKey duration (ms)") == L"") { er(); break; }
				cKeyMax = stoi(max);
			}
			if (check_if_num(v, L"CtrlKey") == L"") { er(); break; }
			cKey = stoi(v);
		} break;
		case 1004://Frequency:
		{ if (check_if_num(v) > L"") frequency = stoi(v); else er(); } break;
		case 964://RepeatKey:
		{ if (check_if_num(v) > L"") repeat_key = stoi(v); else er(); } break;
		case 1649://AutoBs_RepeatKey:
		{ if (v == L"0" || v == L"1") auto_bs_repeat_key = stoi(v); else er(); } break;
		case 1467://RgbScaleLayout:
		{ if (check_if_num(v) > L"") RgbScaleLayout = stod(v); else er(); } break;
		case 1098://Kb_Key_PgUp: 
			Kb_Key_PgUp = v; break;
		case 1001://Kb_Key_Esc:
			Kb_Key_Esc = v; break;

		}
	}

	f.close();
}

static void printSe() {
	wcout << settings << '\n'; ifstream f(settings); if (f.fail()) { showOutsMsg(L"Copy to ", settings, L"\n", 0); } f.close();
	cout << "StartHidden: " << start_hidden << '\n';
	wcout << "Settings: " << settings << '\n';
	wcout << "Database: " << database << '\n';
	cout << "DbMultiLineDelimiter: "; if (delimiter[0] == '\n') cout << "\\n\n"; else cout << delimiter.substr(1) << '\n';
	wcout << "ReplacerDb: " << replacerDb << '\n';
	cout << "UTF8: " << utf_8 << '\n';
	cout << "Debug: " << debug << '\n';
	cout << "ShowInput: " << show_strand << '\n';
	cout << "InputLength: " << strand_length << '\n';
	cout << "CtrlKey: " << cKey << ' ' << cKeyMax << '\n';
	cout << "CloseCtrlMode: " << close_ctrl_mode << '\n';
	cout << "RSHIFT+CtrlKey_Toggle: " << RSHIFTCtrlKeyToggle << '\n';
	cout << "CtrlScanOnlyMode: " << ctrl_scan_only_mode << '\n';
	cout << "RSHIFT+LSHIFT_Only: " << RSHIFTLSHIFT_Only << '\n';
	cout << "RepeatKey: " << repeat_key << '\n';
	cout << "PauseKey: " << PauseKey << '\n';
	cout << "RgbScaleLayout: " << RgbScaleLayout << '\n';
	cout << "Frequency: " << frequency << '\n';
	wcout << "Kb_Key_0: " << Kb_Key_0 << '\n';
	wcout << "Kb_Key_1: " << Kb_Key_1 << '\n';
	wcout << "Kb_Key_2: " << Kb_Key_2 << '\n';
	wcout << "Kb_Key_3: " << Kb_Key_3 << '\n';
	wcout << "Kb_Key_4: " << Kb_Key_4 << '\n';
	wcout << "Kb_Key_5: " << Kb_Key_5 << '\n';
	wcout << "Kb_Key_6: " << Kb_Key_6 << '\n';
	wcout << "Kb_Key_7: " << Kb_Key_7 << '\n';
	wcout << "Kb_Key_8: " << Kb_Key_8 << '\n';
	wcout << "Kb_Key_9: " << Kb_Key_9 << '\n';
	wcout << "Kb_Key_A: " << Kb_Key_A << '\n';
	wcout << "Kb_Key_B: " << Kb_Key_B << '\n';
	wcout << "Kb_Key_C: " << Kb_Key_C << '\n';
	wcout << "Kb_Key_D: " << Kb_Key_D << '\n';
	wcout << "Kb_Key_E: " << Kb_Key_E << '\n';
	wcout << "Kb_Key_F: " << Kb_Key_F << '\n';
	wcout << "Kb_Key_G: " << Kb_Key_G << '\n';
	wcout << "Kb_Key_H: " << Kb_Key_H << '\n';
	wcout << "Kb_Key_I: " << Kb_Key_I << '\n';
	wcout << "Kb_Key_J: " << Kb_Key_J << '\n';
	wcout << "Kb_Key_K: " << Kb_Key_K << '\n';
	wcout << "Kb_Key_L: " << Kb_Key_L << '\n';
	wcout << "Kb_Key_M: " << Kb_Key_M << '\n';
	wcout << "Kb_Key_N: " << Kb_Key_N << '\n';
	wcout << "Kb_Key_O: " << Kb_Key_O << '\n';
	wcout << "Kb_Key_P: " << Kb_Key_P << '\n';
	wcout << "Kb_Key_Q: " << Kb_Key_Q << '\n';
	wcout << "Kb_Key_R: " << Kb_Key_R << '\n';
	wcout << "Kb_Key_S: " << Kb_Key_S << '\n';
	wcout << "Kb_Key_T: " << Kb_Key_T << '\n';
	wcout << "Kb_Key_U: " << Kb_Key_U << '\n';
	wcout << "Kb_Key_V: " << Kb_Key_V << '\n';
	wcout << "Kb_Key_W: " << Kb_Key_W << '\n';
	wcout << "Kb_Key_X: " << Kb_Key_X << '\n';
	wcout << "Kb_Key_Y: " << Kb_Key_Y << '\n';
	wcout << "Kb_Key_Z: " << Kb_Key_Z << '\n';
	wcout << "Kb_Key_Left: " << Kb_Key_Left << '\n';
	wcout << "Kb_Key_Up: " << Kb_Key_Up << '\n';
	wcout << "Kb_Key_Right: " << Kb_Key_Right << '\n';
	wcout << "Kb_Key_Down: " << Kb_Key_Down << '\n';
	wcout << "Kb_Key_Backslash: " << Kb_Key_Backslash << '\n';
	wcout << "Kb_Key_Caps: " << Kb_Key_Caps << '\n';
	wcout << "Kb_Key_Comma: " << Kb_Key_Comma << '\n';
	wcout << "Kb_Key_Delete: " << Kb_Key_Delete << '\n';
	wcout << "Kb_Key_End: " << Kb_Key_End << '\n';
	wcout << "Kb_Key_Enter: " << Kb_Key_Enter << '\n';
	wcout << "Kb_Key_Equal: " << Kb_Key_Equal << '\n';
	wcout << "Kb_Key_Esc: " << Kb_Key_Esc << '\n';
	wcout << "Kb_Key_F1: " << Kb_Key_F1 << '\n';
	wcout << "Kb_Key_F2: " << Kb_Key_F2 << '\n';
	wcout << "Kb_Key_F3: " << Kb_Key_F3 << '\n';
	wcout << "Kb_Key_F4: " << Kb_Key_F4 << '\n';
	wcout << "Kb_Key_F5: " << Kb_Key_F5 << '\n';
	wcout << "Kb_Key_F6: " << Kb_Key_F6 << '\n';
	wcout << "Kb_Key_F7: " << Kb_Key_F7 << '\n';
	wcout << "Kb_Key_F8: " << Kb_Key_F8 << '\n';
	wcout << "Kb_Key_F9: " << Kb_Key_F9 << '\n';
	wcout << "Kb_Key_F10: " << Kb_Key_F10 << '\n';
	wcout << "Kb_Key_F11: " << Kb_Key_F11 << '\n';
	wcout << "Kb_Key_F12: " << Kb_Key_F12 << '\n';
	wcout << "Kb_Key_Print_Screen: " << Kb_Key_Print_Screen << '\n';
	wcout << "Kb_Key_ScLk: " << Kb_Key_ScLk << '\n';
	wcout << "Kb_Key_Forwardslash: " << Kb_Key_Forwardslash << '\n';
	wcout << "Kb_Key_Grave_Accent: " << Kb_Key_Grave_Accent << '\n';
	wcout << "Kb_Key_Home: " << Kb_Key_Home << '\n';
	wcout << "Kb_Key_Insert: " << Kb_Key_Insert << '\n';
	wcout << "Kb_Key_Left_Bracket: " << Kb_Key_Left_Bracket << '\n';
	wcout << "Kb_Key_Menu: " << Kb_Key_Menu << '\n';
	wcout << "Kb_Key_Minus: " << Kb_Key_Minus << '\n';
	wcout << "Kb_Key_Numpad_0: " << Kb_Key_Numpad_0 << '\n';
	wcout << "Kb_Key_Numpad_1: " << Kb_Key_Numpad_1 << '\n';
	wcout << "Kb_Key_Numpad_2: " << Kb_Key_Numpad_2 << '\n';
	wcout << "Kb_Key_Numpad_3: " << Kb_Key_Numpad_3 << '\n';
	wcout << "Kb_Key_Numpad_4: " << Kb_Key_Numpad_4 << '\n';
	wcout << "Kb_Key_Numpad_5: " << Kb_Key_Numpad_5 << '\n';
	wcout << "Kb_Key_Numpad_6: " << Kb_Key_Numpad_6 << '\n';
	wcout << "Kb_Key_Numpad_7: " << Kb_Key_Numpad_7 << '\n';
	wcout << "Kb_Key_Numpad_8: " << Kb_Key_Numpad_8 << '\n';
	wcout << "Kb_Key_Numpad_9: " << Kb_Key_Numpad_9 << '\n';
	wcout << "Kb_Key_Numlock: " << Kb_Key_Numlock << '\n';
	wcout << "Kb_Key_Numpad_Divide: " << Kb_Key_Numpad_Divide << '\n';
	wcout << "Kb_Key_Numpad_Multiply: " << Kb_Key_Numpad_Multiply << '\n';
	wcout << "Kb_Key_Numpad_Minus: " << Kb_Key_Numpad_Minus << '\n';
	wcout << "Kb_Key_Numpad_Add: " << Kb_Key_Numpad_Add << '\n';
	wcout << "Kb_Key_Numpad_Period: " << Kb_Key_Numpad_Period << '\n';
	wcout << "Kb_Key_Numpad_Enter: " << Kb_Key_Numpad_Enter << '\n';
	wcout << "Kb_Key_Period: " << Kb_Key_Period << '\n';
	wcout << "Kb_Key_PgDn: " << Kb_Key_PgDn << '\n';
	wcout << "Kb_Key_PgUp: " << Kb_Key_PgUp << '\n';
	wcout << "Kb_Key_Quote: " << Kb_Key_Quote << '\n';
	wcout << "Kb_Key_Right_Bracket: " << Kb_Key_Right_Bracket << '\n';
	wcout << "Kb_Key_Semicolon: " << Kb_Key_Semicolon << '\n';
	wcout << "Kb_Key_Space: " << Kb_Key_Space << '\n';
	wcout << "Kb_Key_Tab: " << Kb_Key_Tab << '\n';
	wcout << "Kb_Key_Pause: " << Kb_Key_Pause << '\n';
	cout << "AutoBs_RepeatKey: " << auto_bs_repeat_key << '\n';
	wcout << "Editor: " << editor << '\n';
	wcout << "EditorDb: "; wcout << editorDb << '\n';
	wcout << "EditorSe: "; wcout << editorSe << '\n';
	wcout << "Loop_Insert_Text: " << Loop_Insert_Text << '\n';
	cout << endl;
}

static void mouseEvent(short key) {
	INPUT ip{}; ip.type = INPUT_MOUSE; ip.mi.time = 0;
	ip.mi.dwFlags = key;
	if (key == MOUSEEVENTF_HWHEEL) {
		if (qq.substr(0, 3) == L"<sr") ip.mi.mouseData = WHEEL_DELTA;//scroll right
		else if (qq.substr(0, 3) == L"<sd") { ip.mi.dwFlags = MOUSEEVENTF_WHEEL; ip.mi.mouseData = -WHEEL_DELTA; }//scroll down
		else if (qq.substr(0, 3) == L"<sl") ip.mi.mouseData = -WHEEL_DELTA;//scroll left
		else if (qq.substr(0, 3) == L"<su") { ip.mi.dwFlags = MOUSEEVENTF_WHEEL; ip.mi.mouseData = WHEEL_DELTA; }//scroll up
	}
	SendInput(1, &ip, sizeof(ip));
}

static void rei() {
	c += qq.find('>');
}

static void kb_hold(short key) {
	INPUT ip{}; ip.type = INPUT_KEYBOARD; ip.ki.wVk = key; ip.ki.time = 0;
	if (key == VK_LMENU || key == VK_CONTROL) ip.ki.dwFlags = 0; else ip.ki.dwFlags = 1;
	SendInput(1, &ip, sizeof(INPUT));
}

static void kb_release(short key) {
	INPUT ip{}; ip.type = INPUT_KEYBOARD; ip.ki.wVk = key;
	ip.ki.dwFlags = KEYEVENTF_KEYUP; SendInput(1, &ip, sizeof(INPUT));
}

static void shift_release() {
	INPUT ip{}; ip.type = INPUT_KEYBOARD; ip.ki.dwFlags = 2;
	ip.ki.wVk = VK_LSHIFT;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.wVk = VK_RSHIFT;
	SendInput(1, &ip, sizeof(INPUT));
	if (hold_shift) hold_shift = false;
}

static void prints() {
	if (show_strand)
		wcout << strand << '\n';
}

static void printq() {
	kb_hold(VK_LSHIFT);
	kb('<');
	shift_release();
}

static void sleep(unsigned long ms) {
	this_thread::sleep_for(chrono::milliseconds(ms));
}

static void kb_press(wstring s, short key) {
	if (!qp[0])
		qp = L"1";
	else if (check_if_num(qp, L"<key #>") == L"") { //if (qp[0] < '0' || qp[0] > '9' || )
		printq(); return;
	}
	
	INPUT ip[2]{};
	ip[0].type = INPUT_KEYBOARD;
	ip[0].ki.wVk = key;
	ip[0].ki.dwFlags = key > 0x22 && key < 0x29 ? 1 : 0; //if (key == VK_END || key == VK_HOME || key == VK_LEFT || key == VK_UP || key == VK_RIGHT || key == VK_DOWN || )
	ip[1] = ip[0];
	ip[1].ki.dwFlags = 2;

	unsigned x = stoul(qp);
	//if (to_wstring(x).length() != qp.length()) {
	//	printq(); return;
	//}
	for (unsigned j = 0; j < x; ++j) {
		if (GetAsyncKeyState(VK_ESCAPE))
			return;

		if (s.length() == 3) {
			key = 0;
			if (s == L"<lc") {
				mouseEvent(MOUSEEVENTF_LEFTDOWN);
				mouseEvent(MOUSEEVENTF_LEFTUP);
			}
			else if (s == L"<rc") {
				mouseEvent(MOUSEEVENTF_RIGHTDOWN);
				mouseEvent(MOUSEEVENTF_RIGHTUP);
			}
			else if (s == L"<mc") {
				mouseEvent(MOUSEEVENTF_MIDDLEDOWN);
				mouseEvent(MOUSEEVENTF_MIDDLEUP);
			}
			else if (s == L"<sd" || s == L"<sr"
				|| s == L"<su" || s == L"<sl")
				mouseEvent(MOUSEEVENTF_HWHEEL);
			else
				SendInput(2, ip, sizeof(ip[0]));
		}
		else
			SendInput(2, ip, sizeof(ip[0]));

		if (out_speed > 0 && x != j + 1) sleep(out_speed);
	}

	rei();

}

static bool npos_find(wstring& w, char c, bool b = 1) {
	return b
		? w.find(c) != string::npos
		: w.find(c) == string::npos;
}

static void setQxQy(wstring x) {
	size_t q;

	if (x.find(' ') != string::npos) //<xy:# #>
		q = x.find(' ');
	else if (x.find(',') != string::npos) //<xy:#,#>
		q = x.find(',');
	else {
		if (qx[0]) { qx = L"", qy = L""; }
		return;
	}
	qx = x.substr(0, q);
	qy = x.substr(q + 1, 0 - q - 1);

	//wcout << "x: " << x  << "\nqx: " << qx << "\nqy: " << qy << endl;
}

static wstring get_out(wstring q) {
	wstring g = q.substr(q.find_first_of(L" -:>"));
	if (q[0] != '<') q = q.substr(0, q.length() - g.length());

	if (vstrand.at(found_io - 1).in == q && vstrand.at(found_io - 1).g == g) //possible <x:><x:> loop
		return vstrand_out.at(found_io - 1).out;

	size_t n{};

	wstring b;
	
	switch (q[1]) {
	case '!': { //downwards scan or go to line #; <!x:>
		if (q.substr(2).find('!') != string::npos) { //<!a!b:>
			wstring a = q.substr(2);
			a = a.substr(0, a.find('!'));

			if (check_if_num(a) != L"") {
				n = a[0] == '.' ? found_io : stoi(a); //<!.!> | <!#!>

				if (n <= 0 || n > vstrand_out.size()) return L"";

				n -= 1;

				b = L"<" + q.substr(a.length() + 3);

				// go to line #; <!#!> || <!#!x:>
				if (b == L"<" + g || vstrand.at(n).in == b && vstrand.at(n).g == g) {
					found_io = n + 1;
					return vstrand_out.at(n).out;
				}
			}

			return L"";
		}

		b = L"<" + q.substr(2);

		n = found_io < vstrand.size() ? found_io : n;

		if (b == L"<>") //!
			return vstrand_out.at(n).out;

		for (; n != found_io - 1; ++n) { //<!x:>
			if (vstrand.at(n).in == b && vstrand.at(n).g == g) {
				found_io = n + 1;
				return vstrand_out.at(n).out;
			}
			if (n == vstrand.size() - 1) n = -1;
		}
	}
		break;
	case '^': { //upwards scan; <^x:>
		if (vstrand.size() == 1) return L"";
		if (found_io == 1) n = vstrand.size() - 1;
		else
			n = found_io == vstrand.size() ? vstrand.size() - 2 : found_io - 2;

		b = L"<" + q.substr(2);

		if (b == L"<>") //^
			return vstrand_out.at(n).out;

		for (; n != found_io - 1; --n) { //<^b:>
			if (vstrand.at(n).in == b && vstrand.at(n).g == g) {
				found_io = n + 1;
				return vstrand_out.at(n).out;
			}
			if (n == 0) n = vstrand.size();
		}
	}
		break;
	default: //regular top to bottom scan; <x:>
		for (; n < vstrand.size(); ++n)
			if (vstrand.at(n).in == q && vstrand.at(n).g == g) {
				found_io = n + 1;
				return vstrand_out.at(n).out;
			}
	}

	return L"";

}

static wstring is_replacer(wstring& q) { // Replacer | {var:} {var-} {var>} | <r:>
	if (q.find('{') != string::npos && q.find('}') != string::npos) {
		wstring tqg = q, tq{};
		GetAsyncKeyState(VK_ESCAPE);
		while (tqg.find('{') != string::npos) {
			if (GetAsyncKeyState(VK_ESCAPE)) break;
			q = q.substr(q.find('{') + 1);
			q = q.substr(0, q.find(L'}'));
			tq = q;
			if (q[0]) {
				if (q[0] == '\'' && q != L"'") { tqg.replace(tqg.find('{'), 2 + q.length(), L""); q = tqg; continue; } //{'ignore}
				if (q.length() > 1 && (q[q.length() - 1] == ' ' || q[q.length() - 1] == '-' || q[q.length() - 1] == ':' || q[q.length() - 1] == '>'))
					q = get_out(q);
				else {
					q = tqg;
					return q;
				}
			}
			if (!q[0]) {
				tqg.replace(tqg.find('{'), 1, L"::_::"); q = tqg;
				continue;
			}
			q = regex_replace(q, wregex(L"\\$"), L":s:_:s:");
			tq = regex_replace(tq, wregex(L"\\\\"), L":b:_:b:");
			tq = regex_replace(tq, wregex(L"\\$"), L"\\$");
			tq = regex_replace(tq, wregex(L"\\["), L"\\[");
			tq = regex_replace(tq, wregex(L"\\]"), L"\\]");
			tq = regex_replace(tq, wregex(L"\\("), L"\\(");
			tq = regex_replace(tq, wregex(L"\\)"), L"\\)");
			tq = regex_replace(tq, wregex(L"\\{"), L"\\{");
			tq = regex_replace(tq, wregex(L"\\}"), L"\\}");
			tq = regex_replace(tq, wregex(L"\\|"), L"\\|");
			tq = regex_replace(tq, wregex(L"\\?"), L"\\?");
			tq = regex_replace(tq, wregex(L"\\+"), L"\\+");
			tq = regex_replace(tq, wregex(L"\\*"), L"\\*");
			tq = regex_replace(tq, wregex(L"\\^"), L"\\^");
			tq = regex_replace(tq, wregex(L"\\."), L"\\.");
			tq = regex_replace(tq, wregex(L":b:_:b:"), L"\\\\");
			tqg = regex_replace(tqg, wregex(L"\\{" + tq + L"\\}"), q);
			q = tqg;
		}
		tqg = regex_replace(tqg, wregex(L"::_::"), L"{"); tqg = regex_replace(tqg, wregex(L":s:_:s:"), L"$");
		q = tqg;
	}
	return q;
}

static wstring connect(wstring& w, bool bg = 0) {
	bool con{};
	wstring qqs = qq.substr(0, qq.find('>') + 1);
	if (bg) { qqs = qq + L">"; con = 1; }

	if (qqs.find('>') != string::npos) {
		wchar_t s = qqs[qqs.length() - 2];
		if (s == '!' || s == '^' || s == ':' || s == '-' || s == ' ')
			con = 1;
	}

	if (con) {
		bool x{};
		if (!follow) { follow = found_io; x = 1; }

		wstring o = get_out(qqs);
		
		if (o[0]) {
			if (x) o += L"<@:>"; //follow
			if (bg) return replacerDb[0] ? is_replacer(o) : o;
			
			w = o + qq.substr(qqs.length());
			if (replacerDb[0]) is_replacer(w);
			c = -1;
			if (out_speed > 0) out_sleep = 0;
			return L"";
		}
		//else use <x:><''> for exit
	}
	printq();
	return L"";
}

static bool qqb(const wstring s) {
	return s == chk.substr(0, chk.find(' ')) || s + L">" == chk;
}

static void print_ctrls() {
	cout << R"(Anunnaki Keyboard

?+ESC		Help
X+ESC		Exit
H+ESC		Toggle visibility
P+ESC		<xy:>
A+ESC		<ifapp~:>
R+ESC		<ifrgb:>
L+ESC		Toggle se.txt [RSHIFT+LSHIFT_Only]
G+ESC		RGBXY to clipboard (cb) in 3 sec.
Set mouse pointer over target, press G+ESC, then move it away

Input Output Syntax (c:\anu\db.txt)
i:o
i o		Use space or - for auto backspace input
i-o
i>o		Use > for remember input for [RepeatKey]

i\>		Use this format to ignore tabs and newlines
	o
\

<i:>o		Link. Use : or -
i <i:>

i		Fallthrough
ii o

Use RCTRL, F2, PAUSE, RSHIFT+LSHIFT, or COMMA+ESC after input to run (or to toggle < if no input)

Repeat
Use SCROLL [RepeatKey 70], RCTRL+LCTRL, or EQUAL+ESC

Clear input
Hold RSHIFT, Press LSHIFT three times

Use <anu> to run its output when program starts

<'''		0 db underneath

Output:

Settings
<se>		Reload and show
<se:>		Load other (<se:c:\anu\se1.txt>)
<SE>		Reload
<SE:>		Soft load

Database
<db>		Show
<db:>		Load too. Use se.txt [Database] for fresh db
<DB>		Reload

Mouse event
<~>		Set current position
<xy:>		Move to
<xy~:>		Auto set
<~~>		Return
<lc>		LEFT CLICK
<rc>		RIGHT
<mc>		MIDDLE
<lh>		HOLD
<rh>
<mh>
<lr>		RELEASE
<rr>
<mr>
<sl>		SCROLL LEFT
<su>		UP
<sr>		RIGHT
<sd>		DOWN
in <xy: 0 0><lc 2>

Window controls
<ifapp:>	If app is open; continue
<ifapp~:>	Use ~ to move app to foreground
<ifApp:>	Use A to check if app window is in focus

Full syntax
<ifapp~: 'title | Title, *, ms n, t: f:'>

Use ' before the closing > for final ms delay (optional)

Stop if false
<ifapp~: title>

Loop. Check every 160ms
<ifapp~: title,>

Loop feedback message. Use ' (prepend to title)
<ifapp~: '?'t,> (extended)

Check 3 times. 3000ms delay
<ifapp~: 't, 3, 3000>

Loop infinitely
<ifapp~: 't, 1, 1000,>

Link to <f:> if false
<ifapp~: t, 1, 1, f:>
<f:><'F>

Link to <t:> if true (true false slot)
<ifapp~: t, 1, 1, t: f:>
<t:><'T>
<f:><'F>

Link and continue. Use <
<ifapp~: t, 1, 1, <t: <f:><'1>

Options for true false slot. Use <db> algos or
<		Continue
,		Retry (false slot)
!		Link to output below
^		Above

Print to Terminal
<:x\n>		Custom message
<'x>		Auto newline
<' x>		No print. Use SPACE
<''x>0		Use '' to dead line to the right
		
Print options
\1		Color (1-9). Or use \012\ \R \G \B \W \00\
\n		Newline
\t		Tab
\T		Time
\g		>
\c		Cb
\i		Input
\+		Counter
\'		Ignore
\,		Clock. Use before and after codes for time elapsed (ms)
\*		Toggle multi-run
\0C\		Toggle only \n mode

Keyboard
<ctrl>		Hold key
<shift>
<alt>
<win>
<ctrl->		Release key
<shift->
<alt->
<win->
<up>		Press key
<right>
<down>
<left>
<delete>
<esc>
<bs>
<home>
<end>
<space>
<tab>
<enter>
<pause>
<caps>
<menu>
<pause>
<ins>
<pu>
<pd>
<ps>
<f12>
<win 1>		Multi press
in <shift><left 3><shift-><ctrl>x<ctrl->

Sleep
<,>		160 milliseconds
<,1000>		1000 ms
<,10000 40>	Make it escapable (Hold ESC; F12 pause/resume)

Output speed
<speed: 160>

Message box
<yesno: Title\ here Continue\n?>

Replace cb
<replace: (\r\n) x$1>

<upper>		Uppercase cb
<lower>

<Audio: c:\anu\fx.wav>
<audio: play c:\anu\fx.mp3>

Set se.txt [RgbScaleLayout] to match Display settings > Scale & layout. [1.00] is 100%
<ifrgb:>	Continue running if rgbxy is true (x y optional or use . for current location)
<ifrgb~:>	Use ~ to move mouse pointer to x y if r g b x y is true

Syntax		Use either & or | (optional)
<ifrgb~: 'r g b x y & r g b x y, *, ms n, t: f:'>

<ifcb:>		Options:
<ifcb!=:>	== != < <= g g= (logical)
<ifcbf:>	Regex find
<ifcbF:>	Find
<ifcbS:>	Starts with
<ifcbE:>	Ends with
<ifcblen:>	Length

<ifxy:>		Same logical options

Counter
<+>		Out
<+:1>		Adjust counter with math. Use + - * / %
<+: 1>		Use space for cb counter
<if+:>		Stop if counters value is true. Same logical options
<if+:1 x:>	Link to <x:> if counters value equals 1. Use space followed by the link

Manual controls
<!:>		Set input; return
<!!:>		Set repeat
<!!!:>		Detach run

<app>		To cb
<xy>		Out
<rgb>
<time>
<time:>

<cb>		Paste
<cb:>		Set

<db> algos (Use : or -)
<in:>		Scan db from top to bottom
<!in:>		Strat scan at next line for <in:> (full circle). Use !
<^in:>		Upwards scan. Use ^
<!#!>		Get output from <db> line #. Use . for current
<!#!in:>	With sanity check

Misc.
\\\\g		Inside <ifapp:> for >
Other		\g \, \| \&

CTRL+S inside
[EditorDb]	Rebuild [Database]
[EditorSe]	Push new settings

[Debug 2]	Assume

Set se.txt [ReplacerDb c:\anu\db.txt] for replacer ability
in {x:}
x:1

VS Code:	"[plaintext]": { "editor.insertSpaces": false, "editor.detectIndentation": false
)"; //Use legacy terminal: WIN + "Terminal settings" > Windows Console Host

}

static void toggle_visibility() {
	if (IsWindowVisible(GetConsoleWindow())) {
		SetForegroundWindow(GetConsoleWindow());
		//kb(VK_F12); //if title "Select" x86
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
	else
		show_fg();

	strand.clear();
}

static wstring getRGB(unsigned short bg = 0) {
	POINT pt;
	GetCursorPos(&pt);

	COLORREF color;
	HDC hDC;
	wstring out = L"";
	hDC = GetDC(NULL);

	if (hDC != NULL) {
		auto x = pt.x, y = pt.y;
		bool cb = 0;

		if (bg) {
			if (!qq[0]) {
				cb = 1;
				sleep(3000);
			}
			else
			{
				wstring ms = bg == 2 ? qp : L"1";

				if (check_if_num(ms, L"<rgb {slot}>") == L"") {
					c = out.length();
					return L"";
				}

				sleep(stoul(ms));
			}
		}

		color = GetPixel(hDC, int(x * RgbScaleLayout), int(y * RgbScaleLayout));
		ReleaseDC(NULL, hDC);

		if (color != CLR_INVALID) {
			wstring c = to_wstring(GetRValue(color)) + L" " + to_wstring(GetGValue(color)) + L" " + to_wstring(GetBValue(color));//cb
			if (bg) {
				if (cb) { //g + esc
					wstring r = L"<ifrgb~:";
					r += c + L" " + to_wstring(x) + L" " + to_wstring(y);
					r += Loop_Insert_Text > L"" ? Loop_Insert_Text : L">";

					cbSet(r);

					return L"";
				}
				qx = to_wstring(x); qy = to_wstring(y);
				return c + L" " + qx + L" " + qy;
			}
			out = L"ifrgb:" + c + L" " + to_wstring(x) + L" " + to_wstring(y) + (Loop_Insert_Text > L"" ? Loop_Insert_Text : L">");

		}
	}
	return out;
}

static wstring getXY() {
	POINT pt; GetCursorPos(&pt);
	wstring xy = to_wstring(pt.x) + L" " + to_wstring(pt.y);
	xy += Loop_Insert_Text > L"" ? Loop_Insert_Text : L">";
	return xy;
}

static wstring getAppT() {
	HWND h = GetForegroundWindow();
	int l = GetWindowTextLength(h);
	wstring title(l, 0);
	GetWindowTextW(h, &title[0], l + 1);
	title = regex_replace(title, wregex(L","), L"\\,");
	title = regex_replace(title, wregex(L">"), L"\\g");
	title = regex_replace(title, wregex(L"\\|"), L"\\|");
	title = regex_replace(title, wregex(L"&"), L"\\&");
	return title;
}

static void if_esc() {
	GetAsyncKeyState(VK_ESCAPE); if (GetAsyncKeyState(VK_ESCAPE))
		stop = 1;
}

static void if_pause() {
	while (1) {
		if (!pause) break;

		if (GetAsyncKeyState(VK_ESCAPE))
			stop = 1;

		if (stop) { pause = 0; if (show_strand) cout << " ESC\n"; break; }

		sleep(frequency);
	}
}

static void multi_sleep(Multi_ &multi_, unsigned long ms, unsigned long n = 1) {
	if (ms > 0) {
		multi_.out_ = out;
		multi_.qq_ = qq;
		multi_.qp_ = qp;
		multi_.c_ = c;

		if (n > 1 && ms > n) {
			for (size_t i = 0; i < n; ++i) {
				if_esc();
				if (pause) if_pause();
				if (stop) break;
				this_thread::sleep_for(chrono::milliseconds(ms / n));
			}
		}
		else
			this_thread::sleep_for(chrono::milliseconds(ms));

		out = multi_.out_;
		qq = multi_.qq_;
		qp = multi_.qp_;
		c = multi_.c_;
	}
}

static void scan_db() {

	if (repeats[0] != '>') found_io_repeat = 0;
	found_io = 0;
	follow = 0;
	stop = 0;
	fallthrough_ = 0;
	clo = 0;

	for (size_t i = 0; i < vstrand.size(); ++i)
	{
		if (repeats[0] == '>'
			|| fallthrough_
			|| close_ctrl_mode && vstrand.at(i).in == strand.substr(0, strand.length() - 1)
			|| vstrand.at(i).in[0] == '<' &&
				vstrand.at(i).in.substr(0, vstrand.at(i).in.length() - vstrand.at(i).g.length())
				== strand.substr(0, strand.length() - 1)
			|| !close_ctrl_mode && vstrand.at(i).in == strand
			|| !close_ctrl_mode && vstrand.at(i).in == strand + vstrand.at(i).g
			) {

			if (out[0]) out.clear();

			if (repeats[0] == '>') {
				repeats = repeats.substr(1);
				if (!repeats[0]) return;
				out = repeats;
				found_io = found_io_repeat;
			}
			else {
				repeat_switch = 0;

				//fallthrough
				if (fallthrough_ && !vstrand.at(i).ft) fallthrough_ = 0;
				if (vstrand.at(i).ft) { fallthrough_ = 1; continue; }
				
				//backspace input depending on g and set repeat and input accordingly
				switch (vstrand.at(i).g[0])
				{
				case '>':
					if (vstrand.at(i).in[0] == '<') {
						repeats = vstrand.at(i).in.substr(1);
						repeats.pop_back();
					}
					else
						repeats = vstrand.at(i).in;
					repeats += vstrand_out.at(i).out;
					out = vstrand_out.at(i).out;
					break;
					//case ' ':
					//case '-':
				default:
					for (auto x : strand) {
						if (x == '>' || x == '<') continue;
						kb(VK_BACK);
					}
					[[fallthrough]];
				case ':':
					out = repeats = vstrand_out.at(i).out;
				}

				//set first hit
				found_io = found_io_repeat = i + 1;
			}

			//run output

			if (replacerDb[0]) is_replacer(out); //<r:>

			Multi_ multi_;

			if (strand[0]) strand.clear();

			for (c = 0; c < out.length(); ++c) {

				if_esc();
				if (pause) if_pause();
				if (stop) { stop = 0; break; }

				if (out_speed > 0) {
					if (out_sleep) {
						if (c)
							multi_sleep(multi_, out_speed);
					}
					out_sleep = 1;
				}

				switch (out[c]) { //extracted
				case '<':
					qq = out.substr(c, out.length() - c); //<test>
					
					if (qq[1] == '!' || qq[1] == '^') { //<!x:> or <^x:> scan
						if (qq[2] != '!' && qq[2] != ':' || qq[1] == '^') {
							connect(out);
							break;
						}
					}

					if (auto f = qq.find('>'); f != string::npos) {
						chk = L"";
						qp = L"";
						
						if (qq[1] == ':' || qq[1] == '\'' || qq[1] == ',') { //<:> <'> <,>
							chk = qq.substr(0, 2); //<:
							qp = qq.substr(2, f - 2); //#
						}
						else {
							if (qq.substr(0, f).find(':') != std::string::npos) { //<test:#>
								chk = qq.substr(0, qq.find(':') + 1); //<test:
								qp = qq.substr(chk.length(), f - chk.length()); //#
							}
							else if (qq.substr(0, f).find(' ') != std::string::npos) { //<test #>
								chk = qq.substr(0, qq.find(' ') + 1); //<test:
								qp = qq.substr(chk.length(), f - chk.length()); //#
							}
						}

						if (qp[0] == ' ') qp = qp.substr(1);

						if (!chk[0]) chk = qq.substr(0, f + 1); //<test:>
					}
					else {
						qp = L"";
						printq();
						continue;
					}

					switch (qq[1]) {
					case '@': //<@:> follow
						found_io = found_io_repeat;
						follow = 0;
						if (out_speed > 0) out_sleep = 0;
						rei();
						break;
					case ':':
						if (qqb(L"<:")) { //cout
							showOutsMsg(L"", qp, L"", 1);
							rei();
							break;
						}
						else connect(out);
						break;
					case '#':
						if (qqb(L"<#:")) { //ascii_calc
							if (qp.find('\\') != string::npos) qp = regex_replace(qp, wregex(L"\\\\g"), L">");
							int s{}; for (auto& x : qp) s += x;
							auto q = to_wstring(s);	cbSet(q);
							rei();
						}
						else connect(out);
						break;
					case '!':
						if (qqb(L"<!:")) { //set strand
							strand = qp;
							prints();
							return;
						}
						else if (qqb(L"<!!:") || qqb(L"<!!!:")) { //set repeat
							wstring v = qq.substr(qq.find(':') + 1);
							v = v.substr(0, v.find('>'));
							if (qq[qq.find(':') + 1] != '<')
								num_error(L"Not a link", v, L"VALUE:");
							else {
								if (qq[3] == '!') { multi_.store_ = out; multi_.qq_ = qq; } //!!!
								qq = v;
								v = connect(v, 1);
								if (!v[0]) {
									kb(VK_BACK);
									sleep(frequency / 2);
									num_error(L"No output", qq, L"VALUE:");
								}
								else {
									repeats = v;

									if (multi_.store_[0]) { //!!! run
										multi_.c_ = c;
										repeat();
										sleep(1);
										out = multi_.store_.substr(multi_.c_);
										c = 0;
									}

									qq = out;
									rei();
								}
							}
						}
						else connect(out);
						break;
					case '~':
						if (qqb(L"<~>")) {//manual set xy
							POINT pt; GetCursorPos(&pt); qxcc = pt.x; qycc = pt.y; rei();
						}
						else if (qqb(L"<~~>")) {//manual return xy
							SetCursorPos(qxcc, qycc); rei();
						}
						else connect(out);
						break;
					case'+': //calc
					case'-':
					case'*':
					case'/':
					case'%':
						if (qq[2] == '>' || qq[3] != '>') { //<+:>
							if (qq[3] == ' ') { //<+: #>
								wstring cb = cbGet();
								wstring e = cb;
								if (!e[0] || check_if_num(e, L"clipboard") == L"") { connect(out); continue; }
								multi_.icp_ = stod(cb);
							}

							bool b = 0;
							wstring e = qp;
							if (qq[2] == '>' && qq[1] == '+') b = 1; //<+>
							else if (check_if_num(qp, qq.substr(0, qq.find('>')) + L">") == L"") {
								connect(out);
								continue;
							}

							if (b) {}
							else {
								if (qq[2] != ':') { connect(out); continue; }
								switch (qq[1]) {
								case'+': multi_.icp_ += stod(qp); break; // <+:>
								case'-': multi_.icp_ -= stod(qp); break;
								case'*': multi_.icp_ *= stod(qp); break;
								case'/':
								case'%': if (stoi(qp) <= 0) { printq(); continue; }
									   int x = (int)multi_.icp_; if (qq[1] == '/')
										   multi_.icp_ /= stod(qp);
									   else multi_.icp_ = x % stoi(qp);
								}
							}

							static bool dp;
							if (qp.find('.') != string::npos || qq[3] == ' ' && cbGet().find('.') != string::npos) dp = 1; else { if (!b) dp = 0; }

							wstring x = to_wstring(multi_.icp_);
							if (!dp || qq[1] == '%') x = x.substr(0, x.find(L"."));

							if (qq[3] == ' ') cbSet(x);

							if (b) {
								out = x + qq.substr(qq.find('>') + 1);
								c = -1;
								if (out_speed > 0) out_sleep = 0;
								ic = multi_.icp_;
							}
							else rei();
						}
						else connect(out);
						break;
					case ',':
						if (qqb(L"<,")) { //<,#>
							unsigned long n = 1, ms;
							setQxQy(qp); //# #
							if (qy[0]) { //<,1000 4>
								if (check_if_num(qy, L"<,# #>") == L"") return;
								n = stoul(qy);
								if (check_if_num(qx, L"<,#>") == L"" || n == 0) return;
								ms = stoul(qx);
							}
							else { //<,1000>
								if (!qp[0]) ms = frequency; //default <,>
								else if (check_if_num(qp, L"<,#>") == L"") return;
								else ms = stoul(qp);
							}

							multi_sleep(multi_, ms, n);
							rei();
						}
						else connect(out);
						break;
					case'\'':
						if (qqb(L"<'")) { //<'comments>
							if (qq[2] == '\'') { c = out.length(); break; }//<''ignore>...
							else if (qq[2] != ' ' && show_strand) {
								showOutsMsg(L"", qp, L"", 1);
								cout << '\n';
							}
							rei();
							out_sleep = 0;
							break;
						}
						else connect(out);
						break;
					case'a':
					case 'A':
						switch (qq[2]) {
						case 'l':
							if (qqb(L"<alt>")) { if (out_speed > 0) out_sleep = 0; kb_hold(VK_LMENU); rei(); }
							else if (qqb(L"<alt->")) { if (out_speed > 0) out_sleep = 0; kb_release(VK_LMENU); rei(); }
							else if (qqb(L"<alt")) kb_press(L"<alt", VK_LMENU);
							else connect(out);
							break;
						case 'p':
							if (qqb(L"<app>")) {//app title to cb
								wstring a(getAppT());
								cbSet(a);
								rei();
							}
							else connect(out);
							break;
						case 'u':
							if (qqb(L"<Audio:") || qqb(L"<audio:")) {
								if (qq[1] == 'A') sndPlaySoundW((qp).c_str(), SND_FILENAME | SND_ASYNC); else mciSendStringW((qp).c_str(), 0, 0, 0); //<audio:play test.mp3>
								rei();
							}
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'b':
						if (qqb(L"<bs")) kb_press(L"<bs", VK_BACK);
						else connect(out);
						break;
					case'c':
						switch (qq[2]) {
						case 'l':
							if (qqb(L"<cl>")) { wstring l = cbGet(); l = to_wstring(l.length()); cbSet(l); rei(); }
							else connect(out);
							break;
						case 't':
							if (qqb(L"<ctrl>")) { if (out_speed > 0) out_sleep = 0; kb_hold(VK_CONTROL); rei(); }
							else if (qqb(L"<ctrl->")) { if (out_speed > 0) out_sleep = 0; kb_release(VK_CONTROL); rei(); }
							else if (qqb(L"<ctrl")) kb_press(L"<ctrl", VK_CONTROL);
							else connect(out);
							break;
						case 'b':
							if (qqb(L"<cb") || qqb(L"<cb:")) {
								if (qq[3] == '>') {
									kb_hold(VK_CONTROL); kb('v'); kb_release(VK_CONTROL);
								}
								else if (qq[3] == ':') {
									if (npos_find(qp, '\\', 1)) qp = regex_replace(qp, wregex(L"\\\\\\\\\\\\\\\\g"), L">"); // \\\\g
									cbSet(qp);
								}
								rei();
							}
							else connect(out);
							break;
						case 'a':
							if (qqb(L"<caps")) kb_press(L"<caps", VK_CAPITAL);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'd':
					case'D':
						switch (qq[2]) {
						case 'B':
						case 'b':
							if (qqb(L"<db:")) {//.h Database:
								qp = regex_replace(qp, wregex(L"/"), L"\\");
								wifstream f(qp); if (!f) { f.close(); showOutsMsg(L"", L"\\n\\4Database \\7\\0C\\" + qp + L"\\0C\\\\4 not found!\\7\\n", L"", 1); return; } f.close();
								rei();
								//append db
								wstring _ = database;
								database = qp;
								make_vdb_table();
								database = _;
								break;
							}
							else if (qqb(L"<db>") || qqb(L"<DB>")) {
								if (qq[1] == 'D') {
									vstrand.clear(); vstrand_out.clear(); make_vdb_table();
								}
								else {
									for (size_t i = 0; i < vstrand.size(); ++i) {
										wstring in_ = vstrand.at(i).in[0] && vstrand.at(i).in[vstrand.at(i).in.length() - 1] == '>' ? L"" : vstrand.at(i).g;
										wcout << i + 1 << L": " << vstrand.at(i).in << in_ << vstrand_out.at(i).out << L"\n";
									}
									show_fg();
								}
								rei();
							}
							else connect(out);
							break;
						case 'o':
							if (qqb(L"<down")) kb_press(L"<down", VK_DOWN);
							else connect(out);
							break;
						case 'n':
							if (qqb(L"<dna:")) {
								if (npos_find(qp, '\\', 1)) qp = regex_replace(qp, wregex(L"\\\\\\\\\\\\\\\\g"), L">"); // \\\\g
								HWND h = GetConsoleWindow(); SetConsoleTitleW(qp.c_str()); rei();
							}
							else connect(out);
							break;
						case 'e':
							if (qqb(L"<delete")) kb_press(L"<delete", VK_DELETE);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'e':
						switch (qq[3]) {
						case 't':
							if (qqb(L"<enter")) kb_press(L"<enter", VK_RETURN);
							else connect(out);
							break;
						case 'd':
							if (qqb(L"<end")) kb_press(L"<end", VK_END);
							else connect(out);
							break;
						case 'c':
							if (qqb(L"<esc")) kb_press(L"<esc", VK_ESCAPE);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'f':
						switch (qq[2]) {
						case '1':
							if (qqb(L"<f10")) kb_press(L"<f10", VK_F10);
							else if (qqb(L"<f11")) kb_press(L"<f11", VK_F11);
							else if (qqb(L"<f12")) kb_press(L"<f12", VK_F12);
							else if (qqb(L"<f1")) kb_press(L"<f1", VK_F1);
							else connect(out);
							break;
						case '2':
							if (qqb(L"<f2")) kb_press(L"<f2", VK_F2);
							else connect(out);
							break;
						case '3':
							if (qqb(L"<f3")) kb_press(L"<f3", VK_F3);
							else connect(out);
							break;
						case '4':
							if (qqb(L"<f4")) kb_press(L"<f4", VK_F4);
							else connect(out);
							break;
						case '5':
							if (qqb(L"<f5")) kb_press(L"<f5", VK_F5);
							else connect(out);
							break;
						case '6':
							if (qqb(L"<f6")) kb_press(L"<f6", VK_F6);
							else connect(out);
							break;
						case '7':
							if (qqb(L"<f7")) kb_press(L"<f7", VK_F7);
							else connect(out);
							break;
						case '8':
							if (qqb(L"<f8")) kb_press(L"<f8", VK_F8);
							else connect(out);
							break;
						case '9':
							if (qqb(L"<f9")) kb_press(L"<f9", VK_F9);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'h':
						if (qqb(L"<home")) kb_press(L"<home", VK_HOME);
						else connect(out);
						break;
					case'i':
						switch (qq[2]) {
						case 'f':
							{
							bool _{};
							{
								wstring cmd{ qq.substr(3, qq.find(':') - 2) };

								switch (qq[3]) {
								case 'a':
								case 'A':
									if (cmd == L"app~:" || cmd == L"app:" || cmd == L"App:") _ = 1;
									break;
								case 'r':
									if (cmd == L"rgb~:" || cmd == L"rgb:") _ = 1;
									break;
								case 'x': //qqb(L"<ifxy") || qqb(L"<ifcb")
								case 'c':
									if (qp[0] && chk == qq.substr(0, chk.length())) _ = 1;
									break;
								}
							}
							if (_) {
#pragma region ifinit
								if (!qp[0]) { connect(out); break; }

								wstring t{};
								wstring a{};
								wstring x{};
								wstring ms{};
								wstring tf{};
								wstring tf_T{};
								wstring tf_F{};
								wstring tf_feedback{};
								wstring R{}, G{}, B{}, X{}, Y{};

								unsigned short slash_pipes = 0;
								unsigned short slash_ands = 0;
								unsigned short slash_commas = 0;
								unsigned short ands = 0;
								unsigned short commas = 0;
								unsigned short pipes = 0;
								unsigned short spaces = 0;

								bool sleeper_tick{}; //last ' for final sleep. <ifapp~:...'>
								bool tf_T_link{}; //x:
								bool tf_F_link{};
								bool tf_T_link_plus_connect{}; //<x:
								bool tf_F_link_plus_connect{};
								bool tf_T_continue{}; //<
								bool tf_F_continue{};
								bool tf_F_retry{}; // ,
								bool tf_loop{}; // : -

								if (qp.substr(qp.length() - 1, 1) == L"'") {
									sleeper_tick = 1;
									qp.pop_back();
								}

								t = qp;

								for (size_t i = 0; i < qp.length(); ++i)
								{
									if (qp.length() == 1) break;
									if (qp[i] == ',') {
										if (qp[i - 1] == '\\') {
											++slash_commas;
											continue;
										}
										++commas;
										continue;
									}
									if (qp[i] == '|') {
										if (qp[i - 1] == '\\') {
											++slash_pipes;
											continue;
										}
										++pipes;
										continue;
									}
									if (qp[i] == '&') {
										if (qp[i - 1] == '\\') {
											++slash_ands;
											continue;
										}
										++ands;
										continue;
									}
								}

								for (size_t i = 0; i <= slash_commas; ++i, t = t.substr(t.find(',') + 1))
								{
									if (!commas && i == slash_commas) { t = qp; break; }
								}

								//		<app: db.txt, 1, 1000 4, t: f:>
								//set	<app: a,	  x, ms   n,  tf  >
								if (!a[0]) {
									a = qp.substr(0, qp.length() - t.length() - 1);
									//set default loop <app:a,>
									if (commas == 1) { tf_loop = 1; ms = to_wstring(frequency * 4); x = L"1"; }
									//set <app:'feedback'a,>
									if (a[0] == '\'') {
										tf_feedback = a.substr(1);
										if (npos_find(tf_feedback, '\'', 1)) {
											tf_feedback = tf_feedback.substr(0, tf_feedback.find('\''));
											a = a.substr(tf_feedback.length() + 2);
										}
										else {
											tf_feedback = L"'";
											a = a.substr(tf_feedback.length());
										}
									}
								}
								if (!x[0] && commas) { x = t.substr(0, t.find(',')); t = t.substr(t.find(',') + 1); if (x[0] == ' ') x = x.substr(1); }
								if (!ms[0] && commas > 1) { ms = t.substr(0, t.find(',')); t = t.substr(t.find(',') + 1); if (ms[0] == ' ') ms = ms.substr(1); }
								if (!tf[0] && commas > 2) {
									tf = t; if (tf[0] == ' ') tf = tf.substr(1); // set

									if (tf[0] && npos_find(tf, ' ', 1)) { //t: f: slot
										tf_T = tf.substr(0, tf.find(' '));
										tf_F = tf.substr(tf.find(' ') + 1);

										//lint x:
										if (tf_T.length() >= 1 && (npos_find(tf_T, '!', 1) || npos_find(tf_T, '^', 1) || npos_find(tf_T, ':', 1) || npos_find(tf_T, '-', 1))) {
											//link_plus_connect <x:
											if (tf_T[0] == '<')
												tf_T_link_plus_connect = 1;
											else
												tf_T_link = 1;
										}
										if (tf_F.length() >= 1 && (npos_find(tf_F, '!', 1) || npos_find(tf_F, '^', 1) || npos_find(tf_F, ':', 1) || npos_find(tf_F, '-', 1))) {
											if (tf_F[0] == '<')
												tf_F_link_plus_connect = 1;
											else
												tf_F_link = 1;
										}

										//continue <
										if (tf_T == L"<") tf_T_continue = 1;
										if (tf_F == L"<") tf_F_continue = 1;

										//retry ,
										if (tf_F == L",") tf_F_retry = 1;

									}
									else if (tf == L":" || tf == L"-" || !tf[0])
										tf_loop = 1;
									else if (tf == L"<")
										tf_F_continue = 1; //single tf_F continue
									else if (tf.length() >= 1 && (npos_find(tf, '!', 1) || npos_find(tf, '^', 1) || npos_find(tf, ':', 1) || npos_find(tf, '-', 1))) {
										if (tf[0] == '<') //single tf_F case
											tf_F_link_plus_connect = 1;
										else
											tf_F_link = 1;
									}

									//if (debug == 1) {
									//	wcout << tf << " tf\n";
									//	cout << tf_loop << " tf_loop\n";
									//	cout << tf_T_link << " tf_T_link\n";
									//	cout << tf_F_link << " tf_F_link\n";
									//	cout << tf_T_link_plus_connect << " tf_T_link_plus_connect\n";
									//	cout << tf_F_link_plus_connect << " tf_F_link_plus_connect\n";
									//	cout << tf_T_continue << " tf_T_continue\n";
									//	cout << tf_F_continue << " tf_F_continue\n";
									//	cout << tf_F_retry << " tf_F_retry\n";
									//}
								}

								if (a.find('\\') != string::npos) {
									a = regex_replace(a, wregex(L"\\\\,"), L","); // \,
									a = regex_replace(a, wregex(L"\\\\\\\\\\\\\\\\g"), L">"); // \\\\g
								}

								vector<wstring>p{};
								if (pipes) {
									t = a;
									t = regex_replace(t, wregex(L"[\\s][\\\\\\|][\\s]"), L"|");
									if (slash_pipes) t = regex_replace(t, wregex(L"\\\\\\|"), L"  ");

									for (unsigned short i = 0; i < pipes + 1; ++i)
									{
										wstring v = t.substr(0, t.find('|'));
										if (slash_pipes) v = regex_replace(v, wregex(L"  "), L"|");
										p.push_back(v);
										t = t.substr(t.find('|') + 1);
									}

								}
								else if (ands) {
									t = a;
									t = regex_replace(t, wregex(L"[\\s][&][\\s]"), L"&");
									if (slash_ands) t = regex_replace(t, wregex(L"[\\&]"), L"  ");

									for (unsigned short i = 0; i < ands + 1; ++i)
									{
										wstring v = t.substr(0, t.find('&'));
										if (slash_ands) v = regex_replace(v, wregex(L"  "), L"&");
										p.push_back(v);
										t = t.substr(t.find('&') + 1);
									}

								}
								else p.push_back(a);

								unsigned long x_times{};
								if (x[0]) {
									if (check_if_num(x, L"* slot") == L"")
										break;
									else x_times = stoul(x);
								}
								else x_times = 1;

								unsigned long ms_milliseconds{}, n = 1;
								if (ms[0]) {
									if (npos_find(ms, ' ', 1)) { //set ms_milliseconds
										t = ms.substr(0, ms.find(' ')); //1000 4
										if (check_if_num(t) == L"") { num_error(L"ms slot", t); break; }
										else ms_milliseconds = stoul(t);
										t = ms.substr(ms.find(' ') + 1);
										if (check_if_num(t) == L"") { num_error(L"ms n slot", t); break; }
										else n = stoul(t);
									}
									else
										if (check_if_num(ms, L"ms slot") == L"") break;
										else ms_milliseconds = stoul(ms);
								}
								else ms_milliseconds = 0;
#pragma endregion
								//<if inits
								if (qq[3] == 'r') {
									for (size_t i = 0; i < a.length(); ++i)
										if (a[i] == ' ') ++spaces;
								}

								unsigned short count = 0;

								for (size_t i = 0; i < x_times; ++i)
								{
									if_esc();
									if (pause) if_pause();
									if (stop) break;

									if (tf_loop || tf_F_retry) ++x_times;

									for (size_t j = 0; j < p.size(); ++j)
									{
										if (p[j] == L"") {
											wstring e = qq.substr(0, 6) + L"> \\4NO VALUE FOUND. \\7USE ONE "; e += pipes ? L"|\\n" : L"&\\n"; showOutsMsg(L"", e, L"", 1);
											stop = 1; break;
										}

										//if loops
										switch (qq[3]) {
											case 'a':
											case 'A': {
												HWND h{}, h1{}; DWORD pid{};

												if (qq[3] == 'A') { //ifApp
													h = GetForegroundWindow(); h1 = FindWindowW(0, p[j].c_str());
													if (h == h1) ++count;
												}
												else if (qq[3] == 'a') { //'ifapp
													h = FindWindowW(0, p[j].c_str()); GetWindowThreadProcessId(h, &pid);
													if (h) {
														if (IsIconic(h)) { ShowWindow(h, SW_RESTORE); ShowWindow(h, SWP_SHOWWINDOW); }
														if (qq[6] == '~') SetForegroundWindow(h); //ifapp~
														++count;
													}
												}
												break;
											}
											case 'r': {
												R = L"", G = L"", B = L"", X = L"", Y = L"";
												t = L" " + p[j];
												for (unsigned short i = 0; i < spaces + 1; ++i) {
													t = t.substr(t.find(' ') + 1);
													if (!R[0]) { R = t.substr(0, t.find(' ')); continue; }
													if (!G[0]) { G = t.substr(0, t.find(' ')); continue; }
													if (!B[0]) { B = t.substr(0, t.find(' ')); continue; }
													if (!X[0]) { X = t.substr(0, t.find(' ')); continue; }
													if (!Y[0]) { Y = t; break; }
												}
												//if (debug == 1) {
												//	t = R + G + B + X + Y;
												//	t = regex_replace(a, wregex(L"-"), L"");
												//	if (check_if_num(t, L"CHECK RGBXY slot") != L"") { stop = 1; break; }
												//}

												COLORREF color;
												HDC hDC;
												hDC = GetDC(NULL);

												if (X[0] && Y[0]) {
													if (X[0] == '.' || Y[0] == '.') {
														POINT pt; GetCursorPos(&pt);
														if (X[0] == '.') { X = to_wstring(pt.x); }
														if (Y[0] == '.') { Y = to_wstring(pt.y); }
													}
													color = GetPixel(hDC, int(stoi(X) * RgbScaleLayout), int(stoi(Y) * RgbScaleLayout));
												}
												else { POINT pt; GetCursorPos(&pt); color = GetPixel(hDC, int(pt.x * RgbScaleLayout), int(pt.y * RgbScaleLayout)); }
												ReleaseDC(NULL, hDC);
												if (color != CLR_INVALID
													&& GetRValue(color) == stoi(R)
													&& GetGValue(color) == stoi(G)
													&& GetBValue(color) == stoi(B))
													++count; //&
										
												break;
											}
											case 'x': {
												auto q = p[j].find(' ');
												auto x = p[j].substr(0, q), y = p[j].substr(q + 1);
												POINT pt; GetCursorPos(&pt);
												if (x == L".") x = to_wstring(pt.x);
												if (y == L".") y = to_wstring(pt.y);
												auto tx = stoi(x), ty = stoi(y);

												switch (qq[5]) {
													case ':': //== <ifxy:> <ifxy=:> <ifxye:>
													case '=':
													case 'e': {
														if (pt.x == tx && pt.y == ty) ++count;
														break;
													}
													case 'n': //!= <ifxyn:> <ifxy!:>
													case '!': {
														if (pt.x != tx && pt.y != ty) ++count;
														break;
													}
													case 'l'://<= <ifxyl:> <ifxyle:> <ifxy<:> <ifxy<=:>
													case 'L':
													case '<': {
														if (qq[6] == 'e' || qq[6] == '=') { if (pt.x <= tx && pt.y <= ty) { ++count; break; } } //ifxyle <=
														if (pt.x < tx && pt.y < ty) ++count;
														break;
													}
													case 'g': { //>= <ifxyg:> <ifxyge:> <ifxyg=:>
														if (qq[6] == 'e' || qq[6] == '=') { if (pt.x >= tx && pt.y >= ty) { ++count; break; } } //ifxyge >=/g=
														if (pt.x > tx && pt.y > ty) ++count;
														break;
													}
												}
											
												break;
											}
											case 'c': {
												HANDLE hcb;
												wchar_t* cb;
												wstring w;

												OpenClipboard(0);
												hcb = GetClipboardData(CF_UNICODETEXT);
												if (hcb != nullptr) {
													cb = static_cast<wchar_t*>(GlobalLock(hcb));
													if (cb != nullptr)
														w = cb;
												}
												CloseClipboard();

												switch (qq[5]) {
													case ':': //== <ifcb:> <ifcb=:> <ifcbe:>
													case '=':
													case 'e':
														if (w == p[j]) ++count;
														break;
													case 'A': //<if cb find y starting @ offset x: x y> | <ifcba:1 test>
													case 'a': { //<if cb substring from index x matches y: x y> | <ifcbA:0 test>
														auto x = p[j].substr(0, p[j].find(' ')), y = p[j].substr(p[j].find(' ') + 1);
														if (qq[5] == 'A') {
															auto s = stoi(x) - 1;
															if (w.find(y, s) != wstring::npos)
																++count;
														}
														else { //'a'
															if (w.substr(stoi(x), y.length()) == y)
																++count;
														}
														break;
													}
													case 'S': //if cb starts with | <ifcbS:test>
														if (w.starts_with(p[j]))
															++count;
														break;
													case 'E': //<ifcbE:>
														if (w.ends_with(p[j]))
															++count;
														break;
													case 'n': //!= <ifcbn:> <ifcb!:>
													case '!':
														if (w != p[j])
															++count;
														break;
													case 'f': //<ifcbf:>
														if (regex_search(w, wregex(p[j])))
															++count;
														break;
													case 'F': //<ifcbF:>
														if (w.find(p[j]) != string::npos)
															++count;
														break;
													case 'l'://<= <ifcbl:> <ifcble:> <ifcb<:> <ifcb<=:> || <ifcblen:>
													case 'L':
													case '<': {
														if (check_if_num(p[j], L"a slot") != L"" && check_if_num(w, L"clipboard") != L"") {
															if (qq.substr(5, 3) == L"len") { //length <ifcblen:> <ifcbleng:>
																unsigned short len = stoi(p[j]);
																if (qq[8] == '!' || qq[8] == 'n') { if (w.length() != len) { ++count; break; } }
																else if (qq.substr(8, 2) == L"ge" || qq.substr(8, 2) == L"g=") { if (w.length() >= len) { ++count; break; } }
																else if (qq.substr(8) == L"g") { if (w.length() > len) { ++count; break; } }
																else if (qq.substr(8, 2) == L"le" || qq.substr(8, 2) == L"<e" || qq.substr(8, 2) == L"<=") { if (w.length() <= len) { ++count; break; } }
																else if (qq[8] == 'l' || qq[8] == '<') { if (w.length() < len) { ++count; break; } }
																else if (qq[8] == ':' || qq[8] == 'e' || qq[8] == '=') { if (w.length() == len) ++count; break; }//==
																else { p[j].clear(); ++count; break; }
															}
															if (qq[6] == 'e' || qq[6] == '=') { if (a == L"0" && w == L"0" || stod(w) <= stod(a)) { ++count; break; } } //ifcble <=
															if (stod(w) < stod(a)) ++count;
														}
														else {
															stop = 1;
															c = out.length();
														}
														break;
													}
													case 'g': { //>= <ifcbg:> <ifcbge:> <ifcbg=:>
														if (check_if_num(p[j], L"a slot") != L"" && check_if_num(w, L"clipboard") != L"") {
															if (qq[6] == 'e' || qq[6] == '=') { if (p[j] == L"0" && w == L"0" || stod(w) >= stod(p[j])) { ++count; break; } } //ifcbge >=/g=
															if (stod(w) > stod(p[j])) ++count;
														}
														break;
													}
												}

												break;
											}
										}

										if (stop) break;

										if (ands ? count == p.size() : count) multi_.br_ = 1;
										if (multi_.br_) break;

									}

									if (stop) break;

									if (tf_feedback[0]) if (tf_feedback.length() > 1) showOutsMsg(L"", tf_feedback, L"", 1); else wcout << tf_feedback;

									if (multi_.br_) {
										if (sleeper_tick) multi_sleep(multi_, ms_milliseconds, n);
										break;
									}

									ms_milliseconds = multi_.br_ || !tf_loop && x_times == i + 1 && !multi_.br_ ? 0 : ms_milliseconds;
									multi_sleep(multi_, ms_milliseconds, n);

								}

								if (stop) { stop = 0; c = out.length(); break; }

								if (qq[3] == 'r' && qq[6] == '~' && multi_.br_ && !stop && X[0] && Y[0]) {
									POINT pt; GetCursorPos(&pt); qxcc = pt.x; qycc = pt.y;
									SetCursorPos(stoi(X), stoi(Y));
								}

								if (tf_T[0] || tf_F[0] || tf[0] && !tf_F[0]) {
									if (tf_T_continue && multi_.br_ || tf_F_continue && !multi_.br_ || tf_loop) { rei(); multi_.br_ = 0; break; }
									tf_T = multi_.br_ ? tf_T : tf_F;
									if (!tf_F[0]) tf_T = tf;//single tf !tf_F[0] case
									tf_T = tf_T + L">";
									if (tf_T_link && multi_.br_ || tf_F_link && !multi_.br_ || !tf_F[0] && tf_F_link) tf_T = L"<" + tf_T;
									wstring l = qq.substr(qq.find('>') + 1);
									qq = tf_T;
									connect(tf_T);
									out = tf_T_link_plus_connect && multi_.br_ || tf_F_link_plus_connect && !multi_.br_ || !tf_F[0] && tf_F_link_plus_connect ? tf_T + l : tf_T;
									
									multi_.br_ = 0;

									break;
								}

								if (!multi_.br_) { c = out.length(); break; }

								rei();

								multi_.br_ = 0;

							}
							//qqb(L"<if+")
							else if (qp[0] && chk == qq.substr(0, chk.length())) {//<if+:> | stop if <+>
								wstring x = qp.substr(0, qp.find(' '));
								if (check_if_num(x) == L"" || !qp[0]) { connect(out); break; }

								bool b = 0; int q = stoi(qp.substr(0, qp.find(' ')));
								wstring l = L""; if (qp.find(' ') != string::npos) l = qp.substr(qp.find(' ') + 1);//<if+:# true:>
								switch (qq[4]) {
								default:
								case ':': //==
								case 'e':
								case '=':
									if (multi_.icp_ == q) b = 1;
									break;
								case 'n': //!=
								case '!':
									if (multi_.icp_ != q) b = 1;
									break;
								case 'l': //<=
								case 'L':
								case '<':
									if (qq[5] == '=' || qq[5] == 'e') {
										if (qp <= to_wstring(multi_.icp_)) b = 1;
									} //if+le <=
									else {
										if (multi_.icp_ < q) b = 1;
									}
									break;
								case 'g': //g=
									if (qq[5] == '=' || qq[5] == 'e') {
										if (multi_.icp_ >= q) b = 1;
									} //if+ge >=/g=
									else {
										if (multi_.icp_ > q) b = 1;
									}
								}
								if (b) {
									if (l > L"") {
										if (l == L"<") { out = out.substr(out.find('>') + 1); }
										else
										out = l[0] == '<'
											? l + L">" + qq.substr(qq.find('>') + 1)
											: L"<" + l + L">";//<if+:# true->
										if (out_speed > 0) out_sleep = 0;
										c = -1; break;
									}
									c = out.length(); break;
								}
								else rei();
							}
							else connect(out);
							}
							break;
						case 'n':
							if (qqb(L"<ins")) kb_press(L"<ins", VK_INSERT);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'l':
						switch (qq[2]) {
						case 'o': //lowercase cb
							if (qqb(L"<lower>")) {
								wstring s = L"", b = L"";
								b = cbGet();
								for (size_t x = 0; x < b.length(); ++x)
									s += tolower(b[x]);
								cbSet(s);
								rei();
							}
							else connect(out);
							break;
						case 'c':
							if (qqb(L"<lc"))
								kb_press(L"<lc", VK_F7);//left click
							else
								connect(out);
							break;
						case 'h':
							if (qqb(L"<lh>")) { //left hold
								mouseEvent(MOUSEEVENTF_LEFTDOWN);
								rei();
							}
							else
								connect(out);
							break;
						case 'r':
							if (qqb(L"<lr>")) { //left release
								mouseEvent(MOUSEEVENTF_LEFTUP);
								rei();
							}
							else
								connect(out);
							break;
						case 'e':
							if (qqb(L"<left"))
								kb_press(L"<left", VK_LEFT);
							else
								connect(out);
							break;
						case 's':
							if (qqb(L"<ls"))
								kb_press(L"<ls", VK_F7); //hscroll+
							else
								connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'm':
						switch (qq[2]) {
						case 'l':
							if (qqb(L"<ml>")) {//print multiLineDelimiter
								wstring w = repeats;
								run(utf8_to_wstring(delimiter));
								repeats = w;
								rei();
								if (out_speed > 0) out_sleep = 0;
							}
							else connect(out);
							break;
						case 'c':
							if (qqb(L"<mc")) kb_press(L"<mc", VK_F7);//middle click
							else connect(out);
							break;
						case 'h':
							if (qqb(L"<mh>")) {//middle hold
								mouseEvent(MOUSEEVENTF_MIDDLEDOWN);
								rei();
							}
							else connect(out);
							break;
						case 'r':
							if (qqb(L"<mr>")) {//middle release
								mouseEvent(MOUSEEVENTF_MIDDLEUP);
								rei();
							}
							else connect(out);
							break;
						case 'e':
							if (qqb(L"<menu")) kb_press(L"<menu", VK_APPS);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'p':
						switch (qq[2]) {
						case 'a':
							if (qqb(L"<pause")) { kb_press(L"<pause", VK_PAUSE); GetAsyncKeyState(VK_PAUSE); }
							else connect(out);
							break;
						case 's':
							if (qqb(L"<ps")) kb_press(L"<ps", VK_SNAPSHOT);
							else connect(out);
							break;
						case 'u':
							if (qqb(L"<pu")) kb_press(L"<pu", VK_PRIOR);//pgup
							else connect(out);
							break;
						case 'd':
							if (qqb(L"<pd")) kb_press(L"<pd", VK_NEXT);//pgdn
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'R':
					case'r':
						switch (qq[2]) {
						case ':':
							if (qqb(L"<R:") || qqb(L"<r:")) {//.h ReplacerDb:
								if (qq[1] == 'R') showOutsMsg(L"", qp, L"\n", 0);
								qp = regex_replace(qp, wregex(L"/"), L"\\");
								replacerDb = qp;
								rei();
							}
							else connect(out);
							break;
						case 'c':
							if (qqb(L"<rc")) kb_press(L"<rc", VK_F7); else connect(out);
							break;
						case 'h':
							if (qqb(L"<rh>")) {//right hold
								mouseEvent(MOUSEEVENTF_RIGHTDOWN);
								rei();
							}
							else connect(out);
							break;
						case 'r':
							if (qqb(L"<rr>")) {//right release
								mouseEvent(MOUSEEVENTF_RIGHTUP);
								rei();
							}
							else connect(out);
							break;
						case 'i':
							if (qqb(L"<right")) kb_press(L"<right", VK_RIGHT); else connect(out);
							break;
						case 's':
							if (qqb(L"<rs")) { kb_press(L"<rs", VK_F7); }
							else connect(out);//hscroll-
							break;
						case 'G':
						case 'g':
							if (qqb(L"<rgb")) {//print r g b x y | <rgb> <rgb 5000>
								out = getRGB(qq[4] == '>' ? 1 : 2);
								if (out[0]) c = -1;
								if (out_speed > 0) out_sleep = 0;
							}
							else connect(out);
							break;
						case 'e':
							if (qqb(L"<replace:")) {
								if (cbGet() > L"") {
									setQxQy(qp);
									if (qp.find(L"\\,") != wstring::npos) {// \,
										wstring t = qp.substr(qp.find_last_of(L"\\") + 2);
										if (t.find(',') != string::npos) {
											qx = qp.substr(0, qp.find_last_of(L"\\") + t.find(',') + 2);
											qy = qp.substr(qx.length() + 1);
											qx = regex_replace(qx, wregex(L"\\\\,"), L",");// \,
										}
									}
									wstring d = utf8_to_wstring(delimiter);
									qx = regex_replace(qx, wregex(L"\\\\g"), L">"); qx = regex_replace(qx, wregex(L"\\\\m"), d);
									qy = regex_replace(qy, wregex(L"\\\\g"), L">"); qy = regex_replace(qy, wregex(L"\\\\m"), d);
									wstring b = regex_replace(cbGet(), wregex(qx), qy);
									cbSet(b);
								}
								rei();
							}
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case 's':
					case 'S':
						switch (qq[2]) {
						case 'E':
						case 'e':
							if (qqb(L"<SE:") || qqb(L"<se:")) {//.h Switch Settings: file
								qp = regex_replace(qp, wregex(L"/"), L"\\");
								wifstream f(qp); if (!f) { f.close(); showOutsMsg(L"", L"\\n\\4Settings \\7\\0C\\" + qp + L"\\0C\\\\4 not found!\\7\\n", L"", 1); return; } f.close();
								wstring t = settings, _ = database;
								settings = qp;
								if (qq[1] == 's') se = settings.substr(settings.find_last_of('\\') + 1) + L" - ";
								load_settings();
								if (qq[1] == 'S') settings = t;
								if (_ != database)
									mvdb = 1;
								rei();
								break;
							}
							else if (qqb(L"<se>") || qqb(L"<SE>")) { 
								if (debug != 1) load_settings();
								if (qq[1] == 's') {
									printSe();
									show_fg();
								}
								rei();
							}
							else connect(out);
							break;
						case 'h':
							if (qqb(L"<shift>")) { if (out_speed > 0) out_sleep = 0; kb_hold(VK_LSHIFT); rei(); }
							else if (qqb(L"<shift->")) { if (out_speed > 0) out_sleep = 0; kb_release(VK_LSHIFT); kb_release(VK_RSHIFT); rei(); }
							else if (qqb(L"<shift")) kb_press(L"<shift", VK_LSHIFT);
							else connect(out);
							break;
						case 'p':
							if (qqb(L"<speed:")) {
								if (check_if_num(qp, L"<speed: {slot}>") != L"") {
									out_speed = stoi(qp); rei(); out_sleep = 0;
								}
								else printq();
							}
							else if (qqb(L"<space")) kb_press(L"<space", VK_SPACE);
							else connect(out);
							break;
						case 'd':
							if (qqb(L"<sd")) { kb_press(L"<sd", VK_F7); }//scroll down
							else connect(out);
							break;
						case 'r':
							if (qqb(L"<sr")) { kb_press(L"<sr", VK_F7); }//scroll right
							else connect(out);
							break;
						case 'u':
							if (qqb(L"<su")) { kb_press(L"<su", VK_F7); }//scroll up
							else connect(out);
							break;
						case 'l':
							if (qqb(L"<sl")) { kb_press(L"<sl", VK_F7); }//scroll left
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case 't':
						if (qqb(L"<tab")) kb_press(L"<tab", VK_TAB);
						else if (qqb(L"<time>") || qqb(L"<time:")) {
							wstring w{}; getTime(w);
							if (qq[5] == '>') w = w.substr(w.rfind(L" ") - 8, 8);
							out = w + qq.substr(qq.find('>') + 1, qq.length());
							c = -1;
							if (out_speed > 0) out_sleep = 0;
						}
						else connect(out);
						break;
					case 'u':
						if (qqb(L"<upper>")) { wstring s = L"", c = L""; c = cbGet(); for (size_t x = 0; x < c.length(); ++x) { s += toupper(c[x]); } cbSet(s); rei(); }
						else if (qqb(L"<up")) kb_press(L"<up", VK_UP);
						else connect(out);
						break;
					case 'v':
						if (qqb(L"<v>")) { toggle_visibility(); rei(); }
						else connect(out);
						break;
					case 'w':
						if (qqb(L"<win>")) { if (out_speed > 0) out_sleep = 0; kb_hold(VK_LWIN); rei(); }
						else if (qqb(L"<win->")) { if (out_speed > 0) out_sleep = 0; kb_release(VK_LWIN); rei(); }
						else if (qqb(L"<win")) kb_press(L"<win", VK_LWIN);
						else connect(out);
						break;
					case 'x':
						switch (qq[2]) {
						case 'y':
							if (qqb(L"<xy:") || qqb(L"<xy~:")) {
								setQxQy(qp); //# #
								if (delimiter[0] != '\n' && qx[0] == '\n' || qx[0] == '\t' || qy[0] == '\n' || qy[0] == '\t') {
									qx = regex_replace(qx, wregex(L"\n"), L""); qx = regex_replace(qx, wregex(L"\t"), L"");
									qy = regex_replace(qy, wregex(L"\n"), L""); qy = regex_replace(qy, wregex(L"\t"), L"");
								}
								if (qx[0] == '.' || qy[0] == '.' || qq[3] == '~') {//Use . for current pt | <xy:. 0>  <t-<ifxy:0 . | . 0 | . 864 | 1638 .,1,1000,:>1
									POINT pt; GetCursorPos(&pt);
									if (qq[3] == '~') { //<~~>
										qxcc = pt.x;
										qycc = pt.y;
									}
									
									if (qx == L".")
										qx = to_wstring(pt.x);
									if (qy == L".")
										qy = to_wstring(pt.y);
									
								}
								SetCursorPos(stoi(qx), stoi(qy));
								rei();
							}
							else if (qqb(L"<xy>")) {//print pointer
								POINT pt; GetCursorPos(&pt);
								out = to_wstring(pt.x) + L" " + to_wstring(pt.y) + qq.substr(qq.find('>') + 1, qq.length());
								c = -1;
								if (out_speed > 0) out_sleep = 0;
							}
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case 'y':
						if (qqb(L"<yesno:")) {

							wstring me = qp;

							if (npos_find(qp, '\\', 1)) {
								me = regex_replace(me, wregex(L"[\\\\][\\s]"), L"::s::");
							}

							auto qu = me.substr(0, me.find(' '));
							me = me.substr(me.find(' ') + 1);

							if (npos_find(qp, '\\', 1)) {
								me = regex_replace(me, wregex(L"::s::"), L" ");
								me = regex_replace(me, wregex(L"\\\\g"), L">");
								me = regex_replace(me, wregex(L"\\\\n"), L"\n");
								qu = regex_replace(qu, wregex(L"::s::"), L" ");
								qu = regex_replace(qu, wregex(L"\\\\g"), L">");
								qu = regex_replace(qu, wregex(L"\\\\n"), L"\n");
							}

							multi_.out_ = out;
							multi_.qq_ = qq;
							multi_.qp_ = qp;
							multi_.c_ = c;

							int m = MessageBoxW(0, me.c_str()
								, qu.c_str()
								, MB_YESNO);
							if (m == IDYES) {
								out = multi_.out_;
								qq = multi_.qq_;
								qp = multi_.qp_;
								c = multi_.c_;
								rei();
								continue;
							}
							else {
								c = out.length();
								break;
							}
						}
						else connect(out);
						break;
					default:
						connect(out);
					} //<x>
					break;
				default:
				{
					//if !"#$%& ()*+ : > ?&AZ ^ _ {|}~
					if (out[c] == 58
						|| out[c] < 91 && out[c] > 61
						|| out[c] < 39 && out[c] > 32
						|| out[c] == 95
						|| out[c] < 44 && out[c] > 39
						|| out[c] > 122 && out[c] < 127
						|| out[c] == 94)
					{
						kb_hold(VK_LSHIFT);
						hold_shift = 1;
					}

					kb(out[c]);

					if (hold_shift)
						shift_release();

				}

				}

			}

			if (multi_.store_[0]) repeats = multi_.store_;

			break;
		}

	}

	out_speed = 0;
	if (RSHIFTLSHIFT_Only) rri = 0;
	if (found_io || strand[0] && strand[strand.length() - 1] == '>') {
		if (ccm) { close_ctrl_mode = !close_ctrl_mode; ccm = 0; }
		if (strand[0]) strand.clear();
		prints();
		stop = 0;
		found_io = 0;
	}
	
	if (mvdb) { //<se:>
		mvdb = 0;

		vstrand.clear();
		vstrand_out.clear();
		make_vdb_table();

		strand = L"<anu>";
		scan_db();
		repeats = repeats[0] ? repeats.substr(3) : L"";
		strand.clear();
	}
}

static void run(wstring ai) {
	repeats = L">" + ai;
	if (repeats != L">")
		scan_db();
}

static void repeat() {
	switch (repeat_switch) {
	case 0: {
		if (strand[0]) strand.clear();
		thread thread(run, *&repeats);
		thread.detach();
	}
		break;
	case 1: { //p + esc
		bool s = show_strand; show_strand = 0;

		printq();
		run(L"xy~:");
		run(getXY());

		show_strand = s;
		prints();
	}
		break;
	case 2: //r + esc
		printq();
		run(getRGB());
		break;
	case 3: //g + esc
		qq.clear();
		getRGB(1);
		if (strand[0]) strand.clear();
		prints();
		break;
	case 4: { //a + esc
		bool s = show_strand; show_strand = 0;

		sleep(frequency / 2);
		run(L"<alt><esc><alt->");
		wstring t = getAppT();
		run(L"<,><shift><alt><esc><alt-><shift->");
		printq();
		run(L"ifapp~:" + t + (Loop_Insert_Text > L"" ? Loop_Insert_Text : L">"));
		repeat_switch = 4;

		show_strand = s;
		prints();
	}
		break;
	}
}

static void scan() {
	scan_db();
}

static void key(wstring k) {
	if (k[0] == '>') { //Kb_Key_F2 = ">"
		if (!strand[0]) k[0] = '<';
		else if (strand[0] != '<' && strand.length() > 0 || strand.length() > 1)
			k = '>';
		else {
			strand.clear();
			prints();
			return;
		}
	}

	strand.append(k);

	if (k[0] == '>' || !close_ctrl_mode) {
		//scan_db()
		if (k[0] == '>') prints();
		thread thread(scan); thread.detach();
		if (close_ctrl_mode) return;
	}

	if (strand_length && strand[0] != '<' && k[0] != '>') {
		if (strand.length() > strand_length) {
			if (!utf_8)
				strand = strand.substr(1);
			else {
				if (k[0] > 32 && k[0] < 128 && strand[0] > 32 && strand[0] < 128)
					strand = strand.substr(1);
				else {
					unsigned short bits{}; bool b{};

					for (size_t i = 0; i < strand.length(); ++i) {
						if ((strand[i] & 0xc0) != 0x80)
							++bits;

						if (i == 1 && bits == 1)
							b = 1;
					}

					if (bits > strand_length)
						strand = b ? strand.substr(2) : strand.substr(1);
				}
			}
		}
	}

	if (k[0] != '>')
		prints();
}

#pragma endregion

#pragma comment(lib, "Winmm.lib")//<audio:>

static LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {

	if (nCode == HC_ACTION) {
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
		
		if (p->flags & LLKHF_INJECTED || p->flags & LLKHF_ALTDOWN)
			return 0;
		
		if (!multi_run && found_io)
			if (p->scanCode == 1) {
				stop = 1;
				return 0;
			}
			else if (p->scanCode != PauseKey)
				return 0;

		switch (wParam) {
			case WM_KEYDOWN:
			case WM_SYSKEYDOWN: {
				//PauseKey
				if (p->scanCode == PauseKey) {
					if (found_io) {
						pause = !pause;
						if (show_strand) cout << ' ' << (pause ? "PAUSE" : "!PAUSE") << ' ';
						return 0;
					}
				}

				if (pause || isWinKeyPressed || isCkey0Pressed) return 0; //cKey 0

				if (debug == 1) printf("Scan Code = %d\n", p->scanCode);

				switch (p->scanCode) {
				case 91:
				case 92:
					isWinKeyPressed = 1; return 0;
				case 42: //Shift
					isLshiftPressed = 1; return 0;
				case 54:
					isRshiftPressed = 1; return 0;
				case 14: { //Backspace
					if (!strand[0]) { if (rri) rri = 0; return 0; }

					if (!utf_8)
						strand.pop_back();
					else {
						if (strand.length() == 1 || strand[strand.length() - 1] > 32 && strand[strand.length() - 1] < 128 || (strand[strand.length() - 1] & 0xc0) != 0x80)
							strand.pop_back();
						else {
							unsigned short bits{};

							for (size_t i = 0; i < strand.length(); ++i)
								if ((strand[i] & 0xc0) != 0x80)
									++bits;

							if (bits == strand.length())
								strand.pop_back();
							else
								strand = strand.substr(0, strand.length() - 2);
						}
					}

					prints();
				}
					return 0;
				case 29: { //Ctrl
					if (cKey == 29) {
						bool extended = (p->flags & LLKHF_EXTENDED) != 0;
						if (!extended)
							isLctrlPressed = 1;
						else {
							isRctrlPressed = 1;
							clockr(c1);
						}
					}
					else
						isCkey0Pressed = 1;
				}
					return 0;
				}

				if (isLshiftPressed || isRshiftPressed
					|| isLctrlPressed || isRctrlPressed)
					break;

				if (p->scanCode == repeat_key) {
					bool extended = (p->flags & LLKHF_EXTENDED) != 0;
					if (!extended) {
						if (auto_bs_repeat_key)
							kb(VK_BACK);
						repeat();
					}
					return 0;
				}

				//VK_ESCAPE
				if (p->scanCode == 1) {
					GetAsyncKeyState('P'); if (GetAsyncKeyState('P')) { //p + esc: <xy:>
						kb_release(VK_ESCAPE); kb(VK_BACK);
						repeat_switch = 1;
						repeat();
						return 0;
					}
					GetAsyncKeyState('R'); if (GetAsyncKeyState('R')) { //r + esc: <rgb:>
						kb_release(VK_ESCAPE); kb(VK_BACK);
						repeat_switch = 2;
						repeat();
						return 0;
					}
					GetAsyncKeyState('G'); if (GetAsyncKeyState('G')) { //g + esc: <RGB~:> to cb
						kb_release(VK_ESCAPE); kb(VK_BACK);
						repeat_switch = 3;
						repeat();
						return 0;
					}
					GetAsyncKeyState('A'); if (GetAsyncKeyState('A')) { //a + esc: <app:>
						kb_release(VK_ESCAPE); kb(VK_BACK);
						repeat_switch = 4;
						repeat();
						return 0;
					}
					GetAsyncKeyState(VK_OEM_PLUS); if (GetAsyncKeyState(VK_OEM_PLUS)) { //= + esc: repeat
						kb_release(VK_ESCAPE); kb(VK_BACK);
						repeat(); return 0;
					}
					GetAsyncKeyState(VK_OEM_COMMA); if (GetAsyncKeyState(VK_OEM_COMMA)) { //, + esc
						rshift_lshift = 1;
						return 0;
					}
					GetAsyncKeyState('L'); if (GetAsyncKeyState('L')) { //L + esc
						kb(VK_BACK);
						static unsigned short escL = RSHIFTLSHIFT_Only;
						if (RSHIFTLSHIFT_Only) RSHIFTLSHIFT_Only = 0;
						else RSHIFTLSHIFT_Only = escL ? escL : 2;
						strand.clear(); prints();
						sleep(frequency);
						return 0;
					}
					GetAsyncKeyState('X'); if (GetAsyncKeyState('X')) { //x + esc
						kb(VK_BACK);
						PostQuitMessage(0);
						return 0;
					}
					GetAsyncKeyState('H'); if (GetAsyncKeyState('H')) { //h + esc
						kb_release(VK_ESCAPE); kb(VK_BACK);
						sleep(1);
						toggle_visibility();
						prints();
						return 0;
					}
					GetAsyncKeyState(VK_OEM_2); if (GetAsyncKeyState(VK_OEM_2)) { //? + esc
						kb_release(VK_ESCAPE); kb(VK_BACK);
						print_ctrls();
						show_fg();
						return 0;
					}
					if (found_io) { stop = 1; return 0; }
					if (Kb_Key_Esc[0]) { kb_release(VK_ESCAPE); key(Kb_Key_Esc); }
					return 0;
				}

				if (ctrl_scan_only_mode && strand[0] != '<') return 0;

				if (!rri && RSHIFTLSHIFT_Only && !strand[0]) return 0;

				switch (p->scanCode) {
				case 30: if (Kb_Key_A[0]) key(Kb_Key_A); return 0;
				case 48: if (Kb_Key_B[0]) key(Kb_Key_B); return 0;
				case 46: if (Kb_Key_C[0]) key(Kb_Key_C); return 0;
				case 32: if (Kb_Key_D[0]) key(Kb_Key_D); return 0;
				case 18: if (Kb_Key_E[0]) key(Kb_Key_E); return 0;
				case 33: if (Kb_Key_F[0]) key(Kb_Key_F); return 0;
				case 34: if (Kb_Key_G[0]) key(Kb_Key_G); return 0;
				case 35: if (Kb_Key_H[0]) key(Kb_Key_H); return 0;
				case 23: if (Kb_Key_I[0]) key(Kb_Key_I); return 0;
				case 36: if (Kb_Key_J[0]) key(Kb_Key_J); return 0;
				case 37: if (Kb_Key_K[0]) key(Kb_Key_K); return 0;
				case 38: if (Kb_Key_L[0]) key(Kb_Key_L); return 0;
				case 50: if (Kb_Key_M[0]) key(Kb_Key_M); return 0;
				case 49: if (Kb_Key_N[0]) key(Kb_Key_N); return 0;
				case 24: if (Kb_Key_O[0]) key(Kb_Key_O); return 0;
				case 25: if (Kb_Key_P[0]) key(Kb_Key_P); return 0;
				case 16: if (Kb_Key_Q[0]) key(Kb_Key_Q); return 0;
				case 19: if (Kb_Key_R[0]) key(Kb_Key_R); return 0;
				case 31: if (Kb_Key_S[0]) key(Kb_Key_S); return 0;
				case 20: if (Kb_Key_T[0]) key(Kb_Key_T); return 0;
				case 22: if (Kb_Key_U[0]) key(Kb_Key_U); return 0;
				case 47: if (Kb_Key_V[0]) key(Kb_Key_V); return 0;
				case 17: if (Kb_Key_W[0]) key(Kb_Key_W); return 0;
				case 45: if (Kb_Key_X[0]) key(Kb_Key_X); return 0;
				case 21: if (Kb_Key_Y[0]) key(Kb_Key_Y); return 0;
				case 44: if (Kb_Key_Z[0]) key(Kb_Key_Z); return 0;

				case 2: if (Kb_Key_1[0]) key(Kb_Key_1); return 0;
				case 3: if (Kb_Key_2[0]) key(Kb_Key_2); return 0;
				case 4: if (Kb_Key_3[0]) key(Kb_Key_3); return 0;
				case 5: if (Kb_Key_4[0]) key(Kb_Key_4); return 0;
				case 6: if (Kb_Key_5[0]) key(Kb_Key_5); return 0;
				case 7: if (Kb_Key_6[0]) key(Kb_Key_6); return 0;
				case 8: if (Kb_Key_7[0]) key(Kb_Key_7); return 0;
				case 9: if (Kb_Key_8[0]) key(Kb_Key_8); return 0;
				case 10: if (Kb_Key_9[0]) key(Kb_Key_9); return 0;
				case 11: if (Kb_Key_0[0]) key(Kb_Key_0); return 0;

				case 59: if (Kb_Key_F1[0]) key(Kb_Key_F1); return 0;
				case 60: if (Kb_Key_F2[0]) key(Kb_Key_F2); return 0;
				case 61: if (Kb_Key_F3[0]) key(Kb_Key_F3); return 0;
				case 62: if (Kb_Key_F4[0]) key(Kb_Key_F4); return 0;
				case 63: if (Kb_Key_F5[0]) key(Kb_Key_F5); return 0;
				case 64: if (Kb_Key_F6[0]) key(Kb_Key_F6); return 0;
				case 65: if (Kb_Key_F7[0]) key(Kb_Key_F7); return 0;
				case 66: if (Kb_Key_F8[0]) key(Kb_Key_F8); return 0;
				case 67: if (Kb_Key_F9[0]) key(Kb_Key_F9); return 0;
				case 68: if (Kb_Key_F10[0]) key(Kb_Key_F10); return 0;
				case 87: if (Kb_Key_F11[0]) key(Kb_Key_F11); return 0;
				case 88: if (Kb_Key_F12[0]) key(Kb_Key_F12); return 0;


				case 70: if (Kb_Key_ScLk[0]) key(Kb_Key_ScLk); return 0;
				case 57: if (Kb_Key_Space[0]) key(Kb_Key_Space); return 0;
				case 15: if (Kb_Key_Tab[0]) key(Kb_Key_Tab); return 0;
				case 58: if (Kb_Key_Caps[0]) key(Kb_Key_Caps); return 0;
				case 41: if (Kb_Key_Grave_Accent[0]) key(Kb_Key_Grave_Accent); return 0;
				case 12: if (Kb_Key_Minus[0]) key(Kb_Key_Minus); return 0;
				case 13: if (Kb_Key_Equal[0]) key(Kb_Key_Equal); return 0;
				case 26: if (Kb_Key_Left_Bracket[0]) key(Kb_Key_Left_Bracket); return 0;
				case 27: if (Kb_Key_Right_Bracket[0]) key(Kb_Key_Right_Bracket); return 0;
				case 43: if (Kb_Key_Backslash[0]) key(Kb_Key_Backslash); return 0;
				case 39: if (Kb_Key_Semicolon[0]) key(Kb_Key_Semicolon); return 0;
				case 40: if (Kb_Key_Quote[0]) key(Kb_Key_Quote); return 0;
				case 51: if (Kb_Key_Comma[0]) key(Kb_Key_Comma); return 0;
				case 52: if (Kb_Key_Period[0]) key(Kb_Key_Period); return 0;
				case 93: if (Kb_Key_Menu[0]) key(Kb_Key_Menu); return 0;

				case 69:
				case 72:
				case 75:
				case 77:
				case 80:
				case 28:
				case 83:
				case 55:
				case 53:
				case 73:
				case 71:
				case 81:
				case 79:
				case 82: {
					bool extended = (p->flags & LLKHF_EXTENDED) != 0;
					switch (p->scanCode) {
					case 72:
						if (!extended) { if (Kb_Key_Numpad_8[0]) key(Kb_Key_Numpad_8); return 0; }
						if (Kb_Key_Up[0]) key(Kb_Key_Up); return 0;
					case 75:
						if (!extended) { if (Kb_Key_Numpad_4[0]) key(Kb_Key_Numpad_4); return 0; }
						if (Kb_Key_Left[0]) key(Kb_Key_Left); return 0;
					case 77:
						if (!extended) { if (Kb_Key_Numpad_6[0]) key(Kb_Key_Numpad_6); return 0; }
						if (Kb_Key_Right[0]) key(Kb_Key_Right); return 0;
					case 80:
						if (!extended) { if (Kb_Key_Numpad_2[0]) key(Kb_Key_Numpad_2); return 0; }
						if (Kb_Key_Down[0]) key(Kb_Key_Down); return 0;
					case 82:
						if (!extended) { if (Kb_Key_Numpad_0[0]) key(Kb_Key_Numpad_0); return 0; }
						if (Kb_Key_Insert[0]) key(Kb_Key_Insert); return 0;
					case 79:
						if (!extended) { if (Kb_Key_Numpad_1[0]) key(Kb_Key_Numpad_1); return 0; }
						if (Kb_Key_End[0]) key(Kb_Key_End); return 0;
					case 81:
						if (!extended) { if (Kb_Key_Numpad_3[0]) key(Kb_Key_Numpad_3); return 0; }
						if (Kb_Key_PgDn[0]) key(Kb_Key_PgDn); return 0;
					case 71:
						if (!extended) { if (Kb_Key_Numpad_7[0]) key(Kb_Key_Numpad_7); return 0; }
						if (Kb_Key_Home[0]) key(Kb_Key_Home); return 0;
					case 73:
						if (!extended) { if (Kb_Key_Numpad_9[0]) key(Kb_Key_Numpad_9); return 0; }
						if (Kb_Key_PgUp[0]) key(Kb_Key_PgUp); return 0;
					case 53:
						if (!extended) { if (Kb_Key_Numpad_Divide[0]) key(Kb_Key_Numpad_Divide); return 0; }
						if (Kb_Key_Forwardslash[0]) key(Kb_Key_Forwardslash); return 0;
					case 55:
						if (!extended) { if (Kb_Key_Numpad_Multiply[0]) key(Kb_Key_Numpad_Multiply); return 0; }
						if (Kb_Key_Print_Screen[0]) key(Kb_Key_Print_Screen); return 0;
					case 83:
						if (!extended) { if (Kb_Key_Numpad_Period[0]) key(Kb_Key_Numpad_Period); return 0; }
						if (Kb_Key_Delete[0]) key(Kb_Key_Delete); return 0;
					case 28:
						if (!extended) { if (Kb_Key_Numpad_Enter[0]) key(Kb_Key_Numpad_Enter); return 0; }
						if (Kb_Key_Enter[0]) key(Kb_Key_Enter); return 0;
					case 69:
						if (extended) { if (Kb_Key_Numlock[0]) key(Kb_Key_Numlock); return 0; }
						if (Kb_Key_Pause[0]) key(Kb_Key_Pause);
						return 1;
					}
				}
					   break;
				case 76: if (Kb_Key_Numpad_5[0]) key(Kb_Key_Numpad_5); return 0;
				case 74: if (Kb_Key_Numpad_Minus[0]) key(Kb_Key_Numpad_Minus); return 0;
				case 78: if (Kb_Key_Numpad_Add[0]) key(Kb_Key_Numpad_Add); return 0;

				}
			}
				break;
			case WM_KEYUP:
			case WM_SYSKEYUP: {
				if (p->scanCode == 91 || p->scanCode == 92) { isWinKeyPressed = 0; return 0; }
				if (pause || isWinKeyPressed) return 0;

				++breaker;
				
				switch (p->scanCode) {
				case 31: //S
					if (isLctrlPressed || isRctrlPressed || isCkey0Pressed) ctrl_s = 1;
					break;
				case 42: //Lshift
					isLshiftPressed = 0;
					GetAsyncKeyState(VK_RSHIFT); if (GetAsyncKeyState(VK_RSHIFT) && !isRctrlPressed) {
						++clear;
						rshift_lshift = 1;
					}
					break;
				case 54: //Rshift
					isRshiftPressed = 0;
					break;
				case 29: //Ctrl
					if (cKey == 29) {
						bool extended = (p->flags & LLKHF_EXTENDED) != 0;
						if (!extended) {
							isLctrlPressed = 0;
							GetAsyncKeyState(VK_RCONTROL); if (GetAsyncKeyState(VK_RCONTROL))
								repeated = 1;
							if (breaker > 1) repeated = 0;
						}
						else {
							isRctrlPressed = 0;
							if (repeated) break;
							
							if (isRshiftPressed) { if (RSHIFTCtrlKeyToggle && breaker == 1) rshift_rctrl = 1; break; }
							
							clockr(c2);
							chrono::duration<double, milli> ts = c1 - c2;
							if (breaker == 1) { breaker_c = abs(static_cast<short>(ts.count())); } else ++breaker;

							//cout << "breaker: " << breaker << "\n";
							if (breaker == 1 && breaker_c <= cKeyMax && !isLctrlPressed && !isLshiftPressed) {
								breaker = 0;
								if (RSHIFTLSHIFT_Only && !strand[0] && !rri) return 0;
								if (!strand[0]) strand = L"<";
								else {
									if (strand[0] && strand != L"<") { key(L">"); return 0; }
									if (RSHIFTLSHIFT_Only > 1) strand = L"";
									else strand = strand[0] == '<' ? L"" : L"<";
								}
								prints();
								return 0;
							}
							isLshiftPressed = 0;
							isRshiftPressed = 0;
							isLctrlPressed = 0;
							isRctrlPressed = 0;
							breaker = 0;
							return 0;
						}
					}
					else { isCkey0Pressed = 0; return 0; }
				}

			}
				break;
		}

		if (!isRctrlPressed) breaker = 0;
		
		if (isLshiftPressed || isRshiftPressed)
			return 0;
		
		//ctrl+s
		if (ctrl_s) {
			ctrl_s = 0;
			isLctrlPressed = 0;
			isRctrlPressed = 0;
			isCkey0Pressed = 0;
			HWND h = GetForegroundWindow();
			bool cs{};

			if (FindWindowW(0, (editorDb).c_str()) == h || FindWindowW(0, (db + editor).c_str()) == h) {
				//cout << "db Saved\n";
				vstrand.clear(); vstrand_out.clear(); make_vdb_table(); cs = 1;
			}
			else if (FindWindowW(0, (editorSe).c_str()) == h || FindWindowW(0, (se + editor).c_str()) == h) {
				//cout << "se Saved\n";
				load_settings(); cs = 1;
			}
			if (cs) {
				strand.clear(); prints();
			}
			return 0;
		}
		
		if (isLctrlPressed || isRctrlPressed)
			return 0;

		if (rshift_rctrl) {
			//cout << "rshift_rctrl\n";
			rshift_rctrl = 0;
			isRshiftPressed = 0;
			close_ctrl_mode = !close_ctrl_mode;
			ccm = !ccm;
			return 0;
		}

		if (rshift_lshift) {
			//cout << "rshift_lshift\n";
			rshift_lshift = 0;
			if (RSHIFTLSHIFT_Only) ++rri;
			if (clear > 1) strand = clear == 2 ? L"<" : L"";
			else if (strand[0] && strand != L"<") { key(L">"); clear = 0; return 0; }
			else if (!strand[0]) { strand = RSHIFTLSHIFT_Only > 1 && rri == 1 ? L"" : L"<"; }
			else if (RSHIFTLSHIFT_Only > 1) strand = L"";
			else strand = strand[0] == '<' ? L"" : L"<";
			prints();
			clear = 0;
			return 0;
		}

		if (repeated) {
			//cout << "repeated\n";
			repeated = 0;
			repeat();
			return 0;
		}
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
	{
		GetAsyncKeyState(VK_ESCAPE);
		for (size_t i = 0; i <= 1; ++i) {
			if (GetAsyncKeyState(VK_ESCAPE)) break;
			WCHAR t[MAX_PATH];
			GetSystemDirectoryW(t, MAX_PATH);
			wstring c = L"";
			for (i = 0; ; ++i) {
				if (t[i] == ':') {
					c += L":\\anu";
					break;
				}
				c += t[i];
			} //root dir
			database = c + L"\\db.txt";
			settings = c + L"\\se.txt";
			if (CreateDirectoryW(c.c_str(), NULL)) { //L"c:\anu"
				wstring db_ = L"";
				wstring se_ = L"";
				wcout << database << " not found.\n[1] auto create \n(delete c:\\anu to reset)\n\n";
				bool num = 0;
				for (;; sleep(frequency)) {
					GetAsyncKeyState(VK_ESCAPE); if (GetAsyncKeyState(VK_ESCAPE)) { RemoveDirectoryW(c.c_str()); break; }
					if (GetAsyncKeyState('1') || GetAsyncKeyState(VK_NUMPAD1)) { num = 1; break; }
				}
				if (num) {
					db_ = LR"(<anu\:><:\R\n
         /    \ \n
    __ // \  / \\\ __\n
   / / \\\  \/  // \ \ \n
  / /   \7ANUNNAKi\R   \ \ \n
  \ \\   //\7.13\R \\\   / /\n
   \_\ //  /\  \\\ /_/\n
       \\\\ /  \ //\n
         \    /\n\n
\7WELCOME! [\T] [\012\?+ESC\7]\n\n><db->
\

db
<db-><wr:>c:\anu\db.txt<enter>

<wr:><win>r<win-><ifapp~:run,6,9>

se
<se ><se>)";
					se_ = LR"(StartHidden				0
ShowInput				1
InputLength				2
Kb_Key_F2				>
RgbScaleLayout			1.00
)";

					wofstream fd(database); fd << db_; fd.close();
					wofstream fs(settings); fs << se_; fs.close();
				}
			}
		}
	}

	load_settings();

	if (start_hidden) ShowWindow(GetConsoleWindow(), SW_HIDE);

	SetConsoleOutputCP(CP_UTF8);

	if (utf_8)
		call_utf8();

	make_vdb_table();
	
	strand = L"<anu>";

	scan_db();
	
	repeats = repeats[0] ? repeats.substr(3) : L"";

	HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
	//if (!hook) { cout << "Load hook failed. Try v1.0.0.1"; return 1; }

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	UnhookWindowsHookEx(hook);

	return 0;

}