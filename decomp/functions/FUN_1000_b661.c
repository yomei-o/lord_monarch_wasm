/* 1000:b661 */

undefined4 __cdecl16near FUN_1000_b661(undefined2 param_1)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  undefined2 in_AX;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined2 unaff_DS;
  undefined1 uVar8;
  
  iVar6 = *(int *)0xce70 + 1;
  uVar4 = 0;
  puVar7 = (undefined2 *)&DAT_0000_cc00;
  do {
    if (uVar4 < (uint)puVar7[3]) {
      uVar4 = puVar7[3];
    }
    puVar7 = puVar7 + 6;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_1000_c492();
  if ((byte)((char *)s_0000000000_0000_32b0)[5] < 0x31) {
    bVar2 = ((char *)s_0000000000_0000_32b0)[6] - 0x30;
  }
  else {
    bVar2 = ((char *)s_0000000000_0000_32b0)[5] - 0x27;
  }
  *(uint *)0xce72 = (uint)bVar2;
  FUN_1000_0ccc();
  *(undefined2 *)&DAT_0000_3bc6 = 3;
  FUN_1000_5f7e();
  FUN_1000_0ceb();
  iVar6 = 0x3e70;
  pcVar1 = (code *)swi(0x1c);
  (*pcVar1)();
  bVar2 = FUN_1000_6fc4();
  bVar3 = bVar2 + 0xa8;
  if (bVar2 < 0x58) {
    bVar3 = bVar2 + 0xc;
  }
  uVar4 = (uint)bVar3;
  if (0x1f < uVar4) {
    uVar4 = 0x20;
  }
  *(uint *)0xc54e = uVar4;
  uVar8 = (*(byte *)(iVar6 + 1) >> 3 & 1) != 0;
  uVar5 = FUN_1000_6fc4();
  *(undefined2 *)0xc550 = uVar5;
  uVar5 = FUN_1000_6fc4();
  *(undefined2 *)0xc552 = uVar5;
  FUN_1000_7c9e();
  FUN_1000_5e57();
  if ((bool)uVar8) {
    FUN_1000_4a4d();
    FUN_1000_8738();
  }
  else {
    FUN_1000_4a81();
    *(undefined2 *)0x32a8 = 0xf;
    FUN_1000_4ae5();
    *(undefined2 *)0x32a8 = 0x70f;
    FUN_1000_8738();
  }
  FUN_1000_0d0a();
  FUN_1000_72ad();
  FUN_1000_c90f();
  return CONCAT22(in_AX,param_1);
}


