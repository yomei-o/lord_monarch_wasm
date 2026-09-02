/* 1000:87a0 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_87a0(void)

{
  char *pcVar1;
  byte bVar2;
  uint in_AX;
  byte bVar3;
  int in_CX;
  int iVar4;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  undefined1 auStack_16 [16];
  
  iVar4 = in_CX + -1;
  if (SBORROW2(in_CX,1)) {
    *(byte *)(unaff_BP + (int)unaff_SI) = *(byte *)(unaff_BP + (int)unaff_SI) ^ (byte)in_AX;
    in_BX = 0x2000;
    unaff_ES = 0x2000;
    unaff_SI = (undefined2 *)0x0;
    iVar4 = 0x900;
    in_DX = 0x808;
  }
  else {
    *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) | (byte)iVar4;
  }
  do {
    bVar2 = (byte)in_AX;
    bVar3 = *(char *)(unaff_SI + -0x16c1) - (char)((uint)in_DX >> 8);
    in_AX = CONCAT11(bVar3,bVar2);
    if ((bVar3 < (byte)in_DX) && (in_AX = CONCAT11(bVar3,bVar2) & 0x3ff, bVar2 != (bVar3 & 3))) {
      *unaff_SI = 0xffff;
    }
    bVar5 = (undefined2 *)0xfffd < unaff_SI;
    unaff_SI = unaff_SI + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  pcVar1 = (char *)(CONCAT11((char)((uint)in_BX >> 8),3) + 2);
  *pcVar1 = (*pcVar1 - (char)(in_AX >> 8)) - bVar5;
  *(undefined2 *)0x32bb = 0xffff;
  *(undefined1 **)0xc4ec = auStack_16;
  *(undefined2 *)0xc4ea = unaff_SS;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


