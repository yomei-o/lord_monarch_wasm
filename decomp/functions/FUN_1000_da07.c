/* 1000:da07 */

void __cdecl16near FUN_1000_da07(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 extraout_DX;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  uVar3 = *(undefined2 *)0x2f83;
  puVar5 = (undefined2 *)0x261b;
  puVar6 = (undefined2 *)&DAT_0000_3e20;
  for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = *puVar1;
  }
  FUN_1000_5efe();
  iVar4 = 4;
  do {
    FUN_1000_9859();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_1000_5efe();
  iVar4 = 3;
  do {
    FUN_1000_9859();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_1000_74c6();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_c612();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_c72e();
  FUN_1000_72c1();
  FUN_1000_9aae();
  iVar4 = 200;
  *(undefined2 *)0x2f83 = 1;
  do {
    FUN_1000_9aa6();
    *(undefined1 *)0x32d3 = 1;
    *(undefined2 *)0xc560 = extraout_DX;
    FUN_1000_98a0();
    FUN_1000_c72e();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_1000_9aa6();
  FUN_1000_c6fa();
  *(undefined2 *)0xc560 = 0;
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_72a7();
  FUN_1000_98a0();
  FUN_1000_98a0();
  FUN_1000_72c1();
  FUN_1000_9aae();
  FUN_1000_c5f4();
  FUN_1000_c6b3();
  FUN_1000_74c6();
  FUN_1000_72c1();
  FUN_1000_72a7();
  *(undefined2 *)0x2f83 = uVar3;
  return;
}


