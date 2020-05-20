#ifndef CONTROL_FILE_H
#define CONTROL_FILE_H

typedef const char* FileName;

void InputFile(FileName i_fileName);
void CopyFile();
int GetFileSize(FileName i_fileName);

#endif