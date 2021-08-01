#include "../include/8080.h"
int DISASSEMBLE(const unsigned char *BinaryBuffer, int PC)
{
	unsigned char *CurrentOPCode = &BinaryBuffer[ PC ];
	printf("OPCODE: %02x\t", CurrentOPCode[0]);
	/* PCIncrementer serve per capire quanti byte saltare, perchè operazioni come JMP richiedono 2 byte */
	int PCIncrementer = 1;
		switch ( *CurrentOPCode )
		{
			case 0x00:
			case 0x08:
			case 0x10:
			case 0x18:
			case 0x20:
			case 0x28:
			case 0x30:
			case 0x38:
			case 0xcb:
			case 0xd9:
			case 0xdd:
			case 0xed:
			case 0xfd:
				printf("NOP\n");
				break;
			case 0x01:
				printf("LXI\tB, #$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			case 0x02:
				printf("STAX\tB\n");
				
				break;
			case 0x03:
				printf("INX\tB\n");
				
				break;
			case 0x04:
				printf("INR\tB\n");
				
				break;
			
			case 0x05:
				printf("DCR\tB\n");
				
				break;
			
			case 0x06:
				printf("MVI\tB, #$%02x\n", CurrentOPCode[1]);
				
				PCIncrementer = 2;
				break;
			case 0x07:
				printf("RLC\n");
				
				break;
			case 0x09:
				printf("DAD\tB\n");
				
				break;
			
			case 0x0a:
				printf("LDAX\tB\n");
				
				break;
			
			case 0x0b:
				printf("DCX\tB\n");
				break;
			
			case 0x0c:
				printf("INR\tC\n");
				break;
			
			case 0x0d:
				printf("DCR\tC\n");
				break;
			
			case 0x0e:
				printf("MVI\tC, #$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0x0f:
				printf("RRC\n");
				break;
			
			case 0x11:
				printf("LXI\tD, #$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0x12:
				printf("STAX\tD\n");
				break;
			
			case 0x13:
				printf("INX\tD\n");
				break;
			
			case 0x14:
				printf("INR\tD\n");
				break;
			
			case 0x15:
				printf("DCR\tD\n");
				break;
			
			case 0x16:
				printf("MVI\tD, #$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0x17:
				printf("RAL\n");
				break;
			
			case 0x19:
				printf("DAD\tD\n");
				break;
			
			case 0x1a:
				printf("LDAX\tD\n");
				break;
			
			case 0x1b:
				printf("DCX\tD\n");
				break;
			
			case 0x1c:
				printf("INR\tE\n");
				break;
			
			case 0x1d:
				printf("DCR\tE\n");
				break;
			
			case 0x1e:
				printf("MVI\tE, #$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				
				break;
			
			
			case 0x1f:
				printf("RAR\n");
				break;
			
			case 0x21:
				printf("LXI\tH, #$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0x22:
				printf("SHLD\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0x23:
				printf("INX\tH\n");
				break;
			
			case 0x24:
				printf("INR\tH\n");
				break;
			
			case 0x25:
				printf("DCR\tH\n");
				break;
			
			case 0x26:
				printf("MVI\tH, #$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0x27:
				printf("DAA\n");
				break;
			
			case 0x29:
				printf("DAD\tH\n");
				break;
			
			case 0x2a:
				printf("LHDL\t%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0x2b:
				printf("DCX\tH\n");
				break;
			
			case 0x2c:
				printf("INR\tL\n");
				break;
			
			case 0x2d:
				printf("DCR\tL\n");
				break;
			
			case 0x2e:
				printf("MVI\tL, %02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0x2f:
				printf("CMA\n");
				break;
			
			
			case 0x31:
				printf("LXI\tSP, #$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0x32:
				printf("STA\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0x33:
				printf("INX\tSP\n");
				break;
			
			case 0x34:
				printf("INR\tM\n");
				break;
			
			case 0x35:
				printf("DCR\tM\n");
				break;
			
			case 0x36:
				printf("MVI\tM, #$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0x37:
				printf("STC\n");
				break;
			
			case 0x39:
				printf("DAD\tSP\n");
				break;
			
			case 0x3a:
				printf("LDA\t%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0x3b:
				printf("DCX\tSP\n");
				break;
			
			case 0x3c:
				printf("INR\tA\n");
				break;
			
			case 0x3d:
				printf("DCR\tA\n");
				break;
			
			case 0x3e:
				printf("MVI\tA, %02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0x3f:
				printf("CMC\n");
				break;
			case 0x40:
				printf("MOV\tB,B\n");
				break;
			case 0x41:
				printf("MOV\tB,C\n");
				break;
			case 0x42:
				printf("MOV\tB,D\n");
				break;
			case 0x43:
				printf("MOV\tB,E\n");
				break;
			
			case 0x44:
				printf("MOV\tB,H\n");
				break;
			
			case 0x45:
				printf("MOV\tB,L\n");
				break;
			
			case 0x46:
				printf("MOV\tB,M\n");
				break;
			
			case 0x47:
				printf("MOV\tB,A\n");
				break;
			
			case 0x48:
				printf("MOV\tC,B\n");
				break;
			
			case 0x49:
				printf("MOV\tC,C\n");
				break;
			
			case 0x4A:
				printf("MOV\tC,D\n");
				break;
			
			case 0x4B:
				printf("MOV\tC,E\n");
				break;
			
			case 0x4C:
				printf("MOV\tC,H\n");
				break;
			
			case 0x4D:
				printf("MOV\tC,L\n");
				break;
			
			case 0x4E:
				printf("MOV\tC,M\n");
				break;
			
			case 0x4F:
				printf("MOV\tC,A\n");
				break;
			
			
			case 0x50:
				printf("MOV\tD,B\n");
				break;
			case 0x51:
				printf("MOV\tD,C\n");
				break;
			case 0x52:
				printf("MOV\tD,D\n");
				break;
			case 0x53:
				printf("MOV\tD,E\n");
				break;
			
			case 0x54:
				printf("MOV\tD,H\n");
				break;
			
			case 0x55:
				printf("MOV\tD,L\n");
				break;
			
			case 0x56:
				printf("MOV\tD,M\n");
				break;
			
			case 0x57:
				printf("MOV\tE,B\n");
				break;
			
			case 0x58:
				printf("MOV\tE,B\n");
				break;
			
			case 0x59:
				printf("MOV\tE,C\n");
				break;
			
			case 0x5A:
				printf("MOV\te,D\n");
				break;
			
			case 0x5B:
				printf("MOV\tE,E\n");
				break;
			
			case 0x5C:
				printf("MOV\tE,H\n");
				break;
			
			case 0x5D:
				printf("MOV\tE,L\n");
				break;
			
			case 0x5E:
				printf("MOV\tE,M\n");
				break;
			
			case 0x5F:
				printf("MOV\tE,A\n");
				break;
			
			case 0x60:
				printf("MOV\tH,B\n");
				break;
			case 0x61:
				printf("MOV\tH,C\n");
				break;
			case 0x62:
				printf("MOV\tH,D\n");
				break;
			case 0x63:
				printf("MOV\tH,E\n");
				break;
			
			case 0x64:
				printf("MOV\tH,H\n");
				break;
			
			case 0x65:
				printf("MOV\tH,L\n");
				break;
			
			case 0x66:
				printf("MOV\tH,M\n");
				break;
			
			case 0x67:
				printf("MOV\tH,A\n");
				break;
			
			case 0x68:
				printf("MOV\tL,B\n");
				break;
			
			case 0x69:
				printf("MOV\tL,C\n");
				break;
			
			case 0x6A:
				printf("MOV\tL,D\n");
				break;
			
			case 0x6B:
				printf("MOV\tL,E\n");
				break;
			
			case 0x6C:
				printf("MOV\tL,H\n");
				break;
			
			case 0x6D:
				printf("MOV\tL,L\n");
				break;
			
			case 0x6E:
				printf("MOV\tL,M\n");
				break;
			
			case 0x6F:
				printf("MOV\tL,A\n");
				break;
			
			case 0x70:
				printf("MOV\tM,B\n");
				break;
			case 0x71:
				printf("MOV\tM,C\n");
				break;
			case 0x72:
				printf("MOV\tM,D\n");
				break;
			case 0x73:
				printf("MOV\tM,E\n");
				break;
			
			case 0x74:
				printf("MOV\tM,H\n");
				break;
			
			case 0x75:
				printf("MOV\tM,L\n");
				break;
			
			case 0x76:
				printf("HALT\n");
				break;
			
			case 0x77:
				printf("MOV\tM,A\n");
				break;
			
			case 0x78:
				printf("MOV\tA,B\n");
				break;
			
			case 0x79:
				printf("MOV\tA,C\n");
				break;
			
			case 0X7A:
				printf("MOV\tA,D\n");
				break;
			
			case 0x7B:
				printf("MOV\tA,E\n");
				break;
			
			case 0x7C:
				printf("MOV\tA,H\n");
				break;
			
			case 0x7D:
				printf("MOV\tA,L\n");
				break;
			
			case 0x7E:
				printf("MOV\tA,M\n");
				break;
			
			case 0x7F:
				printf("MOV\tA,A\n");
				break;
			
			case 0x80:
				printf("ADD\tB\n");
				break;
			case 0x81:
				printf("ADD\tc\n");
				break;
			case 0x82:
				printf("ADD\tD\n");
				break;
			case 0x83:
				printf("ADD\tE\n");
				break;
			
			case 0x84:
				printf("ADD\tH\n");
				break;
			
			case 0x85:
				printf("ADD\tL\n");
				break;
			
			case 0x86:
				printf("ADD\tM\n");
				break;
			
			case 0x87:
				printf("ADD\tA\n");
				break;
			
			case 0x88:
				printf("ADC\tB\n");
				break;
			
			case 0x89:
				printf("ADC\tC\n");
				break;
			
			case 0X8A:
				printf("ADC\tD\n");
				break;
			
			case 0x8B:
				printf("ADC\tE\n");
				break;
			
			case 0x8C:
				printf("ADC\tH\n");
				break;
			
			case 0x8D:
				printf("ADC\tL\n");
				break;
			
			case 0x8E:
				printf("ADC\tM\n");
				break;
			
			case 0x8F:
				printf("ADC\tA\n");
				break;
			case 0x90:
				printf("SUB\tB\n");
				break;
			case 0x91:
				printf("SUB\tC\n");
				break;
			case 0x92:
				printf("SUB\tD\n");
				break;
			case 0x93:
				printf("SUB\tE\n");
				break;
			
			case 0x94:
				printf("SUB\tH\n");
				break;
			
			case 0x95:
				printf("SUB\tL\n");
				break;
			
			case 0x96:
				printf("SUB\tM\n");
				break;
			
			case 0x97:
				printf("SUB\tA\n");
				break;
			
			case 0x98:
				printf("SBB\tB\n");
				break;
			
			case 0x99:
				printf("SBB\tC\n");
				break;
			
			case 0X9A:
				printf("SBB\tD\n");
				break;
			
			case 0x9B:
				printf("SBB\tE\n");
				break;
			
			case 0x9C:
				printf("SBB\tH\n");
				break;
			
			case 0x9D:
				printf("SBB\tL\n");
				break;
			
			case 0x9E:
				printf("SBB\tM\n");
				break;
			
			case 0x9F:
				printf("SBB\tA\n");
				break;
			
			case 0xa0:
				printf("ANA\tB\n");
				break;
			case 0xa1:
				printf("ANA\tC\n");
				break;
			case 0xa2:
				printf("ANA\tD\n");
				break;
			case 0xa3:
				printf("ANA\tE\n");
				break;
			
			case 0xa4:
				printf("ANA\tH\n");
				break;
			
			case 0xa5:
				printf("ANA\tL\n");
				break;
			
			case 0xa6:
				printf("ANA\tM\n");
				break;
			
			case 0xa7:
				printf("ANA\tA\n");
				break;
			
			case 0xa8:
				printf("XRA\tB\n");
				break;
			
			case 0xa9:
				printf("XRA\tC\n");
				break;
			
			case 0XAA:
				printf("XRA\tD\n");
				break;
			
			case 0xAB:
				printf("XRA\tE\n");
				break;
			
			case 0xAC:
				printf("XRA\tH\n");
				break;
			
			case 0xAD:
				printf("XRA\tL\n");
				break;
			
			case 0xAE:
				printf("XRA\tM\n");
				break;
			
			case 0xAF:
				printf("XRA\tA\n");
				break;
			default:
				printf("ERROR: OPCode %02x doesn't have an instruction\n", CurrentOPCode[0]);
				break;
			
			case 0xB0:
				printf("ORA\tB\n");
				break;
			case 0xB1:
				printf("ORA\tC\n");
				break;
			case 0xB2:
				printf("ORA\tD\n");
				break;
			case 0xB3:
				printf("ORA\tE\n");
				break;
			
			case 0xB4:
				printf("ORA\tH\n");
				break;
			
			case 0xB5:
				printf("ORA\tL\n");
				break;
			
			case 0xB6:
				printf("ORA\tM\n");
				break;
			
			case 0xB7:
				printf("ORA\tA\n");
				break;
			
			case 0xB8:
				printf("CMP\tB\n");
				break;
			
			case 0xB9:
				printf("CMP\tC\n");
				break;
			
			case 0XBA:
				printf("CMP\tD\n");
				break;
			
			case 0xBB:
				printf("CMP\tE\n");
				break;
			
			case 0xBC:
				printf("CMP\tH\n");
				break;
			
			case 0xBD:
				printf("CMP\tL\n");
				break;
			
			case 0xBE:
				printf("CMP\tM\n");
				break;
			
			case 0xBF:
				printf("CMP\tA\n");
				break;
			case 0xC0:
				printf("RNZ\n");
				break;
			case 0xC1:
				printf("POP\tB\n");
				break;
			case 0xC2:
				/* REMEMBER: LITTLE ENDIAN */
				printf("JNZ\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			case 0xC3:
				printf("JMP\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			case 0xC4:
				printf("CNZ\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			case 0xC5:
				printf("PUSH\tB\n");
				break;
			
			case 0xC6:
				printf("ADI\t#$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0xC7:
				printf("RST\t0\n");
				break;
			
			case 0xC8:
				printf("RZ\n");
				break;
			
			case 0xC9:
				printf("RET\n");
				break;
			
			case 0XCA:
				printf("JZ\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0xCC:
				printf("CZ\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0xCD:
				printf("CALL\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0xCE:
				printf("ACI\t#$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0xCF:
				printf("RST\t1\n"); // Call #$8
				break;
			case 0xD0:
				printf("RNC\n");
				break;
			case 0xD1:
				printf("POP\tD\n");
				break;
			case 0xD2:
				printf("JNC\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			case 0xD3:
				printf("OUT\t#$%02x\n",CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0xD4:
				printf("CNC\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0xD5:
				printf("PUSH\tD\n");
				break;
			
			case 0xD6:
				printf("SUI\t#$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0xD7:
				printf("RST\t2\n"); // CALL #$10
				break;
			
			case 0xD8:
				printf("RC\n");
				break;
			
			case 0XDA:
				printf("JC\t#$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			case 0XDB:
				printf("IN\t#$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0xDC:
				printf("CC\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0xDE:
				printf("SBI\t#$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0xDF:
				printf("RST\t3\n"); // Call #$8
				break;
			case 0xE0:
				printf("RPO\n");
				break;
			case 0xE1:
				printf("POP\tH\n");
				break;
			case 0xE2:
				printf("JPO\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			case 0xE3:
				printf("XTHL");
				break;
			
			case 0xE4:
				printf("CPO\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0xE5:
				printf("PUSH\tH\n");
				break;
			
			case 0xE6:
				printf("ANI\t#$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0xE7:
				printf("RST\t4\n"); // CALL #$20
				break;
			
			case 0xE8:
				printf("RPE\n");
				break;
			case 0xE9:
				printf("PCHL\n");
				break;
			
			case 0XEA:
				printf("JPE\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0xEB:
				printf("XCHG\n");
				break;
			
			case 0xEC:
				printf("CPE\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			case 0xEE:
				printf("XRI\t#$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0xEF:
				printf("RST\t5\n"); // Call #28
				break;
			case 0xF0:
				printf("RP\n");
				break;
			case 0xF1:
				printf("POP\tPSW\n");
				break;
			case 0xF2:
				printf("JP\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			case 0xF3:
				printf("DI\n");
				break;
			
			case 0xF4:
				printf("CP\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0xF5:
				printf("PUSH\tPSW\n");
				break;
			
			case 0xF6:
				printf("ORI\t#$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0xF7:
				printf("RST\t6\n"); // CALL #$30
				break;
			
			case 0xF8:
				printf("RM\n");
				break;
			case 0xF9:
				printf("SPHL\n");
				break;
			
			case 0XFA:
				printf("JM\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0xFC:
				printf("CM\t#$%02x%02x\n", CurrentOPCode[2], CurrentOPCode[1]);
				PCIncrementer = 3;
				break;
			
			case 0xFB:
				printf("EI");
				break;
			
			case 0xFE:
				printf("CPI\t#$%02x\n", CurrentOPCode[1]);
				PCIncrementer = 2;
				break;
			
			case 0xFF:
				printf("RST\t7\n"); // Call #38
				break;
		}
		return PCIncrementer;
}
