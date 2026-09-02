/* 1000:5c14 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00015c4e) overlaps instruction at (ram,0x00015c4c)
    */

void FUN_1000_5c14(void)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  undefined2 in_AX;
  undefined1 uVar5;
  uint uVar4;
  undefined2 in_CX;
  int iVar6;
  undefined2 in_DX;
  int in_BX;
  char *unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined2 uStack_b12;
  undefined2 uStack_b10;
  
  while( true ) {
    uVar5 = (undefined1)((uint)in_AX >> 8);
    out(0xec,uVar5);
    bVar2 = in(0xec);
    uVar4 = CONCAT11(uVar5,bVar2) & 0xff02;
    iVar6 = *(int *)0x0;
    if ((bVar2 & 2) != 0) {
      iVar6 = *(int *)0x0 + -0x6928;
      *(int *)0x0 = iVar6;
      if (iVar6 == *(int *)0x0) {
        pcVar1 = (char *)(in_BX + unaff_DI + 0x10);
        *pcVar1 = *pcVar1 + '\x18';
        uVar4 = CONCAT11((char)((uint)uStack_b12 >> 8) + '\x01',(char)uStack_b12);
        iVar6 = uStack_b10;
      }
    }
    if (iVar6 == 1) break;
    in_AX = 0x100;
    in_CX = 0x8000;
  }
  iVar6 = 0x1000;
  out(0x10,uVar4);
  bVar2 = (byte)(uVar4 >> 8);
  bVar3 = in(in_DX);
  while ((((bVar3 & 2) == 0 && ((bVar3 & 1) == 0)) && (iVar6 = iVar6 + -1, iVar6 != 0))) {
    bVar3 = (byte)((uint)in_BX >> 8);
    in_BX = (uint)(byte)(bVar3 + bVar2) << 8;
    *unaff_SI = *unaff_SI + (char)((uint)in_DX >> 8) + CARRY1(bVar3,bVar2);
    bVar3 = in(0xec);
  }
  out(0x467,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


