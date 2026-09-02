/* 1000:68bb */

undefined4 __cdecl16near FUN_1000_68bb(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  uint in_CX;
  uint uVar3;
  uint uVar4;
  undefined2 in_DX;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  bool bVar7;
  undefined4 uVar8;
  
  puVar6 = (undefined2 *)*(undefined2 *)0x3e8e;
  uVar5 = *(uint *)0x3e90;
  do {
    if (uVar5 == 0) {
      bVar7 = *(int *)0x3e8a != -1;
      if ((*(int *)0x3e8a == -1) || (FUN_1000_6fda(), bVar7)) goto LAB_1000_6911;
      uVar8 = FUN_1000_6e3a();
      in_CX = (uint)((ulong)uVar8 >> 0x10);
      *(undefined2 *)0x3e8a = (int)uVar8;
      if (bVar7) goto LAB_1000_6911;
      puVar6 = (undefined2 *)&DAT_0000_b98e;
      uVar5 = 0x400;
    }
    uVar3 = in_CX;
    if (uVar5 < in_CX) {
      uVar3 = uVar5;
    }
    in_CX = in_CX - uVar3;
    uVar5 = uVar5 - uVar3;
    uVar4 = uVar3 >> 1;
    if (uVar4 != 0) {
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        puVar2 = unaff_DI;
        unaff_DI = unaff_DI + 1;
        puVar1 = puVar6;
        puVar6 = puVar6 + 1;
        *puVar2 = *puVar1;
      }
    }
    if ((uVar3 & 1) != 0) {
      puVar2 = unaff_DI;
      unaff_DI = (undefined2 *)((int)unaff_DI + 1);
      puVar1 = puVar6;
      puVar6 = (undefined2 *)((int)puVar6 + 1);
      *(undefined1 *)puVar2 = *(undefined1 *)puVar1;
    }
  } while (in_CX != 0);
  *(undefined2 *)0x3e8e = puVar6;
  *(uint *)0x3e90 = uVar5;
LAB_1000_6911:
  return CONCAT22(in_DX,in_AX);
}


