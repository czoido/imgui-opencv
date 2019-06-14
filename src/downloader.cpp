#include "../include/downloader.h"
#include <iterator>

Downloader::Downloader(void)
{
	HTTPStreamFactory::registerFactory();
	HTTPSStreamFactory::registerFactory();
	FTPStreamFactory::registerFactory();
}

Downloader::~Downloader(void)
{
}

std::string Downloader::DownloadFile(const std::string &url)
{
	Path path(url);
	std::string filename = "";
	try
	{
		URI uri(url);
		std::unique_ptr<std::istream> pStr(URIStreamOpener::defaultOpener().open(uri));
		std::ofstream fileStream;
		filename = path.getFileName();
		fileStream.open(filename, std::ios::out | std::ios::trunc | std::ios::binary);
		StreamCopier::copyStream(*pStr.get(), fileStream);
		fileStream.close();
	}
	catch (Exception &exc)
	{
		std::cerr << exc.displayText() << std::endl;
		filename = "";
	}
	return filename;
}
