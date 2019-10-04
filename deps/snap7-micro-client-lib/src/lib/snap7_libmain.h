/*=============================================================================|
|  PROJECT SNAP7                                                         1.3.0 |
|==============================================================================|
|  Copyright (C) 2013, 2015 Davide Nardella                                    |
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
|=============================================================================*/
#ifndef snap7_libmain_h
#define snap7_libmain_h
//---------------------------------------------------------------------------
#include "s7_client-wrapper.h"
#include "s7_text.h"
//---------------------------------------------------------------------------

const int mkEvent  = 0;
const int mkLog    = 1;

typedef uintptr_t S7Object; // multi platform/processor object reference

//==============================================================================
// CLIENT EXPORT LIST - Sync functions
//==============================================================================
EXPORTSPEC S7Object S7API Cli_Create();
EXPORTSPEC void S7API Cli_Destroy(S7Object &Client);
EXPORTSPEC int S7API Cli_Connect(S7Object Client);
EXPORTSPEC int S7API Cli_SetConnectionParams(S7Object Client, const char *Address, word LocalTSAP, word RemoteTSAP);
EXPORTSPEC int S7API Cli_SetConnectionType(S7Object Client, word ConnectionType);
EXPORTSPEC int S7API Cli_ConnectTo(S7Object Client, const char *Address, int Rack, int Slot);
EXPORTSPEC int S7API Cli_Disconnect(S7Object Client);
EXPORTSPEC int S7API Cli_GetParam(S7Object Client, int ParamNumber, void *pValue);
EXPORTSPEC int S7API Cli_SetParam(S7Object Client, int ParamNumber, void *pValue);
// Data I/O functions
EXPORTSPEC int S7API Cli_ReadArea(S7Object Client, int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData);
EXPORTSPEC int S7API Cli_WriteArea(S7Object Client, int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData);
EXPORTSPEC int S7API Cli_ReadMultiVars(S7Object Client, PS7DataItem Item, int ItemsCount);
EXPORTSPEC int S7API Cli_WriteMultiVars(S7Object Client, PS7DataItem Item, int ItemsCount);
// Data I/O Lean functions
EXPORTSPEC int S7API Cli_DBRead(S7Object Client, int DBNumber, int Start, int Size, void *pUsrData);
EXPORTSPEC int S7API Cli_DBWrite(S7Object Client, int DBNumber, int Start, int Size, void *pUsrData);
EXPORTSPEC int S7API Cli_MBRead(S7Object Client, int Start, int Size, void *pUsrData);
EXPORTSPEC int S7API Cli_MBWrite(S7Object Client, int Start, int Size, void *pUsrData);
EXPORTSPEC int S7API Cli_EBRead(S7Object Client, int Start, int Size, void *pUsrData);
EXPORTSPEC int S7API Cli_EBWrite(S7Object Client, int Start, int Size, void *pUsrData);
EXPORTSPEC int S7API Cli_ABRead(S7Object Client, int Start, int Size, void *pUsrData);
EXPORTSPEC int S7API Cli_ABWrite(S7Object Client, int Start, int Size, void *pUsrData);
EXPORTSPEC int S7API Cli_TMRead(S7Object Client, int Start, int Amount, void *pUsrData);
EXPORTSPEC int S7API Cli_TMWrite(S7Object Client, int Start, int Amount, void *pUsrData);
EXPORTSPEC int S7API Cli_CTRead(S7Object Client, int Start, int Amount, void *pUsrData);
EXPORTSPEC int S7API Cli_CTWrite(S7Object Client, int Start, int Amount, void *pUsrData);
// Directory functions
EXPORTSPEC int S7API Cli_ListBlocks(S7Object Client, TS7BlocksList *pUsrData);
EXPORTSPEC int S7API Cli_GetAgBlockInfo(S7Object Client, int BlockType, int BlockNum, TS7BlockInfo *pUsrData);
EXPORTSPEC int S7API Cli_GetPgBlockInfo(S7Object Client, void *pBlock, TS7BlockInfo *pUsrData, int Size);
EXPORTSPEC int S7API Cli_ListBlocksOfType(S7Object Client, int BlockType, TS7BlocksOfType *pUsrData, int &ItemsCount);
// Blocks functions
EXPORTSPEC int S7API Cli_Upload(S7Object Client, int BlockType, int BlockNum, void *pUsrData, int &Size);
EXPORTSPEC int S7API Cli_FullUpload(S7Object Client, int BlockType, int BlockNum, void *pUsrData, int &Size);
EXPORTSPEC int S7API Cli_Download(S7Object Client, int BlockNum, void *pUsrData, int Size);
EXPORTSPEC int S7API Cli_Delete(S7Object Client, int BlockType, int BlockNum);
EXPORTSPEC int S7API Cli_DBGet(S7Object Client, int DBNumber, void *pUsrData, int &Size);
EXPORTSPEC int S7API Cli_DBFill(S7Object Client, int DBNumber, int FillChar);
// Date/Time functions
EXPORTSPEC int S7API Cli_GetPlcDateTime(S7Object Client, tm &DateTime);
EXPORTSPEC int S7API Cli_SetPlcDateTime(S7Object Client, tm *DateTime);
EXPORTSPEC int S7API Cli_SetPlcSystemDateTime(S7Object Client);
// System Info functions
EXPORTSPEC int S7API Cli_GetOrderCode(S7Object Client, TS7OrderCode *pUsrData);
EXPORTSPEC int S7API Cli_GetCpuInfo(S7Object Client, TS7CpuInfo *pUsrData);
EXPORTSPEC int S7API Cli_GetCpInfo(S7Object Client, TS7CpInfo *pUsrData);
EXPORTSPEC int S7API Cli_ReadSZL(S7Object Client, int ID, int Index, TS7SZL *pUsrData, int &Size);
EXPORTSPEC int S7API Cli_ReadSZLList(S7Object Client, TS7SZLList *pUsrData, int &ItemsCount);
// Control functions
EXPORTSPEC int S7API Cli_PlcHotStart(S7Object Client);
EXPORTSPEC int S7API Cli_PlcColdStart(S7Object Client);
EXPORTSPEC int S7API Cli_PlcStop(S7Object Client);
EXPORTSPEC int S7API Cli_CopyRamToRom(S7Object Client, int Timeout);
EXPORTSPEC int S7API Cli_Compress(S7Object Client, int Timeout);
EXPORTSPEC int S7API Cli_GetPlcStatus(S7Object Client, int &Status);
// Security functions
EXPORTSPEC int S7API Cli_GetProtection(S7Object Client, TS7Protection *pUsrData);
EXPORTSPEC int S7API Cli_SetSessionPassword(S7Object Client, char *Password);
EXPORTSPEC int S7API Cli_ClearSessionPassword(S7Object Client);
// Low level
EXPORTSPEC int S7API Cli_IsoExchangeBuffer(S7Object Client, void *pUsrData, int &Size);
// Misc
EXPORTSPEC int S7API Cli_GetExecTime(S7Object Client, int &Time);
EXPORTSPEC int S7API Cli_GetLastError(S7Object Client, int &LastError);
EXPORTSPEC int S7API Cli_GetPduLength(S7Object Client, int &Requested, int &Negotiated);
EXPORTSPEC int S7API Cli_ErrorText(int Error, char *Text, int TextLen);
EXPORTSPEC int S7API Cli_GetConnected(S7Object Client, int &Connected);

#endif // snap7_libmain_h
