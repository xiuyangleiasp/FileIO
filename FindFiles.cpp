#include<string>
#include<vector>
#include<Windows.h>
using namespace std;

vector<string> getFileNames(const string& inputDir, const string& filter){
	vector<string> res;
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	hFind = FindFirstFile((inputDir + filter).c_str(), &ffd);
	if (INVALID_HANDLE_VALUE == hFind){
		perror("FindFirstFile Error\n");
		exit(-1);
	}
	do{
		if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)){
			res.push_back(ffd.cFileName);
		}
	} while (FindNextFile(hFind, &ffd) != 0);
	FindClose(hFind);
	return res;
}