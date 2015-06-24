#include "crc.h"

const unsigned short crc_table[] = {
	0x0000, 0xcc01, 0xd801, 0x1400,
	0xf001, 0x3c00, 0x2800, 0xe401,
	0xa001, 0x6c00, 0x7800, 0xb401,
	0x5000, 0x9c01, 0x8801, 0x4400
};

u16 crc16(const unsigned char* pmsg,
		unsigned char len) {
	unsigned short	crc		= 0xffff;
	unsigned char	i;
	unsigned char	temp;

	for(i = 0; i < len; i++) {
		temp = *pmsg++;
		crc	 =  crc_table[(temp ^ crc) & 15] ^ (crc >> 4);
		crc	 =  crc_table[((temp >> 4) ^ crc) & 15] ^ (crc >> 4);
	}

	return crc;
}
