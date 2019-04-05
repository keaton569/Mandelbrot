#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(push, 2)
namespace keatonProgram {
	struct BitmapFileHeader {
		char header[2]{'B','M'};
		int32_t fileSize;
		int32_t reserved{ 0 };
		int32_t dataOffset;

	};

#pragma pack(pop)
}//end namespace




#endif // BITMAPFILEHEADER_H_

