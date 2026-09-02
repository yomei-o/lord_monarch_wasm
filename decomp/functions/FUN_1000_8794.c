/* 1000:8794 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_8794(void)

{
  char *pcVar1;
  byte bVar2;
  int in_AX;
  uint uVar3;
  byte bVar4;
  int in_CX;
  int iVar5;
  byte bVar6;
  undefined2 in_DX;
  char cVar7;
  int in_BX;
  int unaff_BP;
  undefined2 *unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  bool bVar8;
  undefined1 auStack_28 [16];
  
  *(char *)(unaff_BP + (int)unaff_SI) = *(char *)(unaff_BP + (int)unaff_SI) + (byte)in_AX + in_CF;
  cVar7 = (char)((uint)in_DX >> 8);
  bVar6 = (char)in_DX + *(char *)(unaff_BP + unaff_DI);
  *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) ^ (byte)in_AX;
  uVar3 = in_AX + 1;
  iVar5 = in_CX + -4;
  if (SBORROW2(in_CX + -3,1)) {
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) ^ (byte)uVar3;
    in_BX = 0x2000;
    unaff_ES = 0x2000;
    unaff_SI = (undefined2 *)0x0;
    iVar5 = 0x900;
    bVar6 = 8;
    cVar7 = '\b';
  }
  else {
    *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) | (byte)iVar5;
  }
  do {
    bVar2 = (byte)uVar3;
    bVar4 = *(char *)(unaff_SI + -0x16c1) - cVar7;
    uVar3 = CONCAT11(bVar4,bVar2);
    if ((bVar4 < bVar6) && (uVar3 = CONCAT11(bVar4,bVar2) & 0x3ff, bVar2 != (bVar4 & 3))) {
      *unaff_SI = 0xffff;
    }
    bVar8 = (undefined2 *)0xfffd < unaff_SI;
    unaff_SI = unaff_SI + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  pcVar1 = (char *)(CONCAT11((char)((uint)in_BX >> 8),3) + 2);
  *pcVar1 = (*pcVar1 - (char)(uVar3 >> 8)) - bVar8;
  *(undefined2 *)0x32bb = 0xffff;
  *(undefined1 **)0xc4ec = auStack_28;
  *(undefined2 *)0xc4ea = unaff_SS;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


