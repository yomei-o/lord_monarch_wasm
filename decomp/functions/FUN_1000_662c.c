/* 1000:662c */

undefined4 __cdecl16near FUN_1000_662c(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 *puVar3;
  undefined2 unaff_ES;
  undefined1 in_CF;
  undefined1 in_ZF;
  undefined1 uVar4;
  
  do {
    uVar4 = in_ZF;
    FUN_1000_6c3f();
    FUN_1000_69df();
    if (!(bool)in_CF) goto LAB_1000_663f;
    FUN_1000_6cb5();
    in_ZF = 1;
  } while ((bool)uVar4);
  goto LAB_1000_665e;
  while( true ) {
    FUN_1000_687e();
    if (!(bool)in_CF) {
      FUN_1000_6f4b();
      FUN_1000_68a0();
      if (!(bool)in_CF) goto LAB_1000_6668;
    }
    FUN_1000_6cb5();
    if (!(bool)uVar4) break;
LAB_1000_663f:
    FUN_1000_6d3a();
    if ((bool)in_CF) break;
  }
LAB_1000_665e:
  puVar3 = (undefined2 *)&DAT_0000_fa3e;
  for (iVar2 = 0x1a0; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0;
  }
LAB_1000_6668:
  return CONCAT22(in_DX,in_AX);
}


