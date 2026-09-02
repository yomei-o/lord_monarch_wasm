/* 1000:25f8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00012673) overlaps instruction at (ram,0x00012671)
    */

void FUN_1000_25f8(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int unaff_BP;
  uint unaff_SI;
  uint uVar7;
  uint *unaff_DI;
  uint *puVar8;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  uint *in_stack_00000000;
  
  uVar3 = CONCAT11(100,(char)*(undefined2 *)0x34ce);
  iVar6 = 0x60;
  uVar2 = *(uint *)(unaff_BP + -2);
  uVar5 = *(uint *)(unaff_BP + -4);
  if (-1 < (int)uVar5) {
    bVar9 = true;
    if (uVar2 < uVar5) {
      while( true ) {
        uVar7 = uVar2;
        *(int *)(unaff_SI + 0x60) = (*(int *)(unaff_SI + 0x60) - (int)&stack0x0000) - (uint)bVar9;
        *unaff_DI = uVar3;
        bVar9 = unaff_SI < uVar7;
        unaff_SI = unaff_SI - uVar7;
        puVar8 = unaff_DI + 1;
        if (bVar9) {
          unaff_SI = unaff_SI + *(int *)(unaff_BP + -4);
          puVar8 = unaff_DI + 0x31;
        }
        bVar9 = bVar9 && (uint *)0xff9f < unaff_DI + 1;
        if (uVar5 - 1 == 0) break;
        unaff_DI = puVar8 + 1;
        *puVar8 = uVar3;
        uVar2 = uVar5 - 1;
        uVar5 = uVar7;
      }
      iVar6 = *(int *)(unaff_BP + -2) * 0x60;
      iVar4 = *(int *)(unaff_BP + -4);
    }
    else {
      uVar7 = uVar2 >> 1;
      iVar4 = uVar2 + 1;
      do {
        *unaff_DI = uVar3;
        puVar8 = unaff_DI + 0x30;
        bVar9 = uVar7 < uVar5;
        uVar7 = uVar7 - uVar5;
        if (bVar9) {
          uVar7 = uVar7 + *(int *)(unaff_BP + -2);
          puVar8 = unaff_DI + 0x31;
        }
        iVar4 = iVar4 + -1;
        unaff_DI = puVar8;
      } while (iVar4 != 0);
      *(char *)(uVar7 - 0x15) = *(char *)(uVar7 - 0x15) + '\x01';
      iVar4 = 0;
    }
    iVar4 = iVar4 + 1;
    do {
      *(uint *)(iVar6 + (int)puVar8) = uVar3;
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar1 = uVar3;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar6 = *(int *)(unaff_BP + -4);
    iVar4 = *(int *)(unaff_BP + -2) + 1;
    do {
      *in_stack_00000000 = uVar3;
      in_stack_00000000[iVar6] = uVar3;
      in_stack_00000000 = in_stack_00000000 + 0x30;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(uint *)(unaff_BP + -4) = uVar5;
  do {
  } while ((uVar3 ^ 0x8f0) == 0);
  *(char *)(unaff_BP + unaff_SI) =
       *(char *)(unaff_BP + unaff_SI) + (char)(uVar3 ^ 0x8f0) + (unaff_DI < (uint *)0x35);
  *(uint *)((int)unaff_DI + -0x35) = uVar3 ^ 0x2b0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


