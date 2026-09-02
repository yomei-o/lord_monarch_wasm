/* 1000:6822 */

undefined4 __cdecl16near FUN_1000_6822(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  char extraout_DL;
  undefined2 in_DX;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 in_ZF;
  undefined1 uVar6;
  
  FUN_1000_6c3f();
  FUN_1000_705b();
  do {
    iVar3 = 0x9a;
    uVar6 = in_ZF;
    do {
      FUN_1000_6c08();
      if ((bool)in_CF) goto LAB_1000_6876;
      uVar6 = extraout_DL == -1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    puVar4 = (undefined2 *)0x247d;
    puVar5 = (undefined2 *)&DAT_0000_b98e;
    for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = *puVar1;
    }
    in_CF = false;
    uVar6 = 1;
    for (iVar3 = 0x1f1; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar1 = 0;
    }
    FUN_1000_6aea();
    if (!(bool)in_CF) {
      puVar5 = (undefined2 *)*(undefined2 *)0x3e82;
      puVar4 = (undefined2 *)*(undefined2 *)0x3e86 + 1;
      *(undefined2 *)*(undefined2 *)0x3e86 = 0xfffe;
      *puVar4 = 0xff;
      for (iVar3 = 0x3fe; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
      }
      in_CF = false;
      uVar6 = 1;
      for (iVar3 = 0xc00; iVar3 != 0; iVar3 = iVar3 + -1) {
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar1 = 0;
      }
      FUN_1000_6a55();
      if (!(bool)in_CF) break;
    }
LAB_1000_6876:
    FUN_1000_6cb5();
    in_ZF = 1;
  } while ((bool)uVar6);
  return CONCAT22(in_DX,in_AX);
}


