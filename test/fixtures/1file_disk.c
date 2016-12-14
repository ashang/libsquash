/*
 * Copyright (c) 2016 Libsquash contributers
 *
 * This file is part of libsquash, distributed under the MIT License
 * For full terms see the included LICENSE file
 */

#include <stdint.h>
#include <stddef.h>

/*
Found a valid SQUASHFS 4:0 superblock on 1file.
Creation or last append time Thu Dec  1 19:40:23 2016
Filesystem size 0.22 Kbytes (0.00 Mbytes)
Compression gzip
Block size 131072
Filesystem is exportable via NFS
Inodes are compressed
Data is compressed
Fragments are compressed
Always-use-fragments option is not specified
Xattrs are compressed
Duplicates are removed
Number of fragments 1
Number of inodes 2
Number of ids 1

drwxrwxr-x ubuntu/ubuntu            28 2016-12-01 19:40 squashfs-root
-rw-rw-r-- ubuntu/ubuntu             4 2016-12-01 19:40 squashfs-root/minqi
*/

const uint8_t fixtures_1file_disk[] =
    { 104, 115, 113, 115, 2, 0, 0, 0, 39, 12, 64, 88, 0, 0, 2, 0, 1, 0, 0, 0, 1,
	0, 17, 0, 192, 0, 1, 0, 4, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 230, 0, 0,
	0, 0, 0, 0, 0, 222, 0, 0, 0, 0, 0,
	0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 100, 0, 0, 0, 0, 0, 0, 0,
	141, 0, 0, 0, 0, 0, 0, 0, 184, 0,
	0, 0, 0, 0, 0, 0, 208, 0, 0, 0, 0, 0, 0, 0, 112, 97, 110, 10, 39, 0,
	120, 218, 99, 98, 216, 194, 200, 0,
	4, 34, 60, 14, 17, 96, 6, 18, 96, 1, 98, 70, 134, 191, 112, 121, 38,
	168, 56, 136, 150, 1, 98, 102, 32, 6,
	0, 130, 192, 3, 79, 23, 0, 120, 218, 99, 96, 128, 0, 70, 40, 205, 196,
	192, 194, 144, 155, 153, 87, 152,
	9, 0, 6, 178, 2, 38, 16, 128, 96, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 1, 0, 0,
	0, 0, 166, 0, 0, 0, 0, 0, 0, 0,
	14, 0, 120, 218, 99, 96, 128, 0, 5, 40, 13, 0, 1, 16, 0, 33, 192, 0, 0,
	0, 0, 0, 0, 0, 4, 128, 232, 3, 0,
	0, 216, 0, 0, 0, 0, 0, 0, 0
};

const size_t fixtures_1file_disk_size = 230;
