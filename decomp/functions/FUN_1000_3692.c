/* 1000:3692 */

void FUN_1000_3692(void)

{
  byte *pbVar1;
  byte in_AL;
  byte bVar2;
  char cVar3;
  byte bVar4;
  int in_BX;
  int iVar5;
  int unaff_BP;
  int unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar6;
  undefined4 uVar7;
  
  bVar2 = in_AL & *(byte *)(unaff_BP + unaff_SI);
  pbVar1 = (byte *)(unaff_BP + unaff_SI + 0x22);
  bVar4 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar2;
  *unaff_DI = bVar2;
  cVar6 = 0x99 < bVar2 || CARRY1(bVar4,bVar2);
  cVar3 = FUN_1000_8f5c();
  in(0x22);
  iVar5 = CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + *(char *)(in_BX + unaff_SI + 0x293e));
  uVar7 = func_0x0001e104(cVar3 + *(char *)(unaff_BP + unaff_SI + 4) + cVar6 ^
                          *(byte *)(unaff_BP + unaff_SI));
  bVar4 = ((byte)uVar7 | 0x55) - 0x20;
  if (0xf < bVar4) {
    *(undefined2 *)(unaff_DI + 1 + (iVar5 - (int)((ulong)uVar7 >> 0x10)) + 0x12a7) = unaff_SS;
    return;
  }
  *(uint *)(unaff_DI + 1) = CONCAT11((char)((ulong)uVar7 >> 8),bVar4);
  unaff_DI[3] = bVar4;
  FUN_1000_8f07();
  return;
}


