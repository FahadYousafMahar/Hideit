#include<iostream>
#include<conio.h>
#include<random>
#include<fstream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include <tchar.h>
using namespace std;
char c, opt;
string const KEY = " YOUR-PASSWORD-HERE"; // Change Password
string pass,winDir, name[20], path[20], state[20];
ifstream fin;
ofstream fout;
string const DISKFILE = "disks.txt";
int size;
void createFile();
void getWinDir(string& name);
void DisplayVolumePaths(__in PWCHAR VolumeName);
void addremDrive(int argc, TCHAR *argv[]);
void main(){
	system(("attrib -h -s " + DISKFILE).c_str());
	system("cls");
	system("color 0a");cout<<
	"====================================================================================================================\n"
		"\t\n"
		"\tHHHHHHHHH     HHHHHHHHH  iiii              d::::::d                  IIIIIIIIII       tttt          \n"
		"\tH:::::::H     H:::::::H i::::i             d::::::d                  I::::::::I    ttt:::t          \n"
		"\tH:::::::H     H:::::::H  iiii              d::::::d                  I::::::::I    t:::::t          \n"
		"\tHH::::::H     H::::::HH                    d:::::d                   II::::::II    t:::::t          \n"
		"\t  H:::::H     H:::::H  iiiiiii     ddddddddd:::::d     eeeeeeeeeeee    I::::Ittttttt:::::ttttttt    \n"
		"\t  H:::::H     H:::::H  i:::::i   dd::::::::::::::d   ee::::::::::::ee  I::::It:::::::::::::::::t    \n"
		"\t  H::::::HHHHH::::::H   i::::i  d::::::::::::::::d  e::::::eeeee:::::eeI::::It:::::::::::::::::t    \n"
		"\t  H:::::::::::::::::H   i::::i d:::::::ddddd:::::d e::::::e     e:::::eI::::Itttttt:::::::tttttt    \n"
		"\t  H:::::::::::::::::H   i::::i d::::::d    d:::::d e:::::::eeeee::::::eI::::I      t:::::t          \n"
		"\t  H::::::HHHHH::::::H   i::::i d:::::d     d:::::d e:::::::::::::::::e I::::I      t:::::t          \n"
		"\t  H:::::H     H:::::H   i::::i d:::::d     d:::::d e::::::eeeeeeeeeee  I::::I      t:::::t          \n"
		"\t  H:::::H     H:::::H   i::::i d:::::d     d:::::d e:::::::e           I::::I      t:::::t    tttttt\n"
		"\tHH::::::H     H::::::HHi::::::id::::::ddddd::::::dde::::::::e        II::::::II    t::::::tttt:::::t\n"
		"\tH:::::::H     H:::::::Hi::::::i d:::::::::::::::::d e::::::::eeeeeeeeI::::::::I    tt::::::::::::::t\n"
		"\tH:::::::H     H:::::::Hi::::::i  d:::::::::ddd::::d  ee:::::::::::::eI::::::::I      tt:::::::::::tt\n"
		"\tHHHHHHHHH     HHHHHHHHHiiiiiiii   ddddddddd   ddddd    eeeeeeeeeeeeeeIIIIIIIIII        ttttttttttt  \n"
		"\t                                                                                                    \n"
		"\t\t\t _            __          __  _    _____ _______      _    \n"
		"\t \t\t| |           \\ \\        / / | |  |_   _|__   __|    | |   \n"
		"\t \t\t| |__  _   _   \\ \\  /\\  / /__| |__  | |    | |  _ __ | | __\n"
		"\t \t\t| '_ \\| | | |   \\ \\/  \\/ / _ \\ '_ \\ | |    | | | '_ \\| |/ /\n"
		"\t \t\t| |_) | |_| |    \\  /\\  /  __/ |_) || |_   | |_| |_) |   < \n"
		"\t \t\t|_.__/ \\__, |     \\/  \\/ \\___|_.__/_____|  |_(_) .__/|_|\\_\\\n"
		"\t \t\t        __/ |                                  | |         \n"
		"\t \t\t       |___/                                   |_|         \n"
		"====================================================================================================================\n"
		"\t           ENTER PASSWORD : \t";
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> randrang(97, 122); // define the range
	while ((c = _getch())!= 13){
		if (c == '\b'){
			pass.pop_back();
			printf("\b \b");
			}
		else{
			pass.push_back(c);
			putchar(randrang(eng));
			}
		
	}
	if (pass == KEY){
		getWinDir(winDir); // Getting Windows Directory
		cout << "\t ACCESS GRANTED.\n\n\n\t\t\t\t ";
		Beep(7500, 500);
		fin.open(DISKFILE);
		if (!fin.is_open()){
			createFile();
			//system("makedisks.exe");
			fin.open(DISKFILE);
		}
		cout << right << setw(4) << "  DRIVE LETTER " << "||" << left << " DRIVE STATUS  " << "\n\t\t\t\t ";
		cout << right << setw(4) << "  -------------" << "||" << left << "-------------   " << "\n\t\t\t\t ";

		for (int i = 0; !fin.eof(); i++, size=i){
			getline(fin, name[i]);
			getline(fin, path[i]);
			getline(fin, state[i]);
			if (name[i]!="")
				cout << right << setw(12) << name[i] << "   ||   " << left << state[i] << "\n\t\t\t\t ";
		}
		fin.close();
		cout << "Enter Drive Letter : ";
		cin >> c;
		c = toupper(c);
		for (int i = 0; i<size ; i++){
			if (name[i][0] == c){
				if (state[i] == "SHOWN"){
					cout << "\t\t\t\t Do You Want To HIDE (y/n) : ";
					cin >> opt;
					opt	= tolower(opt);
					if (opt == 'y'){
						system(("dledit.exe -r " + name[i]).c_str());
						state[i] = "HIDDEN";
					}
				}
				else if(state[i]=="HIDDEN"){
				
						cout << "\t\t\t\t Do You Want To SHOW (y/n) : ";
						cin >> opt;
						opt = tolower(opt);
						if (opt == 'y'){
							system(("dledit.exe " + name[i] + " " + path[i]).c_str());
							state[i] = "SHOWN";
						}
				}
				fout.open(DISKFILE);
				for (int i = 0; i<size ; i++){
					if (name[i] != ""){
						fout << name[i] << '\n';
					fout << path[i] << '\n';
					fout << state[i] << '\n';
					}
				}
				fout.close();
		break;
			}
		}
	}
	else{ 
		cout << "\n\t\t\t ACCESS DENIED !\n\t\t\t"; 
		Beep(1000, 700);
	}
	system(("attrib +h +s " + DISKFILE).c_str());
}

