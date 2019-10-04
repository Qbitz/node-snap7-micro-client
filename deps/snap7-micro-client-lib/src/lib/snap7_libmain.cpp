/*=============================================================================|
|  PROJECT SNAP7                                                         1.4.1 |
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
#include "snap7_libmain.h"

#ifndef OS_WINDOWS
void libinit(void) __attribute__((constructor));
void libdone(void) __attribute__((destructor));
#endif

static bool libresult = true;

void libinit(void)
{
     // in future expansions here can be inserted some initialization code
     libresult=true;
}

void libdone(void)
{
     // in future expansions here can be inserted some destruction code
}

#ifdef OS_WINDOWS
BOOL APIENTRY DllMain (HINSTANCE hInst,
                       DWORD reason,
                       LPVOID reserved)
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
        libinit();
        break;
      case DLL_PROCESS_DETACH:
        libdone();
        break;
      case DLL_THREAD_ATTACH:
        break;
      case DLL_THREAD_DETACH:
        break;
    }
    return libresult;
}
#endif

//***************************************************************************
// CLIENT
//***************************************************************************
S7Object S7API Cli_Create()
{
    return S7Object(new TSnap7Client());
}
//---------------------------------------------------------------------------
void S7API Cli_Destroy(S7Object &Client)
{
    if (Client)
    {
        delete PSnap7Client(Client);
        Client=0;
    }
}
//---------------------------------------------------------------------------
int S7API Cli_SetConnectionParams(S7Object Client, const char *Address, word LocalTSAP, word RemoteTSAP)
{
    if (Client)
    {
        PSnap7Client(Client)->SetConnectionParams(Address, LocalTSAP, RemoteTSAP);
        return 0;
    }
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_SetConnectionType(S7Object Client, word ConnectionType)
{
    if (Client)
    {
        PSnap7Client(Client)->SetConnectionType(ConnectionType);
        return 0;
    }
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ConnectTo(S7Object Client, const char *Address, int Rack, int Slot)
{
    if (Client)
        return PSnap7Client(Client)->ConnectTo(Address, Rack, Slot);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_Connect(S7Object Client)
{
    if (Client)
        return PSnap7Client(Client)->Connect();
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_Disconnect(S7Object Client)
{
    if (Client)
        return PSnap7Client(Client)->Disconnect();
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetParam(S7Object Client, int ParamNumber, void *pValue)
{
    if (Client)
        return PSnap7Client(Client)->GetParam(ParamNumber, pValue);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_SetParam(S7Object Client, int ParamNumber, void *pValue)
{
    if (Client)
        return PSnap7Client(Client)->SetParam(ParamNumber, pValue);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ReadArea(S7Object Client, int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->ReadArea(Area, DBNumber, Start, Amount, WordLen, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_WriteArea(S7Object Client, int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->WriteArea(Area, DBNumber, Start, Amount, WordLen, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ReadMultiVars(S7Object Client, PS7DataItem Item, int ItemsCount)
{
    if (Client)
        return PSnap7Client(Client)->ReadMultiVars(Item, ItemsCount);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_WriteMultiVars(S7Object Client, PS7DataItem Item, int ItemsCount)
{
    if (Client)
        return PSnap7Client(Client)->WriteMultiVars(Item, ItemsCount);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_DBRead(S7Object Client, int DBNumber, int Start, int Size, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->DBRead(DBNumber, Start, Size, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_DBWrite(S7Object Client, int DBNumber, int Start, int Size, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->DBWrite(DBNumber, Start, Size, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_MBRead(S7Object Client, int Start, int Size, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->MBRead(Start, Size, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_MBWrite(S7Object Client, int Start, int Size, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->MBWrite(Start, Size, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_EBRead(S7Object Client, int Start, int Size, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->EBRead(Start, Size, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_EBWrite(S7Object Client, int Start, int Size, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->EBWrite(Start, Size, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ABRead(S7Object Client, int Start, int Size, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->ABRead(Start, Size, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ABWrite(S7Object Client, int Start, int Size, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->ABWrite(Start, Size, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_TMRead(S7Object Client, int Start, int Amount, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->TMRead(Start, Amount, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_TMWrite(S7Object Client, int Start, int Amount, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->TMWrite(Start, Amount, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_CTRead(S7Object Client, int Start, int Amount, void *pUsrData)
{
    if (Client)
         return PSnap7Client(Client)->CTRead(Start, Amount, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_CTWrite(S7Object Client, int Start, int Amount, void *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->CTWrite(Start, Amount, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ListBlocks(S7Object Client, TS7BlocksList *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->ListBlocks(pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetAgBlockInfo(S7Object Client, int BlockType, int BlockNum, TS7BlockInfo *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->GetAgBlockInfo(BlockType, BlockNum, pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetPgBlockInfo(S7Object Client, void *pBlock, TS7BlockInfo *pUsrData, int Size)
{
    if (Client)
        return PSnap7Client(Client)->GetPgBlockInfo(pBlock, pUsrData, Size);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ListBlocksOfType(S7Object Client, int BlockType, TS7BlocksOfType *pUsrData, int &ItemsCount)
{
    if (Client)
        return PSnap7Client(Client)->ListBlocksOfType(BlockType, pUsrData, ItemsCount);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_Upload(S7Object Client, int BlockType, int BlockNum, void *pUsrData, int &Size)
{
    if (Client)
        return PSnap7Client(Client)->Upload(BlockType, BlockNum, pUsrData, Size);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_FullUpload(S7Object Client, int BlockType, int BlockNum, void *pUsrData, int &Size)
{
    if (Client)
        return PSnap7Client(Client)->FullUpload(BlockType, BlockNum, pUsrData, Size);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_Download(S7Object Client, int BlockNum, void *pUsrData, int Size)
{
    if (Client)
        return PSnap7Client(Client)->Download(BlockNum, pUsrData, Size);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_Delete(S7Object Client, int BlockType, int BlockNum)
{
    if (Client)
        return PSnap7Client(Client)->Delete(BlockType, BlockNum);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_DBGet(S7Object Client, int DBNumber, void *pUsrData, int &Size)
{
    if (Client)
        return PSnap7Client(Client)->DBGet(DBNumber, pUsrData, Size);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_DBFill(S7Object Client, int DBNumber, int FillChar)
{
    if (Client)
        return PSnap7Client(Client)->DBFill(DBNumber, FillChar);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetPlcDateTime(S7Object Client, tm &DateTime)
{
    if (Client)
        return PSnap7Client(Client)->GetPlcDateTime(DateTime);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_SetPlcDateTime(S7Object Client, tm *DateTime)
{
    if (Client)
        return PSnap7Client(Client)->SetPlcDateTime(DateTime);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_SetPlcSystemDateTime(S7Object Client)
{
    if (Client)
        return PSnap7Client(Client)->SetPlcSystemDateTime();
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetOrderCode(S7Object Client, TS7OrderCode *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->GetOrderCode(pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetCpuInfo(S7Object Client, TS7CpuInfo *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->GetCpuInfo(pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetCpInfo(S7Object Client, TS7CpInfo *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->GetCpInfo(pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ReadSZL(S7Object Client, int ID, int Index, TS7SZL *pUsrData, int &Size)
{
    if (Client)
        return PSnap7Client(Client)->ReadSZL(ID, Index, pUsrData, Size);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ReadSZLList(S7Object Client, TS7SZLList *pUsrData, int &ItemsCount)
{
    if (Client)
        return PSnap7Client(Client)->ReadSZLList(pUsrData, ItemsCount);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_PlcHotStart(S7Object Client)
{
    if (Client)
        return PSnap7Client(Client)->PlcHotStart();
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_PlcColdStart(S7Object Client)
{
    if (Client)
        return PSnap7Client(Client)->PlcColdStart();
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_PlcStop(S7Object Client)
{
    if (Client)
        return PSnap7Client(Client)->PlcStop();
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_CopyRamToRom(S7Object Client, int Timeout)
{
    if (Client)
        return PSnap7Client(Client)->CopyRamToRom(Timeout);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_Compress(S7Object Client, int Timeout)
{
    if (Client)
        return PSnap7Client(Client)->Compress(Timeout);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetPlcStatus(S7Object Client, int &Status)
{
    if (Client)
        return PSnap7Client(Client)->GetPlcStatus(Status);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetProtection(S7Object Client, TS7Protection *pUsrData)
{
    if (Client)
        return PSnap7Client(Client)->GetProtection(pUsrData);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_SetSessionPassword(S7Object Client, char *Password)
{
    if (Client)
        return PSnap7Client(Client)->SetSessionPassword(Password);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ClearSessionPassword(S7Object Client)
{
    if (Client)
        return PSnap7Client(Client)->ClearSessionPassword();
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_IsoExchangeBuffer(S7Object Client, void *pUsrData, int &Size)
{
    if (Client)
        return PSnap7Client(Client)->isoExchangeBuffer(pUsrData, Size);
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetExecTime(S7Object Client, int &Time)
{
    if (Client)
    {
        Time=PSnap7Client(Client)->Time();
        return 0;
    }
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetLastError(S7Object Client, int &LastError)
{
    if (Client)
    {
        LastError=PSnap7Client(Client)->LastError;
        return 0;
    }
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_GetPduLength(S7Object Client, int &Requested, int &Negotiated)
{
    if (Client)
    {
        Negotiated=PSnap7Client(Client)->PDULength;
        Requested =PSnap7Client(Client)->PDURequest;
        return 0;
    }
    else
        return errLibInvalidObject;
}
//---------------------------------------------------------------------------
int S7API Cli_ErrorText(int Error, char *Text, int TextLen)
{
	try{
		ErrCliText(Error, Text, TextLen);
		Text[TextLen - 1] = '\0';
	}
	catch (...){
		return errLibInvalidParam;
	}
	return 0;
}
//---------------------------------------------------------------------------
int S7API Cli_GetConnected(S7Object Client, int &Connected)
{
    Connected=0;
	if (Client)
    {
		Connected=PSnap7Client(Client)->Connected;
		return 0;
	}
    else
        return errLibInvalidObject;
}
