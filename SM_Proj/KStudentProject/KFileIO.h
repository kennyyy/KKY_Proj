class KFileIO{
	FILE* fp = nullptr;
public:
	FILE* CreateFile(const char* filename, const char* filemode);
	void CloseFile();
};


FILE* KFileIO::CreateFile(const char* filename, const char* filemode){
	fp = fopen(filename, filemode);
	if (fp != nullptr)
	{
		return fp;
	}
	return fp;
}

void KFileIO::CloseFile(){
	fclose(fp);
}
