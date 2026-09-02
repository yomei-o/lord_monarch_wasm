/* 1000:8cd0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018d0b) overlaps instruction at (ram,0x00018d0a)
    */

void FUN_1000_8cd0(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined2 in_AX;
  uint uVar4;
  undefined1 extraout_AH;
  byte bVar5;
  undefined2 in_CX;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint extraout_DX;
  uint in_BX;
  uint uVar9;
  int unaff_BP;
  byte *pbVar10;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  bool bVar11;
  bool bVar12;
  byte in_AF;
  byte bVar13;
  
  uVar8 = 0;
  uVar9 = in_BX & 0xff00;
  iVar6 = 0x10;
  bVar13 = 9 < ((byte)in_AX & 0xf) | in_AF;
  uVar4 = (uint)(byte)((((char)((uint)in_AX >> 8) - (char)((uint)in_CX >> 8)) - in_CF) - bVar13) <<
          8;
  cVar1 = *(char *)0xe2d8;
  *(char *)0xe2d8 = cVar1 + bVar13;
  out(0x46,uVar4);
  if (!SCARRY1(cVar1,bVar13)) {
    FUN_1000_8daf();
    FUN_1000_8daf();
    func_0x0001d7af();
    uVar4 = CONCAT11(extraout_AH,0x5e);
    *(undefined2 *)0x3e9c = 0;
    *(undefined2 *)0x3e9e = 0;
    uVar8 = extraout_DX & 0xff;
    iVar6 = 0x18;
    uVar9 = uVar4;
  }
  do {
    bVar11 = CARRY2(uVar9,uVar9);
    uVar9 = uVar9 * 2;
    bVar12 = CARRY2(uVar8,uVar8) || CARRY2(uVar8 * 2,(uint)bVar11);
    uVar8 = uVar8 * 2 + (uint)bVar11;
    pbVar10 = (byte *)0x3e9f;
    iVar7 = 4;
    do {
      bVar3 = *pbVar10;
      bVar5 = (byte)(uVar4 >> 8);
      bVar2 = bVar3 * '\x02' + bVar12;
      bVar13 = 9 < (bVar2 & 0xf) | bVar13;
      bVar12 = 0x99 < bVar2 || (CARRY1(bVar3,bVar3) || CARRY1(bVar3 * '\x02',bVar12));
      bVar3 = bVar2 + bVar13 * '\x06' + bVar12 * '`';
      uVar4 = CONCAT11(bVar5,bVar3);
      *pbVar10 = bVar3;
      pbVar10 = pbVar10 + -1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(byte *)0x32b0 = bVar3;
  *(byte *)(unaff_BP + 0x3e9b) = *(byte *)(unaff_BP + 0x3e9b) ^ bVar5;
  FUN_1000_8da3(0xff9a);
  FUN_1000_8da3();
  FUN_1000_8da3();
  func_0x0001e1a3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


