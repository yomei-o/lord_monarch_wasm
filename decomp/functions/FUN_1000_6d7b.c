/* 1000:6d7b */

undefined4 __cdecl16near FUN_1000_6d7b(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined2 in_AX;
  undefined2 uVar3;
  undefined2 in_CX;
  int iVar4;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined1 *puVar5;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_6ecd();
  if (!(bool)in_CF) {
    uVar3 = FUN_1000_6efd();
    if (!(bool)in_CF) {
      *(undefined2 *)0x3e94 = unaff_DI;
      *(undefined2 *)0x3e8a = uVar3;
      *(undefined2 *)(unaff_DI + 0x1a) = uVar3;
      unaff_DI[0xb] = 0x20;
      FUN_1000_6f1f();
      *(undefined2 *)(unaff_DI + 0x1c) = 0;
      *(undefined2 *)(unaff_DI + 0x1e) = 0;
      FUN_1000_6f65();
      *(undefined2 *)(unaff_DI + 0x18) = extraout_DX;
      *(undefined2 *)(unaff_DI + 0x16) = in_CX;
      puVar5 = (undefined1 *)*(undefined2 *)0x3e8c;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        puVar2 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar2 = *puVar1;
      }
      *unaff_DI = 0x20;
      for (iVar4 = 10; unaff_DI = unaff_DI + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
        *unaff_DI = 0;
      }
    }
  }
  return CONCAT22(in_DX,in_AX);
}