std::wofstream wfout;
std::wofstream wfout1;

void DisplayVolumePaths(
	__in PWCHAR VolumeName
	)
{
	wfout1.open(DISKFILE, std::ios::app);
	DWORD  CharCount = MAX_PATH + 1;
	PWCHAR Names = NULL;
	PWCHAR NameIdx = NULL;
	BOOL   Success = FALSE;

	for (;;)
	{
		//
		//  Allocate a buffer to hold the paths.
		Names = (PWCHAR) new BYTE[CharCount * sizeof(WCHAR)];

		if (!Names)
		{
			//
			//  If memory can't be allocated, return.
			return;
		}

		//
		//  Obtain all of the paths
		//  for this volume.
		Success = GetVolumePathNamesForVolumeNameW(
			VolumeName, Names, CharCount, &CharCount
			);

		if (Success)
		{
			break;
		}

		if (GetLastError() != ERROR_MORE_DATA)
		{
			break;
		}

		//
		//  Try again with the
		//  new suggested size.
		delete[] Names;
		Names = NULL;
	}

	if (Success)
	{
		//
		//  Display the various paths.
		for (NameIdx = Names;
			NameIdx[0] != L'\0';
			NameIdx += wcslen(NameIdx) + 1)
		{
			wfout1 << NameIdx;
		}
		wfout1 << "\n";
	}
	wfout1.close();
	if (Names != NULL)
	{
		delete[] Names;
		Names = NULL;
	}
	return;
}

void __cdecl createFile(void)
{
	DWORD  CharCount = 0;
	WCHAR  DeviceName[MAX_PATH] = L"";
	DWORD  Error = ERROR_SUCCESS;
	HANDLE FindHandle = INVALID_HANDLE_VALUE;
	BOOL   Found = FALSE;
	size_t Index = 0;
	BOOL   Success = FALSE;
	WCHAR  VolumeName[MAX_PATH] = L"";

	//
	//  Enumerate all volumes in the system.
	FindHandle = FindFirstVolumeW(VolumeName, ARRAYSIZE(VolumeName));

	if (FindHandle == INVALID_HANDLE_VALUE)
	{
		Error = GetLastError();
		wprintf(L"FindFirstVolumeW failed with error code %d\n", Error);
		return;
	}

	for (;;)
	{
		//
		//  Skip the \\?\ prefix and remove the trailing backslash.
		Index = wcslen(VolumeName) - 1;

		if (VolumeName[0] != L'\\' ||
			VolumeName[1] != L'\\' ||
			VolumeName[2] != L'?' ||
			VolumeName[3] != L'\\' ||
			VolumeName[Index] != L'\\')
		{
			Error = ERROR_BAD_PATHNAME;
			wprintf(L"FindFirstVolumeW/FindNextVolumeW returned a bad path: %s\n", VolumeName);
			break;
		}

		//
		//  QueryDosDeviceW does not allow a trailing backslash,
		//  so temporarily remove it.
		VolumeName[Index] = L'\0';

		CharCount = QueryDosDeviceW(&VolumeName[4], DeviceName, ARRAYSIZE(DeviceName));

		VolumeName[Index] = L'\\';

		if (CharCount == 0)
		{
			Error = GetLastError();
			wprintf(L"QueryDosDeviceW failed with error code %d\n", Error);
			break;
		}
		wfout.open(DISKFILE, std::ios::app);
		wfout << DeviceName << "\n";
		DisplayVolumePaths(VolumeName);
		wfout << "SHOWN\n";
		wfout.close();

		//
		//  Move on to the next volume.
		Success = FindNextVolumeW(FindHandle, VolumeName, ARRAYSIZE(VolumeName));

		if (!Success)
		{
			Error = GetLastError();

			if (Error != ERROR_NO_MORE_FILES)
			{
				wprintf(L"FindNextVolumeW failed with error code %d\n", Error);
				break;
			}

			//
			//  Finished iterating
			//  through all the volumes.
			Error = ERROR_SUCCESS;
			break;
		}
	}

	FindVolumeClose(FindHandle);
	FindHandle = INVALID_HANDLE_VALUE;
	return;
}
TCHAR* envVarStrings[] =
{
	TEXT("OS         = %OS%"),
	TEXT("PATH       = %PATH%"),
	TEXT("HOMEPATH   = %HOMEPATH%"),
	TEXT("TEMP       = %TEMP%")
};
#define  ENV_VAR_STRING_COUNT  (sizeof(envVarStrings)/sizeof(TCHAR*))
#define INFO_BUFFER_SIZE 32767

void getWinDir(string& name)
{
	TCHAR  infoBuf[INFO_BUFFER_SIZE];
	DWORD  bufCharCount = INFO_BUFFER_SIZE;
	// Get and display the Windows directory. 
	GetWindowsDirectory(infoBuf, INFO_BUFFER_SIZE);
	name = infoBuf;
}
