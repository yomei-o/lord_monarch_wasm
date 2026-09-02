/* 1000:8a5c */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_8a5c(void)

{
  int in_AX;
  int in_CX;
  undefined2 in_DX;
  byte bVar1;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined4 in_EDI;
  undefined4 uVar2;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_XMM0 [16];
  
  uVar2 = movmskps(in_EDI,in_XMM0);
  *(int *)(unaff_BP + 2) = *(int *)(unaff_BP + 2) + (int)uVar2;
  bVar1 = (char)((uint)in_DX >> 8) << 2 | (byte)in_DX;
  if (in_AX == 1) {
    *(uint *)(in_BX + unaff_SI) = *(uint *)(in_BX + unaff_SI) | CONCAT11(bVar1,(byte)in_DX);
  }
  else if (in_CX == 1) {
    *(byte *)((int)uVar2 + -1) = bVar1;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


