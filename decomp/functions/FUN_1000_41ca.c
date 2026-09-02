/* 1000:41ca */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00014244) overlaps instruction at (ram,0x00014243)
    */

void FUN_1000_41ca(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  char cVar4;
  byte bVar5;
  undefined1 extraout_AH;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte bVar10;
  int iVar9;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined2 uVar11;
  undefined2 extraout_DX_00;
  int in_BX;
  int unaff_BP;
  undefined2 unaff_SI;
  undefined2 *unaff_DI;
  char *pcVar12;
  int iVar13;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uStackY_17;
  undefined1 uStackY_16;
  
  iVar9 = CONCAT11((char)((uint)in_BX >> 8) + *(char *)((int)unaff_DI + in_BX + 0x15),(char)in_BX);
  uVar11 = in(in_DX);
  *unaff_DI = uVar11;
  pcVar12 = (char *)(*(int *)(unaff_BP + -2) + 0xa03);
  FUN_1000_66a0();
  FUN_1000_669c();
  uVar11 = CONCAT11((char)((uint)extraout_DX >> 8),(byte)extraout_DX ^ *(byte *)(iVar9 + 0xd74));
  cVar4 = *pcVar12;
  uVar7 = CONCAT11(extraout_AH,cVar4) * 4;
  bVar5 = cVar4 * '\b';
  bVar10 = (byte)((uint)unaff_SI >> 8);
  bVar8 = (char)unaff_SI + *(char *)(unaff_BP + 0xd74) + CARRY2(uVar7,uVar7);
  *(byte *)(iVar9 + 0xd74) = *(byte *)(iVar9 + 0xd74) & (byte)((uint)iVar9 >> 8);
  iVar13 = (int)pcVar12 * 0x50 + 0xa0f;
  if (iVar13 != *(int *)0x328e) {
                    /* WARNING: Call to offcut address within same function */
    func_0x00014227(0xd74,unaff_SI);
    *(int *)0x328e = iVar13;
    cVar4 = func_0x00017883();
    bVar5 = cVar4 + 1;
    *(uint *)0xe806 = ~*(uint *)0xe806;
    uVar11 = extraout_DX_00;
  }
  bVar1 = *(byte *)(iVar9 + 0xd74);
  pbVar3 = (byte *)*(int *)0x558e;
  uStackY_16 = (undefined1)uVar11;
  bVar2 = *(byte *)0xb80d;
  *pbVar3 = bVar5;
  uStackY_17 = (undefined1)((uint)unaff_ES >> 8);
  uVar6 = CONCAT11(uStackY_16,uStackY_17) + 1;
  iVar9 = CONCAT11(bVar10,(bVar8 & bVar1 & bVar2) + *(char *)(iVar9 + 0xd73) +
                          ((bVar5 | bVar10) < 0x20));
  uVar7 = uVar6;
  while( true ) {
    iVar9 = iVar9 + -1;
    if (iVar9 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((uVar7 & 2) == 0) break;
    if (0x2ff < uVar7) {
      halt_baddata();
    }
    bVar5 = (char)(uVar7 >> 8) + 1;
    uVar7 = CONCAT11(bVar5,(char)uVar7);
    if ((char)(uVar6 >> 8) != '\0') {
      out(uVar11,uVar7);
      pbVar3[1] = bVar5;
    }
  }
  halt_baddata();
}


