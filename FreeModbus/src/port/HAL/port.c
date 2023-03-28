#include "mb.h"
#include "mbport.h"

#define REG_INPUT_SIZE 10
uint16_t REG_INPUT_BUF[REG_INPUT_SIZE];

#define REG_HOLD_SIZE 10
uint16_t REG_HOLD_BUF[REG_HOLD_SIZE] = { 0x1111, 0x2222, 0x3333, 0x4444, 0x5555, 0x6666, 0x7777, 0x8888, 0x9999, 0xFFFF };

#define REG_COILS_SIZE 10
uint8_t REG_COILS_BUF[REG_COILS_SIZE] ;

#define REG_DISC_SIZE 10
uint8_t REG_DISC_BUF[REG_DISC_SIZE];

eMBErrorCode eMBRegInputCB(UCHAR* pucRegBuffer, USHORT usAddress, USHORT usNRegs)
{
    USHORT usRegIndex = usAddress - 1;

    if ((usRegIndex + usNRegs) > REG_INPUT_SIZE) {
        return MB_ENOREG;
    }

    // 循环读取
    while (usNRegs > 0) {
        *pucRegBuffer++ = (unsigned char)(REG_INPUT_BUF[usRegIndex] >> 8);
        *pucRegBuffer++ = (unsigned char)(REG_INPUT_BUF[usRegIndex] & 0xFF);
        usRegIndex++;
        usNRegs--;
    }

    for (usRegIndex = 0; usRegIndex < REG_INPUT_SIZE; usRegIndex++) {
        REG_INPUT_BUF[usRegIndex]++;
    }

    return MB_ENOERR;
}

eMBErrorCode eMBRegHoldingCB(UCHAR* pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode)
{
    USHORT usRegIndex = usAddress - 1;

    if ((usRegIndex + usNRegs) > REG_HOLD_SIZE) {
        return MB_ENOREG;
    }

    if (eMode == MB_REG_WRITE) {
        while (usNRegs > 0) {
            REG_HOLD_BUF[usRegIndex] = (pucRegBuffer[0] << 8) | pucRegBuffer[1];
            pucRegBuffer += 2;
            usRegIndex++;
            usNRegs--;
        }
    }
    
    else {
        while (usNRegs > 0) {
            *pucRegBuffer++ = (unsigned char)(REG_HOLD_BUF[usRegIndex] >> 8);
            *pucRegBuffer++ = (unsigned char)(REG_HOLD_BUF[usRegIndex] & 0xFF);
            usRegIndex++;
            usNRegs--;
        }
    }

    return MB_ENOERR;
}

eMBErrorCode eMBRegCoilsCB(UCHAR* pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode)
{
    USHORT usRegIndex = usAddress - 1;
    UCHAR ucBits = 0;
    UCHAR ucState = 0;
    UCHAR ucLoops = 0;

    if ((usRegIndex + usNCoils) > REG_COILS_SIZE) {
        return MB_ENOREG;
    }

    if (eMode == MB_REG_WRITE) {
        ucLoops = (usNCoils - 1) / 8 + 1;
        while (ucLoops != 0) {
            ucState = *pucRegBuffer++;
            ucBits = 0;
            while (usNCoils != 0 && ucBits < 8) {
                REG_COILS_BUF[usRegIndex++] = (ucState >> ucBits) & 0X01;
                usNCoils--;
                ucBits++;
            }
            ucLoops--;
        }
    } else {
        ucLoops = (usNCoils - 1) / 8 + 1;
        while (ucLoops != 0) {
            ucState = 0;
            ucBits = 0;
            while (usNCoils != 0 && ucBits < 8) {
                if (REG_COILS_BUF[usRegIndex]) {
                    ucState |= (1 << ucBits);
                }
                usNCoils--;
                usRegIndex++;
                ucBits++;
            }
            *pucRegBuffer++ = ucState;
            ucLoops--;
        }
    }

    return MB_ENOERR;
}

eMBErrorCode eMBRegDiscreteCB(UCHAR* pucRegBuffer, USHORT usAddress, USHORT usNDiscrete)
{
    USHORT usRegIndex = usAddress - 1;
    UCHAR ucBits = 0;
    UCHAR ucState = 0;
    UCHAR ucLoops = 0;

    if ((usRegIndex + usNDiscrete) > REG_DISC_SIZE) {
        return MB_ENOREG;
    }

    ucLoops = (usNDiscrete - 1) / 8 + 1;
    while (ucLoops != 0) {
        ucState = 0;
        ucBits = 0;
        while (usNDiscrete != 0 && ucBits < 8) {
            if (REG_DISC_BUF[usRegIndex]) {
                ucState |= (1 << ucBits);
            }
            usNDiscrete--;
            usRegIndex++;
            ucBits++;
        }
        *pucRegBuffer++ = ucState;
        ucLoops--;
    }

    for (usRegIndex = 0; usRegIndex < REG_DISC_SIZE; usRegIndex++) {
        REG_DISC_BUF[usRegIndex] = !REG_DISC_BUF[usRegIndex];
    }

    return MB_ENOERR;
}
