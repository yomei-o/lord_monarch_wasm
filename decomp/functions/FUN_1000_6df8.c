/* 1000:6df8 */

undefined2 __cdecl16near FUN_1000_6df8(void)

{
  undefined2 in_AX;
  int iVar1;
  undefined2 unaff_DS;
  undefined1 in_CF;
  undefined1 uVar2;
  
  iVar1 = FUN_1000_6e3a();
  if (!(bool)in_CF) {
    uVar2 = iVar1 != -1;
    if (iVar1 != -1) {
      FUN_1000_6f1f(iVar1);
      do {
        iVar1 = FUN_1000_6e3a();
        if ((bool)uVar2) {
          return in_AX;
        }
        FUN_1000_6f1f();
        uVar2 = iVar1 != -1;
      } while (iVar1 != -1);
    }
    iVar1 = *(int *)0x3e94;
    *(undefined2 *)(iVar1 + 0x1c) = 0;
    *(undefined2 *)(iVar1 + 0x1e) = 0;
  }
  return in_AX;
}


