/* 1000:5507 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00015513) overlaps instruction at (ram,0x00015510)
    */
/* WARNING: Removing unreachable block (ram,0x00015534) */

void FUN_1000_5507(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  uint in_CX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 *unaff_DI;
  undefined2 unaff_DS;
  bool bVar7;
  undefined4 uVar8;
  
  puVar6 = (undefined2 *)*(int *)0x3e8e;
  uVar5 = *(uint *)0x3e90;
  do {
    if (uVar5 == 0) {
      bVar7 = CARRY2(*(uint *)0x3e8a,*(uint *)0x0);
      if (bVar7) {
        halt_baddata();
      }
      uVar8 = FUN_1000_5a85();
      in_CX = (uint)((ulong)uVar8 >> 0x10);
      *(undefined2 *)0x3e8a = (int)uVar8;
      if (bVar7) {
        halt_baddata();
      }
      puVar6 = (undefined2 *)0xb98e;
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
    if (in_CX == 0) {
      *(int *)0x3e8e = (int)puVar6;
      *(uint *)0x3e90 = uVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  } while( true );
}


