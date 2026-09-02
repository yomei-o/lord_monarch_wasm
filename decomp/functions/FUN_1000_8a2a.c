/* 1000:8a2a */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_8a2a(void)

{
  char *pcVar1;
  uint uVar2;
  undefined2 in_AX;
  uint uVar3;
  uint uVar4;
  int in_CX;
  undefined2 in_DX;
  byte bVar5;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined4 in_EDI;
  undefined4 uVar6;
  undefined2 unaff_ES;
  int unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_XMM0 [16];
  
  uVar3 = CONCAT11((byte)((uint)in_AX >> 8) | *(byte *)(in_BX + unaff_SI),(char)in_AX);
  bVar5 = (byte)((uint)in_DX >> 8);
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) ^ bVar5;
  uVar2 = *(uint *)(in_BX + -0x60);
  uVar4 = uVar3;
  if (uVar2 < uVar3) {
    in_DX = CONCAT11(bVar5,2);
    uVar4 = uVar2;
  }
  pcVar1 = (char *)(*(int *)(in_BX + 0xffe) + (int)in_EDI);
  *pcVar1 = *pcVar1 + (char)uVar4 + (uVar3 < uVar2);
  pcVar1 = (char *)(*(int *)(in_BX + 0x60) + 0x60);
  *pcVar1 = *pcVar1 + (char)((uint)in_BX >> 8);
  uVar6 = movmskps(in_EDI,in_XMM0);
  *(int *)(unaff_CS + 2) = *(int *)(unaff_CS + 2) + (int)uVar6;
  bVar5 = (char)((uint)in_DX >> 8) << 2 | (byte)in_DX;
  if (uVar4 == 0) {
    *(uint *)(in_BX + -2) = *(uint *)(in_BX + -2) | CONCAT11(bVar5,(byte)in_DX);
  }
  else if (in_CX == 1) {
    *(byte *)((int)uVar6 + -1) = bVar5;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


