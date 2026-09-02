/* 1000:5c30 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00015c4e) overlaps instruction at (ram,0x00015c4c)
    */

void FUN_1000_5c30(void)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  undefined2 in_AX;
  int in_CX;
  int iVar4;
  undefined2 in_DX;
  int in_BX;
  char *unaff_SI;
  int unaff_DI;
  undefined2 unaff_DS;
  bool bVar5;
  undefined2 uStack_b14;
  int iStack_b12;
  
  pcVar1 = unaff_SI + in_BX;
  *pcVar1 = *pcVar1 + (char)in_AX;
  bVar5 = *pcVar1 == '\0';
  do {
    if (bVar5) {
      pcVar1 = (char *)(in_BX + unaff_DI + 0x10);
      *pcVar1 = *pcVar1 + '\x18';
      in_AX = CONCAT11((char)((uint)uStack_b14 >> 8) + '\x01',(char)uStack_b14);
      in_CX = iStack_b12;
    }
    do {
      if (in_CX == 1) {
        iVar4 = 0x1000;
        out(0x10,in_AX);
        bVar2 = (byte)((uint)in_AX >> 8);
        bVar3 = in(in_DX);
        while ((((bVar3 & 2) == 0 && ((bVar3 & 1) == 0)) && (iVar4 = iVar4 + -1, iVar4 != 0))) {
          bVar3 = (byte)((uint)in_BX >> 8);
          in_BX = (uint)(byte)(bVar3 + bVar2) << 8;
          *unaff_SI = *unaff_SI + (char)((uint)in_DX >> 8) + CARRY1(bVar3,bVar2);
          bVar3 = in(0xec);
        }
        out(0x467,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      out(0xec,1);
      bVar2 = in(0xec);
      in_AX = CONCAT11(1,bVar2 & 2);
      in_CX = iRam00080000;
    } while ((bVar2 & 2) == 0);
    in_CX = iRam00080000 + -0x6928;
    bVar5 = true;
    iRam00080000 = in_CX;
  } while( true );
}


