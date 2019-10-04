/*=============================================================================|
|  PROJECT SNAP7                                                         1.4.0 |
|==============================================================================|
|  Copyright (C) 2013, 2014 Davide Nardella                                    |
|  All rights reserved.                                                        |
|==============================================================================|
|  SNAP7 is free software: you can redistribute it and/or modify               |
|  it under the terms of the Lesser GNU General Public License as published by |
|  the Free Software Foundation, either version 3 of the License, or           |
|  (at your option) any later version.                                         |
|                                                                              |
|  It means that you can distribute your commercial software linked with       |
|  SNAP7 without the requirement to distribute the source code of your         |
|  application and without the requirement that your application be itself     |
|  distributed under LGPL.                                                     |
|                                                                              |
|  SNAP7 is distributed in the hope that it will be useful,                    |
|  but WITHOUT ANY WARRANTY; without even the implied warranty of              |
|  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               |
|  Lesser GNU General Public License for more details.                         |
|                                                                              |
|  You should have received a copy of the GNU General Public License and a     |
|  copy of Lesser GNU General Public License along with Snap7.                 |
|  If not, see  http://www.gnu.org/licenses/                                   |
|==============================================================================|
|                                                                              |
|  C/C++ Snap 7 classes/Imports definitions                                    |
|                                                                              |
|=============================================================================*/
#ifndef snap7_h
#define snap7_h
//---------------------------------------------------------------------------
// Platform detection
//---------------------------------------------------------------------------
#if defined (_WIN32)||defined(_WIN64)||defined(__WIN32__)||defined(__WINDOWS__)
# define OS_WINDOWS
#endif

// Visual Studio needs this to use the correct time_t size
#if defined (_WIN32) && !defined(_WIN64)
# define _USE_32BIT_TIME_T
#endif

#if defined(unix) || defined(__unix__) || defined(__unix)
# define PLATFORM_UNIX
#endif

#if defined(__SVR4) || defined(__svr4__)
# define OS_SOLARIS
#endif

#if BSD>=0
# define OS_BSD
#endif

#if defined(__APPLE__)
# define OS_OSX
#endif

#if defined(PLATFORM_UNIX) || defined(OS_OSX)
# include <unistd.h>
# if defined(_POSIX_VERSION)
#   define POSIX
# endif
#endif

//---------------------------------------------------------------------------
// C++ Library
//---------------------------------------------------------------------------
#ifdef __cplusplus
#include <string>
#include <time.h>

// Visual C++ not C99 compliant (VS2008--)
#ifdef _MSC_VER
# if _MSC_VER >= 1600
#  include <stdint.h>  // VS2010++ have it
# else
   typedef signed __int8     int8_t;
   typedef signed __int16    int16_t;
   typedef signed __int32    int32_t;
   typedef signed __int64    int64_t;
   typedef unsigned __int8   uint8_t;
   typedef unsigned __int16  uint16_t;
   typedef unsigned __int32  uint32_t;
   typedef unsigned __int64  uint64_t;
   #ifdef _WIN64
     typedef unsigned __int64  uintptr_t;
   #else
     typedef unsigned __int32  uintptr_t;
   #endif
# endif
#else
# include <stdint.h>
#endif

