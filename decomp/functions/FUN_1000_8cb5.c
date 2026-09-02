/* 1000:8cb5 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018d0b) overlaps instruction at (ram,0x00018d0a)
    */

void FUN_1000_8cb5(void)

{
  char cVar1;
  char in_AL;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined1 extraout_AH;
  byte bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint extraout_DX;
  uint *in_BX;
  uint uVar10;
  int unaff_BP;
  byte *pbVar11;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar12;
  bool bVar13;
  byte in_AF;
  
  uVar4 = CONCAT11(in_AL,in_AL);
  *unaff_DI = uVar4;
  unaff_DI[1] = uVar4;
  unaff_DI[2] = uVar4;
  FUN_1000_8dc3();
  uVar4 = FUN_1000_8dc3();
  if ((byte)uVar4 == 0x20) {
    *(undefined1 *)((int)unaff_DI + 5) = 0x30;
  }
  uVar9 = 0;
  uVar10 = (int)in_BX + *in_BX & 0xff00;
  iVar7 = 0x10;
  in_AF = 9 < ((byte)uVar4 & 0xf) | in_AF;
  uVar5 = (uint)(byte)((((char)((uint)uVar4 >> 8) - in_AL) - CARRY2((uint)in_BX,*in_BX)) - in_AF) <<
          8;
  cVar1 = *(char *)0xe2d8;
  *(char *)0xe2d8 = cVar1 + in_AF;
  out(0x46,uVar5);
  if (!SCARRY1(cVar1,in_AF)) {
    FUN_1000_8daf();
    FUN_1000_8daf();
    func_0x0001d7af();
    uVar5 = CONCAT11(extraout_AH,0x5e);
    *(undefined2 *)0x3e9c = 0;
    *(undefined2 *)0x3e9e = 0;
    uVar9 = extraout_DX & 0xff;
    iVar7 = 0x18;
    uVar10 = uVar5;
  }
  do {
    bVar12 = CARRY2(uVar10,uVar10);
    uVar10 = uVar10 * 2;
    bVar13 = CARRY2(uVar9,uVar9) || CARRY2(uVar9 * 2,(uint)bVar12);
    uVar9 = uVar9 * 2 + (uint)bVar12;
    pbVar11 = (byte *)0x3e9f;
    iVar8 = 4;
    do {
      bVar3 = *pbVar11;
      bVar6 = (byte)(uVar5 >> 8);
      bVar2 = bVar3 * '\x02' + bVar13;
      in_AF = 9 < (bVar2 & 0xf) | in_AF;
      bVar13 = 0x99 < bVar2 || (CARRY1(bVar3,bVar3) || CARRY1(bVar3 * '\x02',bVar13));
      bVar3 = bVar2 + in_AF * '\x06' + bVar13 * '`';
      uVar5 = CONCAT11(bVar6,bVar3);
      *pbVar11 = bVar3;
      pbVar11 = pbVar11 + -1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  *(byte *)0x32b0 = bVar3;
  *(byte *)(unaff_BP + 0x3e9b) = *(byte *)(unaff_BP + 0x3e9b) ^ bVar6;
  FUN_1000_8da3();
  FUN_1000_8da3();
  FUN_1000_8da3();
  func_0x0001e1a3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


