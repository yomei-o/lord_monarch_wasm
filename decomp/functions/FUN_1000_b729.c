/* 1000:b729 */

undefined4 __cdecl16near FUN_1000_b729(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  int iVar3;
  undefined2 in_DX;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_DS;
  
  puVar4 = (undefined2 *)0x0;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0xffff;
  }
  iVar2 = 0x17;
  do {
    *puVar4 = 0xffff;
    for (iVar3 = 0x2e; puVar5 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0x4000;
      puVar4 = puVar5;
    }
    *puVar5 = 0xffff;
    puVar4[2] = 0xffff;
    iVar3 = 0x17;
    puVar4 = puVar4 + 3;
    do {
      puVar5 = puVar4;
      *puVar5 = 0x4000;
      puVar5[1] = 0xffff;
      iVar3 = iVar3 + -1;
      puVar4 = puVar5 + 2;
    } while (iVar3 != 0);
    puVar4 = puVar5 + 3;
    puVar5[2] = 0xffff;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0xffff;
  }
  do {
  } while (*(int *)0x32da == *(int *)0x32da);
  iVar2 = *(int *)0x32da;
  FUN_1000_be36();
  iVar3 = 3 - (iVar2 - *(int *)0x32da);
  if (3 < (uint)(iVar2 - *(int *)0x32da)) {
    iVar3 = 0;
  }
  *(int *)0x3c1e = iVar3 + 1;
  return CONCAT22(in_DX,in_AX);
}


