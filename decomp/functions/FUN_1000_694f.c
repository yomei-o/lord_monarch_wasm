/* 1000:694f */

undefined4 __cdecl16near FUN_1000_694f(void)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  undefined2 in_AX;
  uint in_CX;
  uint uVar4;
  undefined2 in_DX;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  undefined1 *unaff_DI;
  undefined2 unaff_DS;
  bool bVar8;
  undefined4 uVar9;
  
  if (in_CX != 0) {
    puVar7 = (undefined *)*(undefined2 *)0x3e8e;
    uVar6 = *(uint *)0x3e90;
    uVar5 = in_CX;
    do {
      if (uVar6 == 0) {
        bVar8 = *(int *)0x3e8a != -1;
        if ((*(int *)0x3e8a == -1) || (FUN_1000_6aaa(), bVar8)) goto LAB_1000_69c0;
        uVar9 = FUN_1000_6e3a();
        uVar5 = (uint)((ulong)uVar9 >> 0x10);
        *(int *)0x3e8a = (int)uVar9;
        if (bVar8) goto LAB_1000_69c0;
        if ((int)uVar9 == -1) {
          uVar9 = FUN_1000_6e73();
          uVar5 = (uint)((ulong)uVar9 >> 0x10);
          *(undefined2 *)0x3e8a = (int)uVar9;
        }
        puVar7 = (undefined *)&DAT_0000_b98e;
        uVar6 = 0x400;
      }
      uVar4 = uVar5;
      if (uVar6 < uVar5) {
        uVar4 = uVar6;
      }
      uVar5 = uVar5 - uVar4;
      uVar6 = uVar6 - uVar4;
      do {
        *puVar7 = *unaff_DI;
        puVar7 = puVar7 + 1;
        unaff_DI = unaff_DI + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    } while (uVar5 != 0);
    *(undefined2 *)0x3e8e = puVar7;
    *(uint *)0x3e90 = uVar6;
    iVar3 = *(int *)0x3e94;
    puVar1 = (uint *)(iVar3 + 0x1c);
    uVar6 = *puVar1;
    *puVar1 = *puVar1 + in_CX;
    piVar2 = (int *)(iVar3 + 0x1e);
    *piVar2 = *piVar2 + (uint)CARRY2(uVar6,in_CX);
  }
LAB_1000_69c0:
  return CONCAT22(in_DX,in_AX);
}


