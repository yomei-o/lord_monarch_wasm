/* 1000:5bfc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00015c4e) overlaps instruction at (ram,0x00015c4c)
    */

void FUN_1000_5bfc(void)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 in_DX;
  undefined2 extraout_DX;
  int in_BX;
  char *unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined2 uStack_b16;
  int iStack_b14;
  
  unaff_SI[-0x4f80] = unaff_SI[-0x4f80] + (char)((uint)in_DX >> 8);
  pcVar1 = (char *)(in_BX + unaff_DI + 0x10);
  *pcVar1 = *pcVar1 + (char)((uint)in_BX >> 8);
  FUN_1000_5cc3();
  do {
    out(0xec,1);
    bVar2 = in(0xec);
    uVar4 = CONCAT11(1,bVar2 & 2);
    iVar5 = iRam00080000;
    if ((bVar2 & 2) != 0) {
      iRam00080000 = iRam00080000 + -0x6928;
      pcVar1 = (char *)(in_BX + unaff_DI + 0x10);
      *pcVar1 = *pcVar1 + '\x18';
      uVar4 = CONCAT11((char)((uint)uStack_b16 >> 8) + '\x01',(char)uStack_b16);
      iVar5 = iStack_b14;
    }
  } while (iVar5 != 1);
  iVar5 = 0x1000;
  out(0x10,uVar4);
  bVar2 = (byte)((uint)uVar4 >> 8);
  bVar3 = in(extraout_DX);
  while ((((bVar3 & 2) == 0 && ((bVar3 & 1) == 0)) && (iVar5 = iVar5 + -1, iVar5 != 0))) {
    bVar3 = (byte)((uint)in_BX >> 8);
    in_BX = (uint)(byte)(bVar3 + bVar2) << 8;
    *unaff_SI = *unaff_SI + (char)((uint)extraout_DX >> 8) + CARRY1(bVar3,bVar2);
    bVar3 = in(0xec);
  }
  out(0x467,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


