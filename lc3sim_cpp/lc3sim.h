// Copyright 2020 by Alexei Bezborodov <AlexeiBv@narod.ru>
#pragma once

#include "sim_types.h"

#ifdef TRACE
#   define DEBUG_TRACE printf
#else
#   define DEBUG_TRACE(...)
#endif

namespace LC3_Sim
{

typedef char        Char;
typedef bool        Bool;
typedef unsigned int RegNumType;
typedef unsigned int InstructionIndex;
typedef LC3_Sim::LC3_RegisterType RegType;
typedef LC3_Sim::LC3MemAddressType AddressType;

class IInputOutput
{
public:
    virtual ~IInputOutput();
    
    virtual Char GetChar() const = 0;

    virtual void PutChar(Char a_Word) = 0;

    virtual Bool CheckKeyboard() const = 0;
};

class IVirtualMemory
{
public:
    enum Result
    {
        rSuccess,
        rErrorAddressOutOfRange,
        rErrorAccess,
    };

    virtual ~IVirtualMemory();

    virtual Result Read(RegType* a_Value, AddressType a_Address) const = 0;

    virtual Result Write(RegType a_Value, AddressType a_Address) = 0;
};

class I_RTI_Operation
{
public:
    enum Result
    {
        rSuccess,
        rRTI_Stop,
    };

    virtual ~I_RTI_Operation();

    virtual Result Operation(RegType a_RegValue1, RegType a_RegValue2, RegType a_Value) = 0;
};

// Регистры процессора.
struct Registers
{
    Registers();
    
    enum EFlags
    {
        flagPositive = 0b001,
        flagZero     = 0b010,
        flagNegative = 0b100,
    };
    
    enum RegName
    {
        rnReg_0 = 0,
        rnReg_1,
        rnReg_2,
        rnReg_3,
        rnReg_4,
        rnReg_5,
        rnReg_6,
        rnReg_7,
        rnReg_PC,  // Командный регистр
        rnReg_NumCC, // Номер последнего изменённого регистра
        rnCount,
    };
    
    RegType m_Reg[rnCount];
};

// Параметры конфигурации процессора.
struct ProcessorConfig
{
    ProcessorConfig(AddressType a_ExceptionHandlerAddress, AddressType a_ExceptionInfoAddress, AddressType a_ExceptionMask);
    
    AddressType m_ExceptionHandlerAddress;
    AddressType m_ExceptionInfoAddress;
    RegType     m_ExceptionMask;
    RegType     m_ExceptionCount;    
};

// InstructionExecuter выполняет одну инструкцию
class InstructionExecuter
{
    friend class Processor;
private:
    struct Exception
    {
        enum Type
        {
            // Программа завершилась успешно
            etSuccess          = 0x00,
            etStop             = 0x01,
            etRTI              = 0x02,
            // Ошибки - необходимо запустить exception handler
            etNotImplemented   = 0x10,
            etErrorRead        = 0x20,
            etErrorWrite       = 0x40,
        };
        Type            m_Type;
        AddressType     m_AccessAddress;
        AddressType     m_ExecuteAddress;

        Exception();
        Exception(Type a_Type, AddressType a_ExecuteAddress, AddressType a_AccessAddress);
    };
public:
    InstructionExecuter(Registers* a_Registers, IVirtualMemory* a_VirtualMemory, IInputOutput* a_InputOutput, I_RTI_Operation* a_RTI_Operation);

    Exception ExecuteOneInstruction(RegType a_Instruction);

private:
    Registers*      m_Registers;
    IVirtualMemory* m_VirtualMemory;
    IInputOutput*   m_InputOutput;
    I_RTI_Operation* m_RTI_Operation;
};

// Процессор исполняет серию инструкций, обрабатывает исключения
class Processor
{
public:
    enum LoadResult
    {
        lrSuccess,
        lrFileNotFound,
        lrFileTooLarge,
        lrWriteError,
    };

    enum Result
    {
        rGlobalError,
        rStop,
        rRTI_Stop,
    };

    Processor(Registers* a_Registers, IVirtualMemory* a_VirtualMemory, IInputOutput* a_InputOutput, I_RTI_Operation* a_RTI_Operation, ProcessorConfig* a_ProcessorConfig);
    
    Result Run(InstructionIndex* a_ExecutedInsructionsCount, InstructionIndex a_MaxExecuteInsructCount);

    LoadResult LoadObjFile(const char* a_FileName);

    LoadResult LoadData(const uint8_t* a_Data, uint32_t a_DataLen);
    
private:
    Registers*       m_Registers;
    IVirtualMemory*  m_VirtualMemory;
    IInputOutput*    m_InputOutput;
    I_RTI_Operation* m_RTI_Operation;
    ProcessorConfig* m_ProcessorConfig;
    InstructionExecuter m_Executer;
};

} // namespace LC3_Sim
