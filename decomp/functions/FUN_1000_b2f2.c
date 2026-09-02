/* 1000:b2f2 */

undefined4 __cdecl16near FUN_1000_b2f2(void)

{
  uint uVar1;
  undefined2 in_AX;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 in_DX;
  int iVar6;
  uint *puVar7;
  undefined2 unaff_DS;
  bool bVar8;
  char cVar9;
  
  bVar8 = false;
  puVar7 = (uint *)0xc792;
  iVar6 = 0;
  iVar5 = 4;
  do {
    if ((*puVar7 & 0xc) == 0xc) {
      iVar6 = iVar6 + 1;
    }
    puVar7 = puVar7 + 0xb;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (iVar6 != 3) {
    return CONCAT22(in_DX,in_AX);
  }
  FUN_1000_0ccc();
  *(undefined2 *)&DAT_0000_3bc6 = 1;
  FUN_1000_5f7e();
  FUN_1000_0ceb();
  puVar7 = (uint *)0xc792;
  iVar5 = 4;
  do {
    if ((*puVar7 & 8) == 0) break;
    puVar7 = puVar7 + 0xb;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = 4 - iVar5;
  *(undefined2 *)0xc538 = *(undefined2 *)((undefined *)&DAT_0000_12ad + iVar5 * 2);
  uVar2 = FUN_1000_bc99();
  cVar9 = (char)iVar5;
  *(uint *)0xc53e = uVar2;
  if (uVar2 == 0) {
    *(undefined2 *)0xc53a = 0;
    uVar2 = 0;
    uVar4 = 0;
  }
  else {
    uVar3 = FUN_1000_bcce();
    *(uint *)0xc53a = uVar3;
    uVar2 = (uint)(((ulong)uVar3 * 1000) / (ulong)uVar2);
    uVar4 = CONCAT11((char)(uVar2 % 10),(char)(uVar2 / 10));
  }
  *(undefined2 *)0xc53c = uVar4;
  uVar2 = (uint)(((ulong)*(uint *)0x3bca * (ulong)uVar2) / 1000);
  *(uint *)0xc4f0 = uVar2;
  if ((cVar9 == *(char *)0x3c00) && (uVar3 = *(uint *)0x3bc2, uVar3 < 0x34)) {
    *(undefined2 *)0xc540 = 0;
    iVar5 = 0;
    iVar6 = uVar3 * 0xc;
    if (iVar6 != 0) {
      iVar5 = *(int *)((undefined *)&DAT_0000_cbfa + iVar6);
    }
    iVar5 = uVar2 - iVar5;
    if (iVar5 < 0) {
      *(undefined2 *)0xc540 = 1;
      iVar5 = -iVar5;
    }
    *(int *)0xc542 = iVar5;
    *(int *)0xc544 = *(int *)0xc4f0 - *(int *)((undefined *)&DAT_0000_cc06 + iVar6);
    if ((*(uint *)((undefined *)&DAT_0000_cc06 + iVar6) < uVar2) && (*(int *)0xc4f0 != 0)) {
      uVar2 = *(uint *)0x3bc2;
      uVar1 = *(uint *)0xce70;
      if (uVar1 <= uVar2) {
        *(int *)0xce70 = *(int *)0xce70 + 1;
      }
      bVar8 = uVar1 > uVar2;
      ((undefined2 *)&DAT_0000_cc00)[uVar3 * 6] = *(undefined2 *)0x3bcc;
      *(undefined2 *)((undefined *)&DAT_0000_cc04 + iVar6) = *(undefined2 *)0x3bca;
      ((undefined2 *)&DAT_0000_cc02)[uVar3 * 6] = *(undefined2 *)0xc53c;
      FUN_1000_acbb();
    }
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    if (bVar8) {
      FUN_1000_4a4d();
    }
    FUN_1000_0d0a();
    uVar4 = FUN_1000_72ad();
    FUN_1000_0d12(uVar4);
    FUN_1000_c90f();
    *(undefined2 *)0x3bd6 = 0xffff;
    if (*(int *)0x3bc2 == 0x33) {
      *(undefined2 *)0xce70 = 0x33;
      FUN_1000_b661();
      FUN_1000_ca4a();
    }
    else {
      FUN_1000_b58f();
      bVar8 = *(int *)0x3bc2 + 1U < *(uint *)0xce70;
      if ((*(int *)0x3bc2 + 1U == *(uint *)0xce70) && (FUN_1000_6315(), !bVar8)) {
        FUN_1000_c5f4();
        FUN_1000_04b8();
      }
    }
  }
  else {
    FUN_1000_7c9e();
    FUN_1000_4a4d();
    FUN_1000_0d0a();
    uVar4 = FUN_1000_72ad();
    FUN_1000_0d12(uVar4);
    FUN_1000_c90f();
    *(undefined2 *)0x3bd6 = 0xffff;
  }
  return CONCAT22(in_DX,in_AX);
}


