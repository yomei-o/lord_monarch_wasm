/* 1000:8cec */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_8cec(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 extraout_AH;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint extraout_DX;
  uint uVar7;
  uint uVar8;
  int unaff_BP;
  byte *pbVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  bool bVar11;
  byte in_AF;
  
  FUN_1000_5079();
  FUN_1000_8daf();
  FUN_1000_8daf();
  func_0x0001d7af();
  uVar3 = CONCAT11(extraout_AH,0x5e);
  *(undefined2 *)0x3e9c = 0;
  *(undefined2 *)0x3e9e = 0;
  uVar7 = extraout_DX & 0xff;
  iVar5 = 0x18;
  uVar8 = uVar3;
  do {
    bVar10 = CARRY2(uVar8,uVar8);
    uVar8 = uVar8 * 2;
    bVar11 = CARRY2(uVar7,uVar7) || CARRY2(uVar7 * 2,(uint)bVar10);
    uVar7 = uVar7 * 2 + (uint)bVar10;
    pbVar9 = (byte *)0x3e9f;
    iVar6 = 4;
    do {
      bVar2 = *pbVar9;
      bVar4 = (byte)(uVar3 >> 8);
      bVar1 = bVar2 * '\x02' + bVar11;
      in_AF = 9 < (bVar1 & 0xf) | in_AF;
      bVar11 = 0x99 < bVar1 || (CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar11));
      bVar2 = bVar1 + in_AF * '\x06' + bVar11 * '`';
      uVar3 = CONCAT11(bVar4,bVar2);
      *pbVar9 = bVar2;
      pbVar9 = pbVar9 + -1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(byte *)0x32b0 = bVar2;
  *(byte *)(unaff_BP + 0x3e9c) = *(byte *)(unaff_BP + 0x3e9c) ^ bVar4;
  FUN_1000_8da3();
  FUN_1000_8da3();
  FUN_1000_8da3();
  func_0x0001e1a3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


