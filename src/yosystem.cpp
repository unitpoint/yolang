#include "yolang.h"

YoSystem::YoSystem()
{
}

YoSystem::~YoSystem()
{
}

std::string YoSystem::getUniqName(const char * fmt)
{
	static int i = 1;
	size_t size = strlen(fmt) + 64;
	char * buf = (char*)alloca(size);
	sprintf_s(buf, size, fmt, i++);
	return buf;
}


bool YoSystem::isFileExist(const char * filename)
{
	FileHandle * f = openFile(filename, "rb");
	if (f){
		closeFile(f);
		return true;
	}
	return false;
}

int YoSystem::getFileSize(const char * filename)
{
	FileHandle * f = openFile(filename, "rb");
	if (f){
		int size = getFileSize(f);
		closeFile(f);
		return size;
	}
	return 0;
}

int YoSystem::getFileSize(FileHandle * f)
{
	if (f){
		int pos = seekFile(f, 0, SEEK_CUR);
		int size = seekFile(f, 0, SEEK_END);
		seekFile(f, pos, SEEK_SET);
		return size;
	}
	return 0;
}

YoSystem::FileHandle * YoSystem::openFile(const char * filename, const char * mode)\
{
	return (FileHandle*)fopen(filename, mode);
}

int YoSystem::readFile(void * buf, int size, FileHandle * f)
{
	if (f){
		return (int)fread(buf, size, 1, (FILE*)f) * size;
	}
	return 0;
}

int YoSystem::writeFile(const void * buf, int size, FileHandle * f)
{
	if (f){
		return (int)fwrite(buf, size, 1, (FILE*)f) * size;
	}
	return 0;
}

int YoSystem::seekFile(FileHandle * f, int offset, int whence)
{
	if (f){
		fseek((FILE*)f, offset, whence);
		return ftell((FILE*)f);
	}
	return 0;
}

void YoSystem::closeFile(FileHandle * f)
{
	if (f){
		fclose((FILE*)f);
	}
}

