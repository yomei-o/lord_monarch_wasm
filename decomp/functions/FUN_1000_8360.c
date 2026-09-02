/* 1000:8360 */

/* WARNING: Instruction at (ram,0x0001836e) overlaps instruction at (ram,0x0001836c)
    */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000_8360(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  int *piVar3;
  int iVar4;
  byte in_DL;
  int in_BX;
  byte bVar5;
  int *piVar6;
  int unaff_BP;
  char *unaff_SI;
  undefined2 *unaff_DI;
  int *piVar7;
  int *piVar8;
  undefined2 unaff_ES;
  int unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  
  pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x4000);
  bVar5 = (byte)((uint)in_BX >> 8);
  bVar9 = CARRY1(*pbVar1,bVar5);
  *pbVar1 = *pbVar1 + bVar5;
  for (iVar4 = 0x30; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *puVar2 = 0xffff;
  }
  piVar7 = unaff_DI + 1;
  *unaff_DI = 0xffff;
  while( true ) {
    for (iVar4 = 0x2e; iVar4 != 0; iVar4 = iVar4 + -1) {
      piVar3 = piVar7;
      piVar7 = piVar7 + 1;
      *piVar3 = in_BX;
    }
    *piVar7 = -1;
    *unaff_SI = *unaff_SI + in_DL + bVar9;
    iVar4 = 0;
    piVar7 = piVar7 + 1;
    do {
      piVar8 = piVar7;
      *piVar8 = in_BX;
      piVar8[1] = -1;
      iVar4 = iVar4 + -1;
      piVar7 = piVar8 + 2;
    } while (iVar4 != 0);
    piVar7 = piVar8 + 3;
    piVar8[2] = -1;
    if (unaff_CS == 1) break;
    pbVar1 = (byte *)((int)piVar7 + in_BX + -0x55);
    bVar9 = CARRY1(*pbVar1,in_DL);
    *pbVar1 = *pbVar1 + in_DL;
  }
  unaff_SI[in_BX] = unaff_SI[in_BX];
  do {
  } while (*(int *)0x32da == *(int *)0x32da);
  *(undefined2 *)0x17 = *(undefined2 *)0x32da;
  piVar6 = (int *)0x15;
  *(undefined2 *)0x15 = 0x839d;
  FUN_1000_8a5c();
  iVar4 = 3 - (*piVar6 - *(int *)0x32da);
  if (3 < (uint)(*piVar6 - *(int *)0x32da)) {
    iVar4 = 0;
  }
  *(int *)0x3c1e = iVar4 + 1;
  return CONCAT22(piVar6[6],piVar6[8]);
}


