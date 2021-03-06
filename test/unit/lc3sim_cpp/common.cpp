#include "../gtest/gtest.h"
#include "common.h"

LC3_Sim::Char TestIO::GetChar() const
{
    LC3_Sim::Char ret = getchar();
    DEBUG_TRACE("GetChar %c\n", ret);
    return ret;
}

void TestIO::PutChar(LC3_Sim::Char a_Word)
{
    DEBUG_TRACE("PutChar %c\n", a_Word);
    putchar(a_Word);
    fflush(stdout);
}

LC3_Sim::Bool TestIO::CheckKeyboard() const
{
    static fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    return select(1, &read_fds, NULL, NULL, &timeout) ? true : false;
}

TestVM::TestVM()
{
    m_Memory.resize(60000);
}

LC3_Sim::IVirtualMemory::Result TestVM::Read(LC3_Sim::RegType* a_Value, LC3_Sim::AddressType a_Address) const
{
    if (a_Address > m_Memory.size())
        return rErrorAddressOutOfRange;
    
    *a_Value = m_Memory[a_Address];
    return rSuccess;
}

LC3_Sim::IVirtualMemory::Result TestVM::Write(LC3_Sim::RegType a_Value, LC3_Sim::AddressType a_Address)
{
    if (a_Address > m_Memory.size())
        return rErrorAddressOutOfRange;
    
    m_Memory[a_Address] = a_Value;
    return rSuccess;
}

TestOp::TestOp()
{
    m_RegValue1 = 0;
    m_RegValue2 = 0;
    m_Value = 0;
    m_Result = rSuccess;
}

LC3_Sim::I_RTI_Operation::Result TestOp::Operation(LC3_Sim::RegType a_RegValue1, LC3_Sim::RegType a_RegValue2, LC3_Sim::RegType a_Value)
{
    m_RegValue1 = a_RegValue1;
    m_RegValue2 = a_RegValue2;
    m_Value = a_Value;
    return m_Result;
}
