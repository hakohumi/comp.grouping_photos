#ifndef CONTROL_FILE_H
#define CONTROL_FILE_H

typedef const char* FileName;

char* GetFileName(FileName i_fileName);
void MyCopyFile(FileName i_fileName, FileName o_fileName);
void StructuredPath(FileName i_fileName);  // 未実装

/* -------------------------------------------------- */
// static関数用プロトタイプ宣言
/* -------------------------------------------------- */

static int myGetFileSize(FileName i_fileName);
static int copyFileFopen(FileName i_filePath, FileName o_filePath);
int existFile(const char *path);
/* -------------------------------------------------- */
// Debug用 関数
/* -------------------------------------------------- */

char* InputDebugFunc(FileName i_fileName);

/* -------------------------------------------------- */

#endif