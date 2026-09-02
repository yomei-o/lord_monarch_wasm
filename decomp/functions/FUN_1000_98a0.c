/* 1000:98a0 */

undefined4 __cdecl16near FUN_1000_98a0(void)

{
  undefined2 uVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint uVar9;
  undefined2 in_AX;
  byte bVar10;
  uint uVar11;
  undefined2 in_DX;
  int unaff_SI;
  byte *pbVar12;
  undefined1 *unaff_DI;
  undefined1 *puVar13;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int local_18;
  
  uVar9 = *(uint *)(unaff_SI + 4);
  local_18 = *(int *)(unaff_SI + 6);
  uVar1 = *(undefined2 *)(unaff_SI + 2);
  pbVar12 = (byte *)*(undefined2 *)0xc560;
  out(0x7c,0xc0);
  uVar11 = uVar9;
  puVar13 = unaff_DI;
  do {
    do {
      uVar4 = ((undefined *)&DAT_0000_cf74)[*pbVar12];
      out(0x7e,((undefined *)&DAT_0000_ce74)[*pbVar12]);
      uVar5 = ((undefined *)&DAT_0000_cf74)[pbVar12[1]];
      out(0x7e,((undefined *)&DAT_0000_ce74)[pbVar12[1]]);
      uVar6 = ((undefined *)&DAT_0000_cf74)[pbVar12[2]];
      out(0x7e,((undefined *)&DAT_0000_ce74)[pbVar12[2]]);
      pbVar2 = pbVar12 + 4;
      uVar7 = ((undefined *)&DAT_0000_cf74)[pbVar12[3]];
      out(0x7e,((undefined *)&DAT_0000_ce74)[pbVar12[3]]);
      pbVar12 = pbVar12 + 5;
      bVar10 = *pbVar2;
      uVar8 = ((undefined *)&DAT_0000_ce74)[bVar10];
      unaff_DI[0x50] = uVar8;
      puVar3 = unaff_DI + 1;
      *unaff_DI = uVar8;
      out(0x7e,uVar4);
      out(0x7e,uVar5);
      out(0x7e,uVar6);
      out(0x7e,uVar7);
      uVar4 = ((undefined *)&DAT_0000_cf74)[bVar10];
      unaff_DI[0x51] = uVar4;
      unaff_DI = unaff_DI + 2;
      *puVar3 = uVar4;
      bVar10 = (char)uVar11 - 1;
      uVar11 = (uint)bVar10;
    } while (bVar10 != 0);
    unaff_DI = puVar13 + 0xa0;
    local_18 = local_18 + -1;
    uVar11 = uVar9;
    puVar13 = unaff_DI;
  } while (local_18 != 0);
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}


