#ifndef __YOSYSTEM_H__
#define __YOSYSTEM_H__

#include "yodef.h"
#include <string>

class YoSystem
{
public:

	struct FileHandle {};

	YoSystem();
	virtual ~YoSystem();

	virtual std::string getUniqName(const char * fmt);

	virtual bool isFileExist(const char * filename);
	virtual int getFileSize(const char * filename);
	virtual int getFileSize(FileHandle * f);
	virtual FileHandle * openFile(const char * filename, const char * mode);
	virtual int readFile(void * buf, int size, FileHandle * f);
	virtual int writeFile(const void * buf, int size, FileHandle * f);
	virtual int seekFile(FileHandle * f, int offset, int whence);
	virtual void closeFile(FileHandle * f);

};

#endif // __YOSYSTEM_H__