extern "C" {
#endif
//---------------------------------------------------------------------------
// C exact length types
//---------------------------------------------------------------------------
#ifndef __cplusplus

#ifdef OS_BSD
#  include <stdint.h>
#  include <time.h>
#endif

#ifdef OS_OSX
#  include <stdint.h>
#  include <time.h>
#endif

#ifdef OS_SOLARIS
#  include <stdint.h>
#  include <time.h>
#endif

#if defined(_UINTPTR_T_DEFINED)
#  include <stdint.h>
#  include <time.h>
#endif

#if !defined(_UINTPTR_T_DEFINED) && !defined(OS_SOLARIS) && !defined(OS_BSD) && !defined(OS_OSX)
  typedef unsigned char   uint8_t;  //  8 bit unsigned integer
  typedef unsigned short  uint16_t; // 16 bit unsigned integer
  typedef unsigned int    uint32_t; // 32 bit unsigned integer
  typedef unsigned long   uintptr_t;// 64 bit unsigned integer
#endif

#endif

#ifdef OS_WINDOWS
# define S7API __stdcall
#else
# define S7API
#endif

#pragma pack(1)
//******************************************************************************
//                                   COMMON
//******************************************************************************
// Exact length types regardless of platform/processor
typedef uint8_t    byte;
typedef uint16_t   word;
typedef uint32_t   longword;
typedef byte       *pbyte;
typedef word       *pword;
typedef uintptr_t  S7Object; // multi platform/processor object reference
                             // DON'T CONFUSE IT WITH AN OLE OBJECT, IT'S SIMPLY
                             // AN INTEGER VALUE (32 OR 64 BIT) USED AS HANDLE.

#ifndef __cplusplus
typedef struct
{
  int   tm_sec;
  int   tm_min;
  int   tm_hour;
  int   tm_mday;
  int   tm_mon;
  int   tm_year;
  int   tm_wday;
  int   tm_yday;
  int   tm_isdst;
}tm;

typedef int bool;
#define false 0;
#define true  1;
#endif

const int errLibInvalidParam  = -1;
const int errLibInvalidObject = -2;

// CPU status
#define S7CpuStatusUnknown  0x00
#define S7CpuStatusRun      0x08
#define S7CpuStatusStop     0x04

// ISO Errors
const longword errIsoConnect            = 0x00010000; // Connection error
const longword errIsoDisconnect         = 0x00020000; // Disconnect error
const longword errIsoInvalidPDU         = 0x00030000; // Bad format
const longword errIsoInvalidDataSize    = 0x00040000; // Bad Datasize passed to send/recv buffer is invalid
const longword errIsoNullPointer    	= 0x00050000; // Null passed as pointer
const longword errIsoShortPacket    	= 0x00060000; // A short packet received
const longword errIsoTooManyFragments   = 0x00070000; // Too many packets without EoT flag
const longword errIsoPduOverflow    	= 0x00080000; // The sum of fragments data exceded maximum packet size
const longword errIsoSendPacket         = 0x00090000; // An error occurred during send
const longword errIsoRecvPacket         = 0x000A0000; // An error occurred during recv
const longword errIsoInvalidParams    	= 0x000B0000; // Invalid TSAP params
const longword errIsoResvd_1            = 0x000C0000; // Unassigned
const longword errIsoResvd_2            = 0x000D0000; // Unassigned
const longword errIsoResvd_3            = 0x000E0000; // Unassigned
const longword errIsoResvd_4            = 0x000F0000; // Unassigned

// Tag Struct
typedef struct{
	int Area;
	int DBNumber;
	int Start;
	int Size;
	int WordLen;
}TS7Tag, *PS7Tag;

//------------------------------------------------------------------------------
//                                  PARAMS LIST
//------------------------------------------------------------------------------
const int p_u16_LocalPort  	    = 1;
const int p_u16_RemotePort 	    = 2;
const int p_i32_PingTimeout	    = 3;
const int p_i32_SendTimeout     = 4;
const int p_i32_RecvTimeout     = 5;
const int p_i32_WorkInterval    = 6;
const int p_u16_SrcRef          = 7;
const int p_u16_DstRef          = 8;
const int p_u16_SrcTSap         = 9;
const int p_i32_PDURequest      = 10;
const int p_i32_MaxClients      = 11;
const int p_i32_BSendTimeout    = 12;
const int p_i32_BRecvTimeout    = 13;
const int p_u32_RecoveryTime    = 14;
const int p_u32_KeepAliveTime   = 15;

// Client/Partner Job status
const int JobComplete           = 0;
const int JobPending            = 1;

//******************************************************************************
//                                   CLIENT
//******************************************************************************

// Error codes
const longword errNegotiatingPDU            = 0x00100000;
const longword errCliInvalidParams          = 0x00200000;
const longword errCliJobPending             = 0x00300000;
const longword errCliTooManyItems           = 0x00400000;
const longword errCliInvalidWordLen         = 0x00500000;
const longword errCliPartialDataWritten     = 0x00600000;
const longword errCliSizeOverPDU            = 0x00700000;
const longword errCliInvalidPlcAnswer       = 0x00800000;
const longword errCliAddressOutOfRange      = 0x00900000;
const longword errCliInvalidTransportSize   = 0x00A00000;
const longword errCliWriteDataSizeMismatch  = 0x00B00000;
const longword errCliItemNotAvailable       = 0x00C00000;
const longword errCliInvalidValue           = 0x00D00000;
const longword errCliCannotStartPLC         = 0x00E00000;
const longword errCliAlreadyRun             = 0x00F00000;
const longword errCliCannotStopPLC          = 0x01000000;
const longword errCliCannotCopyRamToRom     = 0x01100000;
const longword errCliCannotCompress         = 0x01200000;
const longword errCliAlreadyStop            = 0x01300000;
const longword errCliFunNotAvailable        = 0x01400000;
const longword errCliUploadSequenceFailed   = 0x01500000;
const longword errCliInvalidDataSizeRecvd   = 0x01600000;
const longword errCliInvalidBlockType       = 0x01700000;
const longword errCliInvalidBlockNumber     = 0x01800000;
const longword errCliInvalidBlockSize       = 0x01900000;
const longword errCliDownloadSequenceFailed = 0x01A00000;
const longword errCliInsertRefused          = 0x01B00000;
const longword errCliDeleteRefused          = 0x01C00000;
const longword errCliNeedPassword           = 0x01D00000;
const longword errCliInvalidPassword        = 0x01E00000;
const longword errCliNoPasswordToSetOrClear = 0x01F00000;
const longword errCliJobTimeout             = 0x02000000;
const longword errCliPartialDataRead        = 0x02100000;
const longword errCliBufferTooSmall         = 0x02200000;
const longword errCliFunctionRefused        = 0x02300000;
const longword errCliDestroying             = 0x02400000;
const longword errCliInvalidParamNumber     = 0x02500000;
const longword errCliCannotChangeParam      = 0x02600000;

const int MaxVars     = 20; // Max vars that can be transferred with MultiRead/MultiWrite

// Client Connection Type
const word CONNTYPE_PG                      = 0x0001;  // Connect to the PLC as a PG
const word CONNTYPE_OP                      = 0x0002;  // Connect to the PLC as an OP
const word CONNTYPE_BASIC                   = 0x0003;  // Basic connection

// Area ID
const byte S7AreaPE   =	0x81;
const byte S7AreaPA   =	0x82;
const byte S7AreaMK   =	0x83;
const byte S7AreaDB   =	0x84;
const byte S7AreaCT   =	0x1C;
const byte S7AreaTM   =	0x1D;

// Word Length
const int S7WLBit     = 0x01;
const int S7WLByte    = 0x02;
const int S7WLWord    = 0x04;
const int S7WLDWord   = 0x06;
const int S7WLReal    = 0x08;
const int S7WLCounter = 0x1C;
const int S7WLTimer   = 0x1D;

// Block type
const byte Block_OB   = 0x38;
const byte Block_DB   = 0x41;
const byte Block_SDB  = 0x42;
const byte Block_FC   = 0x43;
const byte Block_SFC  = 0x44;
const byte Block_FB   = 0x45;
const byte Block_SFB  = 0x46;

// Sub Block Type
const byte SubBlk_OB  = 0x08;
const byte SubBlk_DB  = 0x0A;
const byte SubBlk_SDB = 0x0B;
const byte SubBlk_FC  = 0x0C;
const byte SubBlk_SFC = 0x0D;
const byte SubBlk_FB  = 0x0E;
const byte SubBlk_SFB = 0x0F;

// Block languages
const byte BlockLangAWL       = 0x01;
const byte BlockLangKOP       = 0x02;
const byte BlockLangFUP       = 0x03;
const byte BlockLangSCL       = 0x04;
const byte BlockLangDB        = 0x05;
const byte BlockLangGRAPH     = 0x06;

// Read/Write Multivars
typedef struct{
   int   Area;
   int   WordLen;
   int   Result;
   int   DBNumber;
   int   Start;
   int   Amount;
   void  *pdata;
} TS7DataItem, *PS7DataItem;

//typedef int TS7ResultItems[MaxVars];
//typedef TS7ResultItems *PS7ResultItems;

// List Blocks
typedef struct {
   int OBCount;
   int FBCount;
   int FCCount;
   int SFBCount;
   int SFCCount;
   int DBCount;
   int SDBCount;
} TS7BlocksList, *PS7BlocksList;

// Blocks info
typedef struct {
   int BlkType;    // Block Type (OB, DB)
   int BlkNumber;  // Block number
   int BlkLang;    // Block Language
   int BlkFlags;   // Block flags
   int MC7Size;    // The real size in bytes
   int LoadSize;   // Load memory size
   int LocalData;  // Local data
   int SBBLength;  // SBB Length
   int CheckSum;   // Checksum
   int Version;    // Block version
   // Chars info
   char CodeDate[11]; // Code date
   char IntfDate[11]; // Interface date
   char Author[9];    // Author
   char Family[9];    // Family
   char Header[9];    // Header
} TS7BlockInfo, *PS7BlockInfo ;

typedef word TS7BlocksOfType[0x2000];
typedef TS7BlocksOfType *PS7BlocksOfType;

// Order code
typedef struct {
   char Code[21];
   byte V1;
   byte V2;
   byte V3;
} TS7OrderCode, *PS7OrderCode;

// CPU Info
typedef struct {
   char ModuleTypeName[33];
   char SerialNumber[25];
   char ASName[25];
   char Copyright[27];
   char ModuleName[25];
} TS7CpuInfo, *PS7CpuInfo;

// CP Info
typedef struct {
   int MaxPduLengt;
   int MaxConnections;
   int MaxMpiRate;
   int MaxBusRate;
} TS7CpInfo, *PS7CpInfo;

// See §33.1 of "System Software for S7-300/400 System and Standard Functions"
// and see SFC51 description too
typedef struct {
   word LENTHDR;
   word N_DR;
} SZL_HEADER, *PSZL_HEADER;

typedef struct {
   SZL_HEADER Header;
   byte Data[0x4000-4];
} TS7SZL, *PS7SZL;

// SZL List of available SZL IDs : same as SZL but List items are big-endian adjusted
typedef struct {
   SZL_HEADER Header;
   word List[0x2000-2];
} TS7SZLList, *PS7SZLList;

// See §33.19 of "System Software for S7-300/400 System and Standard Functions"
typedef struct {
   word  sch_schal;
   word  sch_par;
   word  sch_rel;
   word  bart_sch;
   word  anl_sch;
} TS7Protection, *PS7Protection;

// Client completion callback
typedef void (S7API *pfn_CliCompletion) (void *usrPtr, int opCode, int opResult);
//------------------------------------------------------------------------------
//  Import prototypes
//------------------------------------------------------------------------------
S7Object S7API Cli_Create();
void S7API Cli_Destroy(S7Object *Client);
int S7API Cli_ConnectTo(S7Object Client, const char *Address, int Rack, int Slot);
int S7API Cli_SetConnectionParams(S7Object Client, const char *Address, word LocalTSAP, word RemoteTSAP);
int S7API Cli_SetConnectionType(S7Object Client, word ConnectionType);
int S7API Cli_Connect(S7Object Client);
int S7API Cli_Disconnect(S7Object Client);
int S7API Cli_GetParam(S7Object Client, int ParamNumber, void *pValue);
int S7API Cli_SetParam(S7Object Client, int ParamNumber, void *pValue);
// Data I/O main functions
int S7API Cli_ReadArea(S7Object Client, int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData);
int S7API Cli_WriteArea(S7Object Client, int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData);
int S7API Cli_ReadMultiVars(S7Object Client, PS7DataItem Item, int ItemsCount);
int S7API Cli_WriteMultiVars(S7Object Client, PS7DataItem Item, int ItemsCount);
// Data I/O Lean functions
int S7API Cli_DBRead(S7Object Client, int DBNumber, int Start, int Size, void *pUsrData);
int S7API Cli_DBWrite(S7Object Client, int DBNumber, int Start, int Size, void *pUsrData);
int S7API Cli_MBRead(S7Object Client, int Start, int Size, void *pUsrData);
int S7API Cli_MBWrite(S7Object Client, int Start, int Size, void *pUsrData);
int S7API Cli_EBRead(S7Object Client, int Start, int Size, void *pUsrData);
int S7API Cli_EBWrite(S7Object Client, int Start, int Size, void *pUsrData);
int S7API Cli_ABRead(S7Object Client, int Start, int Size, void *pUsrData);
int S7API Cli_ABWrite(S7Object Client, int Start, int Size, void *pUsrData);
int S7API Cli_TMRead(S7Object Client, int Start, int Amount, void *pUsrData);
int S7API Cli_TMWrite(S7Object Client, int Start, int Amount, void *pUsrData);
int S7API Cli_CTRead(S7Object Client, int Start, int Amount, void *pUsrData);
int S7API Cli_CTWrite(S7Object Client, int Start, int Amount, void *pUsrData);
// Directory functions
int S7API Cli_ListBlocks(S7Object Client, TS7BlocksList *pUsrData);
int S7API Cli_GetAgBlockInfo(S7Object Client, int BlockType, int BlockNum, TS7BlockInfo *pUsrData);
int S7API Cli_GetPgBlockInfo(S7Object Client, void *pBlock, TS7BlockInfo *pUsrData, int Size);
int S7API Cli_ListBlocksOfType(S7Object Client, int BlockType, TS7BlocksOfType *pUsrData, int *ItemsCount);
// Blocks functions
int S7API Cli_Upload(S7Object Client, int BlockType, int BlockNum, void *pUsrData, int *Size);
int S7API Cli_FullUpload(S7Object Client, int BlockType, int BlockNum, void *pUsrData, int *Size);
int S7API Cli_Download(S7Object Client, int BlockNum, void *pUsrData, int Size);
int S7API Cli_Delete(S7Object Client, int BlockType, int BlockNum);
int S7API Cli_DBGet(S7Object Client, int DBNumber, void *pUsrData, int *Size);
int S7API Cli_DBFill(S7Object Client, int DBNumber, int FillChar);
// Date/Time functions
int S7API Cli_GetPlcDateTime(S7Object Client, tm *DateTime);
int S7API Cli_SetPlcDateTime(S7Object Client, tm *DateTime);
int S7API Cli_SetPlcSystemDateTime(S7Object Client);
// System Info functions
int S7API Cli_GetOrderCode(S7Object Client, TS7OrderCode *pUsrData);
int S7API Cli_GetCpuInfo(S7Object Client, TS7CpuInfo *pUsrData);
int S7API Cli_GetCpInfo(S7Object Client, TS7CpInfo *pUsrData);
int S7API Cli_ReadSZL(S7Object Client, int ID, int Index, TS7SZL *pUsrData, int *Size);
int S7API Cli_ReadSZLList(S7Object Client, TS7SZLList *pUsrData, int *ItemsCount);
// Control functions
int S7API Cli_PlcHotStart(S7Object Client);
int S7API Cli_PlcColdStart(S7Object Client);
int S7API Cli_PlcStop(S7Object Client);
int S7API Cli_CopyRamToRom(S7Object Client, int Timeout);
int S7API Cli_Compress(S7Object Client, int Timeout);
int S7API Cli_GetPlcStatus(S7Object Client, int *Status);
// Security functions
int S7API Cli_GetProtection(S7Object Client, TS7Protection *pUsrData);
int S7API Cli_SetSessionPassword(S7Object Client, char *Password);
int S7API Cli_ClearSessionPassword(S7Object Client);
// Low level
int S7API Cli_IsoExchangeBuffer(S7Object Client, void *pUsrData, int *Size);
// Misc
int S7API Cli_GetExecTime(S7Object Client, int *Time);
int S7API Cli_GetLastError(S7Object Client, int *LastError);
int S7API Cli_GetPduLength(S7Object Client, int *Requested, int *Negotiated);
int S7API Cli_ErrorText(int Error, char *Text, int TextLen);
// 1.1.0
int S7API Cli_GetConnected(S7Object Client, int *Connected);

#pragma pack()
#ifdef __cplusplus
 }
