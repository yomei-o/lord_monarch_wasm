/* 1000:2132 */

/* WARNING: Instruction at (ram,0x00012135) overlaps instruction at (ram,0x00012134)
    */
/* WARNING: Unable to track spacebase fully for stack */

undefined2 FUN_1000_2132(void)

{
  byte *pbVar1;
  uint *puVar2;
  code *pcVar3;
  char cVar4;
  char extraout_AL;
  char cVar5;
  byte bVar8;
  byte extraout_AH;
  uint in_AX;
  uint uVar7;
  uint in_CX;
  undefined2 extraout_DX;
  undefined2 in_DX;
  int *unaff_BP;
  uint *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  byte bVar6;
  
  do {
    uVar7 = in_AX & 0xff6f;
    if ((in_AX & 0x6f) != 0) {
      while( true ) {
        bVar9 = uVar7 < 0xc4b;
        bVar6 = (byte)(uVar7 - 0xc4b);
        bVar8 = bVar6 - 0x18;
        cVar5 = bVar8 + bVar9;
        uVar7 = CONCAT11((char)(uVar7 - 0xc4b >> 8),cVar5);
        if (0x17 < bVar6 || CARRY1(bVar8,bVar9)) break;
        if ((POPCOUNT(cVar5) & 1U) == 0) {
          LOCK();
          pbVar1 = (byte *)((int)unaff_SI + *unaff_BP + 0x72);
          bVar8 = *pbVar1;
          *pbVar1 = (byte)((uint)in_DX >> 8);
          UNLOCK();
          *unaff_SI = *unaff_SI >> ((byte)in_CX & 0x1f);
          out((byte)*unaff_SI,CONCAT11(bVar8,(char)in_DX));
          return unaff_BP[1];
        }
        out(in_DX,cVar5);
      }
      unaff_SI[-0xc] = unaff_SI[-0xc] | in_CX;
    }
    cVar4 = (char)uVar7;
    *(char *)0x2ee8 = cVar4;
    *(char *)0x2ce5 = cVar4;
    bVar8 = (byte)(uVar7 >> 8);
    cVar5 = cVar4 + '~';
    pcVar3 = (code *)swi(4);
    if (SCARRY1(cVar4 + 't','\n')) {
      (*pcVar3)(unaff_SI);
      in_DX = extraout_DX;
      cVar5 = extraout_AL;
      bVar8 = extraout_AH;
    }
    in_AX = CONCAT11(bVar8 ^ (byte)*unaff_SI,cVar5);
    puVar2 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    out(*puVar2,in_DX);
  } while( true );
}


