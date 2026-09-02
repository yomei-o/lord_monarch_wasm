/* 1000:633b */

undefined4 __cdecl16near FUN_1000_633b(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined1 in_CF;
  
  FUN_1000_6c3f();
  FUN_1000_687e();
  if (!(bool)in_CF) {
    unaff_DI = (undefined2 *)&DAT_0000_cc00;
    FUN_1000_68bb();
    if (!(bool)in_CF) goto LAB_1000_6363;
  }
  for (iVar2 = 0x13a; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *puVar1 = 0;
  }
LAB_1000_6363:
  FUN_1000_acbb();
  return CONCAT22(in_DX,in_AX);
}


