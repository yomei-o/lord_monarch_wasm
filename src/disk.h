/* Reading files out of the PC-98 floppy image, the way the game does.
 *
 * The original has no filesystem beyond its own boot sector: it scans the FAT12
 * root directory for an 8.3 name and pulls the cluster chain in with INT 1Bh.
 * Keeping that shape here means the port loads exactly the files the original
 * loads, in the same order, and there is no separate asset-packing step to get
 * out of step with the disk.
 */
#ifndef DISK_H
#define DISK_H

typedef struct Disk Disk;

/* Opens a raw / FIM / FDI / HDM image.  Returns 0 and leaves a message in
 * disk_error() on failure. */
Disk *disk_open(const char *path);
void disk_close(Disk *d);
const char *disk_error(void);

/* Reads one file whole.  `name` is the plain name, e.g. "DS7TTL.B1"; matching
 * is case-insensitive.  Returns malloc'd bytes the caller frees, or 0. */
unsigned char *disk_read(Disk *d, const char *name, unsigned *sizeOut);

/* Same, then BZ-decompressed.  Every data file on the disk is compressed;
 * PROG.BIN and PROG.DAT are not, and for those this fails - use disk_read. */
unsigned char *disk_read_bz(Disk *d, const char *name, unsigned *sizeOut);

/* Number of root-directory entries, and the i'th name, for listing. */
int disk_count(Disk *d);
const char *disk_name(Disk *d, int i);

#endif
