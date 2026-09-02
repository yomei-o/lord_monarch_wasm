/* 1000:879d */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_879d(void)

{
  char *pcVar1;
  byte bVar2;
  int in_AX;
  uint uVar3;
  byte bVar4;
  int in_CX;
  int iVar5;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar6;
  undefined1 auStack_16 [16];
  
  *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) ^ (byte)in_AX;
  uVar3 = in_AX + 1;
  iVar5 = in_CX + -1;
  if (SBORROW2(in_CX,1)) {
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) ^ (byte)uVar3;
    in_BX = 0x2000;
    unaff_ES = 0x2000;
    unaff_SI = (undefined2 *)0x0;
    iVar5 = 0x900;
    in_DX = 0x808;
  }
  else {
    *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) | (byte)iVar5;
  }
  do {
    bVar2 = (byte)uVar3;
    bVar4 = *(char *)(unaff_SI + -0x16c1) - (char)((uint)in_DX >> 8);
    uVar3 = CONCAT11(bVar4,bVar2);
    if ((bVar4 < (byte)in_DX) && (uVar3 = CONCAT11(bVar4,bVar2) & 0x3ff, bVar2 != (bVar4 & 3))) {
      *unaff_SI = 0xffff;
    }
    bVar6 = (undefined2 *)0xfffd < unaff_SI;
    unaff_SI = unaff_SI + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  pcVar1 = (char *)(CONCAT11((char)((uint)in_BX >> 8),3) + 2);
  *pcVar1 = (*pcVar1 - (char)(uVar3 >> 8)) - bVar6;
  *(undefined2 *)0x32bb = 0xffff;
  *(undefined1 **)0xc4ec = auStack_16;
  *(undefined2 *)0xc4ea = unaff_SS;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


