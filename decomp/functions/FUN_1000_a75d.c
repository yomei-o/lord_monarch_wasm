/* 1000:a75d */

void __cdecl16near FUN_1000_a75d(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 unaff_DS;
  bool bVar6;
  
  if (3 < *(byte *)0x3c00) {
    return;
  }
  iVar1 = *(int *)((undefined *)&DAT_0000_12ef + (uint)*(byte *)0x3c00 * 2);
  iVar5 = -0x386e;
  iVar3 = 4;
  uVar4 = 0;
  uVar2 = 0;
  do {
    if (iVar1 != iVar5) {
      bVar6 = CARRY2(uVar2,*(uint *)(iVar5 + 8));
      uVar2 = uVar2 + *(uint *)(iVar5 + 8);
      uVar4 = uVar4 + *(int *)(iVar5 + 10) + (uint)bVar6;
    }
    iVar5 = iVar5 + 0x16;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (*(uint *)(iVar1 + 10) < uVar4) {
LAB_1000_a7b2:
    if ((*(uint *)&DAT_0000_3bc6 & 1) != 0) {
      *(uint *)&DAT_0000_3bc6 = *(uint *)&DAT_0000_3bc6 & 0xfffe;
      FUN_1000_0ccc();
      FUN_1000_5f7e();
      FUN_1000_0ceb();
    }
  }
  else {
    if (*(uint *)(iVar1 + 10) <= uVar4) {
      if (*(uint *)(iVar1 + 8) < uVar2) goto LAB_1000_a7b2;
      if (*(uint *)(iVar1 + 8) <= uVar2) {
        return;
      }
    }
    uVar4 = ((uVar4 * 2 + (uint)CARRY2(uVar2,uVar2)) * 2 + (uint)CARRY2(uVar2 * 2,uVar2 * 2)) * 2 +
            (uint)CARRY2(uVar2 * 4,uVar2 * 4);
    if (((uVar4 < *(uint *)(iVar1 + 10)) ||
        ((uVar4 <= *(uint *)(iVar1 + 10) && (uVar2 * 8 < *(uint *)(iVar1 + 8))))) &&
       ((*(uint *)&DAT_0000_3bc6 & 1) == 0)) {
      *(uint *)&DAT_0000_3bc6 = *(uint *)&DAT_0000_3bc6 | 1;
      FUN_1000_0ccc();
      FUN_1000_5f7e();
      FUN_1000_0ceb();
    }
  }
  return;
}


