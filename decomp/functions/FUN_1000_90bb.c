/* 1000:90bb */

/* WARNING: Instruction at (ram,0x00019117) overlaps instruction at (ram,0x00019116)
    */

undefined2 FUN_1000_90bb(void)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar4;
  undefined2 in_AX;
  byte bVar7;
  uint uVar5;
  undefined2 uVar6;
  char cVar8;
  int in_CX;
  byte bVar9;
  byte extraout_DL;
  undefined2 in_DX;
  undefined2 extraout_DX;
  int in_BX;
  int iVar10;
  int iVar11;
  uint unaff_BP;
  byte *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar12;
  char cVar13;
  byte bVar3;
  
  *(int *)(in_BX + -0x77) = *(int *)(in_BX + -0x77) + 1;
  cVar12 = 0x7c < (byte)in_AX;
  *unaff_SI = 0xe2;
  if (!SCARRY1((byte)in_AX,-0x7d)) {
    bVar4 = *(byte *)0x25d0;
    unaff_SI[unaff_BP + 0x50] = unaff_SI[unaff_BP + 0x50] + (char)((uint)in_BX >> 8);
    if (bVar4 == 0) goto LAB_1000_90dd;
    in_DX = 0xa0;
    if (bVar4 < 2) goto LAB_1000_90dd;
    while( true ) {
      in_DX = 0xf0;
LAB_1000_90dd:
      *(undefined2 *)(unaff_SI + 2) = in_DX;
      pbVar1 = unaff_SI + in_BX;
      cVar12 = *pbVar1 < (byte)in_DX;
      *pbVar1 = *pbVar1 - (byte)in_DX;
      in_CX = in_CX + -1;
      if (in_CX == 0 || *pbVar1 != 0) break;
      unaff_SI[unaff_BP] = unaff_SI[unaff_BP] + (char)((uint)in_AX >> 8);
      unaff_SI[10] = 0;
    }
    in_CX = 0x146;
    unaff_SI = (byte *)0x27f;
    FUN_1000_434e();
    in_DX = extraout_DX;
  }
  iVar10 = 0x5549;
  bVar7 = unaff_SI[0x5549] + 1 + cVar12;
  pbVar1 = unaff_SI + unaff_BP;
  bVar4 = *pbVar1;
  bVar9 = (byte)in_DX;
  *pbVar1 = *pbVar1 + bVar9;
  pbVar1 = unaff_SI;
  bVar2 = *pbVar1;
  bVar3 = *pbVar1;
  *pbVar1 = bVar3 + 7 + CARRY1(bVar4,bVar9);
  *unaff_SI = *unaff_SI + 0x12 + (0xf8 < bVar2 || CARRY1(bVar3 + 7,CARRY1(bVar4,bVar9)));
  if (SCARRY1(bVar7,*unaff_SI)) {
    unaff_SI[0x5549] = unaff_SI[0x5549] + (char)((uint)in_DX >> 8) + CARRY1(bVar7,*unaff_SI);
  }
  else {
    FUN_1000_4fc5();
    uVar6 = *(undefined2 *)(unaff_SI + 7);
    iVar11 = iVar10;
    do {
      FUN_1000_3cc4(uVar6);
      pbVar1 = unaff_SI;
      unaff_SI = unaff_SI + 2;
    } while (*(int *)pbVar1 != -1);
    *(undefined2 *)0x32e0 = 0;
    iVar10 = (uint)(byte)((char)((uint)iVar11 >> 8) + *(char *)(iVar11 + 0x2e14)) << 8;
    func_0x00018dd1(iVar11);
    func_0x00018d36();
    *(byte *)0x24cb = *(byte *)0x24cb & extraout_DL;
    uVar5 = FUN_1000_8ef0();
    cVar12 = (char)((uint)in_CX >> 8);
    if ((uVar5 & 0x60) != 0) {
      cVar13 = CARRY2(uVar5 & 0xff60,unaff_BP);
      goto code_r0x00019157;
    }
  }
  *(byte *)(unaff_BP + 0x24fb) = *(byte *)(unaff_BP + 0x24fb) ^ (byte)((uint)iVar10 >> 8);
  func_0x00018d52();
  do {
    bVar4 = FUN_1000_8ef0();
    cVar12 = (char)((uint)in_CX >> 8);
    cVar13 = false;
  } while ((bVar4 & 0x60) == 0);
code_r0x00019157:
  func_0x0001d3ee();
  FUN_1000_5d19();
  uVar6 = FUN_1000_8d16();
  cVar8 = (char)((uint)uVar6 >> 8);
  *(char *)(unaff_BP + 2) = *(char *)(unaff_BP + 2) + cVar8 + cVar13;
  return CONCAT11(cVar8,(char)uVar6 + cVar12);
}


