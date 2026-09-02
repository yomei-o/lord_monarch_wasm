/* 1000:8a1a */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018a21) overlaps instruction at (ram,0x00018a20)
    */

void FUN_1000_8a1a(void)

{
  char *pcVar1;
  uint uVar2;
  undefined2 in_AX;
  uint uVar3;
  uint uVar4;
  byte in_DL;
  byte bVar5;
  byte bVar6;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int iVar7;
  undefined4 in_EDI;
  undefined4 uVar8;
  undefined2 unaff_ES;
  int unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_XMM0 [16];
  
  bVar5 = in_DL & 3;
  if (bVar5 != 0) {
    iVar7 = (int)in_EDI + 1;
    uVar3 = CONCAT11((byte)((uint)in_AX >> 8) | *(byte *)(in_BX + unaff_SI),(char)in_AX);
    *(undefined1 *)(unaff_BP + unaff_SI) = *(undefined1 *)(unaff_BP + unaff_SI);
    uVar2 = *(uint *)(in_BX + -0x60);
    uVar4 = uVar3;
    bVar6 = bVar5;
    if (uVar2 < uVar3) {
      bVar6 = 2;
      uVar4 = uVar2;
    }
    pcVar1 = (char *)(*(int *)(in_BX + 0xffe) + iVar7);
    *pcVar1 = *pcVar1 + (char)uVar4 + (uVar3 < uVar2);
    pcVar1 = (char *)(*(int *)(in_BX + 0x60) + 0x60);
    *pcVar1 = *pcVar1 + (char)((uint)in_BX >> 8);
    uVar8 = movmskps(CONCAT22((int)((ulong)in_EDI >> 0x10),iVar7),in_XMM0);
    *(int *)(unaff_CS + 2) = *(int *)(unaff_CS + 2) + (int)uVar8;
    if (uVar4 == 0) {
      *(uint *)(in_BX + -2) = *(uint *)(in_BX + -2) | CONCAT11(bVar6,bVar6);
    }
    else if (bVar5 == 1) {
      *(byte *)((int)uVar8 + -1) = bVar6;
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


