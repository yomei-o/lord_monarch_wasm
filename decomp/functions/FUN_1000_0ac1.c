/* 1000:0ac1 */

/* WARNING: Instruction at (ram,0x00010af7) overlaps instruction at (ram,0x00010af6)
    */
/* WARNING: Removing unreachable block (ram,0x00010b01) */

undefined4 FUN_1000_0ac1(void)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  int in_CX;
  int iVar3;
  int iVar4;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 uVar6;
  undefined2 in_stack_00000010;
  undefined2 in_stack_00000014;
  undefined2 uStack_2;
  
  while( true ) {
    unaff_SI = unaff_SI + 1;
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    LOCK();
    uVar6 = *unaff_SI;
    *unaff_SI = *unaff_DI;
    UNLOCK();
    puVar1 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *puVar1 = uVar6;
  }
  LOCK();
  uVar6 = *(undefined2 *)0x3472;
  *(undefined2 *)0x3472 = *(undefined2 *)0x3470;
  UNLOCK();
  *(undefined2 *)0x3470 = uVar6;
  *(undefined1 *)0x3b48 = 0;
  *(undefined1 *)0x3b49 = 0;
  puVar5 = (undefined2 *)0x3a3a;
  iVar4 = 6;
  do {
    for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar1 = 0;
    }
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  do {
    uVar6 = unaff_DS;
    iVar4 = 6;
    *(byte *)0x3a59 = *(byte *)0x3a59 & 0x40 | 0xe;
    *(undefined1 *)0x3a3a = 1;
    *(int *)0x3a3c = *(int *)0x3f22 + 0x3f1c;
    *(undefined1 *)0x3a40 = 0x26;
    uStack_2 = 0xb1e;
    FUN_1000_0bde();
    unaff_DS = uStack_2;
  } while (iVar4 != 1);
  *(undefined1 *)0x3b42 = 0xff;
  FUN_1000_1346();
  FUN_1000_1346();
  uVar2 = FUN_1000_1346();
  *(undefined1 *)0x3a5a = uVar2;
  FUN_1000_1388();
  return CONCAT22(in_stack_00000010,in_stack_00000014);
}


