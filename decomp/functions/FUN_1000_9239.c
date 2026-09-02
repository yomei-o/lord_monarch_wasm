/* 1000:9239 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00019240) overlaps instruction at (ram,0x0001923e)
    */

void FUN_1000_9239(undefined2 param_1)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  byte in_AL;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined2 in_DX;
  int in_BX;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 uStack0004;
  
  *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) | in_AL;
  uVar5 = in(in_DX);
  uVar4 = CONCAT11(0xa8,uVar5);
  do {
    uVar6 = uVar4;
    for (iVar8 = 4000; iVar8 != 0; iVar8 = iVar8 + -1) {
      puVar3 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      puVar2 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      *puVar3 = *puVar2;
    }
    uVar7 = uVar6 + 0x7b6;
    uVar4 = uVar7;
  } while ((uVar7 < 0xc000) || (uVar4 = uVar6 + 0x27b6, uVar7 < 0xe000));
  uStack0004 = 0x925f;
  FUN_1000_25f8();
  bVar1 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar1 ^ 1;
  out(0xa6,bVar1 ^ 1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


