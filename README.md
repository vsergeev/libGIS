# libGIS - Atmel Generic, Intel HEX, and Motorola S-Record Parser Routines

**ChangeLog**

  * Release 1.0.5 - 02/05/2011
    * Interface change!: write, print, and checksum functions now take a pointer to the record structure instead of a copy, for more efficient use of memory.
    * Prettier debug printing of Intel HEX8 and Motorola S-Record records
    * Clean up of some of the source code comments and doxygen descriptions
  * Release 1.0.4 - 07/08/2010
    * No source code changes since version 1.0.3, but I've released libGIS as two packages, one that is licensed as purely public domain, for locations where that applies, and one that is licensed as MIT/X11, for locations where "public domain" has no legal standing.
  * Release 1.0.3 - 10/10/2009
    * Small bug fix: record reader functions handle newlines in data record lines better, and support for the carriage return character for Windows.
    * Bug fix: s-record write function no longer writes an inaccurate space between the record start and record type.
    * testGIS.c: a redefine of strcasecmp to stricmp for Windows support.
    * Cleaned up some compiler warnings from signed/unsigned comparisons.
    * Thanks to Brendan McDonnell for the above four fixes.
    * Minor documentation clean up.
  * Release 1.0.2 - 06/27/2009
    * Small bug fix: record reader functions will now return a newline return code when a lone newline in the file (sometimes found at the end) is encountered instead of erroring out with an invalid record error code.
  * Release 1.0.0 - 12/24/2006
    * Initial Release

----

**libGIS README**

libGIS is a collection of utility functions to create, read, and write Atmel Generic, Intel HEX8, and Motorola S-Record formatted files. libGIS is typically not compiled into a library, since the file formats it supports are so specific, and the source code for each file format is contained in only two files.

I wrote libGIS was because I wanted a clean, flexible, and easy-to-use set of functions to deal with the nasty parsing of these formatted binary files. libGIS supports Intel HEX8 and Motorola S-Record formatted files, which are undoubtedly the most popular in use with embedded systems. libGIS also supports the Atmel Generic binary format, which may be applicable in projects targetting the Atmel AVR.

libGIS is very convenient for disassembler, assembler, binary file converter, and other related projects. It is written in C (tested with gcc), but can also be compiled with a C++ compiler (such as g++), which means it can be implemented in any C/C++ projects requiring parsing of such formatted files. libGIS uses the standard C library in its backend.

libGIS is clean and tiny. Each file format is supported with two files, one is the C source code and the other is the C header file, which makes compiling whichever format you need to support very easy. The interface to the utility functions is very straight forward, as demonstrated by the included testGIS.c program.

The code of each file format parser has a structure to store record information, and 4-5 basic functions to create, read, write, print, and checksum (for Intel HEX8 and Motorola S-Record) records. The error handling in libGIS will never leave you out of the dark, as the possible error codes and what they mean are clearly defined in the header file of the format parser you're using.

Remember that libGIS is a low-level interface to formatted binary files, and it will not automatically generate, for example, extended addresses in the Intel HEX8 format, or the header record in the S-Record format. libGIS helps in the actual writing and reading of the raw records, not dealing with the content going into them (but still adhering to the record and field size specifications).

libGIS is offered with two licensing options. The first is Public Domain, which is free for any kind of use (personal or commercial), without warranty of any kind, and no requirement for attribution. The second is MIT/X11.

The following function prototypes summarize the interface of libGIS:

    Atmel Generic format:
        int New_AtmelGenericRecord(uint32_t address, uint16_t data, AtmelGenericRecord *genericRecord);
        int Read_AtmelGenericRecord(AtmelGenericRecord *genericRecord, FILE *in);
        int Write_AtmelGenericRecord(const AtmelGenericRecord *genericRecord, FILE *out);
        void Print_AtmelGenericRecord(const AtmelGenericRecord *genericRecord);
        
    Intel HEX8 format:
        int New_IHexRecord(int type, uint16_t address, const uint8_t *data, int dataLen, IHexRecord *ihexRecord);
        int Read_IHexRecord(IHexRecord *ihexRecord, FILE *in);
        int Write_IHexRecord(const IHexRecord *ihexRecord, FILE *out);
        void Print_IHexRecord(const IHexRecord *ihexRecord);
        uint8_t Checksum_IHexRecord(const IHexRecord *ihexRecord);
        
    Motorola S-Record format:
        int New_SRecord(int type, uint32_t address, const uint8_t *data, int dataLen, SRecord *srec);
        int Read_SRecord(SRecord *srec, FILE *in);
        int Write_SRecord(const SRecord *srec, FILE *out);
        void Print_SRecord(const SRecord *srec);
        uint8_t Checksum_SRecord(const SRecord *srec);

This package includes the parsing for the following formats:

**Atmel Generic format:** atmel_generic.c and atmel_generic.h

**Intel HEX8 format:** ihex.c and ihex.h

**Motorola S-Record format:** srecord.c and srecord.h

Also included is a test program (testGIS.c, with a Makefile to compile it) that prints all of the records contained in a Atmel Generic, Intel HEX8 or Motorola S-Record formatted file, documentation in PDF and html formats, and the README containing all of this.

Please email me (vsergeev at gmail dot com) any bugs, problems, or suggestions you encounter with using libGIS, they are highly appreciated.