#endif // __cplusplus

#ifdef __cplusplus

//******************************************************************************
//                           CLIENT CLASS DEFINITION
//******************************************************************************
class TS7Client
{
private:
    S7Object Client;
public:
	TS7Client();
	~TS7Client();
    // Control functions
    int Connect();
    int ConnectTo(const char *RemAddress, int Rack, int Slot);
    int SetConnectionParams(const char *RemAddress, word LocalTSAP, word RemoteTSAP);
    int SetConnectionType(word ConnectionType);
    int Disconnect();
    int GetParam(int ParamNumber, void *pValue);
    int SetParam(int ParamNumber, void *pValue);
    // Data I/O Main functions
    int ReadArea(int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData);
    int WriteArea(int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData);
    int ReadMultiVars(PS7DataItem Item, int ItemsCount);
    int WriteMultiVars(PS7DataItem Item, int ItemsCount);
    // Data I/O Lean functions
    int DBRead(int DBNumber, int Start, int Size, void *pUsrData);
    int DBWrite(int DBNumber, int Start, int Size, void *pUsrData);
    int MBRead(int Start, int Size, void *pUsrData);
    int MBWrite(int Start, int Size, void *pUsrData);
    int EBRead(int Start, int Size, void *pUsrData);
    int EBWrite(int Start, int Size, void *pUsrData);
    int ABRead(int Start, int Size, void *pUsrData);
    int ABWrite(int Start, int Size, void *pUsrData);
    int TMRead(int Start, int Amount, void *pUsrData);
    int TMWrite(int Start, int Amount, void *pUsrData);
    int CTRead(int Start, int Amount, void *pUsrData);
    int CTWrite(int Start, int Amount, void *pUsrData);
    // Directory functions
    int ListBlocks(PS7BlocksList pUsrData);
    int GetAgBlockInfo(int BlockType, int BlockNum, PS7BlockInfo pUsrData);
    int GetPgBlockInfo(void *pBlock, PS7BlockInfo pUsrData, int Size);
    int ListBlocksOfType(int BlockType, TS7BlocksOfType *pUsrData, int *ItemsCount);
    // Blocks functions
    int Upload(int BlockType, int BlockNum, void *pUsrData, int *Size);
    int FullUpload(int BlockType, int BlockNum, void *pUsrData, int *Size);
    int Download(int BlockNum, void *pUsrData, int Size);
    int Delete(int BlockType, int BlockNum);
    int DBGet(int DBNumber, void *pUsrData, int *Size);
    int DBFill(int DBNumber, int FillChar);
    // Date/Time functions
    int GetPlcDateTime(tm *DateTime);
    int SetPlcDateTime(tm *DateTime);
    int SetPlcSystemDateTime();
    // System Info functions
    int GetOrderCode(PS7OrderCode pUsrData);
    int GetCpuInfo(PS7CpuInfo pUsrData);
    int GetCpInfo(PS7CpInfo pUsrData);
	int ReadSZL(int ID, int Index, PS7SZL pUsrData, int *Size);
	int ReadSZLList(PS7SZLList pUsrData, int *ItemsCount);
	// Control functions
	int PlcHotStart();
	int PlcColdStart();
	int PlcStop();
	int CopyRamToRom(int Timeout);
	int Compress(int Timeout);
	// Security functions
	int GetProtection(PS7Protection pUsrData);
	int SetSessionPassword(char *Password);
	int ClearSessionPassword();
	// Properties
	int ExecTime();
	int LastError();
	int PDURequested();
	int PDULength();
	int PlcStatus();
	bool Connected();
};
typedef TS7Client *PS7Client;

//******************************************************************************
//                               TEXT ROUTINES
// Only for C++, for pure C use xxx_ErrorText() which uses *char
//******************************************************************************
#define TextLen 1024

// String type
// Here we define generic TextString (by default mapped onto std::string).
// So you can change it if needed (Unicodestring, Ansistring etc...)

typedef std::string TextString;

TextString CliErrorText(int Error);

#endif // __cplusplus
#endif // snap7_h
