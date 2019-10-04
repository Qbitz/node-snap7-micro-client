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
|  C++ Snap 7 classes Implementation                                           |
|                                                                              |
|=============================================================================*/

#include "snap7.h"

//==============================================================================
// CLIENT
//==============================================================================
TS7Client::TS7Client()
{
    Client=Cli_Create();
}
//---------------------------------------------------------------------------
TS7Client::~TS7Client()
{
    Cli_Destroy(&Client);
}
//---------------------------------------------------------------------------
int TS7Client::Connect()
{
    return Cli_Connect(Client);
}
//---------------------------------------------------------------------------
int TS7Client::ConnectTo(const char *RemAddress, int Rack, int Slot)
{
    return Cli_ConnectTo(Client, RemAddress, Rack, Slot);
}
//---------------------------------------------------------------------------
int TS7Client::SetConnectionParams(const char *RemAddress, word LocalTSAP, word RemoteTSAP)
{
    return Cli_SetConnectionParams(Client, RemAddress, LocalTSAP, RemoteTSAP);
}
//---------------------------------------------------------------------------
int TS7Client::SetConnectionType(word ConnectionType)
{
    return Cli_SetConnectionType(Client, ConnectionType);
}
//---------------------------------------------------------------------------
int TS7Client::Disconnect()
{
    return Cli_Disconnect(Client);
}
//---------------------------------------------------------------------------
int TS7Client::GetParam(int ParamNumber, void *pValue)
{
    return Cli_GetParam(Client, ParamNumber, pValue);
}
//---------------------------------------------------------------------------
int TS7Client::SetParam(int ParamNumber, void *pValue)
{
    return Cli_SetParam(Client, ParamNumber, pValue);
}
//---------------------------------------------------------------------------
int TS7Client::ReadArea(int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData)
{
    return Cli_ReadArea(Client, Area, DBNumber, Start, Amount, WordLen, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::WriteArea(int Area, int DBNumber, int Start, int Amount, int WordLen, void *pUsrData)
{
    return Cli_WriteArea(Client, Area, DBNumber, Start, Amount, WordLen, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::ReadMultiVars(PS7DataItem Item, int ItemsCount)
{
    return Cli_ReadMultiVars(Client, Item, ItemsCount);
}
//---------------------------------------------------------------------------
int TS7Client::WriteMultiVars(PS7DataItem Item, int ItemsCount)
{
    return Cli_WriteMultiVars(Client, Item, ItemsCount);
}
//---------------------------------------------------------------------------
int TS7Client::DBRead(int DBNumber, int Start, int Size, void *pUsrData)
{
    return Cli_DBRead(Client, DBNumber, Start, Size, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::DBWrite(int DBNumber, int Start, int Size, void *pUsrData)
{
    return Cli_DBWrite(Client, DBNumber, Start, Size, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::MBRead(int Start, int Size, void *pUsrData)
{
    return Cli_MBRead(Client, Start, Size, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::MBWrite(int Start, int Size, void *pUsrData)
{
    return Cli_MBWrite(Client, Start, Size, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::EBRead(int Start, int Size, void *pUsrData)
{
    return Cli_EBRead(Client, Start, Size, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::EBWrite(int Start, int Size, void *pUsrData)
{
    return Cli_EBWrite(Client, Start, Size, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::ABRead(int Start, int Size, void *pUsrData)
{
    return Cli_ABRead(Client, Start, Size, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::ABWrite(int Start, int Size, void *pUsrData)
{
    return Cli_ABWrite(Client, Start, Size, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::TMRead(int Start, int Amount, void *pUsrData)
{
    return Cli_TMRead(Client, Start, Amount, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::TMWrite(int Start, int Amount, void *pUsrData)
{
    return Cli_TMWrite(Client, Start, Amount, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::CTRead(int Start, int Amount, void *pUsrData)
{
    return Cli_CTRead(Client, Start, Amount, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::CTWrite(int Start, int Amount, void *pUsrData)
{
    return Cli_CTWrite(Client, Start, Amount, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::ListBlocks(PS7BlocksList pUsrData)
{
    return Cli_ListBlocks(Client, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::GetAgBlockInfo(int BlockType, int BlockNum, PS7BlockInfo pUsrData)
{
    return Cli_GetAgBlockInfo(Client, BlockType, BlockNum, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::GetPgBlockInfo(void *pBlock, PS7BlockInfo pUsrData, int Size)
{
    return Cli_GetPgBlockInfo(Client, pBlock, pUsrData, Size);
}
//---------------------------------------------------------------------------
int TS7Client::ListBlocksOfType(int BlockType, TS7BlocksOfType *pUsrData, int *ItemsCount)
{
    return Cli_ListBlocksOfType(Client, BlockType, pUsrData, ItemsCount);
}
//---------------------------------------------------------------------------
int TS7Client::Upload(int BlockType, int BlockNum, void *pUsrData, int *Size)
{
    return Cli_Upload(Client, BlockType, BlockNum, pUsrData, Size);
}
//---------------------------------------------------------------------------
int TS7Client::FullUpload(int BlockType, int BlockNum, void *pUsrData, int *Size)
{
    return Cli_FullUpload(Client, BlockType, BlockNum, pUsrData, Size);
}
//---------------------------------------------------------------------------
int TS7Client::Download(int BlockNum, void *pUsrData, int Size)
{
    return Cli_Download(Client, BlockNum, pUsrData, Size);
}
//---------------------------------------------------------------------------
int TS7Client::Delete(int BlockType, int BlockNum)
{
    return Cli_Delete(Client, BlockType, BlockNum);
}
//---------------------------------------------------------------------------
int TS7Client::DBGet(int DBNumber, void *pUsrData, int *Size)
{
    return Cli_DBGet(Client, DBNumber, pUsrData, Size);
}
//---------------------------------------------------------------------------
int TS7Client::DBFill(int DBNumber, int FillChar)
{
    return Cli_DBFill(Client, DBNumber, FillChar);
}
//---------------------------------------------------------------------------
int TS7Client::GetPlcDateTime(tm *DateTime)
{
    return Cli_GetPlcDateTime(Client, DateTime);
}
//---------------------------------------------------------------------------
int TS7Client::SetPlcDateTime(tm *DateTime)
{
    return Cli_SetPlcDateTime(Client, DateTime);
}
//---------------------------------------------------------------------------
int TS7Client::SetPlcSystemDateTime()
{
    return Cli_SetPlcSystemDateTime(Client);
}
//---------------------------------------------------------------------------
int TS7Client::GetOrderCode(PS7OrderCode pUsrData)
{
    return Cli_GetOrderCode(Client, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::GetCpuInfo(PS7CpuInfo pUsrData)
{
    return Cli_GetCpuInfo(Client, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::GetCpInfo(PS7CpInfo pUsrData)
{
    return Cli_GetCpInfo(Client, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::ReadSZL(int ID, int Index, PS7SZL pUsrData, int *Size)
{
    return Cli_ReadSZL(Client, ID, Index, pUsrData, Size);
}
//---------------------------------------------------------------------------
int TS7Client::ReadSZLList(PS7SZLList pUsrData, int *ItemsCount)
{
    return Cli_ReadSZLList(Client, pUsrData, ItemsCount);
}
//---------------------------------------------------------------------------
int TS7Client::PlcHotStart()
{
    return Cli_PlcHotStart(Client);
}
//---------------------------------------------------------------------------
int TS7Client::PlcColdStart()
{
    return Cli_PlcColdStart(Client);
}
//---------------------------------------------------------------------------
int TS7Client::PlcStop()
{
    return Cli_PlcStop(Client);
}
//---------------------------------------------------------------------------
int TS7Client::CopyRamToRom(int Timeout)
{
    return Cli_CopyRamToRom(Client, Timeout);
}
//---------------------------------------------------------------------------
int TS7Client::Compress(int Timeout)
{
    return Cli_Compress(Client, Timeout);
}
//---------------------------------------------------------------------------
int TS7Client::GetProtection(PS7Protection pUsrData)
{
    return Cli_GetProtection(Client, pUsrData);
}
//---------------------------------------------------------------------------
int TS7Client::SetSessionPassword(char *Password)
{
    return Cli_SetSessionPassword(Client, Password);
}
//---------------------------------------------------------------------------
int TS7Client::ClearSessionPassword()
{
    return Cli_ClearSessionPassword(Client);
}
//---------------------------------------------------------------------------
int TS7Client::ExecTime()
{
    int Time;
    int Result = Cli_GetExecTime(Client, &Time);
    if (Result==0)
        return Time;
    else
        return Result;
}
//---------------------------------------------------------------------------
int TS7Client::LastError()
{
    int LastError;
    int Result =Cli_GetLastError(Client, &LastError);
    if (Result==0)
       return LastError;
    else
       return Result;
}
//---------------------------------------------------------------------------
int TS7Client::PDULength()
{
    int Requested, Negotiated;
    if (Cli_GetPduLength(Client, &Requested, &Negotiated)==0)
        return Negotiated;
    else
        return 0;
}
//---------------------------------------------------------------------------
int TS7Client::PDURequested()
{
    int Requested, Negotiated;
    if (Cli_GetPduLength(Client, &Requested, &Negotiated)==0)
        return Requested;
    else
        return 0;
}
//---------------------------------------------------------------------------
int TS7Client::PlcStatus()
{
    int Status;
    int Result = Cli_GetPlcStatus(Client, &Status);
    if (Result==0)
        return Status;
    else
        return Result;
}
//---------------------------------------------------------------------------
bool TS7Client::Connected()
{
	int ClientStatus;
	if (Cli_GetConnected(Client ,&ClientStatus)==0)
		return ClientStatus!=0;
	else
		return false;
}
//==============================================================================
// Text routines
//==============================================================================
TextString CliErrorText(int Error)
{
    char text[TextLen];
    Cli_ErrorText(Error, text, TextLen);
    return TextString(text);
}
