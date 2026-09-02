/* 1000:68a0 */

undefined2 __cdecl16near FUN_1000_68a0(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  uint in_CX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar8;
  undefined1 in_ZF;
  undefined4 uVar9;
  
  uVar3 = FUN_1000_6f55();
  if ((bool)in_ZF) {
    FUN_1000_6f4b();
    FUN_1000_68bb();
    if ((bool)in_CF) {
      return uVar3;
    }
    uVar3 = FUN_1000_c33e();
    return uVar3;
  }
  puVar7 = (undefined2 *)*(undefined2 *)0x3e8e;
  uVar6 = *(uint *)0x3e90;
  do {
    if (uVar6 == 0) {
      bVar8 = *(int *)0x3e8a != -1;
      if (*(int *)0x3e8a == -1) {
        return uVar3;
      }
      FUN_1000_6fda();
      if (bVar8) {
        return uVar3;
      }
      uVar9 = FUN_1000_6e3a();
      in_CX = (uint)((ulong)uVar9 >> 0x10);
      *(undefined2 *)0x3e8a = (int)uVar9;
      if (bVar8) {
        return uVar3;
      }
      puVar7 = (undefined2 *)&DAT_0000_b98e;
      uVar6 = 0x400;
    }
    uVar4 = in_CX;
    if (uVar6 < in_CX) {
      uVar4 = uVar6;
    }
    in_CX = in_CX - uVar4;
    uVar6 = uVar6 - uVar4;
    uVar5 = uVar4 >> 1;
    if (uVar5 != 0) {
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        puVar2 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar1 = puVar7;
        puVar7 = puVar7 + 1;
        *puVar2 = *puVar1;
      }
    }
    if ((uVar4 & 1) != 0) {
      puVar2 = unaff_DI;
      unaff_DI = (undefined2 *)((int)unaff_DI + 1);
      puVar1 = puVar7;
      puVar7 = (undefined2 *)((int)puVar7 + 1);
      *(undefined1 *)puVar2 = *(undefined1 *)puVar1;
    }
    if (in_CX == 0) {
      *(undefined2 *)0x3e8e = puVar7;
      *(uint *)0x3e90 = uVar6;
      return uVar3;
    }
  } while( true );
}


