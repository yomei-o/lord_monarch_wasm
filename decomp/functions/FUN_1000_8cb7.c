/* 1000:8cb7 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018d0b) overlaps instruction at (ram,0x00018d0a)
    */

void FUN_1000_8cb7(void)

{
  byte bVar1;
  byte bVar2;
  undefined2 in_AX;
  undefined2 uVar3;
  uint uVar4;
  undefined1 extraout_AH;
  byte bVar5;
  char cVar8;
  int iVar6;
  int iVar7;
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
  
  *unaff_DI = in_AX;
  unaff_DI[1] = in_AX;
  unaff_DI[2] = in_AX;
  cVar8 = (char)in_AX;
  FUN_1000_8dc3();
  uVar3 = FUN_1000_8dc3();
  if ((byte)uVar3 == 0x20) {
    *(undefined1 *)((int)unaff_DI + 5) = 0x30;
  }
  uVar9 = 0;
  uVar10 = (int)in_BX + *in_BX & 0xff00;
  iVar6 = 0x10;
  in_AF = 9 < ((byte)uVar3 & 0xf) | in_AF;
  uVar4 = (uint)(byte)((((char)((uint)uVar3 >> 8) - cVar8) - CARRY2((uint)in_BX,*in_BX)) - in_AF) <<
          8;
  cVar8 = *(char *)0xe2d8;
  *(char *)0xe2d8 = cVar8 + in_AF;
  out(0x46,uVar4);
  if (!SCARRY1(cVar8,in_AF)) {
    FUN_1000_8daf();
    FUN_1000_8daf();
    func_0x0001d7af();
    uVar4 = CONCAT11(extraout_AH,0x5e);
    *(undefined2 *)0x3e9c = 0;
    *(undefined2 *)0x3e9e = 0;
    uVar9 = extraout_DX & 0xff;
    iVar6 = 0x18;
    uVar10 = uVar4;
  }
  do {
    bVar12 = CARRY2(uVar10,uVar10);
    uVar10 = uVar10 * 2;
    bVar13 = CARRY2(uVar9,uVar9) || CARRY2(uVar9 * 2,(uint)bVar12);
    uVar9 = uVar9 * 2 + (uint)bVar12;
    pbVar11 = (byte *)0x3e9f;
    iVar7 = 4;
    do {
      bVar2 = *pbVar11;
      bVar5 = (byte)(uVar4 >> 8);
      bVar1 = bVar2 * '\x02' + bVar13;
      in_AF = 9 < (bVar1 & 0xf) | in_AF;
      bVar13 = 0x99 < bVar1 || (CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar13));
      bVar2 = bVar1 + in_AF * '\x06' + bVar13 * '`';
      uVar4 = CONCAT11(bVar5,bVar2);
      *pbVar11 = bVar2;
      pbVar11 = pbVar11 + -1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(byte *)0x32b0 = bVar2;
  *(byte *)(unaff_BP + 0x3e9b) = *(byte *)(unaff_BP + 0x3e9b) ^ bVar5;
  FUN_1000_8da3();
  FUN_1000_8da3();
  FUN_1000_8da3();
  func_0x0001e1a3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


