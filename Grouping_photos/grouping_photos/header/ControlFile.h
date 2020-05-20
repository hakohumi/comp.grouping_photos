#ifndef CONTROL_FILE_H
#define CONTROL_FILE_H

typedef const char* FileName;

void InputFile(FileName i_fileName);
void MyCopyFile(FileName i_fileName, FileName o_fileName);
static int myGetFileSize(FileName i_fileName);

#endif